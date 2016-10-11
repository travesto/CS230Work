#include <iostream>
#include <cmath>
#include <string>
#include "Shapes.h"

const double pi = 3.1415926535;
const std::string names[] = {"BLACK", "RED", "GREEN", "YELLOW", "BLUE", "MAGENTA", "CYAN", "WHITE", "INVALID"};
double absv(double points) //make abs for doubles
{
    if (points < 0)
    {
        return points *= -1;
    }
    return points;
}
Color Shape::colorAtPoint(Shape* array[], int num, double x, double y)
{
    for (int i = 0; i < num; i++)
    {
         if (array[i]->inside(x,y))
        {
            return array[i]->color();
        }
        else 
        {
            return INVALID;
        }
    }
}
Polygon::Polygon(Color colour, double* pts, int v) : Shape(colour) //ctor
{
    vertices = new double[v*2];
    for (int i = 0; i < v*2; i++) //puts xy into array
    {
        vertices[i] = pts[i];
    }
    vcount = v; //number of vertices
}
Polygon::~Polygon()
{
    delete [] vertices; //deletes xy array
    vertices = NULL;
}
//Poly Functions
    //Poly vcount
    int Polygon::points() const {return vcount;}
    //Poly getters
    double Polygon::vertexX(int place) const {return vertices[place*2];}
    double Polygon::vertexY(int place) const {return vertices[place*2+1];}
    //Poly setters
    void Polygon::vertexX(int place, double coord) {vertices[place*2] = coord;}
    void Polygon::vertexY(int place, double coord) {vertices[place*2+1] = coord;}
    //Poly move
    void Polygon::move(double dx, double dy) 
    {
        for (int i = 0; i < vcount*2; i += 2)
        {
            vertices[i] = vertices[i] + dx; //move x
        }   
        for (int i = 1; i < vcount*2; i += 2)
        {
            vertices[i] = vertices[i] + dy;//move y
        }
    }
    double Polygon::area() const //modified bourke formula
    {
        double a = 0;
        int t = 0;
        for (; t < (vcount*2)-2; t += 2) 
        {
            a+= (vertices[t]*vertices[t+3])-(vertices[t+2]*vertices[t+1]);
        }
        a += (vertices[t]*vertices[1])-(vertices[t+1]*vertices[0]);
        return absv(a /= 2);
    }
    double Polygon::perimeter() const //distance formula
    {
        double peri = 0;
        int i = 0;
        for (; i < (vcount*2)-2; i+=2)
        {
            peri += std::sqrt(std::pow((vertices[i] - vertices[i+2]), 2)+(std::pow((vertices[i+1] - vertices[i+3]), 2)));
        }
        peri += std::sqrt(std::pow((vertices[i] - vertices[0]), 2)+(std::pow((vertices[i+1] - vertices[1]), 2)));
        return peri;
    }
    void Polygon::render(std::ostream &os) const 
    {
        double* polyout = new double[vcount*2];
        for (int i = 0; i < vcount*2; i++)
        {
            polyout[i] = vertices[i];
        }
        os << "Polygon(" << names[color()] << "," << vcount;
        for (int i = 0; i < (vcount*2); i++)
        {
            os << "," << polyout[i];
        }
        os << ")";
        delete [] polyout;
        polyout = NULL;
    }
    bool Polygon::inside(double dx, double dy) const //if x,y is within a shape perim
    {
        int i, c = 0;
        int j = vcount - 1;
        for (i = 0, j; i < vcount; j = i) 
        {
            if ( ((vertices[i+1]>dy) != (vertices[j+1]>dy)) &&
            (dx < (vertices[j]-vertices[i]) * (dy-vertices[i+1]) / (vertices[j+1]-vertices[i+1]) + vertices[i]) )
            {
                c = !c;
            }
            i +=2;
        }
        if (c == 1)
        {
            return true;
        }
        else 
        {
            return false;
        }
    } 
