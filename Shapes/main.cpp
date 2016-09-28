#include <iostream>
#include "shapes.cpp"
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

    double pts[] = {1,1,7,2,3,5,6,8,4,3};
    Shape * list[100];
    int count = 0;
    list[count++] = new Box(BLUE,0,1,1,0);
    list[count++] = new Box(CYAN,2,9,4,3);
    list[count++] = new Circle(WHITE,5,5,3);
    list[count++] = new Triangle(BLACK,1,1,5,1,3,3);
    list[count++] = new Polygon(GREEN,pts,5);
    Circle c(BLUE,3,4,2.1);    
    double distance = 0;
    double area = 0;
    distance += c.perimeter();
    area += c.area();
    cout << area << endl << distance << endl;
    c.render(cout);
    c.move(3,4);
    cout << endl;
    c.render(cout);

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