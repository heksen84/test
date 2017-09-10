/*
 * Glew.cpp
 *
 *  Created on: 06 сент. 2017 г.
 *      Author: Соня
 */

#include "Glew.h"

void InitGLEW() {
	if (glewInit() != GLEW_OK) Msg::Error("GlewInit error");
	if (!GLEW_VERSION_3_3)
		Msg::Error("OpenGL 3.3 not avaiable!\nUpgrade your hardware or check drivers.");
}
