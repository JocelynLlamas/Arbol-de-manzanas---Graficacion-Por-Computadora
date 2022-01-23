#include "Arbol.hpp"
#include <iostream>
#include <GL/glu.h>
#include <GLFW/glfw3.h>
#include <armadillo>
#include "Object.hpp"
#include "transf.hpp"

Arbol::Arbol()
{
}

void Arbol::dibuja(float Ia, float Ip, arma::frowvec posicion_luz)
{
    //OBJETO
    Object arbol("obj/arbol_con_manzanas.obj");
    //COLORES
    arma::frowvec color_arbol = {0.0, 1.0, 0.0};
    float ki_arbol = 0.9; //NIVEL DE INTENSIDAD DE LUZ QUE TIENE EL OBJETO SIENDO 1 EL NIVEL MAS ALTO
    float kd_arbol = 0.9; //SE AGREGO
    float I_arbol = Ia * ki_arbol;

    //Dibujar el arbol
    for (Face face : arbol.get_faces())
    {
        face.calculate_plane_eq(arbol.verts);
        arma::frowvec normal = face.get_normal();
        //Reflexion difusa
        //float I = Ip * kd_arbol * max(arma::dot(arma::normalise(face.get_normal()), arma::normalise(posicion_luz)), 0.0f);
        //Luz ambiente + Reflexion difusa
        float I = (Ia * ki_arbol) +
                  (Ip * kd_arbol * max(arma::dot(arma::normalise(normal), arma::normalise(posicion_luz)), 0.0f));
                  
        arma::frowvec intensidad = color_arbol * I_arbol;
        glColor3f(intensidad[0], intensidad[1], intensidad[2]);
        for (int index : face.get_vertices())
        {
            Vertex v = arbol.get_vertex()[index];
            arma::fcolvec v_dibuja = Mtr_arbol * v.homogenea();
            v_dibuja = v_dibuja / v_dibuja.at(3, 0);

            glVertex3f(v_dibuja.at(0, 0), v_dibuja.at(1, 0), v_dibuja.at(2, 0));
        }
    }
}
