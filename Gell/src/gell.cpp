// --------------------------
// gell.cpp
// Ilya Bobkov KZ 2017 (c)
// --------------------------
#include "common.h"
#include "imglib.h"
#include "util.h"
#include "texture.h"

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
	
	GLFWimage image;	
	imglib::loadPng("C:/Gell/bin/data/image.png", &image);	
	//msg::info("%dx%d размер=%d", image.width, image.height, sizeof(image.pixels));
	
	/*Texture t1("image.png");
	Texture t2("image.jpg");
	Texture t3("image");*/
		
	GLFWwindow* window;	
	GLFWmonitor* monitor;	
	const GLFWvidmode* mode;		
	
	// FreeType --
	FT_Library ft;
	int result = 0;
	
    if (!glfwInit()) msg::error("glfwInit: Какая-то проблемка");
	
	monitor = glfwGetPrimaryMonitor();
	mode 	= glfwGetVideoMode(monitor);

	glfwWindowHint(GLFW_RED_BITS, mode->redBits);
	glfwWindowHint(GLFW_GREEN_BITS,	mode->greenBits);
	glfwWindowHint(GLFW_BLUE_BITS, mode->blueBits);
	glfwWindowHint(GLFW_REFRESH_RATE, mode->refreshRate);
	
	window = glfwCreateWindow(mode->width, mode->height, "@GELL", monitor, NULL);
	
	if (!window) msg::error("glfwCreateWindow: Не могу создать окно!");

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
	
	/* нзначить ввод */
	glfwSetKeyCallback(window, key_callback);
	glfwSetMouseButtonCallback(window, mouse_button_callback);
	
	// --- Инициализация FreeType
	if (FT_Init_FreeType(&ft)) 
		msg::error("FT_Init_FreeType");

	// --- Инициализация FreeType
	result = FT_New_Face( ft, "C:/Gell/bin/data/arial.ttf", 0, &face );
	
	if ( result == FT_Err_Unknown_File_Format ) msg::error("FreeType: Не известный формат файла");		
	else if ( result ) msg::error("FreeType: Не понятная ошибка, либо файл не найден!");		
	
	FT_Set_Pixel_Sizes(face, 0, 48);	
	
	if (glewInit() != GLEW_OK) {
		msg::error("glewInit");
	}
	
	GLuint texture;
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image.width, image.height, 0, GL_RGB, GL_UNSIGNED_BYTE, image.pixels);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
	
	while (run) {
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);		
		glClear(GL_COLOR_BUFFER_BIT);
				
		glBegin(GL_QUADS);
			glColor3f(0.0f, 0.0f, 0.9f);
			glVertex2f(-0.5f, -0.5f); 
			glVertex2f( 0.5f, -0.5f);
			glColor3f(1.0f, 1.0f, 0.5f);
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
