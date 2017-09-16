/*
 * Renderer.cpp
 *
 *  Created on: 10 сент. 2017 г.
 *      Author: Илья
 */

#include "Renderer.h"
#include "Common.h"

template<> Renderer* Singleton<Renderer>::msSingleton = 0;
Renderer* Renderer::GetSingletonPtr(void) {
  return msSingleton;
}
Renderer& Renderer::GetSingleton(void) {
  assert( msSingleton );
  return ( *msSingleton );
}
Renderer::Renderer() {
}

Renderer::~Renderer() {
}

void Renderer::DrawObject() {
}

