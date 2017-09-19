/*
 * Glew.cpp
 *
 *  Created on: 06 сент. 2017 г.
 *      Author: Соня
 */

#include "Glew.h"

void InitGLEW() {

	glewExperimental = GL_TRUE;

	if (glewInit() != GLEW_OK)
		Msg::Error("GlewInit error");

	if (!GLEW_VERSION_3_0)
		Msg::Error("OpenGL 3.0 not avaiable!\nUpgrade your hardware or check drivers.");
}
