/*
 * Obj.cpp
 *
 *  Created on: 01 сент. 2017 г.
 *      Author: Соня
 */

#include "Obj.h"

std::vector< glm::vec4 > vertices;
std::vector< glm::vec3 > normals;
std::vector<GLushort> elements;

Obj::Obj() {
}

Obj::~Obj() {
}

/*void load_obj(const char* filename, vector<glm::vec4> &vertices, vector<glm::vec3> &normals, vector<GLushort> &elements)
{
    ifstream in(filename, ios::in);
    if (!in)
    {
        cerr << "Cannot open " << filename << endl; exit(1);
    }

    string line;
    while (getline(in, line))
    {
        if (line.substr(0,2) == "v ")
        {
            istringstream s(line.substr(2));
            glm::vec4 v; s >> v.x; s >> v.y; s >> v.z; v.w = 1.0f;
            vertices.push_back(v);
        }
        else if (line.substr(0,2) == "f ")
        {
            istringstream s(line.substr(2));
            GLushort a,b,c;
            s >> a; s >> b; s >> c;
            a--; b--; c--;
           elements.push_back(a); elements.push_back(b); elements.push_back(c);
        }
        else if (line[0] == '#')
        {

        }
        else
        {
        }
    }

    normals.resize(vertices.size(), glm::vec3(0.0, 0.0, 0.0));
    for (int i = 0; i < elements.size(); i+=3)
    {
        GLushort ia = elements[i];
        GLushort ib = elements[i+1];
        GLushort ic = elements[i+2];
        glm::vec3 normal = glm::normalize(glm::cross(
        glm::vec3(vertices[ib]) - glm::vec3(vertices[ia]),
        glm::vec3(vertices[ic]) - glm::vec3(vertices[ia])));
        normals[ia] = normals[ib] = normals[ic] = normal;
    }
}*/


/*
 * ------------------------------------------
 * Загрузка модели
 * v  - вершина x,y,z,w
 * vt - текстурные координаты (u,v,w)
 * vn - нормали (x,y,z)
 * f  - индекс поверхности
 * ------------------------------------------
 */
void Obj::loadFromFile(const String &filename)
{
		std::ifstream file(filename, std::ios::in);

		if (!file)
			msg::error("Obj::loadFromFle: Cannot open file %s", filename.c_str());

		String line;
	    while (getline(file, line))
	    {
	    	// вершины
	    	if (line.substr(0,2) == "v ")
	        {
	            std::istringstream s(line.substr(2));
	            glm::vec4 v; s >> v.x; s >> v.y; s >> v.z; v.w = 1.0f;
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
