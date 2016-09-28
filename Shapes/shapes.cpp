#include <iostream>
#include <cmath>
#include "shapes.h"

const double pi = 3.141592653589793238462643383279502884197169399;

Polygon::Polygon(Color colour, double* pts, int v) : Shape(colour)
{
    color(colour); //set colour
    verticesX = new double[v];
    verticesY = new double[v];
    if (pts != NULL)
    {
        for (int i = 0; i < v; i++)
        {
            verticesX[i] = pts[i*2];
            verticesY[i] = pts[(2*i)+1];
        }
    }
    
    vcount = v;
}
Polygon::~Polygon()
{
    delete [] verticesX;
    delete [] verticesY; 
}
//Poly Functions
    //Poly vcount
    int Polygon::points() const {return vcount;}
    //Poly getters
    double Polygon::vertexX(int place) const {return verticesX[place];}
    double Polygon::vertexY(int place) const {return verticesY[place];}
    //Poly setters
    void Polygon::vertexX(int place, double coord) {verticesX[place] = coord;}
    void Polygon::vertexY(int place, double coord) {verticesY[place] = coord;}
    //Poly move
    void Polygon::move(double x, double y) {};
    double Polygon::area() const {}
    double Polygon::perimeter() const 
    {
        double perimeter;
        for (int i = 0; i < vcount; i++)
        {
            perimeter += std::sqrt(std::pow((verticesX[i+1] - verticesX[i]), 2)+(std::pow((verticesX[i+1] - verticesX[i]), 2))); //distance formula
        }
        perimeter %= vcount*2;
    }
    void Polygon::render(std::ostream &os) const {};

//Circle Constructor
Circle::Circle(Color colour, double x, double y, double r) : Shape(colour)
{
    color(colour);
    centerX(x);
    centerY(y);
    radius(r);
}
Circle::~Circle() {}
//Circle Functions
    //circle getters
    double Circle::centerX() const {return center_x;}
    double Circle::centerY() const {return center_y;}
    double Circle::radius() const {return rad;}
    //circle setters
    void Circle::centerX(double x) {center_x = x;}
    void Circle::centerY(double y) {center_y = y;}
    void Circle::radius(double r) {rad = r;}
    //circle func
    void Circle::move(double dx, double dy) {center_x += dx; center_y += dy;}
    double Circle::area() const {double area = pi*(rad*rad);}
    double Circle::perimeter() const {double perimiter = (2*pi*rad);}
    void Circle::render(std::ostream &os) const 
    {
        os << "Circle(" << names[color()] << "," << center_x <<"," << center_y << "," << rad << ")";
    }

//Box constructor
Box::Box(Color colour, double left, double top, double right, double bottom):
    Polygon(colour, NULL, 4)
{
    color(colour); //set colour
    vertexX(0,left);
    vertexY(0,bottom);
    vertexX(1,left);
    vertexY(1,top);
    vertexX(2,right);
    vertexY(2,top);
    vertexX(3,right);
    vertexY(3,bottom);   
}
Box::~Box() {}
//box functions
    //box getters
    double Box::left() const {return vertexX(0);}
    double Box::top() const {return vertexX(1);}
    double Box::right() const {return vertexX(2);}
    double Box::bottom() const {return vertexX(3);}
    //box setters
    void Box::left(double left) {vertexX(0,left);}
    void Box::top(double top) {vertexX(1,top);}
    void Box::right(double right) {vertexX(2,right);}
    void Box::bottom(double bottom) {vertexX(3,bottom);}
    //Box func
    void Box::render(std::ostream &os) const { os << "Box(" << names[color()] << "," << l <<"," << t << "," << r << "," << b << ")";}

//Triangle constructor
Triangle::Triangle(Color colour, double x1, double y1, double x2, double y2, double x3, double y3) : Polygon(colour, NULL, 3)
{
    color(colour);
    vertexX(0,x1);
    vertexY(0,y1);
    vertexX(1,x2);
    vertexY(1,y2);
    vertexX(2,x3);
    vertexY(2,y3);
}
Triangle::~Triangle() {}
//Triangle Functions
    //Triangle getters
    double Triangle::cornerX1() const {return vertexX(0);}
    double Triangle::cornerX2() const {return vertexX(1);}
    double Triangle::cornerX3() const {return vertexX(2);}
    double Triangle::cornerY1() const {return vertexY(0);}
    double Triangle::cornerY2() const {return vertexY(1);}
    double Triangle::cornerY3() const {return vertexY(2);}
    //Triangle setters
    void Triangle::cornerX1(double corner1a) {vertexX(0,corner1a);}
    void Triangle::cornerX2(double corner2a) {vertexX(1,corner2b);}
    void Triangle::cornerX3(double corner3a) {vertexX(2,corner3a);}
    void Triangle::cornerY1(double corner1b) {vertexX(0,corner1a);}
    void Triangle::cornerY2(double corner2b) {vertexX(1,corner2b);}
    void Triangle::cornerY3(double corner3b) {vertexX(2,corner3b);}
    //others
    void Triangle::render(std::ostream &os) const {};
