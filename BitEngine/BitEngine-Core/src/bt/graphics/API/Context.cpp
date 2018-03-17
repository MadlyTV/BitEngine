#include "bt\bt.h"
#include "Context.h"

#include "bt\platform\opengl\GLContext.h"

#include "bt\system\Memory.h"

namespace bt { namespace graphics { namespace API {

	Context* Context::s_Context = nullptr;
	RenderAPI Context::s_RenderAPI = RenderAPI::NONE;

	void Context::Create(WindowProperties properties, void* deviceContext) {
		switch (GetRenderAPI())
		{
			case RenderAPI::OPENGL: s_Context = btnew GLContext(properties, deviceContext); break;
		}
	}

} } }