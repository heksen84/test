/*
 * GLFW.cpp
 *
 *  Created on: 05 сент. 2017 г.
 *      Author: Илья
 */

#include "GLFW.h"
#include "Screen.h"

GLFWwindow*  window;
GLFWmonitor* monitor;
GLFWcursor*  cursor_default;
GLFWcursor*  cursor_loading;

const GLFWvidmode* 	mode;

void SetSystemCursors() {

	int width, height;
	GLFWimage image_default, image_loading;

	byte* pixels_cursor_default = SOIL_load_image("D:/projects/steppe/data/icons/topor.png", &width, &height, 0, SOIL_LOAD_RGBA);

	image_default.width  = width;
	image_default.height = height;
	image_default.pixels = pixels_cursor_default;

	byte* pixels_cursor_loading = SOIL_load_image("D:/projects/steppe/data/icons/shield_loading.png", &width, &height, 0, SOIL_LOAD_RGBA);

	image_loading.width  = width;
	image_loading.height = height;
	image_loading.pixels = pixels_cursor_loading;

	cursor_default = glfwCreateCursor(&image_default, 0, 0);
	cursor_loading = glfwCreateCursor(&image_loading, 0, 0);

	glfwSetCursor(window, cursor_default);
}
/*
------------------------------------
обработка ввода
------------------------------------*/
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    switch(key) {
		case GLFW_KEY_ESCAPE:

			/* switch(Screen->getActiveElement())
			 * {
			 * 	case "menu": ... break;
			 * 	case "main_screen": ... break;
			 * }
			*/
			glfwDestroyCursor(cursor_default);
			glfwDestroyCursor(cursor_loading);

			g_AppRun=false;

			break;
	}
}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {

    if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS){
    	glfwSetCursor(window, cursor_loading);
    }

    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS){
       	glfwSetCursor(window, cursor_default);
    }
}

void mouse_callback(GLFWwindow* window, double xpos, double ypos) {

}

/*
* -----------------------------
* InitGLFW
* -----------------------------
*/
void InitGLFW(void) {

	if (!glfwInit())
		Msg::Error(L"glfwInit error");

	monitor = glfwGetPrimaryMonitor();

	if (!monitor)
		Msg::Error(L"glfwGetPrimaryMonitor problem");

	mode = glfwGetVideoMode(monitor);

	if (!mode)
		Msg::Error(L"glfwGetVideoMode problem");

	glfwWindowHint(GLFW_RED_BITS, 		mode->redBits);
	glfwWindowHint(GLFW_GREEN_BITS,		mode->greenBits);
	glfwWindowHint(GLFW_BLUE_BITS, 		mode->blueBits);
	glfwWindowHint(GLFW_REFRESH_RATE, 	mode->refreshRate);

	window = glfwCreateWindow(mode->width, mode->height, "[ Strategy ]", monitor, NULL);

	if (!window)
		Msg::Error(L"glfwCreateWindow: problem");

	/* Make the window's context current */
    glfwMakeContextCurrent(window);

	/* назначить ввод */
	glfwSetKeyCallback(window, key_callback);
	glfwSetMouseButtonCallback(window, mouse_button_callback);
	glfwSetCursorPosCallback(window, mouse_callback);

	SetSystemCursors();
}
