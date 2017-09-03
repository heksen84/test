/*
--------------------------
 Texture.cpp
 Ilya Bobkov KZ 2017 (c)
--------------------------*/
#include "Texture.h"
#include "Imglib.h"
#include "Util.h"

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
		msg::error("Texture %s error", filename.c_str());
}

Texture::~Texture()
{
	SAFE_DELETE(data);
}
