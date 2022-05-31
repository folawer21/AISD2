

#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H
#include <iostream>
using namespace std;
template <class T> class DynamicArray
{
private:
    int a_size;
    int a_capacity;
    T * a_data;
public :
    DynamicArray(T* items,int count)
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
    DynamicArray(const DynamicArray<T> & a)
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
    DynamicArray(int size)
    {
        a_size=size;
        a_capacity=size;
        if (size!=0)
            a_data=new T[size];
        else
            a_data=0;
    }
    ~DynamicArray()
    {
        if (a_data)
            delete[] a_data;
    }
public:
    int GetSize() const
    {
        return a_size;
    }
    int GetCapacity() const
    {
        return a_capacity;
    }

    T Get(int index)
    {
        if (index>a_size-1)
            cout << ("Тут будет нормальная обработка ошибки");
        return a_data[index];
    }

    void Set(int index, T value)
    {
        a_data[index]=value;
    }

    void resize(int size)
    {
        if (size > a_capacity)
        {
            int new_capacity = max (size, a_size*2);
            T * new_data=new T[new_capacity];
            for (int i = 0; i< a_size;i++)
                new_data[i]=a_data[i];
            delete [] a_data;
            a_data=new_data;
            a_capacity=new_capacity;
        }
        if (size< a_size)
        {
            int new_capacity = max (size*2, a_size);
            T * new_data= new T[new_capacity];
            for (int i=0;i<size;i++)
            {
                new_data[i]=a_data[i];
            }
            delete[] a_data;
            a_data=new_data;
            a_capacity=new_capacity;

        }
        a_size=size;
    }
    void push_back(T val)
    {
        resize(a_size+1);
        a_data[a_size-1]=val;
    }

};
template<typename T>
ostream & operator << (ostream & out, DynamicArray<T> a)
{
    for (int i = 0; i < a.GetSize(); ++i)
        out << a.Get(i) << " ";
    return out;
}

#endif DYNAMICARRAY_H
