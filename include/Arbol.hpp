#ifndef ARBOL_H
#define ARBOL_H
#pragma once
#include <armadillo>
#include "Object.hpp"
#include "transf.hpp"

class Arbol  
{
	private:
		//VARIABLES
		float ang_arbol = 270.0;
		transf transformacion;
	public:
		//VARIABLES
		arma::fmat Mtr_arbol = transformacion.Rz(ang_arbol) * transformacion.S(0.80, 0.80, 0.80);
		//METODOS
		Arbol();
		void dibuja(float Ia, float Ip, arma::frowvec posicion_luz);
};
#endif