/*
 * Obj.cpp
 *
 *  Created on: 01 сент. 2017 г.
 *      Author: Соня
 */

#include "Obj.h"

Obj::Obj() {
}

Obj::~Obj() {
}

void Obj::loadFromFile(const String &filename) {

	msg::info("%s loaded!", filename.c_str());
}

