/*
 * FreeType.cpp
 *
 *  Created on: 06 сент. 2017 г.
 *      Author: Илья
 */

#include "FreeType.h"

FT_Library 		ft;

void InitFreeType(void) {
	if (FT_Init_FreeType(&ft)) Msg::Error(L"FT_Init_FreeType");
}

