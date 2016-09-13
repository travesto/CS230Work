#include "IntegerQueue.cpp"
#include <cassert>

int main()
{
    IntegerQueue q;
    q.push(7);
    q.push(5);
    q = q;
    int x = q.pop();
    assert(x==7);
}