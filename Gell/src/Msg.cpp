/*
--------------------------
 Msg.cpp
 Ilya Bobkov KZ 2017 (c)
--------------------------*/
#include "Msg.h"
#include "Common.h"

va_list	argptr;
wchar_t buf_u[1024];
char buf_a[1024];


// ***** UNICODE *****
/* ошибка */
void Msg::Error(const wchar_t *msg, ... ) {
	va_start( argptr, msg );
	vswprintf( buf_u, msg, argptr );
	va_end( argptr);	
	MessageBoxW(0, buf_u, L"ERROR", MB_ICONERROR);
	exit(1);
}

/* предупреждение */
void Msg::Warning(const wchar_t *msg, ...) {
	va_start( argptr, msg );
	vswprintf( buf_u, msg, argptr );
	va_end( argptr);
	MessageBoxW(0, buf_u, L"WARNING", MB_ICONWARNING);
}

/* инфобокс */
void Msg::Info(const wchar_t *msg, ...) {
	va_start( argptr, msg );
	vswprintf( buf_u, msg, argptr );
	va_end( argptr);	
	MessageBoxW(0, buf_u, L"INFO", MB_ICONINFORMATION);
}

// ***** ANSI *****
/* ошибка */
void Msg::Error(const char *msg, ... ) {
	va_start( argptr, msg );
	vsprintf( buf_a, msg, argptr );
	va_end( argptr);
	MessageBoxA(0, buf_a, "ERROR", MB_ICONERROR);
	exit(1);
}

/* предупреждение */
void Msg::Warning(const char *msg, ...) {
	va_start( argptr, msg );
	vsprintf( buf_a, msg, argptr );
	va_end( argptr);
	MessageBoxA(0, buf_a, "WARNING", MB_ICONWARNING);
}

/* инфобокс */
void Msg::Info(const char *msg, ...) {
	va_start( argptr, msg );
	vsprintf( buf_a, msg, argptr );
	va_end( argptr);
	MessageBoxA(0, buf_a, "INFO", MB_ICONINFORMATION);
}
