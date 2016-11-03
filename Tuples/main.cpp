#include <iostream>
#include "Tupples.h"
using namespace std;

int main()
{
    double x[] = (1,2,3,4,5);
    Tuple<int> i(5);         // create a zero-filled n-tuple
    Tuple<double> d(x,5)     // create n-tuple from x[]

    cout << i.size();         // number of elements
    cout << d.magnitude();    // Euclidean norm of the vector
}