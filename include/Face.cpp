#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <armadillo>
#include "Face.hpp"
#include "Vertex.hpp"

using namespace std;

Face::Face(vector<int> verts)
{
    this->vertices = verts;
}

vector <int> Face::get_vertices()
{
    return this->vertices;
}

//Aqui se hacen las operaciones necesarias
void Face::calculate_plane_eq(vector <Vertex> verts){

    //Solo tenemos 3 vertices
    arma::frowvec v1 = {verts[this->vertices[0]].get_x(), verts[this->vertices[0]].get_y(), verts[this->vertices[0]].get_z()};
    arma::frowvec v2 = {verts[this->vertices[1]].get_x(), verts[this->vertices[1]].get_y(), verts[this->vertices[1]].get_z()};
    arma::frowvec v3 = {verts[this->vertices[2]].get_x(), verts[this->vertices[2]].get_y(), verts[this->vertices[2]].get_z()};
    
    //Calcular la normal
    this -> normal = arma::cross(v2-v1, v3-v1);

    this -> A = normal[0];
    this -> B = normal[1];
    this -> C = normal[2];
    //Calcular D
    this -> D = -((normal[0]*v1[0]) + (normal[1]*v1[1]) + (normal[2]*v1[2]));
    cout << "NORMAL" ;
    cout << this->normal <<endl;
}

arma::frowvec Face::get_normal()
{
    return (this->normal);
}
 