/*
 * GLFW.cpp
 *
 *  Created on: 05 сент. 2017 г.
 *      Author: Соня
 */

#include "GLFW.h"

GLFWwindow*  window;
GLFWmonitor* monitor;
const GLFWvidmode* 	mode;

void InitGLFW(void)
{
		if (!glfwInit()) msg::error(L"glfwInit error");

		monitor = glfwGetPrimaryMonitor();
		if (!monitor) msg::error(L"glfwGetPrimaryMonitor problem");

		mode = glfwGetVideoMode(monitor);
		if (!mode) msg::error(L"glfwGetVideoMode problem");

		glfwWindowHint(GLFW_RED_BITS, 		mode->redBits);
		glfwWindowHint(GLFW_GREEN_BITS,		mode->greenBits);
		glfwWindowHint(GLFW_BLUE_BITS, 		mode->blueBits);
		glfwWindowHint(GLFW_REFRESH_RATE, 	mode->refreshRate);

		window = glfwCreateWindow(mode->width, mode->height, "[ Strategy ]", monitor, NULL);

		if (!window) msg::error(L"glfwCreateWindow: problem");

	    /* Make the window's context current */
	    glfwMakeContextCurrent(window);
}
