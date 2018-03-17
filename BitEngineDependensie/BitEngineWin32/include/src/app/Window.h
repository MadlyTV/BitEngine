#pragma once

#include "bt\bt.h"

#include "bt\maths\vec2.h"

#include "bt\events\Events.h"

//TODO: Sound

#include "bt\app\Input.h"

namespace bt {

	typedef std::function<void(events::Event& event)> WindowEventCallback;

	struct BT_API WindowProperties
	{
		uint width, height;
		bool fullscreen;
		bool vsync;
	};

	class BT_API Window {
	private:
		static std::map<void*, Window*> s_Handles;
	private:
		String m_Title;
		WindowProperties m_Properties;
		bool m_Closed;
		void* m_Handle;

		bool m_Vsync;
		WindowEventCallback m_EventCallback;
		InputManager* m_InputManager;
	public:
		Window(const String& title, const WindowProperties& properties);
		~Window();
		void Clear() const;
		void Update();
		bool Closed() const;

		void SetTitle(const String& title);

		inline uint GetWidth() const { return m_Properties.width; }
		inline uint GetHeight() const { return m_Properties.height; }

		void SetVsync(bool enabled);
		inline bool IsVsync() const { return m_Vsync; }

		inline InputManager* GetInputManager() const { return m_InputManager; }

		void SetEventCallback(const WindowEventCallback& callback);
	private:
		bool Init();

		bool PlatformInit();
		void PlatformUpdate();

		friend void ResizeCallback(Window* window, int32 width, int32 height);
		friend void FocusCallback(Window* window, bool focused);
	public:
		static void RegisterWindowClass(void* handle, Window* window);
		static Window* GetWindowClass(void* handle);
	};

}