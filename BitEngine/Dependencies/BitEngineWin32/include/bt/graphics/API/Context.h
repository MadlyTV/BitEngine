#pragma once

#include "bt\common.h"
#include "bt\app\Window.h"

namespace bt { namespace graphics { namespace API {

	enum class BT_API RenderAPI
	{
		NONE, OPENGL
	};

	class BT_API Context {
	protected:
		static Context* s_Context;
		static RenderAPI s_RenderAPI;
	public:
		static void Create(WindowProperties properties, void* deviceContext);

		static RenderAPI GetRenderAPI() { return s_RenderAPI; }
		static void SetRenderAPI(RenderAPI api) { s_RenderAPI = api; }
	};

} } }