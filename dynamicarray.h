
#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H
#include <iostream>
#include "myexception.h"
#include "sequence.h"
using namespace std;
template <class T> class DynamicArray
{
private:
    int a_size;
    int a_capacity;
    T * a_data;
public :
    DynamicArray(T* items,int count);
    DynamicArray(const DynamicArray<T> & a);
    DynamicArray(int size);
    ~DynamicArray();
public:
    int GetSize() const ;
    int GetCapacity() const;
    T Get(int index);

    void Set(int index, T value);
    void resize(int size);
    void push_back(T val);
    T& operator[](int index);

};
template<typename T>
ostream & operator << (ostream & out, DynamicArray<T> a)
{
    for (int i = 0; i < a.GetSize(); ++i)
        out << a.Get(i) << " ";
    return out;
}

template <class T>
DynamicArray<T>::DynamicArray(T* items,int count)
{
    {
        a_size=count;
        a_capacity=count;
        a_data=new T[a_size];
        for (int i=0;i<a_size;i++)
        {
            a_data[i]=items[i];

        }
        //delete [] (items);
    }
}
template <class T>
DynamicArray<T>::DynamicArray(const DynamicArray<T> & a)
{
    a_size=a.a_size;
    a_capacity=a.a_capacity;
    a_data=NULL;
    if (a_size!=0)
        a_data=new T[a_size];
    else
        a_data=0;
    for (int i=0; i< a_size; ++i)
        a_data[i]=a.a_data[i];
}
template <class T>
DynamicArray<T>::DynamicArray(int size)
{
    a_size=size;
    a_capacity=size;
    if (size!=0)
        a_data=new T[size];
    else
        a_data=0;
}

template <class T>
DynamicArray<T>::~DynamicArray()
{
    if (a_data)
        delete[] a_data;
}

template <class T>
int DynamicArray<T>::GetSize() const
{
    return a_size;
}
template <class T>
int DynamicArray<T>::GetCapacity() const
{
    return a_capacity;
}
template <class T>
T DynamicArray<T>::Get(int index)
{
    if (index>a_size-1 || index<0)
    {
        throw Myexception(1);
    }
    return a_data[index];
}
template <class T>
void DynamicArray<T>::Set(int index, T value)
{
    if (index>a_size-1 || index<0)
        throw Myexception(1);
    a_data[index]=value;
}
template <class T>
T& DynamicArray<T>::operator[](int index)
{
    if (index>a_size-1 || index<0)
        throw Myexception(1);
    return a_data[index];
}
template <class T>
void DynamicArray<T>::resize(int size)
{

    if (size<0)
        throw Myexception(3);
    if (size > a_capacity)
    {
        int new_capacity = max (size, a_size*2);
        T * new_data=new T[new_capacity];
        for (int i = 0; i< a_size;i++)
            new_data[i]=a_data[i];
        //delete [] a_data;
        a_data=new_data;
        a_capacity=new_capacity;
    }
    else {
        if (size < a_size) {
            for (int i = size; i < a_size; i++) {
                a_data[i]=0;
            }
        }

    }
    a_size = size;
}
template <class T>
void DynamicArray<T>::push_back(T val)
{
    try {
        resize(a_size + 1);
        a_data[a_size - 1] = val;
    }
    catch (Myexception ex)
    {
        ex.show();
    }
}
#endif //DYNAMICARRAY_H
