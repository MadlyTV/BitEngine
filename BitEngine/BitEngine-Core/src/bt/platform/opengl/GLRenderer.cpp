#include "bt\bt.h"
#include "GLRenderer.h"

#include "bt\utils\Log.h"

#include <GL\glew.h>

namespace bt { namespace graphics {

	GLRenderer::GLRenderer() {
		m_Context = API::GLContext::Get();
	}

	void GLRenderer::InitInternal() {
		SetDepthTesting(true);
		SetBlend(true);
		SetBlendFunction(RendererBlendFunction::SOURCE_ALPHA, RendererBlendFunction::ONE_MINUS_SOURCE_ALPHA);

		BT_WARN("----------------------------------");
		BT_WARN(" OpenGL:");
		BT_WARN("    ", glGetString(GL_VERSION));
		BT_WARN("    ", glGetString(GL_VENDOR));
		BT_WARN("    ", glGetString(GL_RENDERER));
		BT_WARN("----------------------------------");

		//Move to API independent layer
		GLCall(glEnable(GL_CULL_FACE));
		GLCall(glFrontFace(GL_CCW));
		GLCall(glCullFace(GL_BACK));

		m_RendererTitle = "OpenGL";
	}

	void GLRenderer::ClearInternal(uint buffer) {
		GLCall(glClear(BTRendererBufferToGL(buffer)));
	}

	void GLRenderer::PresentInternal() {
		m_Context->Present();
	}

	void GLRenderer::SetDepthTestingInternal(bool enabled) {
		if (enabled) {
			GLCall(glEnable(GL_DEPTH_TEST));
		}
		else {
			GLCall(glDisable(GL_DEPTH_TEST));
		}
	}

	void GLRenderer::SetBlendInternal(bool enabled) {
		if (enabled) {
			GLCall(glEnable(GL_BLEND));
		}
		else {
			GLCall(glDisable(GL_BLEND));
		}
	}

	void GLRenderer::SetBlendFunctionInternal(RendererBlendFunction source, RendererBlendFunction destination) {
		GLCall(glBlendFunc(BTRendererBlendFunctionToGL(source), BTRendererBlendFunctionToGL(destination)));
	}

	void GLRenderer::SetBlendEquationInternal(RendererBlendFunction blendEquation) {
		BT_ASSERT(false, "Not implemented");
	}

	void GLRenderer::SetViewportInternal(uint x, uint y, uint width, uint height) {
		GLCall(glViewport(x, y, width, height));
	}

	const String& GLRenderer::GetTitleInternal() const {
		return m_RendererTitle;
	}

	uint GLRenderer::BTRendererBufferToGL(uint buffer) {
		uint result = 0;
		if (buffer & RENDERER_BUFFER_COLOR)
			result |= GL_COLOR_BUFFER_BIT;
		if (buffer & RENDERER_BUFFER_DEPTH)
			result |= GL_COLOR_BUFFER_BIT;
		if (buffer & RENDERER_BUFFER_STENCIL)
			result |= GL_STENCIL_BUFFER_BIT;
		return result;
	}

	uint GLRenderer::BTRendererBlendFunctionToGL(RendererBlendFunction function) {
		switch (function)
		{
			case RendererBlendFunction::ZERO:						return GL_ZERO;
			case RendererBlendFunction::ONE:						return GL_ONE;
			case RendererBlendFunction::SOURCE_ALPHA:				return GL_SRC_ALPHA;
			case RendererBlendFunction::DESTINATION_ALPHA:			return GL_DST_ALPHA;
			case RendererBlendFunction::ONE_MINUS_SOURCE_ALPHA:		return GL_ONE_MINUS_SRC_ALPHA;
		}
		return 0;
	}

} }