#pragma once

#include <sstream>
#include "vec3.h"

namespace BitEngine { namespace maths {

	struct vec3;

	struct vec2
	{
		float x;
		float y;

		vec2();
		vec2(const float& x, const float& y);
		vec2(const vec3& vector);

		vec2& add(const vec2& other);
		vec2& subtract(const vec2& other);
		vec2& multiply(const vec2& other);
		vec2& devide(const vec2& other);

		vec2& add(float other);
		vec2& subtract(float other);
		vec2& multiply(float other);
		vec2& devide(float other);

		friend vec2 operator+(vec2 left, const vec2& right);
		friend vec2 operator-(vec2 left, const vec2& right);
		friend vec2 operator*(vec2 left, const vec2& right);
		friend vec2 operator/(vec2 left, const vec2& right);

		friend vec2 operator+(vec2 left, float right);
		friend vec2 operator-(vec2 left, float right);
		friend vec2 operator*(vec2 left, float right);
		friend vec2 operator/(vec2 left, float right);

		bool operator==(const vec2& other) const;
		bool operator!=(const vec2& other) const;

		vec2& operator+=(const vec2& other);
		vec2& operator-=(const vec2& other);
		vec2& operator*=(const vec2& other);
		vec2& operator/=(const vec2& other);

		bool operator<(const vec2& other) const;
		bool operator<=(const vec2& other) const;
		bool operator>(const vec2& other) const;
		bool operator>=(const vec2& other) const;

		float Distance(const vec2& other) const;

		friend std::ostream& operator<<(std::ostream stream, const vec2& vector);
	};

} }