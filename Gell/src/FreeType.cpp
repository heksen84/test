/*
 * FreeType.cpp
 *
 *  Created on: 06 сент. 2017 г.
 *      Author: Илья
 */

#include "FreeType.h"

FT_Library 		ft;
FT_Face     	face;
FT_GlyphSlot  	slot;

void InitFreeType(void) {
	if (FT_Init_FreeType(&ft)) Msg::Error("FT_Init_FreeType");
}

