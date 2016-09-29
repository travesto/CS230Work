#include <iostream>
#include "Shapes.cpp"
#include <cassert>

int main()
{
    
    // double pts[] = {1,1,7,2,3,5,6,8,4,3};
    // Shape* s = new Polygon(BLUE, pts, 5);                        // of course you can't actually declare an abstract shape 
    // s->color(BLUE);                  // set shape's color to BLUE
    // Color c = s->color();  
    // assert(c==BLUE);
    // Shape* circ = new Circle(GREEN,5,5,3);
    // circ->color(RED);
    // c = circ->color();
    // assert(c==RED);
    Box b(BLUE, 1,6,7,1); //l,t,r,b
    b.render(cout);
    cout << endl;
    double distance = 0;
    double area = 0;
    double test[] = {1,1,1,6,7,6,7,1};
    Polygon p(GREEN,test,4);
    int c = p.points();
    p.render(cout);
    cout << endl;
    distance += p.perimeter();
    cout << "poly peri = " << distance<< endl;
    area += p.area();
    cout << "poly area = " << area << endl;
    double perim = 0;
    double ar = 0;
    perim = b.perimeter();
    ar = b.area();
    cout << "box perim = " << perim << endl;
    cout << "box area = " << ar << endl;

    // Triangle t(WHITE,1,1,5,1,3,3);
    // t.render(cout);
    // // t.cornerX1(2.5);   
    // // double cx1 = t.cornerX1(); 
    // cout << endl;   
    // t.render(cout);
    // distance += t.perimeter();
    // cout << "peri = " << distance;
    // area += t.area();
    // cout << endl << area << endl;
    // stringstream ss;

    // for (int i=0; i<count; i++) {
    //     distance += list[i]->perimeter();
    //     area += list[i]->area();
    //     list[i]->render(ss);
    //     ss << "\n";
    // }

    // for (int i=0; i<count; i++) {
    //     list[i]->move(10,10);
    //     list[i]->render(ss);
    //     ss << "\n";
    // }

    // cout << "distance: " << distance << " area: " << area << "\n";
    // cout << "drawing: " << ss.str();
    // for (int i=0; i<count; i++)
    //     delete list[i];
}