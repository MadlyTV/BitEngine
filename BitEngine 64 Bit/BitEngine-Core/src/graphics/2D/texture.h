#pragma once

#include <FreeImage.h>
#include <string>
#include <GL\glew.h>
#include "../../utils/imageload.h"

//FreeType includes
#include <iostream>
#include <ft2build.h>
#include <algorithm>
#include <cstdio>
#include FT_FREETYPE_H

namespace BitEngine { namespace graphics {

	class Texture
	{
	private:
		std::string m_FileName;
		GLuint m_TID;
		GLsizei m_Width, m_Height;
		const char* m_Text;
	public:
		Texture(const std::string& filename);
		Texture(const char* text, const char* fontFile);
		~Texture();
		void bind() const;
		void unbind() const;
		
		inline const unsigned int getID() const { return m_TID; }
		inline const unsigned int getWidth() const { return m_Width; }
		inline const unsigned int getHeight() const { return m_Height; }


	private:
		GLuint load();
	};
} }