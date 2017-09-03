#ifndef COMMON_H_
#define COMMON_H_
#define GAMEPATH "D:/projects/Gell/Gell/Release/data"

// windows
#include <windows.h>

// C++ standart library
#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

// C standart headers
#include <stdlib.h>
#include <stdio.h>
#include <wchar.h>

typedef std::string 	String;
typedef unsigned int  	uint;
typedef unsigned char 	byte;

#define SAFE_DELETE(a) if( (a) != nullptr ) delete (a); (a) = nullptr;
#define SAFE_DELETE_ARRAY(ptr) { if(ptr) { delete [](ptr); (ptr)=nullptr; } }


#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


#define GLEW_STATIC
#include <glew/glew.h>
#include <glfw3/glfw3.h>
#include <libpng/png.h>
#include <freetype/ft2build.h>
#include FT_FREETYPE_H

#include "Msg.h"
#endif
