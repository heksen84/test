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

	String vertexData, fragmentData;

	v_file.open(vertex_filename);
	f_file.open(fragment_filename);

	StringStream vShaderStream, fShaderStream;

	vShaderStream << v_file.rdbuf();
	fShaderStream << f_file.rdbuf();

	v_file.close();
	f_file.close();

   // const char* vertexData 	 	= vShaderStream.str();
   // const char* fragmentData 	= fShaderStream.str();

    uint vertex, fragment;

    // vertex
   /* vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &vertexData, NULL);
    glCompileShader(vertex);

    // fragment
    fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &fragmentData, NULL);
    glCompileShader(fragment);*/


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
}

Shader::~Shader() {
	// TODO Auto-generated destructor stub
}

void Shader::Bind(){

}

