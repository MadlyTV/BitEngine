#include "bt\bt.h"
#include "vec2.h"

#include <sstream>

namespace bt { namespace maths {

	vec2::vec2()
		: x(0.0f), y(0.0f)
	{
	}

	vec2::vec2(const float& x, const float& y) 
		: x(x), y(y)
	{
	}

	vec2::vec2(const vec3& vector)
		: x(vector.x), y(vector.y)
	{
	}

	vec2& vec2::add(const vec2& other) {
		x += other.x;
		y += other.y;

		return *this;
	}

	vec2& vec2::subtract(const vec2& other) {
		x -= other.x;
		y -= other.y;

		return *this;
	}

	vec2& vec2::multiply(const vec2& other) {
		x *= other.x;
		y *= other.y;

		return *this;
	}

	vec2& vec2::devide(const vec2& other) {
		x /= other.x;
		y /= other.y;

		return *this;
	}

	vec2& vec2::add(float other) {
		x += other;
		y += other;

		return *this;
	}

	vec2& vec2::subtract(float other) {
		x -= other;
		y -= other;

		return *this;
	}

	vec2& vec2::multiply(float other) {
		x *= other;
		y *= other;

		return *this;
	}

	vec2& vec2::devide(float other) {
		x /= other;
		y /= other;

		return *this;
	}

	vec2 operator+(vec2 left, const vec2& right) {
		return left.add(right);
	}

	vec2 operator-(vec2 left, const vec2& right) {
		return left.subtract(right);
	}

	vec2 operator*(vec2 left, const vec2& right) {
		return left.multiply(right);
	}

	vec2 operator/(vec2 left, const vec2& right) {
		return left.devide(right);
	}

	vec2 operator+(vec2 left,float right) {
		return left.add(right);
	}

	vec2 operator-(vec2 left, float right) {
		return left.subtract(right);
	}

	vec2 operator*(vec2 left, float right) {
		return left.multiply(right);
	}

	vec2 operator/(vec2 left, float right) {
		return left.devide(right);
	}

	vec2& vec2::operator+=(const vec2& other) {
		return add(other);
	}

	vec2& vec2::operator-=(const vec2& other) {
		return subtract(other);
	}

	vec2& vec2::operator*=(const vec2& other) {
		return multiply(other);
	}

	vec2& vec2::operator/=(const vec2& other) {
		return devide(other);
	}

	bool vec2::operator==(const vec2& other) const{
		return x == other.x && y == other.y;
	}

	bool vec2::operator!=(const vec2& other) const{
		return !(*this == other);
	}

	bool vec2::operator<(const vec2& other) const
	{
		return x < other.x && y < other.y;
	}

	bool vec2::operator<=(const vec2& other) const
	{
		return x <= other.x && y <= other.y;
	}

	bool vec2::operator>(const vec2& other) const
	{
		return x > other.x && y > other.y;
	}

	bool vec2::operator>=(const vec2& other) const
	{
		return x >= other.x && y >= other.y;
	}

	float vec2::Distance(const vec2& other) const
	{
		float a = x - other.x;
		float b = y - other.y;
		return sqrt(a * a + b * b);
	}

	std::ostream& operator<<(std::ostream stream, const vec2& vector) {
		stream << "vec2: (" << vector.x << ", " << vector.y << ")";
		return stream;
	}

} }