#ifndef MSG_H_
#define MSG_H_

class msg
{
	public:	
	static void error(const wchar_t *msg, ... );
	static void warning(const wchar_t *msg, ... );
	static void info(const wchar_t *msg, ... );
};

#endif
