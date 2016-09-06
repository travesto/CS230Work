#include <iostream>
#include "IntegerQueue.h"

IntegerQueue::IntegerQueue() //makes a queue
{
    head = 0; 
    tail = 0; 
    qsize = 2; 
    data = new int[qsize];
}
IntegerQueue::~IntegerQueue() //destructs the queue
{
    delete [] data; 
    data = NULL;
}
bool IntegerQueue::empty() //sees if queue is empty
{
   return (tail == head);
}
int IntegerQueue::size() //number of elements in queue
{
    if (tail < head)
    {
        return tail + (qsize - head);
    }
    else 
         return (tail - head);
}
void IntegerQueue::push(int enqueue) //enqueue
{
    if (size() == qsize - 1) //resize queue
    {
        int* temp = new int[qsize*2];
        for (int i = 0; i < qsize; i++)
        {
            temp[i] = data[((head+i) % qsize)];
        }
        delete [] data;
        data = temp;
        tail = size();
        head = 0;
        qsize *= 2;
    }
    data[tail] = enqueue;
    tail = (tail + 1) % qsize;
}
int IntegerQueue::pop() //dequeue
{
    int popped;
    popped = data[head];
    head = (head+1) % qsize;
    return popped;
}
