/*
 * Screen.cpp
 *
 *  Created on: 10 сент. 2017 г.
 *      Author: Соня
 */

#include "Screen.h"

template<> Screen* Singleton<Screen>::msSingleton = 0;
Screen* Screen::GetSingletonPtr(void) {
  return msSingleton;
}

Screen& Screen::GetSingleton(void) {
  assert( msSingleton );
  return ( *msSingleton );
}

void Screen::SetSize(int width, int heigth){
	_width  = width;
	_height = heigth;
}

ScreenSize Screen::GetSize(){
	ScreenSize sz;
	sz.width  = _width;
	sz.height = _height;
	return sz;
}
