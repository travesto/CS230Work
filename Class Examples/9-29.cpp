#include <iostream>
#include <string>
using namespace std;

class Example
{
    private:
        static int statval;
    public:
        Example() {statval = 1;}
        static int getval() {return statval;}
};

int Example::statval = 1;

int main()
{
    Example e;
    e.getval();
}