//Circle Constructor
Circle::Circle(Color colour, double x, double y, double r) : Shape(colour)
{
    centerX(x);
    centerY(y);
    radius(r);
}
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
    double Circle::area() const {double a = pi*(rad*rad); return a;}
    double Circle::perimeter() const {double perimiter = (2*pi*rad); return perimiter;}
    void Circle::render(std::ostream &os) const 
    {
        os << "Circle(" << names[color()] << "," << center_x <<"," << center_y << "," << rad << ")";
    }
    bool Circle::inside(double dx, double dy) const //if x,y is within a shape perim
    {
        return ((std::pow((dx-center_x),2))+(std::pow((dy-center_y),2)) < rad*rad);
    } 

//Roundbox ctor
RoundBox::RoundBox(Color colour, double izquierda, double arriba, double derecha, double abajo, double radiums) : Shape(colour)
{
    l = izquierda;
    t = arriba;
    r = derecha;
    b = abajo;
    rad = radiums;
}
//rbox funcs
    //getters
    double RoundBox::left() const {return l;}
    double RoundBox::top() const {return t;}
    double RoundBox::right() const {return r;}
    double RoundBox::bottom() const {return b;}
    double RoundBox::radius() const {return rad;}
    //box setters
    void RoundBox::left(double izquierda) {l = izquierda;}
    void RoundBox::top(double arriba) {t = arriba;}
    void RoundBox::right(double derecha) {r = derecha;}
    void RoundBox::bottom(double abajo) {b = abajo;}
    void RoundBox::radius(double radiums) {rad = radiums;}
    //other funcs
    void RoundBox::render(std::ostream &os) const
    {
        os << "RoundBox(" << names[color()] << "," << left() <<"," << top() << "," << right() << "," << bottom() << "," << radius() << ")";
    }
    double RoundBox::area() const 
    {
        double len = r-l;
        double width = t-b;
        double a = ((len-2*rad)+2*(len-2*rad*rad)+2*(width-2*rad*rad)+2*pi*rad*rad);
        return a;
    }
    void RoundBox::move(double dx, double dy) 
    {
        l += dx; 
        r+=dx; 
        t+=dy; 
        b+=dy;
    }
    double RoundBox::perimeter() const 
    {
        double len = absv(l-r); 
        double width = absv(t-b); 
        double p = (2*(width-2*rad)+2*(len-2*rad)+2*pi*rad); 
        return p;
    }
    bool RoundBox::inside(double dx, double dy) const //if x,y is within a shape perim
    {
        
    } 
//Line ctor
Line::Line(Color colour, double leftx, double lefty, double rightx, double righty) : Shape(colour)
{
    left_x = leftx;
    left_y = lefty;
    right_x = rightx;
    right_y = righty;
}
//line functions
    //getters
    double Line::end1X() const {return left_x;}
    double Line::end1Y() const {return left_y;}
    double Line::end2X() const {return right_x;}
    double Line::end2Y() const {return right_y;}
    //setters
    void Line::end1X(double leftx) {left_x = leftx;}
    void Line::end1Y(double lefty) {left_y = lefty;}
    void Line::end2X(double rightx) {right_x = rightx;}
    void Line::end2Y(double righty) {right_y = righty;}
    //other funcs
    void Line::render(std::ostream &os) const
    {
        os << "Line(" << names[color()] << "," << end1X() <<"," << end1Y() << "," << end2X() << "," << end2Y() << ")";
    }
    void Line::move(double dx, double dy) 
    {
        left_x += dx;
        left_y += dy;
        right_x += dx;
        right_y += dy;
    }
    double Line::perimeter() const {return 0;} //can it have perim?
    bool Line::inside(double dx, double dy) const {return 0;} //if x,y is within a shape perim 
    double Line::area() const {return 0;}
//Box constructor
Box::Box(Color colour, double izquierda, double arriba, double derecha, double butts) :
    Shape(colour)
{
    l = izquierda;
    t = arriba;
    r = derecha;
    b = butts;
}
//box functions
    //box getters
    double Box::left() const {return l;}
    double Box::top() const {return t;}
    double Box::right() const {return r;}
    double Box::bottom() const {return b;}
    //box setters
    void Box::left(double izquierda) {l = izquierda;}
    void Box::top(double arriba) {t = arriba;}
    void Box::right(double derecha) {r = derecha;}
    void Box::bottom(double butts) {b = butts;}
    //Box func
    void Box::render(std::ostream &os) const 
    { 
        os << "Box(" << names[color()] << "," << left() <<"," << top() << "," << right() << "," << bottom() << ")";
    }
    void Box::move(double dx, double dy) {l+=dx; r+=dx; t+=dy; b+=dy;}
    double Box::area() const 
    {
        double len = r-l; 
        double width = t-b; 
        double a = len*width; 
        return a;
    }
    double Box::perimeter() const 
    {
        double len = absv(l-r); 
        double width = absv(t-b); 
        double p = (2*len)+(2*width); 
        return p;
    }
    bool Box::inside(double dx, double dy) const //if x,y is within a shape perim
    {
        return ((dx > l && dx < r) && (dy > b && dy < t));
    } 
