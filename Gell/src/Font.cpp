/*
--------------------------
 font.cpp
 Ilya Bobkov KZ 2017 (c)
--------------------------*/
#include "Font.h"

int result=0;

Font::Font(const String &fontName)
{
	result = FT_New_Face( ft, "D:/projects/Steppe/data/Fonts/Diablo/diablo-font-1.ttf", 0, &face );

	if ( result == FT_Err_Unknown_File_Format ) Msg::Error("FreeType: file format error");
	else  if ( result ) Msg::Error("FreeType: font not found");

	FT_Set_Pixel_Sizes(face, 0, 48);
}

Font::~Font()
{
}
