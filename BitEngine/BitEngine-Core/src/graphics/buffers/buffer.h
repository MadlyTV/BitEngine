#pragma once

#include "../../maths/maths.h"

#include <vector>

#include <GL\glew.h>

namespace bt { namespace graphics {
	
	class Buffer
	{
	private:
		GLuint m_BufferID;
		GLuint m_ComponentCount;
	public:
		Buffer(GLfloat* data, GLsizei count, GLuint componentCount);
		Buffer(std::vector<maths::vec3>* data, GLuint componentCount);
		Buffer(std::vector<maths::vec2>* data, GLuint componentCount);
		~Buffer();

		void bind() const;
		void unbind() const;

		inline GLuint getComponentCount() const { return m_ComponentCount; }
	};

} }