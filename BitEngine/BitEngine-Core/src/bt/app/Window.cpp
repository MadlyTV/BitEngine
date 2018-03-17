#include "bt\bt.h"
#include "Window.h"

#include "bt\graphics\Renderer.h"

#include "bt\utils\Log.h"

//TODO: font stuff

namespace bt {
	using namespace graphics;

	std::map<void*, Window*> Window::s_Handles;

	Window::Window(const String& title, const WindowProperties& properties)
		: m_Title(title), m_Properties(properties), m_Handle(nullptr), m_Closed(false), m_EventCallback(nullptr)
	{
		if (!Init()) {
			BT_ERROR("Failed base window initialization!");
			return;
		}

		//Font stuff here

		//Freeimage

		//Audio

		m_InputManager = new InputManager();
	}

	Window::~Window() {
		//remove font texturemanager och sound
	}

	bool Window::Init() {
		if (!PlatformInit()) {
			BT_FATAL("Failed to initialize platform!");
			return false;
		}

		Renderer::Init();

		SetTitle(m_Title);
		return true;
	}

	void Window::SetVsync(bool enabled) {
		//TODO: Implement
		m_Vsync = enabled;
	}

	void Window::Clear() const {
		Renderer::Clear(RENDERER_BUFFER_COLOR | RENDERER_BUFFER_DEPTH);
	}

	void Window::Update() {
		PlatformUpdate();
		//Audio update
	}

	bool Window::Closed() const {
		return m_Closed;
	}

	void Window::SetEventCallback(const WindowEventCallback& callback) {
		m_EventCallback = callback;
		m_InputManager->SetEventCallback(m_EventCallback);
	}

	void Window::RegisterWindowClass(void* handle, Window* window) {
		s_Handles[handle] = window;
	}

	Window* Window::GetWindowClass(void* handle) {
		if (handle == nullptr)
			return s_Handles.begin()->second;

		return s_Handles[handle];
	}
}