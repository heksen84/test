// --------------------------
// gell.cpp
// Ilya Bobkov KZ 2017 (c)
// --------------------------
#include "Common.h"
#include "Imglib.h"
#include "Util.h"
#include "Texture.h"
#include "Obj.h"

bool run = true;

FT_Face     	face;
FT_GlyphSlot  	slot; 

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

/* 
------------------------------------
обработка ввода
------------------------------------*/	
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods){
    switch(key) {
		case GLFW_KEY_ESCAPE: run=false; break;		
	}
}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods){
    if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS) run=false;
}

/* 
--------------------------------
точка входа
--------------------------------*/	
int main(void)
{

	GLFWwindow* window;
	GLFWmonitor* monitor;
	const GLFWvidmode* mode;
	FT_Library ft;
	int result;

	/*
	 * ининциализация
	 */
	if (!glfwInit())
		msg::error(L"glfwInit error");

	monitor = glfwGetPrimaryMonitor();
	if (!monitor)
		msg::error(L"glfwGetPrimaryMonitor problem");

	mode = glfwGetVideoMode(monitor);
	if (!mode)
		msg::error(L"glfwGetVideoMode problem");

	glfwWindowHint(GLFW_RED_BITS, 		mode->redBits);
	glfwWindowHint(GLFW_GREEN_BITS,		mode->greenBits);
	glfwWindowHint(GLFW_BLUE_BITS, 		mode->blueBits);
	glfwWindowHint(GLFW_REFRESH_RATE, 	mode->refreshRate);
	
	window = glfwCreateWindow(mode->width, mode->height, "[ Strategy ]", monitor, NULL);
	
	if (!window)
		msg::error(L"glfwCreateWindow: problem");

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
	
	/* нзначить ввод */
	glfwSetKeyCallback(window, key_callback);
	glfwSetMouseButtonCallback(window, mouse_button_callback);

	// --- Инициализация FreeType
	if (FT_Init_FreeType(&ft)) 
		msg::error(L"FT_Init_FreeType");

	// --- Инициализация FreeType
	result = FT_New_Face( ft, "D:/projects/Gell/Gell/Release/data/arial.ttf", 0, &face );
	
	if ( result == FT_Err_Unknown_File_Format )
		msg::error(L"FreeType: file format error");
	else
		if ( result )
			msg::error(L"FreeType: file not found");
	
	FT_Set_Pixel_Sizes(face, 0, 48);	
	
	if (glewInit() != GLEW_OK) {
		msg::error(L"glewInit");
	}
	
	Obj mesh;
	mesh.loadFromFile("D:/projects/Gell/Gell/Release/data/meshes/box.obj");

	 glEnable(GL_DEPTH_TEST);
	 glDepthFunc(GL_LESS);

	 float points[] =
	 {
	    0.0f,  0.5f,  0.0f,
	    0.5f, -0.5f,  0.0f,
	   -0.5f, -0.5f,  0.0f
	 };

	 /* генерирую буфер */
	 GLuint vbo = 0;
	 glGenBuffers(1, &vbo);
	 glBindBuffer(GL_ARRAY_BUFFER, vbo);
	 glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(float), points, GL_STATIC_DRAW);

	 GLuint vao = 0;
	 glGenVertexArrays(1, &vao);
	 glBindVertexArray(vao);
	 glEnableVertexAttribArray(0);
	 glBindBuffer(GL_ARRAY_BUFFER, vbo);
	 glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
	
	 const char* vertex_shader =
	 "#version 400\n"
	 "in vec3 vp;"
	 "void main() {"
	 "  gl_Position = vec4(vp, 1.0);"
	 "}";

	 const char* fragment_shader =
	 "#version 400\n"
	 "out vec4 frag_colour;"
	 "void main() {"
	 "  frag_colour = vec4(0.9, 0.5, 0.5, 1.0);"
	 "}";

	 GLuint vs = glCreateShader(GL_VERTEX_SHADER);
	 glShaderSource(vs, 1, &vertex_shader, NULL);
	 glCompileShader(vs);
	 GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
	 glShaderSource(fs, 1, &fragment_shader, NULL);
	 glCompileShader(fs);

	 GLuint shader_programm = glCreateProgram();
	 glAttachShader(shader_programm, fs);
	 glAttachShader(shader_programm, vs);
	 glLinkProgram(shader_programm);

	 while (run)
	 {
		  glClearColor (0.0, 0.0, 0.2, 0.0);
		 // wipe the drawing surface clear
		  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		  glUseProgram(shader_programm);
		  glBindVertexArray(vao);
		  // draw points 0-3 from the currently bound VAO with current in-use shader
		  glDrawArrays(GL_TRIANGLES, 0, 3);
		  // update other events like input handling
		  glfwPollEvents();
		  // put the stuff we've been drawing onto the display
		  glfwSwapBuffers(window);
    }

    glfwTerminate();
    return 0;
}
