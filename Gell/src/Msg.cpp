/*
--------------------------
 Msg.cpp
 Ilya Bobkov KZ 2017 (c)
--------------------------*/
#include "Msg.h"
#include "Common.h"

va_list	argptr;
char text[1024];


/* ошибка */
void Msg::Error(const char *msg, ... ) {
	va_start( argptr, msg );
	vsprintf( text, msg, argptr );
	va_end( argptr);	
	MessageBox(0, text, "ERROR", MB_ICONERROR);
	exit(1);
}

/* предупреждение */
void Msg::Warning(const char *msg, ...) {
	va_start( argptr, msg );
	vsprintf( text, msg, argptr );
	va_end( argptr);	
	MessageBox(0, text, "WARNING", MB_ICONWARNING);
}

/* инфобокс */
void Msg::Info(const char *msg, ...) {
	va_start( argptr, msg );
	vsprintf( text, msg, argptr );
	va_end( argptr);	
	MessageBox(0, text, "INFO", MB_ICONINFORMATION);
}
