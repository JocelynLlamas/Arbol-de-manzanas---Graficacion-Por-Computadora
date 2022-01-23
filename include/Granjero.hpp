#ifndef GRANJERO_H
#define GRANJERO_H
#pragma once
#include "Manzanas.hpp"
#include "Arbol.hpp"
#include "Object.hpp"
#include "transf.hpp"
#include "trayectorias.hpp"

class Granjero
{
private:
	float ang_granjero = 180.0;
	float movimiento_granjero = -0.5;
	transf transformacion;
	Arbol arbol;
public:
	arma::fmat Mtr_granjero = arbol.Mtr_arbol * transformacion.T(movimiento_granjero, 0.0, 0.0) * transformacion.S(0.40, 0.40, 0.40);
	Granjero();
	void dibuja(GLFWwindow* window, float Ia);
	void movimiento(GLFWwindow* window);
};
#endif