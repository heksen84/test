/*
--------------------------
 util.cpp
 Ilya Bobkov KZ 2017 (c)
--------------------------*/
#include "Util.h"

String Util::GetFileExtension(const String &filename)
{	
	 if(filename.find_last_of(".") != std::string::npos)
        return filename.substr(filename.find_last_of(".")+1);
    return "";
}
