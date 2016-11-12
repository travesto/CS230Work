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
            uses = 1;
            items = new T [n];
            for (int i = 0; i < cardinality; i++)
            {
                items[i] = 0;
            }
            
        }
        TupleData(T* list, int n) //creates tuple with elements from list
        {
            cardinality = n;
            uses = 1;
            items = new T [n];
            for (int i = 0; i < cardinality; i++)
            {
                items[i] = list[i];
            }
        }
        TupleData(const TupleData& other) //copy ctor
        {
            this->cardinality = other.cardinality;
            this->uses = 1;
            items = new T [cardinality];
            for (int i = 0; i < cardinality; i++)
            {
                items[i] = other.items[i];
            }
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
        Tuple(const Tuple<T>& copy) //ctor
        {
            data = copy.data;
            data->incrementUse();
        }
        ~Tuple()
        {
            data->decrementUse();
        }
        //data access and manip funcs
        int size()const { return data->size();}
        int useCount()const { return data->useCount();}
        T magnitude() const//euclidean norm
        {
            double mag = 0;
            for (int i = 0; i < data->size(); i++)
            {
                mag += pow((*data)[i], 2);
            }
            return (T)std::sqrt(mag);
        }
        //assignment operator overload
        Tuple<T>& operator=(const Tuple<T>& b) 
        { 
            if (this == &b)
            {
                return *this;
            }
            for (int i = 0; i < (this->size() >= b.size() ? this->size() : b.size()); i++)
            {
                (*this)[i] = b[i];
            }
            this->data->decrementUse();//dec a 
            b.data->incrementUse();//inc b
            this->data = b.data;
            return (*this);
        }
        bool operator==(const Tuple& other) const
        {
            int tamano = size()>other.size() ? size() : other.size();
            for (int i=0; i<tamano; i++)
            {    
                if ((*this)[i] != other[i])
                {
                    return false;
                }
            }
            return true;
        }
        bool operator!=(const Tuple<T>& other) const //not equal
        {
            return !((*this) == other);
        }
        T& operator[](int i) 
        { 
            if (data->useCount() > 1)
            {
                TupleData<T>* dota2 = new TupleData<T>(*data);
                data->decrementUse();
                this->data = dota2;
            }
            if (i < data->size() && i >= 0)
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
            if (i < data->size() && i >= 0)
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
T operator*(const Tuple<T>& a, const Tuple<T>& b) //dot prod
{
    T dotProduct = 0;
    for (int i = 0; i < (a.size() >= b.size() ? a.size() : b.size()); i++)
    {
        dotProduct += a[i] * b[i];
    }
    return dotProduct;
}
template<class T>
Tuple<T> operator*(T x, const Tuple<T>& a)
{
    Tuple<T> scalarProd = Tuple<T>(a.size());
    for (int i = 0; i < a.size; i++)
    {
        scalarProd[i] = a[i]*x;
    }
    return scalarProd;
}
template<class T>
Tuple<T> operator*(const Tuple<T>& a, T x)
{
    Tuple<T> scalarProd = Tuple<T>(a.size());
    for (int i = 0; i < a.size(); i++)
    {
        scalarProd[i] = a[i]*x;
    }
    return scalarProd;
}
template<class T>
Tuple<T>& operator*=(Tuple<T>& a, T x)
{
    for (int i = 0; i < a.size(); i++)
    {
        a[i] = a[i]*x;
    }
    return a;
}
