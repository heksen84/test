// --------------------------
// gell.cpp
// Ilya Bobkov KZ 2017 (c)
// --------------------------
#include "common.h"
#include "imglib.h"
#include "util.h"
#include "texture.h"
#include "obj.h"

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
	//GLFWimage image;
	//imglib::loadPng("D:/projects/Gell/Gell/Release/data/image.png", &image);
		
	GLFWwindow* window;	
	GLFWmonitor* monitor;	
	const GLFWvidmode* mode;		
	
	// FreeType --
	FT_Library ft;
	int result = 0;


    if (!glfwInit())
    	msg::error("glfwInit: problem");
	
	monitor = glfwGetPrimaryMonitor();
	mode 	= glfwGetVideoMode(monitor);

	glfwWindowHint(GLFW_RED_BITS, 		mode->redBits);
	glfwWindowHint(GLFW_GREEN_BITS,		mode->greenBits);
	glfwWindowHint(GLFW_BLUE_BITS, 		mode->blueBits);
	glfwWindowHint(GLFW_REFRESH_RATE, 	mode->refreshRate);
	
	window = glfwCreateWindow(mode->width, mode->height, "-- [степь] --", monitor, NULL);
	
	if (!window)
		msg::error("glfwCreateWindow: problem");

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
	
	/* нзначить ввод */
	glfwSetKeyCallback(window, key_callback);
	glfwSetMouseButtonCallback(window, mouse_button_callback);

	// --- Инициализация FreeType
	if (FT_Init_FreeType(&ft)) 
		msg::error("FT_Init_FreeType");

	// --- Инициализация FreeType
	result = FT_New_Face( ft, "D:/projects/Gell/Gell/Release/data/arial.ttf", 0, &face );
	
	if ( result == FT_Err_Unknown_File_Format )
		msg::error("FreeType: file format error");
	else if ( result )
		msg::error("FreeType: file not found");
	
	FT_Set_Pixel_Sizes(face, 0, 48);	
	
	if (glewInit() != GLEW_OK) {
		msg::error("glewInit");
	}
	

	Obj mesh;
	mesh.loadFromFile("D:/projects/Gell/Gell/Release/data/meshes/box.obj");

	GLuint buffer;
	glGenBuffers(1, &buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(GL_ARRAY_BUFFER, mesh.getVertices().size() * sizeof(mesh.getVertices()[0]), mesh.getVertices().data(), GL_STATIC_DRAW);

	/*GLuint texture;
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image.width, image.height, 0, GL_RGB, GL_UNSIGNED_BYTE, image.pixels);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);*/
	
	while (run) {
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);		
		glClear(GL_COLOR_BUFFER_BIT);
				
		glBegin(GL_QUADS);
			glColor3f(0.0f, 0.0f, 1.0f);
			glVertex2f(-0.5f, -0.5f);
			glVertex2f( 0.5f, -0.5f);
			glColor3f(0.0f, 1.0f, 0.0f);
			glVertex2f( 0.5f,  0.5f);
			glVertex2f(-0.5f,  0.5f);
		glEnd();
		
		//RenderText("123123", 100, 200);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
