/*
 * msg
 */
#ifndef MSG_H_
#define MSG_H_

class Msg
{
	public:	
	static void Error(const char *msg, ... );
	static void Warning(const char *msg, ... );
	static void Info(const char *msg, ... );
};

#endif
