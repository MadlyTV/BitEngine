#pragma once

#include <deque>
#include "renderer3D.h"

namespace MadlyTv { namespace graphics {

	class Simple3DRenderer : public Renderer3D
	{
	private:
		std::deque<const Model*> m_RenderQueue;
	public:
		void submit(const Model* model) override;
		void flush(Shader shader) override;
	};
} }