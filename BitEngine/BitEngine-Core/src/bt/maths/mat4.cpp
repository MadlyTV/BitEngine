#include "bt\bt.h"
#include "mat4.h"

#include <sstream>

namespace bt { namespace maths {
	
	mat4::mat4() {
		memset(elements, 0, 4 * 4 * sizeof(float));
	}

	mat4::mat4(float diagonal) {
		memset(elements, 0, 4 * 4 * sizeof(float));

		elements[0 + 0 * 4] = diagonal;
		elements[1 + 1 * 4] = diagonal;
		elements[2 + 2 * 4] = diagonal;
		elements[3 + 3 * 4] = diagonal;
	}

	mat4 mat4::identity() {
		return mat4(1.0f);
	}

	mat4& mat4::multiply(const mat4& other) {
		float data[16];
		for (int y = 0; y < 4; y++) {
			for (int x = 0; x < 4; x++) {
				float sum = 0.0f;
				for (int e = 0; e < 4; e++)
				{
					sum += elements[e + y * 4] * other.elements[x + e * 4];
				}
				data[x + y * 4] = sum;
			}
		}

		memcpy(elements, data, 4*4*sizeof(float));

		return *this;
	}

	vec3 mat4::multiply(const vec3& other) const {
		return vec3(
			columns[0].x * other.x + columns[0].y * other.y + columns[0].z * other.z + columns[0].w,
			columns[1].x * other.x + columns[1].y * other.y + columns[1].z * other.z + columns[1].w,
			columns[2].x * other.x + columns[2].y * other.y + columns[2].z * other.z + columns[2].w
		);
	}

	vec4 mat4::multiply(const vec4& other) const {
		return vec4(
			columns[0].x * other.x + columns[0].y * other.y + columns[0].z * other.z + columns[0].w * other.w,
			columns[1].x * other.x + columns[1].y * other.y + columns[1].z * other.z + columns[1].w * other.w,
			columns[2].x * other.x + columns[2].y * other.y + columns[2].z * other.z + columns[2].w * other.w,
			columns[3].x * other.x + columns[3].y * other.y + columns[3].z * other.z + columns[3].w * other.w
		);
	}

	mat4 operator*(mat4 left, const mat4 right) {
		return left.multiply(right);
	}

	mat4& mat4::operator*=(const mat4& other) {
		return multiply(other);
	}

	vec3 operator*(const mat4& left, const vec3& right) {
		return left.multiply(right);
	}

	vec4 operator*(const mat4& left, const vec4& right) {
		return left.multiply(right);
	}

	mat4 mat4::orthographic(float left, float right, float bottom, float top, float near, float far) {
		mat4 result(1.0f);

		result.elements[0 + 0 * 4] = 2.0f / (right-left);

		result.elements[1 + 1 * 4] = 2.0f / (top - bottom);

		result.elements[2 + 2 * 4] = 2.0f / (near - far);

		result.elements[3 + 0 * 4] = (left + right) / (left - right);
		result.elements[3 + 1 * 4] = (bottom + top) / (bottom - top);
		result.elements[3 + 2 * 4] = (far + near) / (far - near);

		return result;
	}

	mat4 mat4::perspective(float fov, float aspectRatio, float near, float far) {
		mat4 result(1.0f);

		float q = 1.0f / tan(toRadians(0.5f * fov));
		float a = q / aspectRatio;

		float b = (near + far) / (near - far);
		float c = (2.0f * near * far) / (near - far);

		result.elements[0 + 0 * 4] = a;
		result.elements[1 + 1 * 4] = q;
		result.elements[2 + 2 * 4] = b;
		result.elements[2 + 3 * 4] = -1.0f;
		result.elements[3 + 2 * 4] = c;

		return result;
	}

	mat4 mat4::translate(const vec3& translation) {
		mat4 result(1.0f);

		result.elements[3 + 0 * 4] = translation.x;
		result.elements[3 + 1 * 4] = translation.y;
		result.elements[3 + 2 * 4] = translation.z;

		return result;
	}

	mat4 mat4::rotate(float angle, const vec3& axis) {
		mat4 result(1.0f);

		float r = toRadians(angle);
		float c = cos(r);
		float s = sin(r);
		float omc = 1.0f - c;

		float x = axis.x;
		float y = axis.y;
		float z = axis.z;

		result.elements[0 + 0 * 4] = x * x * omc + c;
		result.elements[0 + 1 * 4] = y * x * omc + z * s;
		result.elements[0 + 2 * 4] = x * z * omc - y * s;

		result.elements[1 + 0 * 4] = x * y * omc - z * s;
		result.elements[1 + 1 * 4] = y * y * omc + c;
		result.elements[1 + 2 * 4] = y * z * omc + x * s;

		result.elements[2 + 0 * 4] = x * z * omc + y * s;
		result.elements[2 + 1 * 4] = y * z * omc - x * s;
		result.elements[2 + 2 * 4] = z * z * omc + c;

		return result;
	}

	mat4 mat4::scale(const vec3& scale) {
		mat4 result(1.0f);

		result.elements[0 + 0 * 4] = scale.x;
		result.elements[1 + 1 * 4] = scale.y;
		result.elements[2 + 2 * 4] = scale.z;

		return result;
	}

} }