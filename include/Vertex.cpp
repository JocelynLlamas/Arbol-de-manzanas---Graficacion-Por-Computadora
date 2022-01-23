#include <iostream>
#include <armadillo>
#include "Vertex.hpp" 

using namespace std;

Vertex::Vertex()
{
    x = y = z = 0.0;
}

Vertex::Vertex(float xi, float yi, float zi)
{
    x = xi;
    y = yi;
    z = zi;
}

float Vertex::get_x(){
    return this->x;
}

float Vertex::get_y(){
    return this->y;
}

float Vertex::get_z(){
    return this->z;
}

void Vertex::print(){
    cout << "(" << this->x << this->y << this->z << ")" << endl;
}

arma::fcolvec Vertex::homogenea()
{
    arma::fcolvec h = {this->x, this->y, this->z, 1};
    return h;
}

