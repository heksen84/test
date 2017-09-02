/*
 * Obj.cpp
 *
 *  Created on: 01 сент. 2017 г.
 *      Author: Соня
 */

#include "Obj.h"

std::vector< glm::vec3 > temp_vertices;
std::vector< glm::vec3 > temp_uvs;
std::vector< glm::vec3 > temp_normals;

Obj::Obj() {
}

Obj::~Obj() {
}

/*
void LoadOBJ( string Path, vector<vec3>& Verticies, vector<vec3>& Normals, vector<vec2>& UVs )
{
    vector<unsigned short> VIndex, NIndex, UVIndex;
    vector<vec3> TempNorms, TempVerts;
    vector<vec2> TempUVs;

    Verticies.clear();
    Normals.clear();
    UVs.clear();

    string Data;
    ifstream File(Path.c_str());
    while ( !File.eof() )
    {
        getline(File, Data);
        string Temp = "";
        if ( Data[0] == 'v' and Data[1] != 't' and Data[1] != 'n' )
        {
            vec3 Current;

            bool Negative[3] = {false, false, false};
            Negative[0] = ( Data[2] == '-' ) ? true : false;
            for ( int x = 0; x < 8 + Negative[0]; x++ )
                Temp += Data[ x+2 ];
           Current[0] = StringToFloat(Temp);

            for ( int vertex = 1; vertex < 3; vertex++ )
            {
                Temp = "";
                int Push = 0;
                for ( int n = 0; n < vertex; n++ )
                    Push += Negative[n];
                Negative[vertex] = ( Data[ 2 + 9*vertex + Push ] == '-' ) ? true : false;
                for ( int x = 0; x < 8 + Negative[vertex]; x++ )
                    Temp += Data[ x + 2 + 9*vertex + Push ];
                Current[vertex] = StringToFloat(Temp);
            }
            TempVerts.push_back(Current);

            //cout<<"Stored: "<<TempVerts.back()<<endl;
            //cout<<"Actual: "<<Data<<endl;

        }
        else if ( Data[0] == 'v' and Data[1] == 't' )
        {
            vec2 Current;
            for ( int v = 0; v < 2; v++ )
            {
                Temp = "";
                for ( int i = 0; i < 8; i++ )
                    Temp += Data[3 + i + v*9];
                Current[v] = StringToFloat(Temp);
                TempUVs.push_back(Current);
            }

            //cout<<"Stored: "<<TempUVs.back()<<endl;
            //cout<<"Actual: "<<Data<<endl;

        }
        else if ( Data[0] == 'v' and Data[1] == 'n' )
        {
            vec3 Current;
            bool Negative[3] = {false,GL_FALSE,0};
            Negative[0] = ( Data[3] == '-' ) ? true : false;
            for ( int i = 0; i < 8 + Negative[0]; i++ )
                Temp += Data[3 + i];
            Current[0] = StringToFloat(Temp);

            for ( int v = 1; v < 3; v++ )
            {
                Temp = "";

                int Push = 0;
                for ( int n = 0; n < v; n++ )
                    Push += Negative[n];
                Negative[v] = ( Data[ 3 + 9*v + Push ] == '-' ) ? true : false;
                for ( int i = 0; i < 8 + Negative[v]; i++ )
                    Temp += Data[ 3 + 9*v + Push + i ];
                Current[v] = StringToFloat(Temp);
                TempNorms.push_back(Current);
            }

            //cout<<"Stored: "<<TempNorms.back()<<endl;
            //cout<<"Actual: "<<Data<<endl;

        }
        else if ( Data[0] == 'f' )
        {
            int position = 2;
            for ( int i = 0; i < 3; i++ )
            {
                while ( IsNumber(Data[position]) )
                {
                    Temp += Data[position];
                    position++;
                }
                StringToFloat(Temp); ///For some reason it only works if I call it once beforehand
                VIndex.push_back(StringToFloat(Temp));

                Temp = "";
                position++;
                while ( IsNumber(Data[position]) )
                {
                    Temp += Data[position];
                    position++;
                }
                StringToFloat(Temp);
                UVIndex.push_back(StringToFloat(Temp));

                Temp = "";
                position++;
                while ( IsNumber(Data[position]) )
                {
                    Temp += Data[position];
                    position++;
                }
                StringToFloat(Temp);
                NIndex.push_back( StringToFloat(Temp) );

                Temp = "";
                position++;
            }

            //cout<<"Actual: "<<Data<<endl;
            //cout<<"Stored: ";
            //for ( int x = 3; x > 0; x-- )
            //{
            //    cout<<VIndex[VIndex.size() - x]<<'/'<<UVIndex[UVIndex.size() - x]<<'/'<<NIndex[NIndex.size() - x];
            //    cout<<' ';
            //}
            //cout<<endl;

        }
    }
    for ( int i = 0; i < VIndex.size(); i++ )
    {
        Verticies.push_back( TempVerts[ VIndex[i] - 1 ] );
        Normals.push_back  ( TempNorms[ NIndex[i] - 1 ] );
        UVs.push_back      ( TempUVs [ UVIndex[i] - 1 ] );
    }
}*/

/*
 * ------------------------------------------
 * Загрузка модели
 * ------------------------------------------
 */
void Obj::loadFromFile(const String &filename) {

	String Data;
	std::ifstream File(filename.c_str());
	if (!File.is_open())
		msg::error("loadFromFle: file %s not open", filename.c_str());

	while ( !File.eof() ){
		getline(File, Data);
	}
}

