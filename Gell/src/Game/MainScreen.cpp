/*
 * MainScreen.cpp
 *
 *  Created on: 11 окт. 2017 г.
 *      Author: Соня
 */

#include "MainScreen.h"

MainScreen::MainScreen() {

	// x,y,r,g,b,u,w
	GLfloat background_vertices[] = {
	   -0.25f,  0.4f, 	1.0f, 0.0f, 0.0f, 0.0f, 0.0f, // Top-left
		0.25f,  0.4f, 	0.0f, 1.0f, 0.0f, 1.0f, 0.0f, // Top-right
		0.25f, -0.4f, 	0.0f, 0.0f, 1.0f, 1.0f, 1.0f, // Bottom-right
	   -0.25f, -0.4f, 	1.0f, 1.0f, 0.0f, 0.0f, 1.0f  // Bottom-left
	};

    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    glGenBuffers(1, &vbo);
    glGenBuffers(1, &ebo);

    glBindBuffer(GL_ARRAY_BUFFER, vbo);
   	glBufferData(GL_ARRAY_BUFFER, sizeof(background_vertices), background_vertices, GL_STATIC_DRAW);
   	glGenBuffers(1, &ebo);

   	GLuint elements[] = { 0, 1, 2, 2, 3, 0 };

   	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
   	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(elements), elements, GL_STATIC_DRAW);
}

MainScreen::~MainScreen()
{
	glDeleteBuffers(1, &ebo);
	glDeleteBuffers(1, &vbo);
	glDeleteVertexArrays(1, &vao);
}

void MainScreen::Render()
{
}

