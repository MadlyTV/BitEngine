#pragma once

#include "../maths/maths.h"
#include <string>
#include <fstream>
#include <vector>

namespace bt {
	class FileUtils
	{
	public:
		static std::string read_file(const char* filepath) {
			FILE* file = fopen(filepath, "rt");
			if (file == NULL) {
				std::cout << "Impossible to open the file !" << std::endl;
				return false;
			}
			fseek(file, 0, SEEK_END);
			unsigned long lenght = ftell(file);
			char* data = new char[lenght + 1];
			memset(data, 0, lenght + 1);
			fseek(file, 0, SEEK_SET);
			fread(data, 1, lenght, file);
			fclose(file);

			std::string result(data);
			delete[] data;
			return result;
		}

		static bool loadOBJ(const char* path, std::vector<maths::vec3>& out_vertices, std::vector<maths::vec2>& out_uvs, std::vector<maths::vec3>& out_normals) {
			std::vector<unsigned int> vertexIndices, uvIndices, normalIndices;
			std::vector<maths::vec3> temp_vertices;
			std::vector<maths::vec2> temp_uvs;
			std::vector<maths::vec3> temp_normals;

			FILE* file = fopen(path, "r");
			if (file == NULL) {
				std::cout << "Impossible to open the file !" << std::endl;
				return false;
			}

			while (1)
			{
				char lineHeader[128];
				//read the first word of the line
				int res = fscanf(file, "%s", lineHeader);
				if (res == EOF) {
					break; //EOF = end of file. quit loop
				}

				//else : barse lineheader

				if (strcmp(lineHeader, "v") == 0) {
					maths::vec3 vertex;
					fscanf(file, "%F %F %F\n", &vertex.x, &vertex.y, &vertex.z);
					temp_vertices.push_back(vertex);
				}
				else if (strcmp(lineHeader, "vt") == 0) {
					maths::vec2 uv;
					fscanf(file, "%F %F\n", &uv.x, &uv.y);
					temp_uvs.push_back(uv);
				}
				else if (strcmp(lineHeader, "vn") == 0) {
					maths::vec3 normal;
					fscanf(file, "%F %F %F\n", &normal.x, &normal.y, &normal.z);
					temp_normals.push_back(normal);
				}
				else if (strcmp(lineHeader, "f") == 0) {
					std::string vertex1, vertex2, vertex3;
					unsigned int vertexIndex[3], uvIndex[3], normalIndex[3];
					int matches = fscanf(file, "%d/%d/%d %d/%d/%d %d/%d/%d\n", &vertexIndex[0], &uvIndex[0], &normalIndex[0], &vertexIndex[1], &uvIndex[1], &normalIndex[1], &vertexIndex[2], &uvIndex[2], &normalIndex[2]);
					if (matches != 9) {
						std::cout << "Faile can't be read by the simple parser : ( Try exporting with other options )" << std::endl;
						return false;
					}
					vertexIndices.push_back(vertexIndex[0]);
					vertexIndices.push_back(vertexIndex[1]);
					vertexIndices.push_back(vertexIndex[2]);
					uvIndices.push_back(uvIndex[0]);
					uvIndices.push_back(uvIndex[1]);
					uvIndices.push_back(uvIndex[2]);
					normalIndices.push_back(normalIndex[0]);
					normalIndices.push_back(normalIndex[1]);
					normalIndices.push_back(normalIndex[2]);
				}
			}

			for (unsigned int i = 0; i < vertexIndices.size(); i++) {
				unsigned int vertexIndex = vertexIndices[i];

				maths::vec3 vertex = temp_vertices[vertexIndex - 1];

				out_vertices.push_back(vertex);
			}
			for (unsigned int i = 0; i < uvIndices.size(); i++) {
				unsigned int uvIndex = uvIndices[i];

				maths::vec2 uv = temp_uvs[uvIndex - 1];

				out_uvs.push_back(uv);
			}
			for (unsigned int i = 0; i < normalIndices.size(); i++) {
				unsigned int normalIndex = normalIndices[i];

				maths::vec3 normal = temp_normals[normalIndex - 1];

				out_normals.push_back(normal);
			}

			return true;
		}
	};
}