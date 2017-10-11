/*
 * MainScreen.h
 *
 *  Created on: 11 окт. 2017 г.
 *      Author: Соня
 */

#ifndef MAINSCREEN_H_
#define MAINSCREEN_H_
#include "..//Common.h"

class MainScreen {
public:
	MainScreen();
	virtual ~MainScreen();
	void Render();
private:
	GLuint vbo, vao, ebo;
};

#endif /* MAINSCREEN_H_ */
