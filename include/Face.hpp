#ifndef FACE_H
#define FACE_H
#pragma once

#include <vector>
#include <armadillo>
#include "Vertex.hpp"
using namespace std;

class Face
{
private:
	//La normal esta en a,b,c
	float A, B, C, D;
	vector<int> vertices;
	arma::frowvec normal;

public:
	vector<Vertex> verts;
	Face(vector<int> vertices);
	vector<int> get_vertices();
	arma::frowvec get_normal();
	//Cada cara va a tener su normal
	void calculate_plane_eq(vector<Vertex> verts);
	void print();
};
#endif