#include "Common.h"
#include "Glfw.h"

FT_Library 	ft 	= nullptr;
sqlite3	*db = nullptr;


static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
  /* int i;
   for(i = 0; i<argc; i++) {
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");*/
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

		/*char *zErrMsg;
		const char *sql = "CREATE TABLE COMPANY('ID INT PRIMARY KEY NOT NULL, NAME TEXT NOT NULL, AGE INT NOT NULL, ADDRESS CHAR(50), SALARY REAL')";
		const char *db_name = "local.db";

		sqlite3_open(db_name, &db);
	    sqlite3_exec(db, sql, callback, 0, &zErrMsg);
	    sqlite3_close(db);*/
}
