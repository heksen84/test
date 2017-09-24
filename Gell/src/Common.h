#ifndef COMMON_H_
#define COMMON_H_

#define DATA_PATH "D:/projects/Gell/Gell/Release/data"

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
#include <stdarg.h>
#include <wchar.h>
#include <tchar.h>
#include <assert.h>

typedef std::stringstream 	StringStream;
typedef std::string 		String;			// анси строка		(char*)
typedef std::wstring 		Unicode; 		// уникод строка	(wchar_t*)
typedef std::ifstream 		file;
typedef unsigned int  		uint;
typedef unsigned long  		ulong;
typedef unsigned char 		byte;

#define SAFE_DELETE(a) if( (a) != nullptr ) delete (a); (a) = nullptr;
#define SAFE_DELETE_ARRAY(ptr) { if(ptr) { delete [](ptr); (ptr)=nullptr; } }

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#define GLEW_STATIC
#include <glew/glew.h>
#include <glfw3/glfw3.h>
#include <libpng/png.h>
#include <soil/soil.h>
#include <freetype/ft2build.h>
#include FT_FREETYPE_H

#include "Msg.h"

// глобально
extern bool g_AppRun;

#endif
