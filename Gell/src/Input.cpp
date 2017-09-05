/*
 * Input.cpp
 *
 *  Created on: 05 сент. 2017 г.
 *      Author: Соня
 */

#include "Input.h"

/*
------------------------------------
обработка ввода
------------------------------------*/
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods){
    switch(key) {
		case GLFW_KEY_ESCAPE:
			g_AppRun=false;
			break;
	}
}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods){
    if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS){
    	g_AppRun=false;
    }
}

void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{

}
