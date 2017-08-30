#ifndef _TEXTURE_H_
#define _TEXTURE_H_
#include "common.h"

class Texture
{
	public:			
		uint width;
		uint height;
		uint pixeldepth;
		byte *data;
		
		Texture(const String &filename);
		~Texture();		
};

#endif