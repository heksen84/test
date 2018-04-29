/*
 * GLTFMesh.h
 *
 *  Created on: 29 апр. 2018 г.
 *      Author: Соня
 */

#ifndef GLTFMESH_H_
#define GLTFMESH_H_

#include "Common.h"

class GLTFMesh {
public:
	GLTFMesh(const String &meshFileName);
	virtual ~GLTFMesh();
};

#endif /* GLTFMESH_H_ */
