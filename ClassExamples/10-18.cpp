//Generic programming
//  -run time polymorhpism
//      -virtual functions -> v-table
//  -compile time polymorhpism
//      -templates ->
//          -functions and classes   

#include <iostream>
using namespace std;

template<class T>
class Foo
{
    private:
        T one, two;
    public:
        Foo(T a, T b) : one(a), two(b) {}
        T smaller();
};

template<class T>
T Foo<T>::smaller()
{
    return (one<two?one:two);
}
int main()
{
    Foo<int> f(5.5,6.3);
    cout << f.smaller << endl;
}