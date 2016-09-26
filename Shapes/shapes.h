#include <iostream>

enum Color
{
    BLACK, RED, GREEN, YELLOW, BLUE, MANGENTA, CYAN, WHITE
};

class Shape
{
    public:
        void move();
        Color color() const; 
        double area() const;
        double perimeter() const;
    private:
        Color c;
};
class Polygon : virtual public Shape
{
    public:
        Polygon();
        ~Polygon();
    private:
        int vertices[];
        int vcount;
};
class Box : virtual public Polygon
{
    public:
        Box();
        ~Box();
    private:
        int left;
        int top;
        int right;
        int bottom;
};
class Circle : virtual public Polygon
{
    public:
        Circle();
        ~Circle();
    private:
        int center_x;
        int center_y;
        float radius;
};
class Triangle :virtual public Polygon
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
