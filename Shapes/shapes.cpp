#include <iostream>
#include "shapes.h"

const double pi = 3.14;

std::ostream render()
{

}

Color Shape::color() const //color getter
{ 
    return c;
} 
Color Shape::color(Color colour) //color setter
{
    c = colour;
}

void Shape::move() {}

Polygon::Polygon(Color colour, double* pts, int v)
{
    color(colour); //set colour
    verticesX = new double[v];
    for (int i = 0; i < (v); i++)
    {
        verticesX[i] = pts[i*2];
    }
    verticesY = new double[v];
    {
        verticesY[i] = pts[(2*x)+1];
    }
    vcount = v;
}
Polygon::~Polygon()
{
    delete [] pts;
}
//Poly vcount
int Polygon::points() const {return vcount;}
//Poly getters
double Polygon::vertexX(int place) const {return verticesX[place];}
double Polygon::vertexY(int place) const {return verticesY[place];}
//Poly setters
void Polygon::vertexX(int place, double coord) {verticesX[place] = coord;}
void Polygon::vertexY(int place, double coord) {verticesY[place] = coord;}
//Circle Constructor
Circle::Circle(Color colour, double x, double y, double r)
{
    color(colour);
    centerX(x);
    centerY(y);
    radius(r);
}
//circle getters
double Circle::centerX() const {return center_x;}
double Circle::centerY() const {return center_y;}
double Circle::radius() const {return radius;}
//circle setters
void Circle::centerX(double x) {center_x = x;}
void Circle::centerY(double y) {center_y = y;}
void Circle::radius(double r) {radius = r;}
//Box constructor
Box::Box(Color colour, double left, double top, double right, double bottom):
    Polygon(Color colour, double* pts = double pts[4], int v)
{
    vertexX(0,left);
    vertexY(0,bottom);
    vertexX(1,left);
    vertexY(1,top);
    vertexX(2,right);
    vertexY(2,top);
    vertexX(3,right);
    vertexY(3,bottom);   
}
//box getters
double Box::left() const {return vertexX[0];}
double Box::top() const {return vertexX[1];}
double Box::right() const {return vertexX[2];}
double Box::bottom() const {return vertexX[3];}
//box setters
Triangle::Triangle(): Polygon(Color colour, double* pts = double pts[3], int v) 
{

}
