/*
 * Landscape.h
 *
 *  Created on: 10 сент. 2017 г.
 *      Author: Соня
 */

#ifndef LANDSCAPE_H_
#define LANDSCAPE_H_

#include "../GameObject.h"

class Landscape: public GameObject {
public:
	Landscape(const String &filename);
	virtual ~Landscape();
private:
	ObjMesh mesh;
};

#endif /* LANDSCAPE_H_ */
