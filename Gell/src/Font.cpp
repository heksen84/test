/*
--------------------------
 font.cpp
 Ilya Bobkov KZ 2017 (c)
--------------------------*/
#include "Font.h"

int result = 0;



// Shader sources
const GLchar* shader = R"glsl(
#version 120
attribute vec4 coord;
varying vec2 texcoord;
void main(void) {
gl_Position = vec4(coord.xy, 0, 1);
texcoord = coord.zw;
)glsl";


/*
void render_text(const char *text, float x, float y, float sx, float sy) {
  const char *p;

  for(p = text; *p; p++) {
    if(FT_Load_Char(face, *p, FT_LOAD_RENDER))
        continue;

    glTexImage2D(
      GL_TEXTURE_2D,
      0,
      GL_RED,
      g->bitmap.width,
      g->bitmap.rows,
      0,
      GL_RED,
      GL_UNSIGNED_BYTE,
      g->bitmap.buffer
    );

    float x2 = x + g->bitmap_left * sx;
    float y2 = -y - g->bitmap_top * sy;
    float w = g->bitmap.width * sx;
    float h = g->bitmap.rows * sy;

    GLfloat box[4][4] = {
        {x2,     -y2    , 0, 0},
        {x2 + w, -y2    , 1, 0},
        {x2,     -y2 - h, 0, 1},
        {x2 + w, -y2 - h, 1, 1},
    };

    glBufferData(GL_ARRAY_BUFFER, sizeof box, box, GL_DYNAMIC_DRAW);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

    x += (g->advance.x/64) * sx;
    y += (g->advance.y/64) * sy;
  }
}*/

Font::Font(const String &fontName)
{
	result = FT_New_Face( ft, "D:/projects/Steppe/data/Fonts/Diablo/diablo-font-1.ttf", 0, &face );

	if ( result == FT_Err_Unknown_File_Format ) Msg::Error("FreeType: file format error");
	else  if ( result ) Msg::Error("FreeType: font not found");

	FT_Set_Pixel_Sizes(face, 0, 48);
}

Font::~Font(){
}
