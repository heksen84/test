/*
 * Input.h
 *
 *  Created on: 05 сент. 2017 г.
 *      Author: Соня
 */

#ifndef INPUT_H_
#define INPUT_H_
#include "Common.h"

/*
------------------------------------
обработка ввода
------------------------------------*/
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);

#endif /* INPUT_H_ */
