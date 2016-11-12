#include <iostream>
#include <cassert>  
#include "Tuple.h"
using namespace std;

Tuple<int> add(Tuple<int> a,Tuple<int> b,Tuple<int> c)
{
return a+b+c;     // allocation for 2 anonymous objects, deallocation for 1 of them
}

int main()
{
    // Tuple<int> a(5);
    // Tuple<int> b = a;
    // Tuple<int> c(a);
    // a[1] = 4;
    // cout << a.implementation().useCount();
   
    // double x[] = {1,2,3,4,5};
    // Tuple<int> i(5);         // create a zero-filled n-tuple
    // Tuple<double> d(x,5);     // create n-tuple from x[]

    // cout << i.size() << endl;        // number of elements
    // cout << d.magnitude() << endl;    // Euclidean norm of the vector
    // cout << i.useCount() << endl;
//-----
    /*
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
    
    int data[] = {2,3,5,7,11,13,17,19,23};
    Tuple<int> a(data,9);
    Tuple<int> b(data,3);
    Tuple<int> c = a + b;
    cout << "b : d" << endl << "====="<< endl;
    for (int i=0; i<9; i++) {
        cout << b[i] << " : " << data[i] << endl;
        assert(b[i] == (i<3 ? data[i] : 0));
    }
    
    int data[] = {2,3,5,7,11,13,17,19,23};
    Tuple<int> a(data,9);
    Tuple<int> b(data,3);
    Tuple<int> c = a + b;
    for (int i=0; i<9; i++) {
    }
    Tuple<int> d(a);
	d += b;
	cout << a.implementation().useCount();
    assert(a.implementation().useCount()==1);
    
    Tuple<int> a(5);
    Tuple<int> b(a);
    Tuple<int> c(b);
    a[3] = 7;
    Tuple<int> d(a);
    cout << endl << "a : b" << endl << "-----" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << a[i] << " : " << b[i] << endl;   
    }
    assert(a!=b);
    
    Tuple<int> x(3);  // allocation of 3 ints
    Tuple<int> y(5);  // allocation of 5 ints
    x[0] = 2;         // no allocation, only one "user" of data
    x[1] = 3;
    x[2] = 7;
    y = x;            // deallocation of 5 ints, share 3 ints
    assert(y == x);
    Tuple<int> z(x);  // no allocation, another shared copy
    z[3] = 9;         // no allocation, z[3] is undefined so its a no-op
    z[1] = 5;         // copy/split occurs before write to element 1
    z += x;           // no allocation, z has its own copy
    x = add(x,y,x);   // no memory allocation should occur due to copy construction
    */
    //dot mult
	// int data[] = {2,3,5,7,11,13,17,19,23};
    // Tuple<int> a(data,9);
    // Tuple<int> b(data+1,5);
    // cout << "mag: " << a.magnitude() << endl;
    // cout << "dot: " << (int)sqrt(a*a); 
    // assert(a.magnitude() == (int)sqrt(a*a));

    // double datax[] = {2,3.4,5,7.75,11,13.6,17,19,23};
    // Tuple<double> a0(datax,9);
    // //a0 *= 3.3;
    // Tuple<double> b0(datax+1,5);
    // cout << "a0 * b0: " << (a0*b0) << endl << "stuff: " << (2*3.4 + 3.4*5 + 5*7.75 + 7.75*11 + 11*13.6) << endl;
    // cout << "a0*b0 - stuff: " << (fabs(a0*b0) - (2*3.4 + 3.4*5 + 5*7.75 + 7.75*11 + 11*13.6)) << endl;
    // cout << "a0: ";
    // for(int i = 0; i < a0.size(); i++)
    // {
    //     cout << a0[i] << "," ;
    // }
    // cout << endl;
    // cout << endl;
    // assert(fabs((a0*b0) - (2*3.4 + 3.4*5 + 5*7.75 + 7.75*11 + 11*13.6)) < .00001);
   

//     int data[] = {2,3,5,7,11,13,17,19,23};
//     Tuple<int> a(data,9);
//     Tuple<int> b = a;
//     a *= 3;
//     b = b*3;
//     cout << "a: ";
//     for (int i=0; i<a.size(); i++) 
//     {
//         cout << a[i] << ",";
//     }
//     cout << endl;
//     cout << "b: ";
//     for (int i=0; i<b.size(); i++) 
//     {
//         cout << b[i] << ",";
//     }
//     cout << endl;

//     Tuple<int> c(data,9);
//     c *= 3;
//     cout << "c: ";
//     for (int i=0; i<c.size(); i++) 
//     {
//         cout << c[i] << ",";
//     }
//     cout << endl << endl;
//     assert(c == b);

    // Tuple<int> a1(5);
    // a1 = a1 * 3;
    // a1 *= 3;
    // Tuple<int> b1(a1);
    // Tuple<int> c1(b1);
    // a1[3] = 7;
    // Tuple<int> d1(a1);
    // assert(a1!=b1);
  
    // int datag[] = {2,3,5,7,11,13,17,19,23};
    // Tuple<int> g(datag,9);
    // Tuple<int> h(datag,3);
    // Tuple<int> e = g + h;
    // Tuple<int> d(g);
    // d += h;
    // assert(d == e);
    

//     int data2[] = {2,3,5,7,11,13,17,19,23};
//     Tuple<int> aa(data2,9);
//     Tuple<int> bb(data2+1,5);
//     cout << "aa magnitude: " << aa.magnitude() << " " << (int)sqrt(aa*aa) << endl;
//     assert(aa.magnitude() == (int)sqrt(aa*aa));
//     assert(aa*bb == 2*3 + 3*5 + 5*7 + 7*11 + 11*13);
//     cout << endl;

//     const TupleData<int> td1(5);
//     const TupleData<int> td2(td1);
//     int l[5] = {1,2,3,4,5};
//     const TupleData<int> td3(l,5);
    
//     int item1 = td3[3];
//     const int item2 = td3[3];
    
//     int p = td3.size();
//     int q = td2.useCount();
    
    
//     Tuple<int> t1(5);
//     Tuple<int> t2(t1);
//     int list[5] = {1,2,3,4,5};
//     Tuple<int> t3(list,5);
    
//     t2 = t3;
//     int it1 = t2[2];
//     const int it2 = t2[2];
//     bool eq = t2 == t3;
//     bool neq = t2 == t1;
    
//     int s = t2.size();
//     int m = t2.magnitude();
    
//     Tuple<int> x(3);  // allocation of 3 ints
//     x[0] = 2;         // no allocation, only one "user" of data
//     x[1] = 3;
//     x[2] = 7;
//     cout << "x: ";
//     for(int i = 0; i < x.size(); i++)
//     {
//        cout << x[i] << ", ";
//     }

//     cout << endl;
//     Tuple<int> y(x); 
//     cout<< "y: ";
//     for(int i = 0; i < y.size(); i++)
//     {
//        cout << y[i] << ", ";
//     }
//     cout << endl;
//     x[0] = 2;         // no allocation, only one "user" of data
//     x[1] = 3;
//     x[2] = 7;
//     Tuple<int> z(x);  // no allocation, another shared copy
//     z[2] = 9;         // no allocation, z[3] is undefined so its a no-op
//     z[1] = 5;         // copy/split occurs before write to element 1
//     cout << "z: ";
//     for(int i = 0; i < z.size(); i++)
//     {
//        cout << z[i] << ", ";
//     }
//     z += x;           // no allocation, z has its own copy
//     cout << endl << "z: ";
//     for(int i = 0; i < z.size(); i++)
//     {
//        cout << z[i] << ", ";
//     }
//    x = x+y;
//     x = add(x,y,x);   // no memory allocation should occur due to copy construction
    /*
     Tuple<int> *a[1000];
    a[0] = new Tuple<int>(3);
    for (int i=1; i<1000; i++)
        a[i] = new Tuple<int>(*a[i-1]);
    for (int i=1; i<1000; i++) {
    }
    for (int i=0; i<1000; i++) {
        delete a[i];
    }
    a[0] = new Tuple<int>(4);
    for (int i=1; i<1000; i++)
        a[i] = new Tuple<int>(*a[i-1]);
    for (int i=1; i<1000; i++) {
    }
    Tuple<int> b(4);
    for (int i=0; i<1000; i++) {
        *a[i] = b;
        assert(b.implementation().useCount() == i+2);
    }
    */
}

//operator*(const Tuple<T>&, const Tuple<T>&) [with T = int](((const Tuple<int>&)((const Tuple<int>*)(& b)))) == 276