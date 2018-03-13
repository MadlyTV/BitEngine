#pragma once

#include <GL\glew.h>
#include <iostream>


namespace MadlyTv { namespace graphics {

	class Textures
	{
	private:
		const char* m_Path;
		GLuint m_TID;
		int m_width, m_height, m_nrChannels;
	public:
		Textures(const char* Path);

		GLuint load();

		void bind() const;
		void unbind() const;
	};
} }