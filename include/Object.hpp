#ifndef OBJECT_H
#define OBJECT_H
#pragma once

#include <string>
#include <vector>
#include "Vertex.hpp"
#include "Face.hpp"

using namespace std;

class Object
{
private:
	string name;
	vector<Face> faces;
	vector<int> index;
	vector<string> split(const string &str, const string &delim);

public:
	vector<Vertex> verts;
	Object(string obj_file);
	void print();
	vector<Face> get_faces();
	vector<Vertex> get_vertex();
};
#endif