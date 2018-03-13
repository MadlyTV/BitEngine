#pragma once

#include <GL\glew.h>
#include <GLFW\glfw3.h>

#include "..\shader.h"
#include "..\..\maths\maths.h"
#include "..\..\maths\maths_func.h"

#include <assimp\Importer.hpp>

#include <string>
#include <sstream>
#include <iostream>
#include <vector>

namespace MadlyTv { namespace graphics {

	struct Vertex
	{
		maths::vec3 Position;
		maths::vec3 Normal;
		maths::vec2 TexCoords;
	};

	struct Texture
	{
		unsigned int id;
		std::string type;
		aiString path;
	};

	class Mesh {
	public:
		/* Mesh Data */
		std::vector<Vertex> vertices;
		std::vector<unsigned int> indices;
		std::vector<Texture> textures;
		/* Functions */
		Mesh(std::vector<Vertex> Vertices, std::vector<unsigned int> Indices, std::vector<Texture> Textures);
		void Draw(Shader shader);
	private:
		/* Render data */
		unsigned int VAO, VBO, EBO;
		/* Functions */
		void setupMesh();
	};

} }