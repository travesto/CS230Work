/*
//////////////Regular INHERITANCE///////////////////
#include <iostream>

class badGuy
{
    protected:
        int attack;
    public:
        void setAttack(int p) {attack = p;}
};
class Ninja : public badGuy
{
    public:
        void doAttack() {cout << "Ninja star attack for " << attack << " DMG" << endl;}
};
class Pirate : public badGuy
{
    public:
        doAttack() {cout << "Pirate gun attack for " << attack << " DMG" << endl;}
};

int main()
{
    Ninja n;
    Pirate p;

    badGuy* b1 = &n;
    badGuy* b2 = &p;

    b1->setAttack(10);
    b2->setAttack(9001);

    n.doAttack();
    p.doAttack();
}
*/
///////////////MULTIPLE INHERITANCE///////////////////
#include <iostream>
#include <string>
using namespace std;

class File
{
    public:
        string name;
        void open() {cout << "File opened" << endl;}
};
class InputFile : virtual public File //VIRTUAL INHERITANCE
{
    public:
        InputFile(string fname) : File(fname) {}
};
class OutputFile : virtual public File
{
    public:
        OutputFile(string fname) : File(fname) {}
};
class IOFile : public InputFile, public OutputFile
{
    public:
        IOFile(string fname) : OutputFile(fname), InputFile(fname), File {};
};

int main()
{
    IOFile f("input.txt");
}