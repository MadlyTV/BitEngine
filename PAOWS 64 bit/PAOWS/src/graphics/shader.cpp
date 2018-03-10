#include "shader.h"

namespace BitEngine { namespace graphics {
	
	Shader::Shader(const char* vertexPath, const char* fragmentPath) 
		: m_vertPath(vertexPath), m_fragPath(fragmentPath)
	{
		m_shaderID = load();
	}

	Shader::~Shader() {
		glDeleteProgram(m_shaderID);
	}

	GLuint Shader::load() {
		GLuint program = glCreateProgram();
		GLuint vertex = glCreateShader(GL_VERTEX_SHADER);
		GLuint fragment = glCreateShader(GL_FRAGMENT_SHADER);

		std::string vertSourcsString = FileUtils::read_file(m_vertPath);
		std::string fragSourcsString = FileUtils::read_file(m_fragPath);

		const char* vertSource = vertSourcsString.c_str();
		const char* fragSource = fragSourcsString.c_str();

		int vertexShader;
		glShaderSource(vertex,1,&vertSource,NULL);
		glCompileShader(vertex);

		int successvert;
		char infoLogvert[512];
		glGetShaderiv(vertex, GL_COMPILE_STATUS, &successvert);

		if (!successvert) {
			glGetShaderInfoLog(vertex, 512, NULL, infoLogvert);
			//Log this
			std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLogvert << std::endl;
			glDeleteShader(vertex);
			return 0;
		}

		int fragmentShader;
		glShaderSource(fragment, 1, &fragSource, NULL);
		glCompileShader(fragment);

		int successfrag;
		char infoLogfrag[512];
		glGetShaderiv(fragment, GL_COMPILE_STATUS, &successfrag);

		if (!successfrag) {
			glGetShaderInfoLog(fragment, 512, NULL, infoLogfrag);
			//Log this
			std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLogfrag << std::endl;
			glDeleteShader(fragment);
			return 0;
		}

		glAttachShader(program, vertex);
		glAttachShader(program, fragment);

		glLinkProgram(program);
		glValidateProgram(program);

		glDeleteShader(vertex);
		glDeleteShader(fragment);

		return program;
	}

	void Shader::setUniform1f(const GLchar* name, float value) {
		glUniform1f(getUniformLocation(name),value);
	}

	void Shader::setUniform1fv(const GLchar* name, int count, float* value) {
		glUniform1fv(getUniformLocation(name), count, value);
	}

	void Shader::setUniform1i(const GLchar* name, int value) {
		glUniform1i(getUniformLocation(name), value);
	}

	void Shader::setUniform1iv(const GLchar* name, int count, int* value) {
		glUniform1iv(getUniformLocation(name), count, value);
	}

	void Shader::setUniform2f(const GLchar* name, maths::vec2& vector) {
		glUniform2f(getUniformLocation(name), vector.x,vector.y);
	}

	void Shader::setUniform3f(const GLchar* name, maths::vec3& vector) {
		glUniform3f(getUniformLocation(name), vector.x, vector.y, vector.z);
	}

	void Shader::setUniform4f(const GLchar* name, maths::vec4& vector) {
		glUniform4f(getUniformLocation(name), vector.x, vector.y, vector.z, vector.w);
	}

	void Shader::setUniformMat4(const GLchar* name, const maths::mat4& matrix) {
		glUniformMatrix4fv(getUniformLocation(name), 1, GL_FLOAT, matrix.elements);
	}

	GLint Shader::getUniformLocation(const GLchar* name) {
		return glGetUniformLocation(m_shaderID, name);
	}

	void Shader::enable() const {
		//Log this
		glUseProgram(m_shaderID);
	}

	void Shader::disable() const {
		//Log this
		glUseProgram(0);
	}

} }