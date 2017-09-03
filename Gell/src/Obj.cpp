/*
 * Obj.cpp
 *
 *  Created on: 01 сент. 2017 г.
 *      Author: —он€
 */

#include "Obj.h"

std::vector< glm::vec3 > vertices;
std::vector< glm::vec3 > uvs;
std::vector< glm::vec3 > normals;

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
 * «агрузка модели
 * v  - вершина x,y,z,w
 * vt - текстурные координаты (u,v,w)
 * vn - нормали (x,y,z)
 * ------------------------------------------
 */
void Obj::loadFromFile(const String &filename) {

	String data;
	std::ifstream file(filename.c_str());

	// проверка на готовность файла
	if (!file.is_open())
		msg::error("Obj::loadFromFle: file %s not open", filename.c_str());

	while ( !file.eof() ) {
		getline(file, data);
		if ( data[0] == 'v' and data[1] != 't' and data[1] != 'n') {
	    	for (uint i = 1; i < data.size(); i++) {
	    		if ( data[i] == ' ') {
	    				// верезать с текущей (позиции + 1) до следующего пробела
	    			 	// int NumRead = sscanf( Line.c_str(), "%6s %f %f %f", Prefix, &X, &Y, &Z );
	    				for (uint a = (i+1); a < data.size(); a++) {
	    					if ( data[a] == ' ') {
	    						//msg::info(data.substr(i+1, a-1).c_str());
	    					}
	    				}
	    			}
	    		}
	    	}
	    	continue;
	    	}
	    }
