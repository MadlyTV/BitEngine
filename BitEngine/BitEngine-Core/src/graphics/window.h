#pragma once


#include <iostream>
#include <GL\glew.h>
#include <GLFW\glfw3.h>

#include "../Logger/logger.h"

namespace BitEngine { namespace graphics {

#define MAX_KEYS 1024
#define MAX_BUTTONS 32

	class Window
	{
	private:
		loglevel_e loglevel = logDEBUG4;
	private:

		const char *m_title;
		int m_width, m_height;
		GLFWwindow *m_window;
		bool m_closed;

		bool m_keys[MAX_KEYS];
		bool m_MouseButtons[MAX_BUTTONS];
		double mx, my;
		double scrollx, scrolly;

	public:
		Window(const char *title, int width, int height);
		~Window();
		void clear() const;
		void update();
		bool closed() const;
		 
		inline int getWidth() const { return  m_width; }
		inline int getHeight() const { return m_height; }

		bool isKeyPressed(unsigned int keycode) const;
		bool isMouseButtonPressed(unsigned int button) const;
		void getMousePosition(double& x, double& y) const;
		void getMouseScroll(double& x, double& y) const;
	private:
		bool init();
		friend void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
		friend void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
		friend void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
		friend void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
	};
} }