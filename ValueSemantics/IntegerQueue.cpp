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
    if (this->data != q.data) //check if queue is being assigned to itself (ie r = r)
    {
        //assign this memebers with q's values
        this->head=q.head; 
        this->tail=q.tail;
        this->qsize=q.qsize;
        delete [] this->data; //delete this->data incase there is dynam. data in previous q
        this->data=new int [qsize]; //create new array qsize
        for (int i=0; i < size(); i++) //copy data from q to this
        {
            data[i] = q.data[i]; 
        }
        return *this; //return deep copied q
    }
    else //if assigning q to itself, just return q
    {
        return *this;
    }
}
std::ostream& operator<<(std::ostream& cout, const IntegerQueue& q) //queue output
{
    if (!q.empty()) //check if queue is empty
    {
        IntegerQueue outq(q); //create copy of orig queue
        cout << "{";
        while (outq.size() > 1) //pop new queue in order
        {
            cout << outq.pop() << ",";
        }
        cout << outq.pop() << "}";
        return cout;   //must return something since not void
    }
    else //if empty cout brackets only
    {
        cout << "{}";
        return cout;
    }  
}
