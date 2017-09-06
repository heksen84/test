// --------------------------
// gell.cpp
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

bool g_AppRun = true;

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

	 float points[] =
	 {
		    0.0f,  0.5f,  0.0f,
		    0.5f, -0.5f,  0.0f,
		   -0.5f, -0.5f,  0.0f
	 };

/* 
--------------------------------
точка входа
--------------------------------*/	
int main(void)
{
	InitGLFW();
	InitFreeType();
	InitGlew();
	
	ObjMesh mesh;
	mesh.loadFromFile("D:/projects/Steppe/data/meshes/box.obj");

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

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

	while (g_AppRun) {
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
