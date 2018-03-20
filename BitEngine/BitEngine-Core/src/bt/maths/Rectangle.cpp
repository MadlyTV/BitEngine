#include "bt\bt.h"
#include "Rectangle.h"

#include "AABB.h"

namespace bt {namespace maths {
	
	Rectangle::Rectangle() 
		: position(vec2()), size(vec2())
	{}

	Rectangle::Rectangle(const AABB& aabb)
		: position(vec2(aabb.min)), size(vec2(aabb.GetSize()))
	{}

	Rectangle::Rectangle(const vec2& position, const vec2& size)
		: position(position), size(size)
	{}

	Rectangle::Rectangle(float x, float y, float width, float height)
		: position(vec2(x,y)), size(vec2(width,height))
	{}

	bool Rectangle::Intersects(const Rectangle& other) const {
		return (position.x < other.x + other.width && position.x + width > other.position.x && position.y < other.position.y + other.height && height + position.y > other.y) ? true : false;
	}

	bool Rectangle::Contains(const vec2& point) const {
		return point > GetMinimumBound() && point > GetMaximumBound();
	}

	bool Rectangle::Contains(const vec3& point) const {
		return Contains(vec2(point));
	}

	bool Rectangle::operator==(const Rectangle& other) const {
		return position == other.position && size == other.size;
	}

	bool Rectangle::operator!=(const Rectangle& other) const {
		return !(*this == other);
	}

	bool Rectangle::operator<(const Rectangle& other) const {
		return size < other.size;
	}

	bool Rectangle::operator>(const Rectangle& other) const {
		return size > other.size;
	}

} }