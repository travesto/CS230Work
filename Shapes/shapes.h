#include <iostream>

enum Color
{
    BLACK, RED, GREEN, YELLOW, BLUE, MANGENTA, CYAN, WHITE
};

class Shape
{
    public:
        void move();
        Color color() const; //color getter
        Color color(Color colour); //overloaded color setter 
        double area() const;
        double perimeter() const;
    private:
        Color c;
};
class Polygon : public Shape
{
    public:
        Polygon(Color colour, double* pts,int v);
        ~Polygon();
        double vertexX(int place) const;
        double vertexY(int place) const;
        void vertexX(int place, double coord);
        void vertexY(int place, double coord);
        int points() const;
    private:
        double* verticesX; //array of x vertices
        double* verticesY; //array of y vertices
        int vcount;
};
class Box : public Polygon
{
    public:
        Box();
        ~Box();
        double left() const;
        double top() const;
        double right() const;
        double bottom() const;
        void left(double left);
        void top(double top);
        void right(double top);
        void bottom(double bottom);
    private:
        double left;
        double top;
        double right;
        double bottom;
};
class Circle : public Shape
{
    public:
        Circle();
        ~Circle();
        centerX() const;//get x
        centerX(double x); //set x
        centerY() const;//get y
        centerY(double y); //set y
        radius() const;//get radius
        radius(double r); //set rad
    private:
        double center_x;
        double center_y;
        double radius;
};
class Triangle : public Polygon
{
    public:
        Triangle();
        ~Triangle();
    private:
        int corner1a;
        int corner1b;
        int corner2a;
        int corner2b;
        int corner3a;
        int corner3b;
};
