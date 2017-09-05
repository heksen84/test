/*
 * GLFW.cpp
 *
 *  Created on: 05 сент. 2017 г.
 *      Author: Соня
 */

#include "GLFW.h"
#include "Common.h"

GLFWwindow* window;
GLFWmonitor* monitor;
const GLFWvidmode* mode;

GLFW::GLFW() {
	// TODO Auto-generated constructor stub

}

GLFW::~GLFW() {
	// TODO Auto-generated destructor stub
}

void GLFW::init()
{
	msg::info(L"init!");
}
