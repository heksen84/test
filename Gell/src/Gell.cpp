// --------------------------
// Gell.cpp
// Ilya Bobkov
// --------------------------
#include "Common.h"
#include "Util.h"
#include "Texture.h"
#include "ObjMesh.h"
#include "GLFW.h"
#include "Renderer.h"
#include "Font.h"
#include "Gui.h"
#include "Shader.h"

bool g_AppRun = true;

GLuint vbo, vao, ebo;
GLuint vertexShader;
GLuint fragmentShader;
GLuint shaderProgram;
GLuint tex;

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

void CreatePlane(){

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
	   	if (!image) Msg::Error(L"SOIL_load_image: image not found");

	    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
	    SOIL_free_image_data(image);

	   	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	   	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	   	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	   	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	    glEnable(GL_BLEND);
	    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void DrawPlane(){
	glBindTexture(GL_TEXTURE_2D, tex);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

LRESULT CALLBACK DlgProc(HWND hWndDlg, UINT Msg, WPARAM wParam, LPARAM lParam) {
switch(Msg) {
	case WM_INITDIALOG:
	return TRUE;
	/*case WM_COMMAND:
		switch(wParam){
			case IDOK: EndDialog(hWndDlg, 0); return TRUE;
		}
		break;*/
		case WM_CLOSE: EndDialog(hWndDlg, 0); break;
	}
	return FALSE;
}


/* 
--------------------------------
точка входа
--------------------------------*/	
int main(void) {

	//Msg::Info(L"Терезе алды құлпырды\nҚызыл, сары, көкала,\nШешек атты гүл түрлі,\nҮйір болды көп ара.\nҚызыға қарап тұрғанда\nШағып алды басымнан\nЕңбекшіні қуам ба\nБалын бізге тасыған!");
	//Msg::Info(L"Die Vögelein schweigen im Walde.");

	COM_InitLibs();
	CreatePlane();

	Gui gui;
	gui.CreateFont(L"arial.ttf", L"arial");

	Font arial("D:/projects/Steppe/data/fonts/diablo/diablo-font-1.ttf");
	//Font arial("D:/projects/Steppe/data/fonts/fonts_kz/baltica kz.ttf");
	Shader shader("vertex","fragment");

	while (g_AppRun)
	{
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		arial.RenderText(L"\"cataleptycs\"", 470, 500, 1.0f, glm::vec3(255, 155, 155));
		arial.RenderText(L"presents", 595, 470, 0.5f, glm::vec3(255, 155, 155));
		//arial.RenderText(L"Алтын күн аспаны Алтын дән даласы Ерліктің дастаны Еліме қарашы Ежелден ер деген Даңқымыз шықты ғой Намысын бермеген Қазағым мықты ғой!", 10, 700, 1.2f, glm::vec3(255, 155, 155));
		glfwPollEvents();
		glfwSwapBuffers(window);

		//DrawPlane();
    }

	glDeleteTextures(1, &tex);
	glDeleteProgram(shaderProgram);
	glDeleteShader(fragmentShader);
	glDeleteShader(vertexShader);
	glDeleteBuffers(1, &ebo);
	glDeleteBuffers(1, &vbo);
	glDeleteVertexArrays(1, &vao);

    glfwTerminate();

    //Msg::Info(L"Приобрести полную версию\nwww.steppegame.com");
    //DialogBox(GetModuleHandle(0), MAKEINTRESOURCE(100), 0, reinterpret_cast<DLGPROC>(DlgProc));
    return 0;
}
