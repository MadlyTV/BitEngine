#pragma once

#include "bt\bt.h"
#include "bt\common.h"
#include "bt\types.h"

#include "bt\app\Window.h"
#include "bt\graphics\layers\Layer.h"
#include "bt\utils\timer.h"
#include "bt\utils\Timestep.h"

#include "bt\events\Events.h"

#include "bt\graphics\API\Context.h"

namespace bt {

	class BT_API Application {
	private:
		static Application* s_Instance;
	public:
		Window* window;
		//TODO: Debug stuff
	private:
		bool m_Running, m_Suspended;
		Timer* m_Timer;
		uint m_UpdatesPerSecond, m_FramesPerSecond;
		float m_Frametime;

		String m_Name;
		WindowProperties m_Properties;

		std::vector<graphics::Layer*> m_LayerStack;
		std::vector<graphics::Layer*> m_OverlayStack;
	public:
		Application(const String& name, const WindowProperties& properties, graphics::API::RenderAPI api = graphics::API::RenderAPI::OPENGL);
		virtual ~Application();

		virtual void Init();

		void PushLayer(graphics::Layer* layer);
		graphics::Layer* PopLayer();
		graphics::Layer* PopLayer(graphics::Layer* layer);

		void PushOverlay(graphics::Layer* layer);
		graphics::Layer* PopOverlay();
		graphics::Layer* PopOverlay(graphics::Layer* layer);

		void Start();
		void Suspend();
		void Resume();
		void Stop();

		inline uint GetFPS() const { return m_FramesPerSecond; }
		inline uint GetUPS() const { return m_UpdatesPerSecond; }
		inline float GetFrameTime() const { return m_Frametime; }

		inline uint GetWindowWidth() const { return window->GetWidth(); }
		inline uint GetWindowHeight() const { return window->GetHeight(); }
		inline maths::vec2 GetWindowSize() const { return maths::vec2((float)window->GetWidth(), (float)window->GetHeight()); }

		String GetBuildConfiguration();
		String GetPlatform(); //TODO: return "Platform" objetct rather then string
	private:
		void PlatformInit();
		void Run();

		void OnTick();
		void OnUpdate(const Timestep& ts);
		void OnRender();
	private:
		void OnEvent(events::Event& event);
	public:
		inline static Application& GetAplication() { return *s_Instance; }
	};

}