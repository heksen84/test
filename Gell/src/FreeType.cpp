/*
 * FreeType.cpp
 *
 *  Created on: 06 сент. 2017 г.
 *      Author: Соня
 */

#include "FreeType.h"

FT_Library 		ft;
FT_Face     	face;
FT_GlyphSlot  	slot;

int result = 0;

void InitFreeType(void)
{

	// --- Инициализация FreeType
	if (FT_Init_FreeType(&ft))
		msg::error(L"FT_Init_FreeType");

	// --- Инициализация FreeType
	result = FT_New_Face( ft, "D:/projects/Steppe/data/arial.ttf", 0, &face );

	if ( result == FT_Err_Unknown_File_Format )
		msg::error(L"FreeType: file format error");
	else
		if ( result )
			msg::error(L"FreeType: font not found");

	FT_Set_Pixel_Sizes(face, 0, 48);
}

