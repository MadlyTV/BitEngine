#pragma once

#include <GL/glew.h>

namespace bt {
	extern GLenum GLCheckError();
	extern bool GLLogCall(const char* function, const char* file, int32 line);
}

#ifdef BT_DEBUG
	#define GLCall(x) bt::GLCheckError();\
		x;\
		if (!bt::GLLogCall(#x,__FILE__, __LINE__)) __debugbreak();
#else
	#define GLCall(x) x;
#endif