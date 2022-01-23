#include <iostream>
#include <GL/glu.h>
#include <GLFW/glfw3.h>
#include <armadillo>
#include "include/Glfw.hpp"

using namespace std;

int main()
{
    GLFWwindow *window;

    if (!glfwInit())
    {
        cout << stderr << "Fallo al inicializar GLFW\n";
        return -1;
    }

    window = glfwCreateWindow(1024, 768, "PROYECTO GRAFICACION POR COMPUTADORA", NULL, NULL);
    if (window == NULL)
    {
        cout << stderr << "Fallo al abrir la ventana de GLFW.\n";
        glfwTerminate();
        return -1;
    }
    
    Glfw glfw;
    glfw.main_glfw(window);
    
    return 0;
}
