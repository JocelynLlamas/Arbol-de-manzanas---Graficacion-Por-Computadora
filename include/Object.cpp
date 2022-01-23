#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Vertex.hpp"
#include "Face.hpp"
#include "Object.hpp"

using namespace std;

Object::Object(string obj_file)
{
    string linea; 

    ifstream archivoOBJ(obj_file); 

    while(getline (archivoOBJ, linea)){

        //Se pasa la linea y el delimitador
        vector<string> elems = this->split(linea," "); 

        if(elems.size() > 0) 
        {
            if(elems[0].compare("o")==0){
                this->name = elems[1];
            }else{
                if(elems[0].compare("g")==0){
                    this->name = elems[1];
                }
            }
            //Analiza cada  linea buscando "V"
            if(elems[0].compare("v") == 0)
            {
                float x = stof(elems[1]); 
                float y = stof(elems[2]);
                float z = stof(elems[3]);

                Vertex new_vertex(x,y,z); 
                this->verts.push_back(new_vertex); 
            }

            //Analiza cada  linea buscando "F"
            if(elems[0].compare("f") == 0)
            {
                //creacion de vector para los vertices porque solo se quiere el indice del vector
                vector<int> vertices;
                for (int i = 1; i < elems.size(); i++)
                {
                    int v_index = stoi(this->split(elems[i],"/")[0]);
                    vertices.push_back(v_index-1); //SE CAMBIO ESTO--------------------------------------
                }
                //Creacion de Faces
                Face f(vertices);
                this->faces.push_back(f);
            }
        }
    }
}

//Significa que esta regresando un string
vector<string> Object::split(const string& str, const string& delim){
    vector<string> tokens;
    size_t prev = 0, pos=0;
    do
    {
        pos= str.find(delim,prev);
        if(pos == string::npos) pos = str.length();
        string token = str.substr(prev,pos-prev);
        if(!token.empty()) tokens.push_back(token);
        prev = pos + delim.length();
    } while (pos < str.length() && prev < str.length());
    return tokens;
}

void Object::print(){
    //Imprimimos el nombre de nuestro archivo
    cout << "ABRIENDO :)"<< endl;
    cout << "NOMBRE DEL ARCHIVO: "<< "g" << this->name << endl;
        
    //Imprimimos los vertices de nuestro archivo
    for(Vertex Vertex : this->verts){

        cout << "v" << "(" << Vertex.get_x() << " , " << Vertex.get_y() << " , " << Vertex.get_z() << ")" << endl;
    }
    //Imprimimos las Faces
    for (Face face : this->faces)
    {
        cout << "f" << "( ";
        for (int index : face.get_vertices())
        {
            cout << index << " ";
        }
        cout << ")" << endl;
        cout << "ECUACION DEL PLANO: ";
    }
}

vector<Vertex> Object::get_vertex()
{
    return(this->verts);
}

vector<Face> Object::get_faces()
{
    return(this->faces);
}