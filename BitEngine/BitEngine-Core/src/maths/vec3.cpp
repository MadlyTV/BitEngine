#include "vec3.h"

namespace bt { namespace maths {

	vec3::vec3() 
		: x(0.0f), y(0.0f), z(0.0f)
	{
	}

	vec3::vec3(const float& x, const float& y, const float& z)
		: x(x), y(y), z(z)
	{
	}

	vec3::vec3(const vec2& vector)
		: x(vector.x), y(vector.y), z(0.0f)
	{
	}

	vec3& vec3::add(const vec3& other) {
		x += other.x;
		y += other.y;
		z += other.z;

		return *this;
	}

	vec3& vec3::subtract(const vec3& other) {
		x -= other.x;
		y -= other.y;
		z -= other.z;

		return *this;
	}

	vec3& vec3::multiply(const vec3& other) {
		x *= other.x;
		y *= other.y;
		z *= other.z;

		return *this;
	}

	vec3& vec3::devide(const vec3& other) {
		x /= other.x;
		y /= other.y;
		z /= other.z;

		return *this;
	}

	vec3& vec3::add(float other) {
		x += other;
		y += other;
		z += other;

		return *this;
	}

	vec3& vec3::subtract(float other) {
		x -= other;
		y -= other;
		z -= other;

		return *this;
	}

	vec3& vec3::multiply(float other) {
		x *= other;
		y *= other;
		z *= other;

		return *this;
	}

	vec3& vec3::devide(float other) {
		x /= other;
		y /= other;
		z /= other;

		return *this;
	}

	vec3 operator+(vec3 left, const vec3& right) {
		return left.add(right);
	}

	vec3 operator-(vec3 left, const vec3& right) {
		return left.subtract(right);
	}

	vec3 operator*(vec3 left, const vec3& right) {
		return left.multiply(right);
	}

	vec3 operator/(vec3 left, const vec3& right) {
		return left.devide(right);
	}

	vec3 operator+(vec3 left, float right) {
		return left.add(right);
	}

	vec3 operator-(vec3 left, float right) {
		return left.subtract(right);
	}

	vec3 operator*(vec3 left, float right) {
		return left.multiply(right);
	}

	vec3 operator/(vec3 left, float right) {
		return left.devide(right);
	}

	vec3& vec3::operator+=(const vec3& other) {
		return add(other);
	}

	vec3& vec3::operator-=(const vec3& other) {
		return subtract(other);
	}

	vec3& vec3::operator*=(const vec3& other) {
		return multiply(other);
	}

	vec3& vec3::operator/=(const vec3& other) {
		return devide(other);
	}

	vec3& vec3::operator+=(const vec2& other) {
		return add(vec3(other));
	}

	vec3& vec3::operator-=(const vec2& other) {
		return subtract(vec3(other));
	}

	vec3& vec3::operator*=(const vec2& other) {
		return multiply(vec3(other));
	}

	vec3& vec3::operator/=(const vec2& other) {
		return devide(vec3(other));
	}

	bool vec3::operator==(const vec3& other) const{
		return x == other.x && y == other.y && z == other.z;
	}

	bool vec3::operator!=(const vec3& other) const{
		return !(*this == other);
	}

	bool vec3::operator<(const vec3& other) const {
		return x < other.x && y < other.y && z < other.z;
	}

	bool vec3::operator<=(const vec3& other) const {
		return x <= other.x && y <= other.y && z <= other.z;
	}

	bool vec3::operator>(const vec3& other) const {
		return x > other.x && y > other.y && z > other.z;
	}

	bool vec3::operator>=(const vec3& other) const {
		return x >= other.x && y >= other.y && z >= other.z;
	}

	float vec3::Distance(const vec3& other) const
	{
		float a = x - other.x;
		float b = y - other.y;
		float c = z - other.z;
		return sqrt(a * a + b * b + c * c);
	}

	std::ostream& operator<<(std::ostream stream, const vec3& vector) {
		stream << "vec3: (" << vector.x << ", " << vector.y << ", " << vector.z << ")";
		return stream;
	}

} }