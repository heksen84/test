/*
 * GLTFMesh.cpp
 *
 *  Created on: 29 апр. 2018 г.
 *      Author: Соня
 */

#include "GLTFMesh.h"
#include "Common.h"
#include "gltf2/gltf2/glTF2.hpp"

GLTFMesh::GLTFMesh(const String &meshFileName) {
    gltf2::Asset mesh = gltf2::load(meshFileName.c_str());
    Msg::Info(L"%d", mesh.metadata.version.c_str());
}

GLTFMesh::~GLTFMesh() {
	// TODO Auto-generated destructor stub
}

