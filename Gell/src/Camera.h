/*
 * Camera.h
 *
 *  Created on: 04 сент. 2017 г.
 *      Author: Илья
 */

#ifndef CAMERA_H_
#define CAMERA_H_

#include "Common.h"

class Camera {
public:
	Camera();
	virtual ~Camera();
private:
	glm::vec3 pos;			// позиция камера
	glm::vec3 target;		// цель камеры
	glm::vec3 direction;	// направление камеры  cameraDirection = glm::normalize(cameraPos - cameraTarget);

};

#endif /* CAMERA_H_ */
