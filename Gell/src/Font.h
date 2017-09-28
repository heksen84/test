#ifndef FONT_H_
#define FONT_H_

#include "Freetype.h" // local
#include "Common.h"

class Font
{
	public:
		void CreateSymbol(const wchar_t &symbol);
		void RenderText(const Unicode &text, GLfloat x, GLfloat y, GLfloat scale, glm::vec3 color);
		Font(const String &fontName);
		virtual ~Font();
	private:
		GLuint 			texture;
		FT_Face     	face;
		FT_GlyphSlot  	slot;
};

#endif
