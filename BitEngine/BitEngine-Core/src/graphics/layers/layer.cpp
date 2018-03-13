#include "layer.h"

namespace BitEngine { namespace graphics {

	Layer::Layer(Renderer2D* renderer, Shader* shader, maths::mat4 projectionmatrix) 
		: m_ProjectionMatrix(projectionmatrix), m_Shader(shader), m_Renderer(renderer)
	{
		m_Shader->enable();
		m_Shader->setUniformMat4("pr_matrix", m_ProjectionMatrix);

		GLint texIDs[] = {
			0,	1,	2,	3,	4,	5,	6,	7,	8,	9,
			10,	11,	12,	13,	14,	15,	16,	17,	18,	19,
			20,	21,	22,	23,	24,	25,	26,	27,	28,	29,
			30,	31
		};

		m_Shader->setUniform1iv("textures", 32, texIDs);

		m_Shader->disable();
	}

	Layer::~Layer() {
		delete m_Shader;
		delete m_Renderer;

		for (int i = 0; i < m_Renderables.size(); i++)
			delete m_Renderables[i];
	}

	void Layer::add(Renderable2D* renderable) {
		m_Renderables.push_back(renderable);
	}

	void Layer::render() {
		m_Shader->enable();

		m_Renderer->begin();

		for (const Renderable2D* renderable : m_Renderables)
			renderable->submit(m_Renderer);

		m_Renderer->end();

		m_Renderer->flush();
		m_Shader->disable();
	}

} }