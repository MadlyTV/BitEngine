#pragma once

#include "bt\common.h"
#include "bt\String.h"

#include "vec3.h"
#include "vec4.h"
#include "maths_func.h"

namespace bt { namespace maths {

	struct BT_API mat4
	{
		union
		{
			float elements[4 * 4];
			vec4 columns[4];
		};

		mat4();
		mat4(float diagonal);

		static mat4 identity();

		mat4& multiply(const mat4& other);
		friend BT_API mat4 operator* (mat4 left, const mat4 right);
		mat4& operator*=(const mat4& other);

		vec3 multiply(const vec3& other) const;
		friend BT_API vec3 operator* (const mat4& left, const vec3& right);

		vec4 multiply(const vec4& other) const;
		friend BT_API vec4 operator* (const mat4& left, const vec4& right);

		static mat4 orthographic(float left, float right, float bottom, float top, float near, float far);
		static mat4 perspective(float fov, float aspectRatio, float near, float far);

		static mat4 translate(const vec3& translation);
		static mat4 rotate(float angle, const vec3& axis);
		static mat4 scale(const vec3& scale);
	};

} }