#include <iostream>
#include "Shapes.cpp"
#include <cassert>
//#include <sstream>

int main()
{
    Shape * list[2];
    list[0] = new Box(GREEN, 0, 1, 1, 0);
    list[1] = new Circle(YELLOW, 2, 2, 2);
    Group g(BLUE, 2, list);
    
    Box b(BLUE,1,4,3,2);
	Circle c(BLUE,1,2,3);
	Triangle t(BLUE,1,2,3,4,3,2);
	double pts[] = {1,2,3,4,5,6,7,8,9,10};
	Polygon p(BLUE,pts,5);
    Box bb(BLUE,0,1,1,0);
    Circle cc(BLACK,5,5,2);
    Triangle tt(RED,0,0,10,0,0,1);
	double pts2[] = {0,0,1,0,1,1, 0,2,0,1};
    Polygon pp(YELLOW,pts2,5);
	RoundBox rb(WHITE,0,3,4,0,1);
    assert(fabs(rb.thickness()-((8.0+M_PI)/(6.0+2.0*M_PI))) < 0.0000001);
    // RoundBox b(BLUE,1,5,3,-1,1.5);
    // cout << b.area() << std::endl;
    // cout << b.perimeter() << std::endl;
    // cout << b.thickness() << std::endl;
    // b.render(cout);
    // cout << endl;
    // Line ln(RED,1,5,3,-1);
    // ln.render(cout);
    // Shape* list[1];
    // list[0] = new Box(BLUE,0,5,5,0);
    // cout << endl << Shape::colorAtPoint(list,1,2.5,2.5);

    // std::string name[]={"BLACK","RED","GREEN","YELLOW","BLUE","MAGENTA","CYAN","WHITE"};
    // for (int i=0; i<8; i++) {
    //     Box b((Color)i,-1,2,3,-4);
    //     //std::stringstream ss;
    //     b.render(cout);
    //     cout << " = " ;
    //     //assert(ss.str() == 
    //     cout << "Box("+name[i]+",-1,2,3,-4)" << endl;
    //     // b.right(7);
    //     // b.top(-5);
    //     // b.color((Color)((i+1)%8));
    //     // ss.str("");
    //     // b.render(ss);
    // }
    /*
    Box b(BLUE,1,2,3,4);
	Circle c(BLUE,1,2,3);
	Triangle t(BLUE,1,2,3,4,5,6);
	b.left(4);
	b.top(3);
	b.right(2);
	b.bottom(1);
	c.centerX(3);
	c.centerY(1);
	c.radius(2);
	t.cornerX1(6);
	t.cornerY1(5);
	t.cornerX2(4);
	t.cornerY2(3);
	t.cornerX3(2);
	t.cornerY3(1);
	static double pts[] = {1,2,3,4,5,6,7,8,9,10};
	Polygon p(BLUE,pts,5);
	cout << p.vertexX(1);
    //assert(p.vertexX(1) == 3);
    */
}