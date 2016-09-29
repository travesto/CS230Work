#include <iostream>

enum Color {BLACK, RED, GREEN, YELLOW, BLUE, MANGENTA, CYAN, WHITE};

class Shape
{
    public:
        Shape(Color colour) : c(colour) {}
        virtual ~Shape() {}
        //color getters and setters
        Color color() const {return c;} //color getter
        void color(Color colour) {c = colour;} //overloaded color setter 
        //shape func
        virtual void move(double dx, double dy) = 0;
        virtual double area() const = 0;
        virtual double perimeter() const  = 0;
        virtual void render(std::ostream &os) const = 0;
    private:
        //member variables
        Color c;

        Shape(const Shape& other);
        void operator=(const Shape& other);
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
        void move(double dx, double dy);
        double area() const;
        double perimeter() const;
        void render(std::ostream &os) const;
    private:
        double* vertices; //array of x vertices
        int vcount;
};
class Box : public Shape
{
    public:
        Box(Color colour, double left, double top, double right, double bottom);
        ~Box();
        double left() const;
        double top() const;
        double right() const;
        double bottom() const;
        void left(double l);
        void top(double t);
        void right(double r);
        void bottom(double b);
        void render(std::ostream &os) const;
        void move(double dx, double dy);
        double area() const;
        double perimeter() const;
    private:
        double l, r, t, b;
};
class Circle : public Shape
{
    public:
        Circle(Color colour, double x, double y, double r);
        ~Circle();
        double centerX() const;//get x
        void centerX(double x); //set x
        double centerY() const;//get y
        void centerY(double y); //set y
        double radius() const;//get radius
        void radius(double r); //set rad
        void move(double dx, double dy);
        double area() const;
        double perimeter() const;
        void render(std::ostream &os) const;
    private:
        double center_x, center_y, rad;
};
class Triangle : public Shape
{
    public:
        Triangle(Color colour, double corner1a, double corner1b, double corner2a, double corner2b, double corner3a, double corner3b);
        ~Triangle();
        //triangle getters
        double cornerX1() const;
        double cornerY1() const;
        double cornerX2() const;
        double cornerY2() const;
        double cornerX3() const;
        double cornerY3() const;
        //triangle setters
        void cornerX1(double corner1a);
        void cornerY1(double corner1b);
        void cornerX2(double corner2a);
        void cornerY2(double corner2b);
        void cornerX3(double corner3a);
        void cornerY3(double corner3b);
        //others
        void move(double dx, double dy);
        double area() const;
        double perimeter() const;
        void render(std::ostream &os) const;
    private:
        double corner1a, corner1b, corner2a, corner2b, corner3a, corner3b;
};
