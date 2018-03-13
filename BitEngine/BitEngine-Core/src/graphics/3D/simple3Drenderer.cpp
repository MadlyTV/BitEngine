#include "simple3Drenderer.h"

namespace MadlyTv { namespace graphics {

	void Simple3DRenderer::submit(const Model* model) {
		m_RenderQueue.push_back(model);
	}

	void Simple3DRenderer::flush(Shader shader) {
		while (!m_RenderQueue.empty())
		{
			const Model* model = m_RenderQueue.front();

			shader.setUniformMat4("ml_matrix", maths::mat4::translate(model->pos));

			m_RenderQueue.pop_front();
		}
	}
} }