#include <iostream>

class IntegerQueue //dynamic integer queue
{
    public:
        IntegerQueue();
        ~IntegerQueue();
        IntegerQueue(const IntegerQueue &q); //copy constructor
        int size() const; //returns num elements in queue
        bool empty() const; //checks if q is empty
        void push(int enqueue); //adds to q
        int pop(); //takes from q
        const IntegerQueue& operator=(const IntegerQueue &);
    
    private:
        int head;
        int tail;
        int qsize; //size of array
        int* data;   //array for queue
};

std::ostream& operator<<(std::ostream& cout, const IntegerQueue& q); //queue output
