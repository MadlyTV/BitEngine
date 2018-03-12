#include "sprite.h"

namespace BitEngine { namespace graphics {

	Sprite::Sprite(float x, float y, float width, float height, const maths::vec4& color)
		: Renderable2D(maths::vec3(x, y, 0), maths::vec2(width, height), color), position(m_Position)
	{

	}

	Sprite::Sprite(float x, float y, float width, float height, Texture* texture)
		: Renderable2D(maths::vec3(x, y, 0), maths::vec2(width, height), maths::vec4(1,0,1,1)), position(m_Position)
	{
		m_Texture = texture;
	}

	void Sprite::UpdateBoundsPosition() {
		m_Bounds.position = position;
	}

	void Sprite::UpdateBoundsSize(maths::vec2 size) {
		m_Bounds.size = size;
	}

} }