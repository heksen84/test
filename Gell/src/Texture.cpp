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
	
	if( Util::GetFileExtension(filename) == "png" )	Msg::Info(L"loadPng");
	else	
		if( Util::GetFileExtension(filename) == "jpg" || Util::GetFileExtension(filename) == "jpeg")
			Msg::Info(L"loadJpeg");
			else
				Msg::Error(L"Texture %s error", filename.c_str());
}

Texture::~Texture()
{
	SAFE_DELETE(data);
}
