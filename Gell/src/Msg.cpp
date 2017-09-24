/*
--------------------------
 Msg.cpp
 Ilya Bobkov KZ 2017 (c)
--------------------------*/
#include "Msg.h"
#include "Common.h"

va_list	argptr;
wchar_t text[1024];

/* ошибка */
void Msg::Error(const wchar_t *msg, ... ) {
	va_start( argptr, msg );
	vswprintf( text, msg, argptr );
	va_end( argptr);	
	MessageBoxW(0, text, L"error", MB_ICONERROR);
	exit(1);
}

/* предупреждение */
void Msg::Warning(const wchar_t *msg, ...) {
	va_start( argptr, msg );
	vswprintf( text, msg, argptr );
	va_end( argptr);
	MessageBoxW(0, text, L"warning", MB_ICONWARNING);
}

/* инфобокс */
void Msg::Info(const wchar_t *msg, ...) {
	va_start( argptr, msg );
	vswprintf( text, msg, argptr );
	va_end( argptr);	
	MessageBoxW(0, text, L"info", MB_ICONINFORMATION);
}
