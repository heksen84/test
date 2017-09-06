/*
 * Glew.cpp
 *
 *  Created on: 06 сент. 2017 г.
 *      Author: Соня
 */

#include "Glew.h"

void InitGlew(void) {
	if (glewInit() != GLEW_OK) msg::error(L"glewInit");
}
