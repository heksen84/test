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
	std::vector< glm::vec4 > 	getVertices();
	std::vector< glm::vec3 > 	getNormals();
	std::vector<GLushort> 		getElements();
private:
	std::vector< glm::vec4 > vertices;
	std::vector< glm::vec3 > normals;
	std::vector<GLushort> elements;
};

#endif /* OBJ_H_ */
