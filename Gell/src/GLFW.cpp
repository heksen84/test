/*
 * GLFW.cpp
 *
 *  Created on: 05 сент. 2017 г.
 *      Author: Илья
 */

#include "GLFW.h"
#include "Input.h"

GLFWwindow*  window;
GLFWmonitor* monitor;
const GLFWvidmode* 	mode;

void InitGLFW(void)
{
		if (!glfwInit())
			Msg::Error("glfwInit error");

		monitor = glfwGetPrimaryMonitor();
		if (!monitor)
			Msg::Error("glfwGetPrimaryMonitor problem");

		mode = glfwGetVideoMode(monitor);
		if (!mode)
			Msg::Error("glfwGetVideoMode problem");

		glfwWindowHint(GLFW_RED_BITS, 		mode->redBits);
		glfwWindowHint(GLFW_GREEN_BITS,		mode->greenBits);
		glfwWindowHint(GLFW_BLUE_BITS, 		mode->blueBits);
		glfwWindowHint(GLFW_REFRESH_RATE, 	mode->refreshRate);

		window = glfwCreateWindow(mode->width, mode->height, "[ Strategy ]", monitor, NULL);

		if (!window) Msg::Error("glfwCreateWindow: problem");

	    /* Make the window's context current */
	    glfwMakeContextCurrent(window);

		/* назначить ввод */
		glfwSetKeyCallback(window, key_callback);
		glfwSetMouseButtonCallback(window, mouse_button_callback);
		glfwSetCursorPosCallback(window, mouse_callback);
}
