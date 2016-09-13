#include <iostream>
#include "IntegerQueue.h"

IntegerQueue::IntegerQueue() //makes a queue
{
    head = 0; 
    tail = 0; 
    qsize = 2; 
    data = new int[qsize];
}
IntegerQueue::IntegerQueue(const IntegerQueue& q) //copy constructor
{
    head = q.head;
    tail = q.tail;
    qsize = q.qsize;
    data = new int [q.qsize];
    for (int i = 0; i < qsize; i++)
    {
        data[i] = q.data[i];
    }
}
IntegerQueue::~IntegerQueue() //destructs the queue
{
    delete [] data; 
    data = NULL;
}
bool IntegerQueue::empty() const //sees if queue is empty
{
   return (tail == head);
}
int IntegerQueue::size() const //number of elements in queue
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
const IntegerQueue& IntegerQueue::operator=(const IntegerQueue& q) //queue assignment
{
    if (this->data != q.data)
    {
        this->head=q.head;
        this->tail=q.tail;
        this->qsize=q.qsize;
        delete [] this->data;
        this->data=new int [qsize];
        for (int i=0; i < size(); i++)
        {
            data[i] = q.data[i]; 
        }
        return *this;
    }
    else
    {
        return *this;
    }
}
std::ostream& operator<<(std::ostream& cout, const IntegerQueue& q) //queue output
{
    if (!q.empty())
    {
        IntegerQueue outq(q); //create copy of orig queue
        cout << "{";
        while (outq.size() > 1) //pop queue in order
        {
            cout << outq.pop() << ",";
        }
        cout << outq.pop() << "}";
        return cout;   
    }
    else
    {
        cout << "{}";
        return cout;
    }
    
}
