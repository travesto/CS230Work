#include <iostream>
#include <string>
using namespace std;

class Father
{
    private:
        string job;
        int bank_accout;
    protected:
        string fname();
        int age;
    public:
        Father();
        ~Father();
        Father(string f_n) {fname = f_n;}
        void family_name();
};
class Son : public Father
{
    public:
        Son(string f_n) : Father(f_n) {};
        ~Son();
        void tell_all();
    private:
        string school;
};
void Father::family_name()
{
    cout << "Our family name is: Jones" << endl;
}
void Son::tell_all()
{
    cout << "Age = " << age << endl;
    cout << "School = " << school << endl;
    // cout << "Job = " << job << endl;
}
Father::Father() {cout << "Father constructor" << endl;}
Father::~Father() {cout << "Father descontructor" << endl;}
Son::Son() {cout << "Son constructor"<< endl;}
Son::~Son() {cout << "Son descontructor"<< endl;}
int main()
{
    Father f;
    f.family_name();

    Son s;
    s.family_name();
    // s.tell_all();
}
