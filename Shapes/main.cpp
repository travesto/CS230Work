#include <iostream>
#include "Shapes.cpp"
#include <cassert>
//#include <sstream>

int main()
{
    std::string name[]={"BLACK","RED","GREEN","YELLOW","BLUE","MAGENTA","CYAN","WHITE"};
    for (int i=0; i<8; i++) {
        Box b((Color)i,-1,2,3,-4);
        //std::stringstream ss;
        b.render(cout);
        cout << " = " ;
        //assert(ss.str() == 
        cout << "Box("+name[i]+",-1,2,3,-4)" << endl;
        // b.right(7);
        // b.top(-5);
        // b.color((Color)((i+1)%8));
        // ss.str("");
        // b.render(ss);
    }
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