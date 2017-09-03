#ifndef IMGLIB_H_
#define IMGLIB_H_
#include "Common.h"

typedef struct{
	uint width, height; 
	uint pixeldepth;
	byte *pixels;	
} Img;

class imglib
{
	public:	
	static void loadPng(const String &filename, GLFWimage *image);
};

#endif
