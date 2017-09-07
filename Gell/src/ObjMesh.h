/*
 * ObjMesh.h
 *
 *  Created on: 01 09. 2017 �.
 *      Author: Ilya
 */

#ifndef OBJMESH_H_
#define OBJMESH_H_
#include "Common.h"

class ObjMesh {

public:
	ObjMesh();
	virtual ~ObjMesh();
	void LoadFromFile(const String &filename);
	std::vector< glm::vec4 > 	&getVertices();
	std::vector< glm::vec3 > 	&getNormals();
	std::vector<GLushort> 		&getElements();
private:
	std::vector< glm::vec4 > vertices;
	std::vector< glm::vec3 > normals;
	std::vector<GLushort>	 elements;
};

#endif /* OBJ_H_ */
