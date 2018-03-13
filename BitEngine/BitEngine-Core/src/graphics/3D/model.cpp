#include "model.h"

namespace MadlyTv { namespace graphics {

//	Model::Model(char *path, maths::vec3 Position) {
//		loadModel(path);
//		pos = Position;
//	}
//
//	void Model::Draw(Shader shader) {
//		for (unsigned int i = 0; i < meshes.size(); i++) {
//			meshes[i].Draw(shader);
//		}
//	}
//
//	void Model::loadModel(std::string path) {
//		Assimp::Importer import;
//
//		const aiScene* scene = import.ReadFile(path, aiProcess_Triangulate | aiProcess_FlipUVs);
//
//		if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) {
//			std::cout << "ERROR::ASSIMP::" << import.GetErrorString() << std::endl;
//			return;
//		}
//
//		processNode(scene->mRootNode, scene);
//	}
//
//	void Model::processNode(aiNode *node, const aiScene *scene) {
//		// Process all the node's meshes (if any)
//		for (unsigned int i = 0; i < node->mNumMeshes; i++) {
//			aiMesh *mesh = scene->mMeshes[node->mMeshes[i]];
//			meshes.push_back(processMesh(mesh, scene));
//		}
//		//then do the same for each of its children
//		for (unsigned int i = 0; i < node->mNumChildren; i++){
//			processNode(node->mChildren[i], scene);
//		}
//	}
//
//	Mesh Model::processMesh(aiMesh *mesh, const aiScene *scene) {
//		std::vector<Vertex> vertices;
//		std::vector<unsigned int> indices;
//		std::vector<Texture> textures;
//
//		for (unsigned int i = 0; i < mesh->mNumVertices; i++) {
//			Vertex vertex;
//			
//			maths::vec3 vector;
//			//position
//			vector.x = mesh->mVertices[i].x;
//			vector.y = mesh->mVertices[i].y;
//			vector.z = mesh->mVertices[i].z;
//
//			vertex.Position = vector;
//			//normalns
//			vector.x = mesh->mNormals[i].x;
//			vector.y = mesh->mNormals[i].y;
//			vector.z = mesh->mNormals[i].z;
//
//			vertex.Normal = vector;
//			//texture coords
//			if (mesh->mTextureCoords[0]) // does the mesh contain texture coordinates?
//			{
//				maths::vec2 vec;
//				vec.x = mesh->mTextureCoords[0][i].x;
//				vec.y = mesh->mTextureCoords[0][i].y;
//				vertex.TexCoords = vec;
//			}
//			else {
//				vertex.TexCoords = maths::vec2(0, 0);
//			}
//			// Tangent
//
//			///TODO: add tangent
//
//			// bitangent
//
//			///TODO: add bitangent
//
//			vertices.push_back(vertex);
//		}
//
//		for (unsigned int i = 0; i < mesh->mNumFaces;i++)
//		{
//			aiFace face = mesh->mFaces[i];
//
//			for (unsigned int j = 0; j < face.mNumIndices; j++) {
//				indices.push_back(face.mIndices[j]);
//			}
//		}
//
//		aiMaterial* material = scene->mMaterials[mesh->mMaterialIndex];
//		// we assume a convention for sampler names in the shaders. Each diffuse texture should be named
//		// as 'texture_diffuseN' where N is a sequential number ranging from 1 to MAX_SAMPLER_NUMBER. 
//		// Same applies to other texture as the following list summarizes:
//		// diffuse: texture_diffuseN
//		// specular: texture_specularN
//		// normal: texture_normalN
//
//		// 1. diffuse maps
//		std::vector<Texture> diffuseMaps = loadMaterialTextures(material, aiTextureType_DIFFUSE, "texture_diffuse");
//		textures.insert(textures.end(), diffuseMaps.begin(), diffuseMaps.end());
//		// 2. specular maps
//		std::vector<Texture> specularMaps = loadMaterialTextures(material, aiTextureType_SPECULAR, "texture_specular");
//		textures.insert(textures.end(), specularMaps.begin(), specularMaps.end());
//		// 3. normals maps
//		std::vector<Texture> normalMaps = loadMaterialTextures(material, aiTextureType_HEIGHT, "texture_normal");
//		textures.insert(textures.end(), normalMaps.begin(), normalMaps.end());
//		// 4. height maps
//		std::vector<Texture> heightMaps = loadMaterialTextures(material, aiTextureType_AMBIENT, "texture_height");
//		textures.insert(textures.end(), heightMaps.begin(), heightMaps.end());
//
//		return Mesh(vertices, indices, textures);
//	}
//
//	std::vector<Texture> Model::loadMaterialTextures(aiMaterial *mat, aiTextureType type, std::string typeName) {
//		std::vector<Texture> texturess;
//		for (unsigned int i = 0; i < mat->GetTextureCount(type); i++) {
//			aiString str;
//			mat->GetTexture(type, i, &str);
//			bool skip = false;
//			for (unsigned int j = 0; j < textures_loaded.size(); j++) {
//				if (std::strcmp(textures_loaded[j].path.C_Str(), str.C_Str()) == 0) {
//					texturess.push_back(textures_loaded[j]);
//					skip = true;
//					break;
//				}
//			}
//			if (!skip) {
//				Texture texture;
//#pragma region Texturefromfile
//
//				std::string filename = std::string(str.C_Str());
//				filename = filename;
//
//				unsigned int textureID;
//				glGenTextures(1, &textureID);
//
//				int width, height, nrComponents;
//
//				stbi_set_flip_vertically_on_load(true);
//
//				unsigned char *data = stbi_load(filename.c_str(), &width, &height, &nrComponents, 0);
//				if (data) {
//					GLenum format;
//					if (nrComponents == 1) {
//						format = GL_RED;
//					}
//					else if (nrComponents == 3)
//					{
//						format = GL_RGB;
//					}
//					else if (nrComponents == 4)
//					{
//						format = GL_RGBA;
//					}
//
//					if (data) {
//						glBindTexture(GL_TEXTURE_2D, textureID);
//						glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
//						glGenerateMipmap(GL_TEXTURE_2D);
//						glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//						glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//						glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
//						glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//					}
//					else {
//						std::cout << "Failed to load texture" << std::endl;
//					}
//
//					stbi_image_free(data);
//				}
//
//				texture.id = textureID;
//
//#pragma endregion
//				texture.type = typeName;
//				texture.path = str;
//				texturess.push_back(texture);
//				textures_loaded.push_back(texture);
//			}
//		}
//		return texturess;
//	}
} }