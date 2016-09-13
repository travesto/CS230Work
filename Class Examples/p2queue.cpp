#include <cstddef>
#include <iostream>
using namespace std;
template <class T>
struct Queue {
    T*  data;	// array of values
    int size;	// size of array	    
    int head;	// index of head value
    int tail;	// 1 + index of tail value
};

template <class T>
void initialize(Queue<T> &q)
{
    q.data = new T[2];
    q.size = 2;
    q.head = 0;
    q.tail = 0;
}
template <class T>
void destroy(Queue<T> &q)
{
    q.tail = 0;
    q.head = 0;
    delete [] q.data;
    q.data = NULL;
}
template <class T>
int  getSize(Queue<T> q)
{
    if (q.tail < q.head)
    {
        return q.tail + (q.size - q.head);
    }
    else 
         return q.tail - q.head;
}
template <class T>
bool isEmpty(Queue<T> q)
{
    if (q.head == q.tail)
    {
        return true;
    }
    else
    {
        return false;
    }
}
template <class T>
void push(Queue<T> &q, T blerg)
{
    if (getSize(q) == (q.size-1))
    {
        T* temp = new T [q.size*2];
        for (int a = 0; a < q.size; a++)
        {
            temp[a] = q.data[((q.head + a) % q.size)];
            cout << temp[a] << endl;
        }
        delete [] q.data;
        q.data = temp;
        q.tail = q.size - 1;
        q.size *= 2;        
        temp = NULL;
        q.head = 0;
    }
   
    q.data[q.tail] = blerg;
    q.tail = (q.tail + 1) % q.size;
}
template <class T>
T    pop(Queue<T> &q)
{
    T a;
    a = q.data[q.head];
    q.head = (q.head + 1) % q.size;
    return a;
}