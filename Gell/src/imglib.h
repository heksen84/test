#ifndef _IMGLIB_H_
#define _IMGLIB_H_
#include "common.h"

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