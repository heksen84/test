#ifndef IMGLIB_H_
#define IMGLIB_H_
#include "Common.h"

typedef struct
{
	uint width;
	uint height;
	uint pixeldepth;
	byte *pixels;	
} Img;

class ImgLib
{
	public:	
	static void LoadPng(const String &filename, GLFWimage *image);
};

#endif
