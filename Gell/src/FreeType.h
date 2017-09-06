/*
 * FreeType.h
 *
 *  Created on: 06 сент. 2017 г.
 *      Author: Соня
 */

#ifndef FREETYPE_H_
#define FREETYPE_H_
#include "Common.h"

extern FT_Library 	 ft;
extern FT_Face     	 face;
extern FT_GlyphSlot  slot;

extern void InitFreeType(void);
#endif /* FREETYPE_H_ */
