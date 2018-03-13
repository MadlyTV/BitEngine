#pragma once

#include <GL\glew.h>
#include <GLFW\glfw3.h>

#include "mesh.h"

#include <assimp\Importer.hpp>
#include <assimp\scene.h>
#include <assimp\postprocess.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <map>
#include <vector>

namespace MadlyTv {namespace graphics {

	class Model
	{
	public:
		/* Model data */
		std::vector<Texture> textures_loaded;
		std::vector<Mesh> meshes;
		maths::vec3 pos;
		/* Functions */
		Model(char *path, maths::vec3 Position);
		void Draw(Shader shader);
	private:
		/* Functions */
		void loadModel(std::string path);
		void processNode(aiNode *node, const aiScene *scene);
		Mesh processMesh(aiMesh *mesh, const aiScene *scene);
		std::vector<Texture> loadMaterialTextures(aiMaterial *mat, aiTextureType type, std::string typeName);
	};

	/*unsigned int TextureFromFile(const char *path, const std::string &directory, bool gamma) {
		std::string filename = std::string(path);
		filename = directory + '/' + filename;

		unsigned int textureID;
		glGenTextures(1, &textureID);

		int width, height, nrComponents;

		stbi_set_flip_vertically_on_load(true);

		unsigned char *data = stbi_load(filename.c_str(), &width, &height, &nrComponents, 0);
		if (data) {
			GLenum format;
			if (nrComponents == 1) {
				format = GL_RED;
			}
			else if (nrComponents == 3)
			{
				format = GL_RGB;
			}
			else if (nrComponents == 4)
			{
				format = GL_RGBA;
			}

			if (data) {
				glBindTexture(GL_TEXTURE_2D, textureID);
				glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
				glGenerateMipmap(GL_TEXTURE_2D);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			}
			else {
				std::cout << "Failed to load texture" << std::endl;
			}

			stbi_image_free(data);

			return textureID;
		}
	}*/
} }