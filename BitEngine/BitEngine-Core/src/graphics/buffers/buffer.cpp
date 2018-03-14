#include "buffer.h"

namespace bt { namespace graphics {

	Buffer::Buffer(GLfloat* data, GLsizei count, GLuint componentCount) {
		m_ComponentCount = componentCount;

		glGenBuffers(1, &m_BufferID);
		glBindBuffer(GL_ARRAY_BUFFER, m_BufferID);
		glBufferData(GL_ARRAY_BUFFER, count * sizeof(GLfloat), data, GL_STATIC_DRAW);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	Buffer::Buffer(std::vector<maths::vec3>* data, GLuint componentCount) {
		m_ComponentCount = componentCount;

		glGenBuffers(1, &m_BufferID);
		glBindBuffer(GL_ARRAY_BUFFER, m_BufferID);
		glBufferData(GL_ARRAY_BUFFER, data->size() * sizeof(maths::vec3), &data[0], GL_STATIC_DRAW);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	Buffer::Buffer(std::vector<maths::vec2>* data, GLuint componentCount) {
		m_ComponentCount = componentCount;

		glGenBuffers(1, &m_BufferID);
		glBindBuffer(GL_ARRAY_BUFFER, m_BufferID);
		glBufferData(GL_ARRAY_BUFFER, data->size() * sizeof(maths::vec2), &data[0], GL_STATIC_DRAW);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	Buffer::~Buffer() {
		glDeleteBuffers(1, &m_BufferID);
	}

	void Buffer::bind() const{
		glBindBuffer(GL_ARRAY_BUFFER, m_BufferID);
	}

	void Buffer::unbind() const{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}
} }