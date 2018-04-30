/*
 * msg
 */
#ifndef MSG_H_
#define MSG_H_

class Msg {
	public:
	// unicode
	static void Error(const wchar_t *msg, ... );
	static void Warning(const wchar_t *msg, ... );
	static void Info(const wchar_t *msg, ... );
	// ansi
	static void Error(const char *msg, ... );
	static void Warning(const char *msg, ... );
	static void Info(const char *msg, ... );
};

#endif
