#pragma once

#include <GL\glew.h>
#include "..\..\maths\maths.h"
#include "model.h"

namespace MadlyTv { namespace graphics {

	class Renderer3D
	{
	public:
		virtual void submit(const Model* model) = 0;
		virtual void flush(Shader shader) = 0;
	};
} }