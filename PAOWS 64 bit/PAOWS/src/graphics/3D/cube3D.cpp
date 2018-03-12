#pragma once

#include "cube3D.h"

namespace MadlyTv {
	namespace graphics {

		Cube3D::Cube3D(maths::vec3 pos, maths::vec3 size, maths::vec4 color, const char* TextureFilePath, Shader& shader)
			: m_Position(pos), m_Size(size), m_Color(color), m_Shader(shader)
		{
			m_VertexArray = new VertexArray();

#pragma region Vaiables for cube

			GLfloat vertices[] = {
				0,			0,			0,
				0,			m_Size.y,	0,
				m_Size.x,	m_Size.y,	0,
				m_Size.x,	0,			0,

				0,			0,			m_Size.z,
				0,			m_Size.y,	m_Size.z,
				m_Size.x,	m_Size.y,	m_Size.z,
				m_Size.x,	0,			m_Size.z,

				0,			0,			0,
				0,			m_Size.y,	0,
				0,			0,			m_Size.z,
				0,			m_Size.y,	m_Size.z,

				m_Size.x,	0,			0,
				m_Size.x,	m_Size.y,	0,
				m_Size.x,	0,			m_Size.z,
				m_Size.x,	m_Size.y,	m_Size.z,

				0,			m_Size.y,	0,
				m_Size.x,	m_Size.y,	0,
				m_Size.x,	m_Size.y,	m_Size.z,
				0,			m_Size.y,	m_Size.z,

				0,			0,			0,
				m_Size.x,	0,			0,
				m_Size.x,	0,			m_Size.z,
				0,			0,			m_Size.z,
			};

			GLfloat colors[] = {
				m_Color.x,m_Color.y,m_Color.z,m_Color.w,
				m_Color.x,m_Color.y,m_Color.z,m_Color.w,
				m_Color.x,m_Color.y,m_Color.z,m_Color.w,
				m_Color.x,m_Color.y,m_Color.z,m_Color.w,

				m_Color.x,m_Color.y,m_Color.z,m_Color.w,
				m_Color.x,m_Color.y,m_Color.z,m_Color.w,
				m_Color.x,m_Color.y,m_Color.z,m_Color.w,
				m_Color.x,m_Color.y,m_Color.z,m_Color.w,

				m_Color.x,m_Color.y,m_Color.z,m_Color.w,
				m_Color.x,m_Color.y,m_Color.z,m_Color.w,
				m_Color.x,m_Color.y,m_Color.z,m_Color.w,
				m_Color.x,m_Color.y,m_Color.z,m_Color.w,

				m_Color.x,m_Color.y,m_Color.z,m_Color.w,
				m_Color.x,m_Color.y,m_Color.z,m_Color.w,
				m_Color.x,m_Color.y,m_Color.z,m_Color.w,
				m_Color.x,m_Color.y,m_Color.z,m_Color.w,

				m_Color.x,m_Color.y,m_Color.z,m_Color.w,
				m_Color.x,m_Color.y,m_Color.z,m_Color.w,
				m_Color.x,m_Color.y,m_Color.z,m_Color.w,
				m_Color.x,m_Color.y,m_Color.z,m_Color.w,

				m_Color.x,m_Color.y,m_Color.z,m_Color.w,
				m_Color.x,m_Color.y,m_Color.z,m_Color.w,
				m_Color.x,m_Color.y,m_Color.z,m_Color.w,
				m_Color.x,m_Color.y,m_Color.z,m_Color.w
			};

			GLfloat textCords[] = {
				0,0,
				0,1,
				1,1,
				1,0,
				0,0,
				0,1,
				1,1,
				1,0,
				0,0,
				0,1,
				1,1,
				1,0,
				0,0,
				0,1,
				1,1,
				1,0,
				0,0,
				0,1,
				1,1,
				1,0,
				0,0,
				0,1,
				1,1,
				1,0
			};

#pragma endregion

			m_VertexArray->addBuffer(new Buffer(vertices, 24 * 3, 3), 0);
			m_VertexArray->addBuffer(new Buffer(colors, 24 * 4, 4), 1);
			m_VertexArray->addBuffer(new Buffer(textCords, 34 * 2, 2), 2);

			GLushort indeces[] = {
				0,1,3,
				3,1,2,
				4,5,7,
				7,5,6,
				8,9,11,
				11,9,10,
				12,13,15,
				15,13,14,
				16,17,19,
				19,17,18,
				20,21,23,
				23,21,22
			};
			m_IndexBuffer = new IndexBuffer(indeces, 12 * 3);

			//m_texture = new Textures(TextureFilePath);
		}

		Cube3D::~Cube3D() {
			delete m_VertexArray;
			delete m_IndexBuffer;
		}

	}
}

