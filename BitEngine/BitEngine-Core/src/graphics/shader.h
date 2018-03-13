#pragma once

#include <GL\glew.h>
#include <iostream>
#include "../utils/FileUtils.h"
#include "../maths/maths.h"

namespace BitEngine { namespace graphics {

	class Shader
	{
	private:
		GLuint m_shaderID;
		const char *m_vertPath, *m_fragPath;
	public:
		Shader();
		Shader(const char* vertexPath, const char* fragmentPath);
		~Shader();

		void setUniform1f(const GLchar* name, float value);
		void setUniform1fv(const GLchar* name, int count ,float* value);
		void setUniform1i(const GLchar* name, int value);
		void setUniform1iv(const GLchar* name, int count ,int* value);
		void setUniform2f(const GLchar* name, maths::vec2& vector);
		void setUniform3f(const GLchar* name, maths::vec3& vector);
		void setUniform4f(const GLchar* name, maths::vec4& vector);
		void setUniformMat4(const GLchar* name, const maths::mat4& matrix);

		void enable()const;
		void disable()const;
	private:
		GLint getUniformLocation(const GLchar* name);
		GLuint load();
	};
} }