#include "bt\bt.h"
#include "Renderer.h"

#include "bt\platform\opengl\GLRenderer.h"

#include "API\Context.h"
#include "bt\system\Memory.h"

namespace bt { namespace graphics {

	Renderer* Renderer::s_Instance = nullptr;

	void Renderer::Init() {
		switch (API::Context::GetRenderAPI())
		{
		case API::RenderAPI::OPENGL: s_Instance = btnew GLRenderer(); break;
		}
		s_Instance->InitInternal();
	}

} }