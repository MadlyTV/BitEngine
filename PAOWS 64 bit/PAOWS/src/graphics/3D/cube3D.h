#pragma once

#include "..\buffers\buffer.h"
#include "..\buffers\indexbuffer.h"
#include "..\buffers\vertexarray.h"
#include "..\shader.h"
//#include "texture.h"

#include "..\..\maths\maths.h"

namespace MadlyTv { namespace graphics {
	
	class Cube3D
	{
	protected:
		maths::vec3 m_Position;
		maths::vec3 m_Size;
		maths::vec4 m_Color;

		VertexArray* m_VertexArray;
		IndexBuffer* m_IndexBuffer;

		Shader& m_Shader;

		//Textures* m_texture;
	public:

		Cube3D(maths::vec3 pos, maths::vec3 size, maths::vec4 color, const char* TextureFilePath ,Shader& shader);
		virtual ~Cube3D();

		inline const VertexArray* getVAO() const { return m_VertexArray; }
		inline Shader& getShader() const { return m_Shader; }
	//	inline Textures* getTexture() const { return m_texture; }
		inline const IndexBuffer* getIBO() const { return m_IndexBuffer; }

		inline const maths::vec3& GetPosition() const { return m_Position; }
		inline const maths::vec3& GetSize() const { return m_Size; }
		inline const maths::vec4& GetColor() const { return m_Color; }
	};
} }