#pragma once

#include "bt\bt.h"
#include "bt\common.h"

#include "vec2.h"
#include "vec3.h"

namespace bt { namespace maths {
	struct Rectangle;

	struct BT_API AABB {
		vec3 min;
		vec3 max;

		AABB();
		AABB(const Rectangle& rectangle);
		AABB(const vec2& min, const vec2& max);
		AABB(const vec3& min, const vec3& max);
		AABB(float x, float y, float width, float height);
		AABB(float x, float y, float z, float width, float height, float depth);

		bool Intersects(const AABB& other) const;
		bool Contains(const vec2& point) const;
		bool Contains(const vec3& point) const;

		vec3 Center() const;

		bool operator==(const AABB& other) const;
		bool operator!=(const AABB& other) const;

		bool operator<(const AABB& other) const;
		bool operator>(const AABB& other) const;

		//add this
		friend std::ostream& operator<<(std::ostream& stream, const AABB& aabb);

		inline vec3 GetSize() const { return vec3(abs(max.x - min.x), abs(max.y - min.y), abs(max.z - min.z)); }
	};
} }