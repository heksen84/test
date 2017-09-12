/*
 * Renderer.h
 *
 *  Created on: 10 сент. 2017 г.
 *      Author: Соня
 */

#ifndef RENDERER_H_
#define RENDERER_H_

#include "Singleton.h"

class Renderer: public Singleton<Renderer> {
public:
	Renderer();
	virtual ~Renderer();
	static Renderer& getSingleton(void);
	static Renderer* getSingletonPtr(void);
	void DrawObject();
};

#endif /* RENDERER_H_ */
