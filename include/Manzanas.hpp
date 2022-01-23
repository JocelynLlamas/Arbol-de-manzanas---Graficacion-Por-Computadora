#ifndef MANZANAS_H
#define MANZANAS_H
#pragma once
#include "Arbol.hpp"
#include <GL/glu.h>
#include <GLFW/glfw3.h>
#include <armadillo>
#include "transf.hpp"

class Manzanas
{
private:
	transf transformacion;
public:
	float ang_manzana = 0.0;
	float ang_manzana2 = 0.0;
	float ang_manzana3 = 0.0;
	float ang_manzana4 = 0.0;
	float coordenada_y = 1.0;
	Manzanas();
	void dibuja(float Ia);
	void caida_manzana();
};
#endif