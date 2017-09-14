/*
 * SkyBox.h
 *
 *  Created on: 10 сент. 2017 г.
 *      Author: Соня
 */

#ifndef SKYBOX_H_
#define SKYBOX_H_

#include "Common.h"

class SkyBox {
public:
	SkyBox(String frontImage, String backImage, String leftImage, String rightImage, String topImage, String bottomImage);
	virtual ~SkyBox();
};

#endif /* SKYBOX_H_ */
