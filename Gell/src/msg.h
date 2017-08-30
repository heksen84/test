#ifndef _MSG_H_
#define _MSG_H_

class msg
{
	public:	
	static void error(const char *msg, ... );
	static void warning(const char *msg, ... );
	static void info(const char *msg, ... );
};

#endif