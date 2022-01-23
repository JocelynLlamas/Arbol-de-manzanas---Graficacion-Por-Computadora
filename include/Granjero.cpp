#include "Granjero.hpp"
#include <iostream>
#include <GL/glu.h>
#include <GLFW/glfw3.h>
#include <armadillo>
#include "Manzanas.hpp"
#include "Arbol.hpp"
#include "Object.hpp"
#include "transf.hpp"

Granjero::Granjero()
{
}
//PONER COMO PARAMETRO EL MOVIMIENTO_GRANJERO
void Granjero::dibuja(GLFWwindow *window, float Ia)
{
    //OBJETO
    Object granjero("obj/character.obj");
    //COLORES
    arma::frowvec color_granjero = {0.0, 0.0, 1.0};
    float ki_granjero = 0.5; //NIVEL DE INTENSIDAD SIENDO 1 EL NIVEL MAS ALTO
    float I_granjero = Ia * ki_granjero;
    arma::frowvec intensidad = color_granjero * I_granjero;
    //Dibujar el granjero
    glColor3f(intensidad[0], intensidad[1], intensidad[2]);
    for (Face face : granjero.get_faces())
    {
        for (int index : face.get_vertices())
        {
            Vertex v = granjero.get_vertex()[index];
            arma::fcolvec v_dibuja = Mtr_granjero * v.homogenea();
            v_dibuja = v_dibuja / v_dibuja.at(3, 0);

            glVertex3f(v_dibuja.at(0, 0), v_dibuja.at(1, 0), v_dibuja.at(2, 0));
        }
    }

    movimiento(window);
}

void Granjero::movimiento(GLFWwindow *window)
{
    //MOVIMIENTO DEL GRANJERO
    if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
    {
        Mtr_granjero *= transformacion.T(movimiento_granjero - 0, 0.0, 0.0);
    }
    if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
    {
        Mtr_granjero *= transformacion.T(movimiento_granjero + 1, 0.0, 0.0);
    }
}