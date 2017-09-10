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

bool g_AppRun = true;

void InitLib(void) {
	InitGLFW();
	InitFreeType();
	InitGLEW();
}

void CreateTexturedPlane(void){

}
void DrawTexturedPlane(void){
	glDrawArrays(GL_TRIANGLES, 0, 3);
}

/* 
--------------------------------
точка входа
--------------------------------*/	
int main(void){
	InitLib();
	CreateTexturedPlane();

	while (g_AppRun) {
	  glClearColor(0.0, 0.0, 0.2, 0.0);
	  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	  DrawTexturedPlane();
	  glfwPollEvents();
	  glfwSwapBuffers(window);
    }

    glfwTerminate();
    return 0;
}
