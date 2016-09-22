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
////////////////////////////////////
// class Logger
// {
//     private:
        
// };
// class Builder
// {

// };
// class Pluginloader
// {
//     public:
//         Logger* const p_Logger;
//         Builder* const p_Builder;
//         Pluginloader(Builder* const pBuilder);
// };

// Pluginloader::Pluginloader(Builder* const pBuilder) : p_Builder(pBuilder), p_Logger(p_Builder->GetLogger())
// {
//     /*
//     Initialization happens in the order in the class (p_logger initialized before p_Builder).
//     To fix this change the order in the class. Or just use pBuilder  instead of p_builder.
//     */
// }
//////////////////////
/*
class A {
    private:
        int a;
        const int q;
    public:
        A(int _a) : q(5)
        {
            a= _a; 
            cout << "base initialized with " << _a << endl;
        }
};
class B : public A {
    public:
        B(int b) : A(b) {cout << "derived initizialed with " << b << endl;}
};
*/
class badGuy
{
    public:
        virtual void doAttack() = 0; //{ cout << "Base class attack!" << endl;}
};
class Ninja : public badGuy
{
    public:
        void doAttack() {cout << "Ninja attack!" << endl;}
};
class Pirate : public badGuy
{
    public:
        void doAttack() {cout << "Pirate attack!" << endl;}
};
class Outlaw : public badGuy
{
    public:
        void doAttack() {cout << "Outlaw attack!" << endl;}
};
int main()
{
    int count = 0;
    badGuy* list[10];
    list[count++] = new Ninja();
    list[count++] = new Ninja();
    list[count++] = new Pirate();
    list[count++] = new Ninja();
    list[count++] = new Outlaw();
    list[count++] = new Pirate();
    list[count++] = new Pirate();
    list[count++] = new Ninja();
    list[count++] = new Outlaw();
    list[count++] = new Ninja();

    for (int i = 0; i <10; i++)
    {
        list[i]->doAttack();
    }
    // badGuy bad;

    // badGuy* b1 = &n;
    // badGuy* b2 = &p;
    // // badGuy* b3 = &bad;

    // b1->doAttack();
    // b2->doAttack();
    // // b3->doAttack();

    //B b1(3);
    // A* a = new D();
    // a->eat();
}