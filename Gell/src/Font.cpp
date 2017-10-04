/*
--------------------------
 font.cpp
 Ilya Bobkov KZ 2017 (c)
--------------------------*/
#include "Font.h"
#include "Screen.h"
#include "GLFW.h"

const GLchar* _VertexSource = R"glsl(
#version 330 core
layout (location = 0) in vec4 vertex; // <vec2 pos, vec2 tex>
out vec2 TexCoords;
uniform mat4 projection;
void main()
{
    gl_Position = projection * vec4(vertex.xy, 0.0, 1.0);
    TexCoords = vertex.zw;
}  
)glsl";

const GLchar* _FragmentSource = R"glsl(
#version 330 core
in vec2 TexCoords;
out vec4 color;
uniform sampler2D text;
uniform vec3 textColor;
void main()
{    
    vec4 sampled = vec4(1.0, 1.0, 1.0, texture(text, TexCoords).r);
    color = vec4(textColor, 1.0) * sampled;
}
)glsl";

struct Glyph
{
    GLuint TextureID;
    glm::ivec2 Size;
    glm::ivec2 Bearing;
    GLuint Advance;
};

GLuint VAO, VBO;
GLuint _vertexShader;
GLuint _fragmentShader;
GLuint _shaderProgram;

std::map<wchar_t, Glyph> Symbols;
std::map<wchar_t, Glyph>::const_iterator item;

static wchar_t symbols_table[] = L"0123456789абвгдеёжзийклмнопрстуфхцчшщьыъэюяАБВГДЕЁЖЗBИЙКЛМНОПРСТУФХЦЧШЩЬЫЪЭЮЯ"	// кириллица
								  "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"							// латиница
								  "әғқңөұүhіӘҒҚҢӨҰҮH"																// арабский
								  "!@#$%^&*()_+-={}[]|:;'<>?~.,\"\\/ ";												// спецсимволы

/*
 * ------------------------------------------------
 * Создаю символ
 * ------------------------------------------------
 */
void Font::CreateSymbol(const wchar_t &symbol){

	if ( FT_Load_Char(face, symbol, FT_LOAD_RENDER) )
		Msg::Error(L"Font: Glyph loading symbol %d error!", symbol);

	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RED, face->glyph->bitmap.width, face->glyph->bitmap.rows, 0, GL_RED, GL_UNSIGNED_BYTE, face->glyph->bitmap.buffer);

	// параметры текстуры
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	Glyph character = {
	   	texture,
	    glm::ivec2(face->glyph->bitmap.width, face->glyph->bitmap.rows),
	    glm::ivec2(face->glyph->bitmap_left,  face->glyph->bitmap_top),
	    (ulong)face->glyph->advance.x
	};

	Symbols.insert(std::pair<wchar_t, Glyph>(symbol, character));
}

/* конструктор */
Font::Font(const String &fontName)
{
	int result=0;

	glPushAttrib(GL_ALL_ATTRIB_BITS);
	glPushClientAttrib(GL_CLIENT_VERTEX_ARRAY_BIT);

	result = FT_New_Face( ft, fontName.c_str(), 0, &face );
	FT_Select_Charmap(face, FT_ENCODING_UNICODE);

	if ( result == FT_Err_Unknown_File_Format ) Msg::Error(L"FreeType: file format error");
	else
		if ( result )
			Msg::Error(L"FreeType: font not found");

	FT_Set_Pixel_Sizes(face, 0, 48);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

	for (uint i = 0; i < sizeof(symbols_table); i++)
		CreateSymbol(symbols_table[i]);

	FT_Done_Face(face);
	FT_Done_FreeType(ft);

	glBindTexture(GL_TEXTURE_2D, 0);
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * 6 * 4, NULL, GL_DYNAMIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), 0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	_vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(_vertexShader, 1, &_VertexSource, NULL);
	glCompileShader(_vertexShader);

	_fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	 glShaderSource(_fragmentShader, 1, &_FragmentSource, NULL);
	 glCompileShader(_fragmentShader);

	_shaderProgram = glCreateProgram();
	 glAttachShader(_shaderProgram, _vertexShader);
	 glAttachShader(_shaderProgram, _fragmentShader);
	 glBindFragDataLocation(_shaderProgram, 0, "outColor");
	 glLinkProgram(_shaderProgram);

	 int width, height;
	 glfwGetWindowSize(window, &width, &height);

	 glm::mat4 projection = glm::ortho(0.0f, static_cast<GLfloat>(width), 0.0f, static_cast<GLfloat>(height));
	 glUseProgram(_shaderProgram);
	 glUniformMatrix4fv(glGetUniformLocation(_shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));

	 glEnable(GL_BLEND);
	 glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	 glPopClientAttrib();
	 glPopAttrib();
}

Font::~Font(){
}

/* отрисовка */
void Font::RenderText(const Unicode &text, GLfloat x, GLfloat y, GLfloat scale, glm::vec3 color) {

	// сохраняю состояния
	glPushAttrib(GL_ALL_ATTRIB_BITS);
	glPushClientAttrib(GL_CLIENT_VERTEX_ARRAY_BIT);

    // загрузить сюда шейдер и передать его параметры дальше
	glUseProgram(_shaderProgram);
    glUniform3f(glGetUniformLocation(_shaderProgram, "textColor"), color.x, color.y, color.z);
    glActiveTexture(GL_TEXTURE0);
    glBindVertexArray(VAO);

    for (uint i = 0; i < text.size(); i++) {
    	item = Symbols.find(text[i]);

    	if (item != Symbols.end()) {
    		Glyph ch = item->second;
    		GLfloat xpos = x + ch.Bearing.x * scale;
    		GLfloat ypos = y - (ch.Size.y - ch.Bearing.y) * scale;
    		GLfloat w = ch.Size.x * scale;
    		GLfloat h = ch.Size.y * scale;

    		GLfloat vertices[6][4] =
    		{
    		   { xpos,     ypos + h,   0.0, 0.0 },
    		   { xpos,     ypos,       0.0, 1.0 },
    		   { xpos + w, ypos,       1.0, 1.0 },
    		   { xpos,     ypos + h,   0.0, 0.0 },
    		   { xpos + w, ypos,       1.0, 1.0 },
    		   { xpos + w, ypos + h,   1.0, 0.0 }
    		};

    		glBindTexture(GL_TEXTURE_2D, ch.TextureID);
    		glBindBuffer(GL_ARRAY_BUFFER, VBO);
    		glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices); // Be sure to use glBufferSubData and not glBufferData
    		glBindBuffer(GL_ARRAY_BUFFER, 0);
    		glDrawArrays(GL_TRIANGLES, 0, 6);
    		x += (ch.Advance >> 6) * scale;
    	}
    	else
    		Msg::Error(L"Font::RenderText: Symbol [ %c ] not found in symbols table", text[i]);
    }

    glBindVertexArray(0);
    glBindTexture(GL_TEXTURE_2D, 0);
    glPopClientAttrib();
    glPopAttrib();
}
