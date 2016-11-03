#include <iostream>
#include <string>

using namespace std;
//operator overloading
struct vec
{
    int x;
    int y;
};
int operator+(vec v1, vec v2)
{
    return v1.x + v2.x;
}
int main()
{
    vec v1;
    vec v2;
    v1.x = 1; v1.y=2;
    v2.x=3; v2.y=4;

    //int x = v1.x+v2.x;
    int y = operator+(v1,v2);
    int x = v1 +v2;
    cout << x+y << endl;
}

// class Cow
// {
//     public:
//         Cow() {mooCount = 0;}
//         void moo() {cout << mooCount++ << endl;}
//         void milk() const {cout << "Have some milk, yo." << endl;}
//         void tip() const {cout << "moooooooooooooooooooooo!" << endl;}
//         int get_mooCount() const {return mooCount;}

//     private:
//         int mooCount;    
// };

// int main()
// {
//     Cow* c = new Cow();
//     const Cow* const c2 = c;

//     c->moo();
//     c2->moo();
//     cout << c->get_mooCount() << endl;
//     cout << c2->get_mooCount() << endl;
    
//     // Cow c;
//     // c.moo();
//     // c.milk();
//     // c.tip();
//     // cout << c.get_mooCount() << endl;
// }