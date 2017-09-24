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

   const char* v_VertexData   = VertexData.c_str();
   const char* f_FragmentData = FragmentData.c_str();

   // vertex
   uint vertex = glCreateShader(GL_VERTEX_SHADER);
   glShaderSource(vertex, 1, &v_VertexData, NULL);
   glCompileShader(vertex);

   // fragment
   uint fragment = glCreateShader(GL_FRAGMENT_SHADER);
   glShaderSource(fragment, 1, &f_FragmentData, NULL);
   glCompileShader(fragment);

   program = glCreateProgram();
   glAttachShader(program, vertex);
   glAttachShader(program, fragment);
   glBindFragDataLocation(program, 0, "outColor");
   glLinkProgram(program);
   glUseProgram(program);

   glDeleteShader(vertex);
   glDeleteShader(fragment);
}

Shader::~Shader() {
}

void Shader::Bind() {
}

