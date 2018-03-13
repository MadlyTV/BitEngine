#pragma once

#include "../2D/renderer2D.h"
#include "../2D/renderable2D.h"

namespace BitEngine { namespace graphics {
	
	class Layer {
	protected:
		Renderer2D* m_Renderer;
		std::vector<Renderable2D*> m_Renderables;
		Shader* m_Shader;
		maths::mat4 m_ProjectionMatrix;
	public:
		Layer(Renderer2D* renderer, Shader* shader, maths::mat4 projectionmatrix);
		virtual ~Layer();
		virtual void add(Renderable2D* renderable);
		virtual void render();
	};

} }