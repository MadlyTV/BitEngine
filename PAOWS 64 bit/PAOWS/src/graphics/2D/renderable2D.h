#pragma once

#include "..\buffers\buffer.h";
#include "..\buffers\indexbuffer.h";
#include "..\buffers\vertexarray.h";

#include "renderer2D.h"

#include "texture.h"

#include "..\..\maths\maths.h";
#include "..\shader.h"

namespace BitEngine { namespace graphics {

	struct VertexData
	{
		maths::vec3 vertex;
		maths::vec2 uv;
		float tid;
		unsigned int color;
	};

	class Renderable2D
	{
	public:
		maths::Rectangle m_Bounds;
	protected:
		maths::vec3 m_Position;
		maths::vec2 m_Size;
		maths::vec4 m_Color;
		std::vector<maths::vec2> m_UV;
		Texture* m_Texture;
	protected:
		Renderable2D() : m_Texture(nullptr) { setUVDefaults(); }
	public:
		Renderable2D(maths::vec3 position, maths::vec2 size, maths::vec4 color)
			: m_Bounds(position, size), m_Position(position), m_Size(size), m_Color(color), m_Texture(nullptr)
		{ setUVDefaults(); }

		virtual ~Renderable2D() { }

		virtual void submit(Renderer2D* renderer) const {
			renderer->submit(this);
		}

		virtual void UpdateBoundsPosition() { 
			m_Bounds.position = maths::vec2();
		}

		virtual void UpdateBoundsSize() {
			m_Bounds.size = maths::vec2();
		}

		inline const maths::vec3& GetPosition() const { return m_Position; };
		inline const maths::vec2& GetSize() const { return m_Size; };
		inline const maths::vec4& GetColor() const { return m_Color; };
		inline const std::vector<maths::vec2>& GetUV() const { return m_UV; };

		inline const maths::Rectangle& GetBounds() const { return m_Bounds; }
		inline maths::Rectangle& GetBounds() { return m_Bounds; }

		inline maths::AABB GetBoundingBox() const { return m_Bounds; }

		inline const GLuint getTID() const { return m_Texture ? m_Texture->getID() : 0; }
	private:
		void setUVDefaults() {
			m_UV.push_back(maths::vec2(0, 0));
			m_UV.push_back(maths::vec2(0, 1));
			m_UV.push_back(maths::vec2(1, 1));
			m_UV.push_back(maths::vec2(1, 0));
		}
	};

} }

