/*
 * Screen.h
 *
 *  Created on: 10 сент. 2017 г.
 *      Author: Соня
 */

#ifndef SCREEN_H_
#define SCREEN_H_

#include "Common.h"
#include "Singleton.h"

typedef struct {
	int width;
	int height;
} ScreenSize;

class Screen: public Singleton<Screen> {
public:
	static Screen* GetSingletonPtr(void);
	static Screen& GetSingleton(void);
	void SetSize(int width, int height);
	ScreenSize GetSize();
private:
	int _width;
	int _height;
};

#endif /* SCREEN_H_ */
