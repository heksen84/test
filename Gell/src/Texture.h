#ifndef TEXTURE_H_
#define TEXTURE_H_
#include "Common.h"

class Texture
{
	public:			
		uint width;
		uint height;
		uint pixeldepth;
		byte *data;
		
		Texture(const String &filename);
		virtual ~Texture();
};

#endif
