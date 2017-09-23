// --------------------------
// Gell.cpp
// Ilya Bobkov
// --------------------------
#include "Common.h"
#include "Imglib.h"
#include "Util.h"
#include "Texture.h"
#include "ObjMesh.h"
#include "GLFW.h"
#include "FreeType.h"
#include "Glew.h"
#include "Renderer.h"
#include "Font.h"
#include "Gui.h"

bool g_AppRun = true;

// Shader sources
const GLchar* vertexSource = R"glsl(
    #version 330
    in vec2 position;
    in vec3 color;
    in vec2 texcoord;
    out vec3 Color;
    out vec2 Texcoord;
    void main() {
        Color = color;
        Texcoord = texcoord;
        gl_Position = vec4(position, 0.0, 1.0);
    }
)glsl";

const GLchar* fragmentSource = R"glsl(
    #version 330
    in vec3 Color;
    in vec2 Texcoord;
    out vec4 outColor;
    uniform sampler2D tex;
    void main() {
        outColor = texture(tex, Texcoord)*1.7;
    }
)glsl";

GLuint vbo, vao, ebo;
GLuint vertexShader;
GLuint fragmentShader;
GLuint shaderProgram;
GLuint tex;

void InitLibs(void){
	InitGLFW();
	InitFreeType();
	InitGLEW();
}

void CreatePlane() {

		// Create Vertex Array Object
	    glGenVertexArrays(1, &vao);
	    glBindVertexArray(vao);

	    // Create a Vertex Buffer Object and copy the vertex data to it
	    glGenBuffers(1, &vbo);

	    GLfloat vertices[] = {
	    	 // x     y    	 r     g     b     u     w
	        -0.25f,  0.4f, 	1.0f, 0.0f, 0.0f, 0.0f, 0.0f, // Top-left
	         0.25f,  0.4f, 	0.0f, 1.0f, 0.0f, 1.0f, 0.0f, // Top-right
	         0.25f, -0.4f, 	0.0f, 0.0f, 1.0f, 1.0f, 1.0f, // Bottom-right
	        -0.25f, -0.4f, 	1.0f, 1.0f, 0.0f, 0.0f, 1.0f  // Bottom-left
	    };

	    glBindBuffer(GL_ARRAY_BUFFER, vbo);
	    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	    // Create an element array
	    glGenBuffers(1, &ebo);

	    // первая верхняя вершина (Top-left) и последняя нижняя (Bottom-left) имеют общую вершину

	    GLuint elements[] = { 	// как-бы 2 треугольника
	        0, 1, 2, 			// 1 (первый)
	        2, 3, 0 			// 2 (второй)
	    };

	    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(elements), elements, GL_STATIC_DRAW);

	    // Create and compile the vertex shader
	    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	    glShaderSource(vertexShader, 1, &vertexSource, NULL);
	    glCompileShader(vertexShader);

	    // Create and compile the fragment shader
	    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	    glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
	    glCompileShader(fragmentShader);

	    // Link the vertex and fragment shader into a shader program
	    GLuint shaderProgram = glCreateProgram();
	    glAttachShader(shaderProgram, vertexShader);
	    glAttachShader(shaderProgram, fragmentShader);
	    glBindFragDataLocation(shaderProgram, 0, "outColor");
	    glLinkProgram(shaderProgram);
	    glUseProgram(shaderProgram);

	    // Specify the layout of the vertex data
	    GLint posAttrib = glGetAttribLocation(shaderProgram, "position");
	    glEnableVertexAttribArray(posAttrib);
	    glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 7 * sizeof(GLfloat), 0);

	    GLint colAttrib = glGetAttribLocation(shaderProgram, "color");
	    glEnableVertexAttribArray(colAttrib);
	    glVertexAttribPointer(colAttrib, 3, GL_FLOAT, GL_FALSE, 7 * sizeof(GLfloat), (void*)(2 * sizeof(GLfloat)));

	    GLint texAttrib = glGetAttribLocation(shaderProgram, "texcoord");
	    glEnableVertexAttribArray(texAttrib);
	    glVertexAttribPointer(texAttrib, 2, GL_FLOAT, GL_FALSE, 7 * sizeof(GLfloat), (void*)(5 * sizeof(GLfloat)));

	    // Load texture
	    glGenTextures(1, &tex);
	    glBindTexture(GL_TEXTURE_2D, tex);

	    // Загрузка текстуры
	   	int width, height;
	   	byte* image = SOIL_load_image("D:/projects/steppe/data/gui/menu/mainmenu.jpg", &width, &height, 0, SOIL_LOAD_RGB);
	   	if (!image) Msg::Error("image not found");

	    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
	    SOIL_free_image_data(image);

	   	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	   	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	   	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	   	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);


	    glEnable(GL_BLEND);
	    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void DrawPlane() {

	glBindTexture(GL_TEXTURE_2D, tex);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

/*void ShowFps(GLFWwindow *pWindow)
{
    // Measure speed
     double currentTime = glfwGetTime();
     double delta = currentTime - lastTime;
     nbFrames++;
     if ( delta >= 1.0 ){ // If last cout was more than 1 sec ago
         cout << 1000.0/double(nbFrames) << endl;

         double fps = double(nbFrames) / delta;

         std::stringstream ss;
         ss << GAME_NAME << " " << VERSION << " [" << fps << " FPS]";

         glfwSetWindowTitle(pWindow, ss.str().c_str());

         nbFrames = 0;
         lastTime = currentTime;
     }
}*/

/* 
--------------------------------
точка входа
--------------------------------*/	
int main(void)
{
	InitLibs();
	CreatePlane();

	Gui gui;
	gui.CreateFontA("arial.ttf", "arial");

	Font arial("D:/projects/Steppe/data/fonts/diablo/diablo-font-1.ttf");

	while (g_AppRun)
	{
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		arial.RenderText("Diablo never die", 420, 600, 1.0f, glm::vec3(255, 155, 155));

		gui.DrawText("small_font", 10, 20, 1, "This is demo!", glm::vec3(200,200,200) );

		DrawPlane();

		glfwPollEvents();
		glfwSwapBuffers(window);

		//ShowFps(window);
    }

	glDeleteTextures(1, &tex);
	glDeleteProgram(shaderProgram);
	glDeleteShader(fragmentShader);
	glDeleteShader(vertexShader);
	glDeleteBuffers(1, &ebo);
	glDeleteBuffers(1, &vbo);
	glDeleteVertexArrays(1, &vao);

    glfwTerminate();
    return 0;
}
