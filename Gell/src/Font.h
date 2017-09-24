#ifndef FONT_H_
#define FONT_H_

#include "Freetype.h" // local
#include "Common.h"

class Font
{
	public:	
		Font(const String &fontName);
		void RenderText(Unicode text, GLfloat x, GLfloat y, GLfloat scale, glm::vec3 color);
		virtual ~Font();
};

#endif
