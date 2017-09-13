// --------------------------
// Gell.cpp
// Ilya Bobkov KZ 2017 (c)
// Тёмные земли
// --------------------------
#include "Common.h"
#include "Imglib.h"
#include "Util.h"
#include "Texture.h"
#include "ObjMesh.h"
#include "GLFW.h"
#include "FreeType.h"
#include "Glew.h"
#include "Landscape.h"
#include "Renderer.h"

bool g_AppRun = true;

void InitLibs(void) {
	InitGLFW();
	InitFreeType();
	InitGLEW();
}

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
 "  frag_colour = vec4(1.0, 1.5, 0.5, 1.0);"
 "}";

 /*
	glVertex2f(-0.75, 0.75);
	glVertex2f(-0.75, -0.75);
	glVertex2f(0.75, -0.75);
	glVertex2f(0.75, 0.75);
*/

 // ------------------
 // x,y,z
 // ------------------
 float points[] = {
   1.0f,  1.0f,  0.0f,
   0.5f, -1.0f,  0.0f,
   1.0f, -1.0f,  0.0f
 };

GLuint vbo=0, vao=0;
GLuint vs, fs;
GLuint shader_programm;

void CreatePanel()
{
	/* генерирую буфер */
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(float), points, GL_STATIC_DRAW);

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);

	vs = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vs, 1, &vertex_shader, NULL);
	glCompileShader(vs);
	fs = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fs, 1, &fragment_shader, NULL);
	glCompileShader(fs);

	shader_programm = glCreateProgram();
	glAttachShader(shader_programm, fs);
	glAttachShader(shader_programm, vs);
	glLinkProgram(shader_programm);
}

void DrawPanel() {
	glUseProgram(shader_programm);
	glBindVertexArray(vao);
	glDrawArrays(GL_TRIANGLES, 0, 3);
}

/* 
--------------------------------
точка входа
--------------------------------*/	
int main(void) {

	InitLibs();
	Renderer::getSingletonPtr()->DrawObject();
	Landscape *land = new Landscape("D:/projects/Steppe/data/meshes/landscape.obj");

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	CreatePanel();

	while (g_AppRun)
	{
		glClearColor (0.0, 0.0, 0.2, 0.0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		DrawPanel();
		glfwPollEvents();
		glfwSwapBuffers(window);
    }

	SAFE_DELETE(land);
    glfwTerminate();

    return 0;
}
