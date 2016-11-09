#include <iostream>
#include <cmath>

#define DEBUG 1

template <class T>
class TupleData
{
    public:
        TupleData(int n) //creates empty tuple of n size
        {
            cardinality = n;
            T* zero = new T [n];
            for (int i = 0; i < cardinality; i++)
            {
                zero[i] = 0;
            }
            uses = 0;
            incrementUse();
        }
        TupleData(T* list, int n) //creates tuple with elements from list
        {
            cardinality = n;
            items = list;
            uses = 0;
            incrementUse();
        }
        TupleData(const TupleData& other) //copy ctor
        {
            items = other.items;
            cardinality = other.cardinality;
            uses = other.uses;
            incrementUse();
        }
        ~TupleData()
        {
            delete [] items;
        }

        int size() const { return cardinality;}
        int useCount() const { return uses;}
        void incrementUse() {uses++;}
        void decrementUse() 
        {
            uses--;
            if (uses == 0)
            {
                delete this;
            }
        }

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
        Tuple(int n)
        {
            data = new TupleData<T>(n);   
        }
        Tuple(T* list, int n)
        {
            data = new TupleData<T>(list, n);
        }
        ~Tuple()
        {
            data = NULL;
        }
        //data access and manip funcs
        int size()const { return data->size();}
        int useCount() { return data->useCount();}
        T magnitude() const//euclidean norm
        {
            T mag = 0;
            for (int i = 0; i < data->size(); i++)
            {
                mag += (T)(pow((*data)[i], 2.0));
            }
            return (T)(sqrt(mag));
        }
        //assignment operator overload
        Tuple<T>& operator=(const Tuple<T>& b) 
        { 
            for (int i = 0; i < (this->size() >= b.size() ? this->size() : b.size()); i++)
            {
                (*this)[i] = b[i];
            }
            data->decrementUse();//dec a 
            b.data->incrementUse();//inc b
            data = b.data;
            return (*this);
        }

        T& operator[](int i) 
        { 
            if (i <= size() && i >= 0)
            {
                return (*data)[i];
            }
            else 
            { 
                static T dummy;
                dummy = 0;
                return dummy;    
            }
        }
        const T& operator[](int i) const
        { 
            if (i <= size() && i >= 0)
            {
                return (*data)[i];
            }
            else
            {
                static T dummy;
                dummy = 0;
                return dummy;
            }
        }
        #ifdef DEBUG
        TupleData<T>& implementation() const { return *data;}
        #endif
    private:
        TupleData<T>* data;
};
//overloaded math operators
template<class T> 
Tuple<T> operator+(const Tuple<T>& a, const Tuple<T>& b) //add
{
    Tuple<T> tupleSum = Tuple<T>(a.size() >= b.size() ? a.size() : b.size());
    for (int i = 0; i < (a.size() >= b.size() ? a.size() : b.size()); i++)
    {
        tupleSum[i] = a[i] + b[i];
    }
    return tupleSum;
}
template<class T> 
Tuple<T>& operator+=(Tuple<T>& a, const Tuple<T>& b) //add
{
    a = a + b;
    return a;
}
template<class T> 
Tuple<T> operator*(const Tuple<T>& a, const Tuple<T>&b) //dot prod
{
    T dotProduct = 0;
    for (int i = 0; i < (a.size() >= b.size() ? a.size() : b.size()); i++)
    {
        dotProduct += a[i] * b[i];
    }
    return dotProduct;
}
template<class T>
Tuple<T> operator*(double x, const Tuple<T>&a)
{
    Tuple<T> scalarProd = Tuple<T>(a.size());
    for (int i = 0; i < a.size; i++)
    {
        scalarProd[i] = a[i]*x;
    }
    return scalarProd;
}
template<class T>
Tuple<T> operator*(const Tuple<T>&a, double x)
{
    Tuple<T> scalarProd = Tuple<T>(a.size());
    for (int i = 0; i < a.size; i++)
    {
        scalarProd[i] = a[i]*x;
    }
    return scalarProd;
}
template<class T>
Tuple<T>& operator*=(Tuple<T>&a, double x)
{
    for (int i = 0; i < a.size; i++)
    {
        a[i] = a[i]*x;
    }
    return a;
}
template<class T>
bool operator==(const Tuple<T>& a, const Tuple<T>&b) //equivalence
{
    bool equal = false;
    if (a.size() == b.size())
    {
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] == b[i])
            {
                equal = true;
            }
        }
    }
    return equal;
}
template<class T>
bool operator!=(const Tuple<T>& a, const Tuple<T>& b) //not equal
{
    return !(a == b);
}
