/*
 * Obj.h
 *
 *  Created on: 01 сент. 2017 г.
 *      Author: Соня
 */

#ifndef OBJ_H_
#define OBJ_H_
#include "common.h"

class Obj {
public:
	Obj();
	virtual ~Obj();
	void loadFromFile(const String &filename);
};

#endif /* OBJ_H_ */
