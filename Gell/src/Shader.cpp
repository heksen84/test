/*
 * Shader.cpp
 *
 *  Created on: 21 сент. 2017 г.
 *      Author: Соня
 */

#include "Shader.h"
#include "Common.h"

Shader::Shader(String vertex_filename, String fragment_filename) {

   if (vertex_filename.size() == 0 || vertex_filename.size() == 0)
		Msg::Error("Shader: не указан один из шейдеров");

   String VertexData, FragmentData;

   v_file.open(vertex_filename);
   f_file.open(fragment_filename);

   StringStream vShaderStream, fShaderStream;

   vShaderStream << v_file.rdbuf();
   fShaderStream << f_file.rdbuf();

   v_file.close();
   f_file.close();

   VertexData 	= vShaderStream.str();
   FragmentData = fShaderStream.str();

   const char* v_VertexData = VertexData.c_str();
   const char* f_FragmentData = FragmentData.c_str();

   // vertex
   uint vertex = glCreateShader(GL_VERTEX_SHADER);
   glShaderSource(vertex, 1, &v_VertexData, NULL);
   glCompileShader(vertex);

   // fragment
   uint fragment = glCreateShader(GL_FRAGMENT_SHADER);
   glShaderSource(fragment, 1, &f_FragmentData, NULL);
   glCompileShader(fragment);


	/*
		// Create and compile the vertex shader
		GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertexShader, 1, &vertexSource, NULL);
		glCompileShader(vertexShader);

		// Create and compile the fragment shader
		GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
		glCompileShader(fragmentShader);

		// Link the vertex and fragment shader into a shader program
		GLuint shaderProgram = glCreateProgram();
		glAttachShader(shaderProgram, vertexShader);
		glAttachShader(shaderProgram, fragmentShader);
		glBindFragDataLocation(shaderProgram, 0, "outColor");
		glLinkProgram(shaderProgram);
		glUseProgram(shaderProgram);
		*/

   glDeleteShader(vertex);
   glDeleteShader(fragment);

}

Shader::~Shader() {
	// TODO Auto-generated destructor stub
}

void Shader::Bind(){

}

