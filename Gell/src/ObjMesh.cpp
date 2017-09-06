/*
 * ObjMesh.cpp
 *
 *  Created on: 01 сент. 2017 г.
 *      Author: Соня
 */

#include "ObjMesh.h"

ObjMesh::ObjMesh() {
}

ObjMesh::~ObjMesh() {
	//msg::info(L"Шешек атып алма ағаштары\nБозғылт тұман өзен үстінде!\n聖尼柯拉﹒喀瓦西拉斯　著");
}

/*
 * ------------------------------------------
 * Загрузка модели
 * v  - вершина x,y,z,w
 * vt - текстурные координаты (u,v,w)
 * vn - нормали (x,y,z)
 * f  - индекс поверхности
 * ------------------------------------------
 */
void ObjMesh::loadFromFile(const String &filename)
{

	std::ifstream file(filename, std::ios::in);

		if (!file)
			msg::error(L"Obj::loadFromFle: Cannot open file %s");

		String line;
	    while (getline(file, line))
	    {
	    	// вершины
	    	if (line.substr(0,2) == "v ")
	        {
	            std::istringstream s(line.substr(2));
	            glm::vec4 v; s >> v.x; s >> v.y; s >> v.z; v.w = 1.0f;
	            //msg::info("%f %f %f", v.x, v.y, v.z);
	            vertices.push_back(v);
	        }
	    	// нормали
	    	else if (line.substr(0,2) == "vn")
	    	{
	    		std::istringstream s(line.substr(2));
	    		glm::vec3 v; s >> v.x; s >> v.y; s >> v.z;
	    		normals.push_back(v);
	    	}
	    	// индексы поверхности
	        else if (line.substr(0,2) == "f ")
	        {
	        	std::istringstream s(line.substr(2));
	            GLushort a,b,c;
	            s >> a; s >> b; s >> c;
	            a--; b--; c--;
	            elements.push_back(a);
	            elements.push_back(b);
	            elements.push_back(c);
	        }
	    }
}

// вернуть вершины
std::vector< glm::vec4 > &ObjMesh::getVertices() {
	return vertices;
}
// вернуть нормали
std::vector< glm::vec3 > &ObjMesh::getNormals() {
	return normals;
}
// вернуть элементы
std::vector<GLushort> &ObjMesh::getElements(){
	return elements;
}
