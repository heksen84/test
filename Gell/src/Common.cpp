#include "Common.h"
#include "Glfw.h"

FT_Library 	ft 	= nullptr;
sqlite3	*db = nullptr;


static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
   return 0;
}

void COM_InitLibs(void) {

	InitGLFW();

	if (glewInit() != GLEW_OK)
			Msg::Error(L"GlewInit error");

	if (!GLEW_VERSION_3_0)
			Msg::Error(L"OpenGL 3.0 not avaiable!\nUpgrade your hardware or check drivers.");

	if (FT_Init_FreeType(&ft))
		Msg::Error(L"FT_Init_FreeType");
}
