#pragma once

#include "bt\common.h"

#include <math.h>

#define BT_PI 3.14159265358f

namespace bt { namespace maths {

	BT_API inline float toRadians(float degrees) {
		return (float)(degrees * (BT_PI / 180.0f));
	}

	BT_API inline float toDegrees(float radians) {
		return (float)(radians * (180 / BT_PI));
	}

	BT_API inline int32 sign(float value) {
		return (value > 0) - (value < 0);
	}

	BT_API inline float sin(float angle) {
		return ::sin(angle);
	}

	BT_API inline float cos(float angle) {
		return ::cos(angle);
	}

	BT_API inline float tan(float angle) {
		return ::tan(angle);
	}

	BT_API inline float sqrt(float angle) {
		return ::sqrt(angle);
	}

	BT_API inline float rsqrt(float angle) {
		return 1.0f / ::sqrt(angle);
	}

	BT_API inline float asin(float angle) {
		return ::asin(angle);
	}

	BT_API inline float acos(float angle) {
		return ::acos(angle);
	}

	BT_API inline float atan(float angle) {
		return ::atan(angle);
	}

	BT_API inline float atan2(float x, float y) {
		return ::atan2(x,y);
	}

	BT_API inline float _min(float value, float minimum) {
		return (value < minimum) ? minimum : value;
	}

	BT_API inline float _max(float value, float maxmum) {
		return (value > maxmum) ? maxmum : value;
	}

	BT_API inline float clamp(float value, float minimum, float maximum) {
		return (value > minimum) ? (value < maximum) ? value : maximum : minimum;
	}

} }