//Triangle constructor
Triangle::Triangle(Color colour, double x1, double y1, double x2, double y2, double x3, double y3) : Shape(colour)
{
    cornerX1(x1);
    cornerY1(y1);
    cornerX2(x2);
    cornerY2(y2);
    cornerX3(x3);
    cornerY3(y3); 
}
//Triangle Functions
    //Triangle getters
    double Triangle::cornerX1() const {return corner1a;}
    double Triangle::cornerX2() const {return corner2a;}
    double Triangle::cornerX3() const {return corner3a;}
    double Triangle::cornerY1() const {return corner1b;}
    double Triangle::cornerY2() const {return corner2b;}
    double Triangle::cornerY3() const {return corner3b;}
    //Triangle setters
    void Triangle::cornerX1(double x1) {corner1a = x1;}
    void Triangle::cornerX2(double x2) {corner2a = x2;}
    void Triangle::cornerX3(double x3) {corner3a = x3;}
    void Triangle::cornerY1(double y1) {corner1b = y1;}
    void Triangle::cornerY2(double y2) {corner2b = y2;}
    void Triangle::cornerY3(double y3) {corner3b = y3;}
    //others
    void Triangle::move(double dx, double dy) 
    {
        cornerX1(corner1a + dx);
        cornerX2(corner2a + dx);
        cornerX3(corner3a + dx);
        cornerY1(corner1b + dy);
        cornerY2(corner2b + dy);
        cornerY3(corner3b + dy);
    }
    double Triangle::area() const 
    {
        double altura, base;
        double a1 = absv(corner1b - corner2b);
        double a2 = absv(corner2b - corner3b);
        double a3 = absv(corner1b - corner3b);
        //find greatest distance for heighth
        if ((a1 >= a2) && (a1 >= a3)) {altura = a1;}
        else if ((a2 >= a1) && (a2 >= a3)) {altura = a2;}
        else {altura = a3;}
       
        double b1 = absv(corner1a - corner2a);
        double b2 = absv(corner2a - corner3a);
        double b3 = absv(corner3a - corner1a);
        //find greatest distance for base
        if ((b1 >= b2) && (b2 >= b3)) {base = b1;}
        else if ((b2 >= b1) && (b2 >= b3)) {base = b2;}
        else {base = b3;}
        
        return (base*altura)/2;
    }
    double Triangle::perimeter() const 
    {
        double peri = 0;
        peri += std::sqrt(std::pow((corner1a - corner2a), 2) + (std::pow((corner1b - corner2b), 2))); //distance formula
        peri += std::sqrt(std::pow((corner2a - corner3a), 2) + (std::pow((corner2b - corner3b), 2)));
        peri += std::sqrt(std::pow((corner3a - corner1a), 2) + (std::pow((corner3b - corner1b), 2)));
        return peri;
    }
    void Triangle::render(std::ostream &os) const 
    {
        os << "Triangle(" << names[color()] << "," << corner1a << "," << corner1b << "," << corner2a << "," << corner2b << "," << corner3a << "," << corner3b << ")";
    }
    bool Triangle::inside(double dx, double dy) const //if x,y is within a shape perim
    {
        double vertx[] = {corner1a, corner2a, corner3a};
        double verty[] = {corner1b, corner2b, corner3b};
        int i, c = 0;
        int j = 2;
        for (i = 0, j; i < 3; j = i++) 
        {
            if (((verty[i]>dy) != (verty[j]>dy)) && (dx < (vertx[j]-vertx[i]) * (dy-verty[i]) / (verty[j]-verty[i])))
            {
                c = !c;
            }
        }
        if (c == 1)
        {
            return true;
        }
        else 
        {
            return false;
        }
    } 
