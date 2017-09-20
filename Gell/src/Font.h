#ifndef FONT_H_
#define FONT_H_
#include "FreeType.h"

class Font
{
	public:	
		Font(const String &fontName);
		virtual ~Font();
};

#endif
