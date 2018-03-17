#include "bt\bt.h"
#include "GLContext.h"

#undef NOGDI
#include <Windows.h>
#define NOGDI
#include "bt\utils\Log.h"

#include <GL\glew.h>

namespace bt { namespace graphics { namespace API {
		
	static HDC hDc;

	GLContext::GLContext(WindowProperties, void* deviceContext) {
		hDc = GetDC((HWND)deviceContext);
		HGLRC hrc = wglCreateContext(hDc);
		if (hrc) {
			if (!wglMakeCurrent(hDc, hrc)) {
				BT_ERROR("Failed setting OpenGL context!");
				BT_ASSERT(false);
			}
		}
		else {
			BT_ERROR("Failed creating OpenGL context!");
		}

		if (glewInit() != GLEW_OK) {
			BT_FATAL("Could not initialize GLEW!");
			BT_ASSERT(false);
		}
	}

	void GLContext::Present() {
		SwapBuffers(hDc);
	}

} } }