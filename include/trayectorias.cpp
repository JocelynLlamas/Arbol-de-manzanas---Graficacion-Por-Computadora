#include "trayectorias.hpp"
#include "Vertex.hpp"

trayectorias::trayectorias()
{
}

vector<Vertex> trayectorias::lineal(Vertex ini, Vertex end, float dt)
{
    //v1 + t(v2 - v1)
    vector<Vertex> line;

    //T=-1 PARA PC1 Y T=2 PARA PC4
    for (float t = 0.0; t < 1.0 + dt; t += dt)
    {
        float xl = ini.get_x() + (t * (end.get_x() - ini.get_x()));
        float yl = ini.get_y() + (t * (end.get_y() - ini.get_y()));
        float zl = ini.get_z() + (t * (end.get_z() - ini.get_z()));
        Vertex p(xl, yl, zl);
        line.push_back(p);
    }
    return (line);
}

vector<Vertex> trayectorias::bezier(Vertex ini, Vertex end, float dt)
{
    vector<Vertex> curve;

    for (float t = 0.0; t <= 1.0 + dt; t = t + dt)
    {
        float xl = ini.get_x() + (t * (end.get_x() - ini.get_x()));
        float yl = ini.get_y() + (t * (end.get_y() - ini.get_y()));
        float zl = ini.get_z() + (t * (end.get_z() - ini.get_z()));
        Vertex p(xl, yl, zl);
        curve.push_back(p);
    }
    return(curve);
}