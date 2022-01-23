#ifndef TRANS_H
#define TRANS_H
#pragma once
	
#include <armadillo>
#include <math.h>
#include "Vertex.hpp"

class transf
{
	private:

	public:
	    //transf transformacion();
		transf();
		arma::fmat T(float dx, float dy, float dz);
		arma::fmat S(float sx, float sy, float sz);
		arma::fmat Rx(float theta);
		arma::fmat Ry(float theta);
		arma::fmat Rz(float theta);
		arma::fmat Rp1p2(Vertex P1, Vertex P2, float theta);
};
#endif