#include <iostream>
#include <string>
using namespace std;

// class A                                 {public: void eat() {cout << "A" << endl;} };
// class B : virtual public A              {public: void eat() {cout << "B" << endl;} };
// class C : virtual public A              {public: void eat() {cout << "C" << endl;} };
// class D : virtual public B, public C    {public: void eat() {cout << "D" << endl;} };

// Box(color c, double _left, double _right, double _top, double _bottome) : Shape(c), l(_left), r(_right), t(_top), b(_bottom)
// {

// }
class Logger
{
    private:
        
};
class Builder
{

};
class Pluginloader
{
    public:
        Logger* const p_Logger;
        Builder* const p_Builder;
        Pluginloader(Builder* const pBuilder);
};

Pluginloader::Pluginloader(Builder* const pBuilder) : p_Builder(pBuilder), p_Logger(p_Builder->GetLogger())
{
    /*
    Initialization happens in the order in the class (p_logger initialized before p_Builder).
    To fix this change the order in the class. Or just use pBuilder  instead of p_builder.
    */
}

int main()
{
    A* a = new D();
    a->eat();
}