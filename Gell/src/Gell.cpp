// --------------------------
// gell.cpp
// Ilya Bobkov KZ 2017 (c)
// Тёмные земли
// --------------------------
#include "Common.h"
#include "Imglib.h"
#include "Util.h"
#include "Texture.h"
#include "Obj.h"
#include "Input.h"
#include "GLFW.h"

bool g_AppRun = true;

FT_Face     	face;
FT_GlyphSlot  	slot;

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

/* 
--------------------------------
точка входа
--------------------------------*/	
int main(void)
{
	FT_Library ft;
	int result;

	// --- Инициализация FreeType
	if (FT_Init_FreeType(&ft))
		msg::error(L"FT_Init_FreeType");

	// --- Инициализация FreeType
	result = FT_New_Face( ft, "D:/projects/Steppe/data/arial.ttf", 0, &face );

	if ( result == FT_Err_Unknown_File_Format )
		msg::error(L"FreeType: file format error");
	else
		if ( result )
			msg::error(L"FreeType: font not found");

	FT_Set_Pixel_Sizes(face, 0, 48);

	InitGLFW();

	/* назначить ввод */
    glfwSetKeyCallback(window, key_callback);
	glfwSetMouseButtonCallback(window, mouse_button_callback);
	glfwSetCursorPosCallback(window, mouse_callback);

	if (glewInit() != GLEW_OK) {
		msg::error(L"glewInit");
	}
	
	Obj mesh;
	mesh.loadFromFile("D:/projects/Steppe/data/meshes/box.obj");

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

	 while (g_AppRun)
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
