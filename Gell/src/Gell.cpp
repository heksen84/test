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

bool g_AppRun = true;

void InitLibs(void) {
	InitGLFW();
	InitFreeType();
	InitGLEW();
}

/* 
--------------------------------
точка входа
--------------------------------*/	
int main(void) {

	InitLibs();

	Landscape *land = new Landscape("D:/projects/Steppe/data/meshes/landscape.obj");

	while (g_AppRun) {
	  glClearColor(0.0, 0.0, 0.2, 0.0);
	  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	  glfwPollEvents();
	  glfwSwapBuffers(window);
    }

	SAFE_DELETE(land);

    glfwTerminate();

    return 0;
}
