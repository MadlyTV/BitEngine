#include "window.h"

namespace BitEngine { namespace graphics {
	
	void window_resize(GLFWwindow *window, int width, int height);

	Window::Window(const char *title, int width, int height) {
		m_title = title;
		m_width = width;
		m_height = height;

		if (!init()) {
			glfwTerminate();
		}

		for (int i = 0; i < MAX_KEYS; i++) {
			m_keys[i] = false;
		}
		for (int i = 0; i < MAX_BUTTONS; i++) {
			m_MouseButtons[i] = false;
		}
	}

	Window::~Window() {
		glfwTerminate();
	}

	bool Window::init() {
		std::cout << "=========================BitEngine v0.2.Alpha (DEV)=========================" << std::endl;

		if (!glfwInit()) {
			log(logERROR) << "Error! Coudent load GLFW window!";
			return false;
		}
		else {
			log(logINFO) << "Succeded to load GLFW window";
		}
		m_window = glfwCreateWindow(m_width, m_height, m_title, NULL,NULL);
		if (!m_window) {
			log(logERROR) << "Failed to create GLFW window!";
			return false;
		}
		else {
			log(logINFO) << "Succeded to create GLFW window";
		}
		glfwMakeContextCurrent(m_window);
		glfwSetWindowUserPointer(m_window, this);
		glfwSetWindowSizeCallback(m_window, window_resize);
		glfwSetKeyCallback(m_window, key_callback);
		glfwSetMouseButtonCallback(m_window,mouse_button_callback);
		glfwSetCursorPosCallback(m_window, cursor_position_callback);
		glfwSetScrollCallback(m_window, scroll_callback);
		glfwSwapInterval(0.0);

		log(logINFO) << glGetString(GL_VERSION);

		if (glewInit() != GLEW_OK) {
			log(logERROR) << "Error! coudent initialize GLEW!";
			return false;
		}
		else {
			log(logINFO) << "Succeded initialized GLEW";
		}

		return true;

	}

	void Window::getMousePosition(double& x, double& y) const {
		x = mx;
		y = my;
	}

	void Window::getMouseScroll(double& x, double& y) const {
		x = scrollx;
		y = scrolly;
	}

	bool Window::isKeyPressed(unsigned int keycode) const {
		if (keycode >= MAX_KEYS) {
			return false;
		}

		return m_keys[keycode];
	}

	bool Window::isMouseButtonPressed(unsigned int button) const {
		if (button >= MAX_BUTTONS) {
			return false;
		}

		return m_MouseButtons[button];
	}

	void Window::clear() const {
		//uncomment the line under me if depth testing should be enabled (only works in 3D)
		//glEnable(GL_DEPTH_TEST);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void Window::update() {
		GLenum error = glGetError();
		if (error != GL_NO_ERROR) {
			log(logWARNING) << "OPENGL Error: " << error;
		}

		if (scrollx != 0)
			scrollx = 0;

		if (scrolly != 0)
			scrolly = 0;

		glfwPollEvents();
		glfwSwapBuffers(m_window);
	}

	bool Window::closed() const {
		return glfwWindowShouldClose(m_window) == 1;
	}

	void window_resize(GLFWwindow *window, int width, int height) {
		glViewport(0, 0, width, height);
	}

	void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
		Window* win = (Window*)glfwGetWindowUserPointer(window);
		win->m_keys[key] = action != GLFW_RELEASE;
	}

	void mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {
		Window* win = (Window*)glfwGetWindowUserPointer(window);
		win->m_keys[button] = action != GLFW_RELEASE;
	}

	void cursor_position_callback(GLFWwindow* window, double xpos, double ypos) {
		Window* win = (Window*)glfwGetWindowUserPointer(window);
		win->mx = xpos;
		win->my = ypos;
	}

	void scroll_callback(GLFWwindow* window, double xoffset, double yoffset) {
		Window* win = (Window*)glfwGetWindowUserPointer(window);
		win->scrollx = xoffset;
		win->scrolly = yoffset;
	}
} }