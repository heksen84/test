#ifndef _COMMON_H_
#define _COMMON_H_
#include <windows.h>

// C++ standart library
#include <string>
#include <map>

// C standart headers
#include <stdlib.h>
#include <stdio.h>

typedef std::string 	String;
typedef unsigned int  	uint;
typedef unsigned char 	byte;

#define SAFE_DELETE(a) if( (a) != nullptr ) delete (a); (a) = nullptr;
#define SAFE_DELETE_ARRAY(ptr) { if(ptr) { delete [](ptr); (ptr)=nullptr; } }

#define GLEW_STATIC
#include <glew/glew.h>
#include <glfw3/glfw3.h>
#include <libpng/png.h>
#include <freetype/ft2build.h>
#include FT_FREETYPE_H

#include "msg.h"  
#endif
