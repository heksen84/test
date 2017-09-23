/*
 * Camera.cpp
 *
 *  Created on: 04 сент. 2017 г.
 *      Author: Илья
 */

#include "Camera.h"

Camera::Camera() {

	pos 		= glm::vec3(0.0f, 0.0f, 3.0f);	// положение
	target 		= glm::vec3(0.0f, 0.0f, 0.0f);  // цель
	direction 	= glm::normalize(pos - target); // нормализация
}

Camera::~Camera() {
	// TODO Auto-generated destructor stub
}

