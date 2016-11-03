#include <iostream>
#include <string>
#include <vector>
using namespace std;

class mySingleton
{
    private:
        //private constructor
        mySingleton();
        //stop the compiler generating methods of copy the object
        mySingleton(mySingleton const& copy);   //not implemented
        mySingleton& operator=(mySingleton const& copy);    //not implmented
    public:
        static mySingleton& getInstance();
            //The only instance. Guaranteed to be lazy initialized and that it will be destroyed correctly
        static mySingleton instance;
        return instance;
};

mySingleton::getInstance();

int main()
{
   // mySingleton::getInstance();

}
// template <class T>
// class Stack
// {
//     public:
//         Stack (T x) { cout << x << " is not a character" << endl;}
// };

// template <>
// class Stack<char>
// {
//     public:
//         Stack (char x) { cout << x << " is a character" << endl;}
// };

// int main()
// {
//     // Stack<string> f("bob");
//     // Stack<int> f2(53);
//     // Stack<char> f3('t');
//     vector<int> v;
//     v.push_back(3);
//     v.push_back(4);
//     v.push_back(7);
//     for (int i = 0; i < 10000; i++)
//     {
//         v.push_back(i);
//     }
//     for (int i = 0; i < v.size(); i++)
//     {
//         cout << v[i] << endl;
//     }
// }