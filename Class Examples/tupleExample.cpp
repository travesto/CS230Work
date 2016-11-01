#include <iostream>
using namespace std;

#define DEBUG 1

template <class T>
class TupleData
{
    public:
        TupleData(int n);
        TupleData(const T* list, int n);
        TupleData(const TupleData& other); //copy ctor
        ~TupleData();

        int size() const { return cardinality;}
        int useCount() const { return uses;}
        void incrementUse() {uses++;}
        void decrementUse() {uses--;}

        T& operator[](int i) { return items[i];}
        const T& operator[](int i) const { return items[i];}

    private:
        T* createCopy(int nSize, const T* other) const;
        int uses;
        int cardinality;
        T* items;
};
template <class T>
class Tuple 
{
    public:
        //ctor
        
        //data access and manip funcs
        
        #ifdef DEBUG
        TupleData<T>& implementation() const { return *data;}
        #endif
    private:
        TupleData<T>* data;
}
int main()
