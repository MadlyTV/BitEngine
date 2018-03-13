#include "texture.h"
#include "..\..\utils\fix.h"

namespace MadlyTv { namespace graphics {

	Textures::Textures(const char* Path)
		: m_Path(Path)
	{
		m_TID = load();
	}

	GLuint Textures::load() {
		GLuint result;
		glGenTextures(1, &result);
		glBindTexture(GL_TEXTURE_2D, result);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		stbi_set_flip_vertically_on_load(true);
		unsigned char* data = stbi_load(m_Path, &m_width, &m_height, &m_nrChannels, 0);

		if (data) {
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_width, m_width, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);
		}
		else {
			std::cout << "Failed to load texture" << std::endl;
		}
		stbi_image_free(data);
		glBindTexture(GL_TEXTURE_2D, 0);

		return result;
	}

	void Textures::bind() const {
		glBindTexture(GL_TEXTURE_2D, m_TID);
	}

	void Textures::unbind() const {
		glBindTexture(GL_TEXTURE_2D, 0);
	}

} }