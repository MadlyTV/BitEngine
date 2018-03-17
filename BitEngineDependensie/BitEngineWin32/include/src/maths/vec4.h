#pragma once

#include "bt\bt.h"
#include "bt\common.h"

#include "vec3.h"

namespace bt { namespace maths {

	struct mat4;

	struct BT_API vec4
	{
		float x;
		float y;
		float z;
		float w;

		vec4();
		vec4(const float& x, const float& y, const float& z, const float& w);

		vec4& add(const vec4& other);
		vec4& subtract(const vec4& other);
		vec4& multiply(const vec4& other);
		vec4& devide(const vec4& other);

		friend vec4 operator+(vec4 left, const vec4& right);
		friend vec4 operator-(vec4 left, const vec4& right);
		friend vec4 operator*(vec4 left, const vec4& right);
		friend vec4 operator/(vec4 left, const vec4& right);

		bool operator==(const vec4& other);
		bool operator!=(const vec4& other);

		vec4& operator+=(const vec4& other);
		vec4& operator-=(const vec4& other);
		vec4& operator*=(const vec4& other);
		vec4& operator/=(const vec4& other);

		friend std::ostream& operator<<(std::ostream stream, const vec4& vector);
	};

} }
