#pragma once

#include <sstream>
#include "vec2.h"

namespace bt { namespace maths {

	struct vec2;

	struct vec3
	{
		float x;
		float y;
		float z;

		vec3();
		vec3(const float& x, const float& y, const float& z);
		vec3(const vec2& vector);

		vec3& add(const vec3& other);
		vec3& subtract(const vec3& other);
		vec3& multiply(const vec3& other);
		vec3& devide(const vec3& other);

		vec3& add(float other);
		vec3& subtract(float other);
		vec3& multiply(float other);
		vec3& devide(float other);

		friend vec3 operator+(vec3 left, const vec3& right);
		friend vec3 operator-(vec3 left, const vec3& right);
		friend vec3 operator*(vec3 left, const vec3& right);
		friend vec3 operator/(vec3 left, const vec3& right);

		friend vec3 operator+(vec3 left, float right);
		friend vec3 operator-(vec3 left, float right);
		friend vec3 operator*(vec3 left, float right);
		friend vec3 operator/(vec3 left, float right);

		bool operator==(const vec3& other) const;
		bool operator!=(const vec3& other) const;

		vec3& operator+=(const vec3& other);
		vec3& operator-=(const vec3& other);
		vec3& operator*=(const vec3& other);
		vec3& operator/=(const vec3& other);

		vec3& operator+=(const vec2& other);
		vec3& operator-=(const vec2& other);
		vec3& operator*=(const vec2& other);
		vec3& operator/=(const vec2& other);

		bool operator<(const vec3& other) const;
		bool operator<=(const vec3& other) const;
		bool operator>(const vec3& other) const;
		bool operator>=(const vec3& other) const;

		float Distance(const vec3& other) const;

		friend std::ostream& operator<<(std::ostream stream, const vec3& vector);
	};

} }