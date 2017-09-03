/*
--------------------------
 Msg.cpp
 Ilya Bobkov KZ 2017 (c)
--------------------------*/
#include "Msg.h"
#include "Common.h"

va_list	argptr;
wchar_t text[512];
	
/* ошибка */
void msg::error(const wchar_t *msg, ... ) {
	va_start( argptr, msg );
	vswprintf( text, msg, argptr );
	va_end( argptr);	
	MessageBoxW(0, text, L"ERROR", MB_ICONERROR);
	exit(1);
}

/* предупреждение */
void msg::warning(const wchar_t *msg, ... ){
	va_start( argptr, msg );
	vswprintf( text, msg, argptr );
	va_end( argptr);	
	MessageBoxW(0, text, L"WARNING", MB_ICONWARNING);
}

/* инфобокс */
void msg::info(const wchar_t *msg, ... ){
	va_start( argptr, msg );
	vswprintf( text, msg, argptr );
	va_end( argptr);	
	MessageBoxW(0, text, L"INFO", MB_ICONINFORMATION);
}
