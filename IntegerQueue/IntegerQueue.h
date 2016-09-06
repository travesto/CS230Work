#include <iostream>

class IntegerQueue //dynamic integer queue
{
    public:
        IntegerQueue();
        ~IntegerQueue();
        int size(); //returns num elements in queue
        bool empty(); //checks if q is empty
        void push(int enqueue); //adds to q
        int pop(); //takes from q

    private:
        int head;
        int tail;
        int qsize; //size of array
        int* data;   //array for queue
};
