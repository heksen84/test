#include "Common.h"


/*
------------------------------------
рендеринг текста
------------------------------------*/
/*void RenderText(const String &text, float x, float y){
	const char *p;
	slot = face->glyph;
	for(p = text.c_str(); *p; p++) {
		if(FT_Load_Char(face, *p, FT_LOAD_RENDER))
			continue;
			slot = face->glyph;
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RED, slot->bitmap.width, slot->bitmap.rows, 0, GL_RED, GL_UNSIGNED_BYTE, slot->bitmap.buffer);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	}
}*/

