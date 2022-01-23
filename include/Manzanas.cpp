#include <iostream>
#include <GL/glu.h>
#include <GLFW/glfw3.h>
#include <armadillo>
#include "Manzanas.hpp"
#include "Arbol.hpp"
#include "Object.hpp"
#include "transf.hpp"

Manzanas::Manzanas()
{
}

void Manzanas::dibuja(float Ia)
{
   //OBJETO
   Object manzana("obj/manzanaBonita.obj");
   Object manzana2("obj/manzanaBonita.obj");
   Object manzana3("obj/manzanaBonita.obj");
   Object manzana4("obj/manzanaBonita.obj");
   Arbol arbol;

   arma::fmat Mtr_manzana = arbol.Mtr_arbol * transformacion.Rz(ang_manzana) * transformacion.T(-0.1, coordenada_y, 0.0) * transformacion.S(0.60, 0.60, 0.60);
   arma::fmat Mtr_manzana2 = arbol.Mtr_arbol * transformacion.Rz(ang_manzana2) * transformacion.T(-0.5, coordenada_y, 0.0) * transformacion.S(0.60, 0.60, 0.60);
   arma::fmat Mtr_manzana3 = arbol.Mtr_arbol * transformacion.Rz(ang_manzana3) * transformacion.T(0.10, coordenada_y, 0.0) * transformacion.S(0.60, 0.60, 0.60);
   arma::fmat Mtr_manzana4 = arbol.Mtr_arbol * transformacion.Rz(ang_manzana4) * transformacion.T(0.2, coordenada_y, 0.0) * transformacion.S(0.60, 0.60, 0.60);

   //COLORES
   arma::frowvec color_manzana = {1.0, 0.0, 0.0};
   float ki_manzana = 1.0; //NIVEL DE INTENSIDAD SIENDO 1 EL NIVEL MAS ALTO
   float I_manzana = Ia * ki_manzana;
   arma::frowvec intensidad = color_manzana * I_manzana;

   //Dibujar la manzana
   glColor3f(intensidad[0], intensidad[1], intensidad[2]);
   for (Face face : manzana.get_faces())
   {
      for (int index : face.get_vertices())
      {
         Vertex v = manzana.get_vertex()[index];
         arma::fcolvec v_dibuja = Mtr_manzana * v.homogenea();
         v_dibuja = v_dibuja / v_dibuja.at(3, 0);
         glVertex3f(v_dibuja.at(0, 0), v_dibuja.at(1, 0), v_dibuja.at(2, 0));
      }
   }
   //Dibujar la manzana2
   glColor3f(intensidad[0], intensidad[1], intensidad[3]);
   for (Face face2 : manzana2.get_faces())
   {
      for (int index2 : face2.get_vertices())
      {
         Vertex v2 = manzana2.get_vertex()[index2];
         arma::fcolvec v_dibuja2 = Mtr_manzana2 * v2.homogenea();
         v_dibuja2 = v_dibuja2 / v_dibuja2.at(3, 0);
         glVertex3f(v_dibuja2.at(0, 0), v_dibuja2.at(1, 0), v_dibuja2.at(2, 0));
      }
   }
   //Dibujar la manzana3
   glColor3f(intensidad[0], intensidad[1], intensidad[2]);
   for (Face face3 : manzana3.get_faces())
   {
      for (int index3 : face3.get_vertices())
      {
         Vertex v3 = manzana3.get_vertex()[index3];
         arma::fcolvec v_dibuja3 = Mtr_manzana3 * v3.homogenea();
         v_dibuja3 = v_dibuja3 / v_dibuja3.at(3, 0);
         glVertex3f(v_dibuja3.at(0, 0), v_dibuja3.at(1, 0), v_dibuja3.at(2, 0));
      }
   }
   //Dibujar la manzana4
   glColor3f(intensidad[0], intensidad[1], intensidad[2]);
   for (Face face4 : manzana4.get_faces())
   {
      for (int index4 : face4.get_vertices())
      {
         Vertex v4 = manzana4.get_vertex()[index4];
         arma::fcolvec v_dibuja4 = Mtr_manzana4 * v4.homogenea();
         v_dibuja4 = v_dibuja4 / v_dibuja4.at(3, 0);
         glVertex3f(v_dibuja4.at(0, 0), v_dibuja4.at(1, 0), v_dibuja4.at(2, 0));
      }
   }

   caida_manzana();
}

void Manzanas::caida_manzana()
{
   //Gravedad constante en la manzana en el eje Y porque es hacia abajo
   float velocidad_y;
   float aceleracion_y = 0.05;
   float limite_angulo = 45.0;

   //Incremento de la gravedad
   if (coordenada_y <= 0.3)
   {
      coordenada_y = 1.0;
   }
   else
   {
      velocidad_y += aceleracion_y;
      coordenada_y -= velocidad_y;
   }

   //Incremento del ángulo
   if (coordenada_y == 1.0)
   {
      if (ang_manzana >= 75.0)
      {
         ang_manzana = 0.0;
         ang_manzana2 = 0.0;
         ang_manzana3 = 0.0;
         ang_manzana4 = 0.0;
      }
      else
      {
         ang_manzana += 10.0;
         ang_manzana2 += 5.0;
         ang_manzana3 -= 10.0;
         ang_manzana4 -= 5.0;
      }
   }
   if (coordenada_y < 1.0)
   {
      if (ang_manzana >= limite_angulo)
      {
         ang_manzana = 0.0;
         ang_manzana2 = 0.0;
         ang_manzana3 = 0.0;
         ang_manzana4 = 0.0;
      }
      else
      {
         ang_manzana += 10.0;
         ang_manzana2 += 5.0;
         ang_manzana3 -= 10.0;
         ang_manzana4 -= 5.0;
         limite_angulo -= 10.0;
      }
   }
}