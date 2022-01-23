#include <iostream>
#include <GL/glu.h>
#include <GLFW/glfw3.h>
#include <armadillo>
#include "Object.hpp"
#include "transf.hpp"
#include "Arbol.hpp"
#include "Manzanas.hpp"
#include "Granjero.hpp"
#include "Glfw.hpp"
#include "trayectorias.hpp"

Glfw::Glfw()
{
}

void Glfw::main_glfw(GLFWwindow *window)
{
    glfwMakeContextCurrent(window);
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

    //CAMARA
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    //P R O Y E C C I O N E S
    //CAMARA: ESTOS APUNTAN A UNA DIRECCION ESPECIFICA
    arma::frowvec eye = {0.0, 0.0, 10.0};//10, 0, 0
    arma::frowvec camera = {0.0, 0.0, 0.0};
    arma::frowvec vista = {1.0, 0.0, 0.0};

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //Tamaño de la ventana
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);

    //Relacion de aspecto
    float ar = width / height;

    //Proyeccion en paralelo
    glViewport(0, 0, width, height);
    glOrtho(-ar, ar, -1.0, 1.0, -40.0, 40.0);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    //INSTANCIAS
    Arbol instancia_arbol;
    Manzanas instancia_manzana;
    Granjero instancia_granjero;
    transf transformacion;
    trayectorias trayectoria;

    //TRAYECTORIA
    Vertex vi = Vertex(-0.5, -0.5, 0.0);
    Vertex vf = Vertex(0.5, 0.5, 0.0);
    vector<Vertex> linea = trayectoria.lineal(vi, vf, 0.01);//SI QUEREMOS AUMENTAR O DISMINUIR LA TRAYECTORIA CAMBIAMOD DELTA T QUE ES EL 0.01
    int numero = linea.size() - 1;
    int ind_linea = 0;

    Vertex vi2 = Vertex(-0.5, -0.5, 0.0);
    Vertex vf2 = Vertex(0.5, 0.5, 0.0);
    vector<Vertex> linea2 = trayectoria.lineal(vi, vf, 0.01);
    int numero2 = linea2.size() - 1;
    int ind_linea2 = 0;

    //COLORES
    float Ia = 0.8; //INTENSIDAD DE LA LUZ DEL AMBIENTE
    do
    {
        Vertex vl = linea[ind_linea];
        if(ind_linea < numero)
        {
            ind_linea++;
        }
        Vertex vl2 = linea2[ind_linea2];
        if(ind_linea2 < numero2)
        {
            ind_linea2++;
        }
        glClear(GL_COLOR_BUFFER_BIT);
        glClear(GL_DEPTH_BUFFER_BIT);

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        gluLookAt(eye[0], eye[1], eye[2], camera[0], camera[1], camera[2], vista[0], vista[1], vista[2]);

        float Ip = 0.9;
        arma::frowvec light_pos = {2.0,0.0,0.0};
        glBegin(GL_TRIANGLES);
        //DIBUJA ARBOL
        instancia_arbol.dibuja(Ia, Ip, light_pos);
        //DIBUJA MANZANAS
        instancia_manzana.dibuja(Ia);
        //DIBUJA GRANJERO
        instancia_granjero.dibuja(window, Ia);
        //DIFERENTES ANGULOS
        if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
        {
            vista = {0.0f, 1.0f, 0.0f};
        }
        if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        {
            vista = {0.0f, 0.0f, 1.0f};//-1.0f, 0.0f, 0.0f
        }
        if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
        {
            vista = {1.0f, 0.0f, 0.0f};//SE REGRESA A LA POSICION ORIGINAL
        }
        if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS)
        {
            vista = {1.0f, 1.0f, 0.0f};
        }
        if (glfwGetKey(window, GLFW_KEY_T) == GLFW_PRESS)
        {
            vista = {0.0f, 1.0f, 1.0f};
        }
        if (glfwGetKey(window, GLFW_KEY_Y) == GLFW_PRESS)
        {
            vista = {1.0f, 0.0f, 1.0f};
        }
        if (glfwGetKey(window, GLFW_KEY_U) == GLFW_PRESS)
        {
            vista = {1.0f, 1.0f, 1.0f};
        }
        if (glfwGetKey(window, GLFW_KEY_I) == GLFW_PRESS)
        {
            vista = {1.0f, 1.0f, 1.0f};
        }
        //MOVIMIENTO DE CAMARA
        if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        {
            camera[1] -= 0.1;
        }
        if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        {
            camera[1] += 0.1;
        }
        if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        {
            camera[0] += 0.1f;
        }
        if (glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS)
        {
            camera[0] -= 0.1f;
        }
        if (glfwGetKey(window, GLFW_KEY_G) == GLFW_PRESS)
        {
            camera[2] += 0.1f;
        }
        if (glfwGetKey(window, GLFW_KEY_H) == GLFW_PRESS)
        {
            camera[2] -= 0.1f;
        }
        glEnd();
        glfwSwapBuffers(window);
        glfwPollEvents();

    } while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
             glfwWindowShouldClose(window) == 0);

    glfwTerminate();
}