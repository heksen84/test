/*
 * msg
 */
#ifndef MSG_H_
#define MSG_H_

class Msg {
	public:	
	static void Error(const wchar_t *msg, ... );
	static void Warning(const wchar_t *msg, ... );
	static void Info(const wchar_t *msg, ... );
};

#endif
