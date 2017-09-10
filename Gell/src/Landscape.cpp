/*
 * Landscape.cpp
 *
 *  Created on: 10 сент. 2017 г.
 *      Author: Соня
 */

#include "Landscape.h"

Landscape::Landscape(const String &filename) {
	//Msg::Error(L"%s", filename.c_str());
	mesh.LoadFromFile(filename);
}

Landscape::~Landscape() {
	// TODO Auto-generated destructor stub
}

