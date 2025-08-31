#ifndef SHADER_CLASS_H
#define SHADER_CLASS_H

#include<glad/glad.h>
#include<string>
#include<fstream>
#include<sstream>
#include<iostream>
#include<cerrno>

std::string get_file_contents(const char* filename);

class Shader
{
	public:
		// The program ID
		GLuint ID;
		// Constructor that builds the shader program from 2 different shaders
		Shader(const char* vertexFile, const char* fragmentFile);

		// Activate the shader
		void Activate();
		// Delete the shader
		void Delete();
	private:
		void compileErrors(unsigned int shader, const char* type);
};


#endif