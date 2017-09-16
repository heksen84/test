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

bool g_AppRun = true;

// Shader sources
const GLchar* vertexSource = R"glsl(
    #version 330 core
    in vec2 position;
    in vec3 color;
    out vec3 Color;
    void main()
    {
        Color = color;
        gl_Position = vec4(position, 0.0, 1.0);
    }
)glsl";
const GLchar* fragmentSource = R"glsl(
    #version 330 core
    in vec3 Color;
    out vec4 outColor;
    void main()
    {
        outColor = vec4(Color, 1.0);
    }
)glsl";

// x, y, z
 float points[] = {
     -0.5f,  0.5f, 1.0f, 0.0f, 0.0f, // Top-left
      0.5f,  0.5f, 0.0f, 1.0f, 0.0f, // Top-right
      0.5f, -0.5f, 0.0f, 0.0f, 1.0f, // Bottom-right
     -0.5f, -0.5f, 1.0f, 1.0f, 1.0f  // Bottom-left
 };

 GLuint elements[] = {
     0, 1, 2,
     2, 3, 0
 };

GLuint vbo, vao, ebo;
GLuint vertexShader, fragmentShader;
GLuint shaderProgram;

void InitLibs(void)
{
	InitGLFW();
	InitFreeType();
	InitGLEW();
}

void CreatePanel()
{
	// Create Vertex Array Object
	    glGenVertexArrays(1, &vao);
	    glBindVertexArray(vao);

	    // Create a Vertex Buffer Object and copy the vertex data to it

	    glGenBuffers(1, &vbo);

	    GLfloat vertices[] = {
	    	 // x     y    	 r     g     b
	        -0.25f,  0.4f, 	1.0f, 0.0f, 0.0f, // Top-left
	         0.25f,  0.4f, 	0.0f, 1.0f, 0.0f, // Top-right
	         0.25f, -0.4f, 	0.0f, 0.0f, 1.0f, // Bottom-right
	        -0.25f, -0.4f, 	1.0f, 1.0f, 0.0f  // Bottom-left
	    };

	    glBindBuffer(GL_ARRAY_BUFFER, vbo);
	    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	    // Create an element array
	    glGenBuffers(1, &ebo);

	    // первая верхняя вершина (Top-left) и последняя нижняя (Bottom-left) имеют общую вершину
	    GLuint elements[] = {
	        0, 1, 2,
	        2, 3, 0
	    };

	    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(elements), elements, GL_STATIC_DRAW);

	    // Create and compile the vertex shader
	    vertexShader = glCreateShader(GL_VERTEX_SHADER);
	    glShaderSource(vertexShader, 1, &vertexSource, NULL);
	    glCompileShader(vertexShader);

	    // Create and compile the fragment shader
	    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	    glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
	    glCompileShader(fragmentShader);

	    // Link the vertex and fragment shader into a shader program
	    shaderProgram = glCreateProgram();
	    glAttachShader(shaderProgram, vertexShader);
	    glAttachShader(shaderProgram, fragmentShader);
	    glBindFragDataLocation(shaderProgram, 0, "outColor");
	    glLinkProgram(shaderProgram);
	    glUseProgram(shaderProgram);

	    // установить позицию из шейдера
	    GLint posAttrib = glGetAttribLocation(shaderProgram, "position");
	    glEnableVertexAttribArray(posAttrib);
	    glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), 0);

	    // установить цвета из шейдера
	    GLint colAttrib = glGetAttribLocation(shaderProgram, "color");
	    glEnableVertexAttribArray(colAttrib);
	    glVertexAttribPointer(colAttrib, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (void*)(2 * sizeof(GLfloat)));
}

void DrawPanel()
{
	 // Clear the screen to black
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	// Draw a rectangle from the 2 triangles using 6 indices
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

/* 
--------------------------------
точка входа
--------------------------------*/	
int main(void) {

	InitLibs();
	CreatePanel();

	while (g_AppRun)
	{
		glClearColor (0.0, 0.0, 0.2, 0.0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		DrawPanel();
		glfwPollEvents();
		glfwSwapBuffers(window);
    }


	glDeleteProgram(shaderProgram);
	glDeleteShader(fragmentShader);
	glDeleteShader(vertexShader);

	glDeleteBuffers(1, &ebo);
	glDeleteBuffers(1, &vbo);
	glDeleteVertexArrays(1, &vao);

    glfwTerminate();

    return 0;
}
