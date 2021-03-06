#pragma once

#include <iostream>
#include "maths.h"
#include "AABB.h"

namespace BitEngine { namespace maths {
	struct AABB;

	struct Rectangle {
		union {
			vec2 position;
			struct {
				float x;
				float y;
			};
		};
		union 
		{
			vec2 size;
			struct 
			{
				float width;
				float height;
			};
		};

		Rectangle();
		Rectangle(const AABB& aabb);
		Rectangle(const vec2& position, const vec2& size);
		Rectangle(float x, float y, float width, float height);

		bool Intersects(const Rectangle& other) const;
		bool Contains(const vec2& point) const;
		bool Contains(const vec3& point) const;

		inline vec2 GetMinimumBound() const { return position - size; }
		inline vec2 GetMaximumBound() const { return position + size; }

		bool operator==(const Rectangle& other) const;
		bool operator!=(const Rectangle& other) const;

		bool operator<(const Rectangle& other) const;
		bool operator>(const Rectangle& other) const;

		friend std::ostream& operator<<(std::ostream& stream, const Rectangle& rectangle);
	};
} }
