/*
--------------------------
 texture.cpp
 Ilya Bobkov KZ 2017 (c)
--------------------------*/
#include "texture.h"
#include "imglib.h"
#include "util.h"

Texture::Texture(const String &filename)
{
	width 		= 0;
	height 		= 0;
	pixeldepth 	= 0;
	data 		= nullptr;
	
	if( util::getFileExtension(filename) == "png" )	{	
		msg::info("loadPng");
	}
	else	
		if( util::getFileExtension(filename) == "jpg" || 
			util::getFileExtension(filename) == "jpeg") {	
			msg::info("loadJpeg");
	}
	else 
		msg::error("Texture: нет данных");
}

Texture::~Texture()
{
	SAFE_DELETE(data);
}
