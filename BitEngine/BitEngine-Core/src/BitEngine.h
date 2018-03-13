#pragma once

#include "graphics\window.h"
#include "utils\timer.h"

#include "graphics\2D\sprite.h"
#include "graphics\2D\renderer2D.h"
#include "graphics\2D\batchrenderer2D.h"
#include "graphics\layers\layer.h"

#include "Logger\logger.h"

#include "maths\maths.h"

namespace BitEngine {
	class BitEngine {
	private:
		graphics::Window* m_Window;
		Timer* m_Timer;
		unsigned int m_FramesPerSecond, m_UpdatesPerSecond;
	protected:
		BitEngine() 
			: m_FramesPerSecond(0), m_UpdatesPerSecond(0)
		{
			
		}

		virtual ~BitEngine() {
			delete m_Window;
		}

		graphics::Window* createWindow(const char *title, int width, int height) {
			
			m_Window = new graphics::Window(title, width, height);
			return m_Window;
		}

	public:
		void start() {
			init();
			run();
		}
	protected:

		/// Runs once upon initialization
		virtual void init() = 0;
		/// Runs once per second
		virtual void tick() {}
		/// Runs 60 times per second
		virtual void update() {}
		/// Runs as fast as possible (unless vsync is enabled)
		virtual void render() = 0;

		const unsigned int  getFPS() const { return m_FramesPerSecond; }
		const unsigned int  getUPS() const { return m_UpdatesPerSecond; }

	private:
		void run() {
			float timer = 0.0f;
			float updateTimer = 0.0f;
			float updateTick = 1.0f / 60.0f;
			m_Timer = new Timer();
			unsigned int frames = 0;
			unsigned int updates = 0;
			while (!m_Window->closed()) {
				m_Window->clear();

				if (m_Timer->elapsed() - updateTimer > updateTick) {
					updates++;
					update();
					updateTimer += updateTick;
				}

				render();

				m_Window->update();
				frames++;
				if (m_Timer->elapsed() - timer > 1.0f) {
					tick();
					timer += 1.0f;
					m_FramesPerSecond = frames;
					m_UpdatesPerSecond = updates;
					frames = 0;
					updates = 0;
				}
			}
		}
	};
}