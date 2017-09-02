/*
--------------------------
 msg.cpp
 Ilya Bobkov KZ 2017 (c)
--------------------------*/
#include "msg.h"
#include "common.h"

va_list	argptr;
char text[4096];
	
/* ошибка */
void msg::error(const char *msg, ... ) {	
	va_start( argptr, msg );
	vsprintf( text, msg, argptr );
	va_end( argptr);	
	MessageBox(0, text, "Error", MB_ICONERROR);
	exit(1);
}

/* предупреждение */
void msg::warning(const char *msg, ... ){
	va_start( argptr, msg );
	vsprintf( text, msg, argptr );
	va_end( argptr);	
	MessageBox(0, text, "Warning", MB_ICONWARNING);
}

/* -информация */
void msg::info(const char *msg, ... ){	
	va_start( argptr, msg );
	vsprintf( text, msg, argptr );
	va_end( argptr);	
	MessageBox(0, text, "Information", MB_ICONINFORMATION);
}
