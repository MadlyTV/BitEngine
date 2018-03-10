#pragma once

#include "renderable2D.h"
#include "../../maths/maths.h"

namespace BitEngine {namespace graphics {

	class Sprite : public Renderable2D
	{
	public:
		maths::vec3& position;
	public:
		Sprite(float x, float y, float width, float height, const maths::vec4& color);
		Sprite(float x, float y, float width, float height, Texture* texture);
	};

} }