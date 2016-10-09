#include <iostream>

enum Color {BLACK, RED, GREEN, YELLOW, BLUE, MANGENTA, CYAN, WHITE}; //enum for color

//Shape
class Shape 
{
    public:
        Shape(Color colour) : c(colour) {}
        virtual ~Shape() {};
        //color getters and setters
        Color color() const {return c;} //color getter
        void color(Color colour) {c = colour;} //color setter 
        //shape func
        virtual void move(double dx, double dy) = 0; //shifts entire shape by dx,dy
        virtual double area() const = 0; //calculates area
        virtual double perimeter() const  = 0; //calculates perimeter
        virtual void render(std::ostream &os) const = 0; //diplays shape details
        virtual bool inside(double dx, double dy) const = 0; //if x,y is within a shape perim
        virtual double thickness() const = 0; //area / perim
        virtual void colorAtPoint() const = 0; // ?
    private:
        //member variables
        Color c;
        Shape(const Shape& other); //disallow copy ctor
        void operator=(const Shape& other); //disallow equivalence
};
class Line : public Shape
{
    public:
        Line(Color colour, double leftx, double lefty, double rightx, double righty);
        //getters and setters
        double leftx() const;
        double lefty() const;
        double rightx() const;
        double righty();
        void leftx(double lx);
        void lefty(double ly);
        void rightx(double rx);
        void righy(double ry);
        //other funcs
        void render(std::ostream &os) const;
        void move(double dx, double dy);
        double perimeter() const; // can a line have a perim?
    private:
        double left_x, left_y, right_x, right_y;
}
class Polygon : public Shape
{
    public:
        //cosntructor & destructor
        Polygon(Color colour, double* pts,int v);
        ~Polygon();
        //setters and getters
        double vertexX(int place) const;
        double vertexY(int place) const;
        void vertexX(int place, double coord);
        void vertexY(int place, double coord);
        int points() const;
        //poly funcs
        void move(double dx, double dy);
        double area() const;
        double perimeter() const;
        void render(std::ostream &os) const;
    private:
        double* vertices; //array of xy coords
        int vcount; //# vertices
};
class Box : public Shape
{
    public:
        Box(Color colour, double left, double top, double right, double bottom); //ctor
        //getters and setters
        double left() const;
        double top() const;
        double right() const;
        double bottom() const;
        void left(double l);
        void top(double t);
        void right(double r);
        void bottom(double b);
        //box funcs
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
        Circle(Color colour, double x, double y, double r); //ctor
        double centerX() const;//get x
        void centerX(double x); //set x
        double centerY() const;//get y
        void centerY(double y); //set y
        double radius() const;//get radius
        void radius(double r); //set rad
        void move(double dx, double dy);
        //circle funcs
        double area() const;
        double perimeter() const;
        void render(std::ostream &os) const;
    private:
        double center_x, center_y, rad;
};
class Triangle : public Shape
{
    public:
        Triangle(Color colour, double corner1a, double corner1b, double corner2a, double corner2b, double corner3a, double corner3b); //ctor
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
