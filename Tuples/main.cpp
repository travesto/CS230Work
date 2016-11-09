#include <iostream>
#include "Tuple.h"
using namespace std;

int main()
{
    double x[] = {1,2,3,4,5};
    Tuple<int> i(5);         // create a zero-filled n-tuple
    Tuple<double> d(x,5);     // create n-tuple from x[]

    cout << i.size() << endl;        // number of elements
    cout << d.magnitude() << endl;    // Euclidean norm of the vector
    cout << i.useCount() << endl;
//-----
    const Tuple<int> t1(5);
    const Tuple<int> t2(t1);
    int list[5] = {1,2,3,4,5};
    const Tuple<int> t3(list,5);
    
    int it1 = t2[2];
    const int it2 = t2[2];
    bool eq = (t2 == t3);
    bool neq = (t2 == t1);
    
    int s = t2.size();
    int m = t2.magnitude();
}