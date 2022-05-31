//
// Created by Александр  Сухинин on 16.04.2022.
//

#ifndef ARRAYSEQUENCE_H
#define ARRAYSEQUENCE_H
#include <iostream>
#include "../sequence.h"
#include "../dynamicarray.h"
using namespace std;

template <class T>class ArraySequence: public Sequence <T>
{
private:
    DynamicArray<T> * a_array;
    int a_size;

public:
    ArraySequence();
    ArraySequence(int count);
    ArraySequence(T *items,int count);
    ArraySequence(const DynamicArray <T> &array );
    ~ArraySequence();
public:
    int Get_Length() override;
    int Get_Capacity();
    T GetFirst() override;
    T GetLast() override;
    T Get(int index) override;
    Sequence<T>* GetSubsequence(int startindex,int endindex ) override ;
    void InsertAt(T item,int index) override;
    void Append(T item) override;
    void Prepend(T item) override;
    Sequence <T> * Concat(Sequence <T> * list)override;

};
template<typename T>
ostream & operator << (ostream & out, ArraySequence<T> a)
{
    for (int i = 0; i < a.Get_Length(); ++i)
        out << a.Get(i) << " ";
    return out;
}
template<class T>
ArraySequence<T>::ArraySequence()
{
    a_array=new DynamicArray<T> (0);
    a_size=0;
}
template<class T>
ArraySequence<T>::ArraySequence(int count)
{
    a_array=new DynamicArray<T> (count);
    a_size=count;
}

template<class T>
ArraySequence<T>::ArraySequence(T *items,int count)
{
    a_array=new DynamicArray<T>(items,count);
    a_size=count;
}
template<class T>
ArraySequence<T>::ArraySequence(const DynamicArray <T> &array )
{
    a_array=new DynamicArray <T>(array);
    a_size=array.GetSize();
}
template<class T>
ArraySequence<T>:: ~ ArraySequence()
{
    delete a_array;
}

template<class T>
int ArraySequence<T>::Get_Length()
{
    return a_array->GetSize();
}
template<class T>
int ArraySequence<T>::Get_Capacity()
{
    return a_array->GetCapacity();
}

template<class T>
T ArraySequence<T>::GetFirst()
{
    if (a_size>0)
        return a_array->Get(0);
}

template <class T>
T ArraySequence<T>::GetLast()
{
    if (a_size>0)
        return a_array->Get(a_size-1);
}
template <class T>
T ArraySequence<T>::Get(int index)
{
    if (index < a_size)
        return a_array->Get(index);
}
template <class T>
Sequence <T>* ArraySequence<T>::GetSubsequence(int startindex,int endindex )
{
    //Проверка ошибки
    DynamicArray<T> buffer(endindex-startindex+1);
    for (int i=startindex;i<=endindex;i++)
    {
        buffer.Get(i-startindex)=(*a_array)[i];
    }
    Sequence<T> subseq=new ArraySequence(buffer,buffer.GetSize());
    return subseq;
}
template <class T>
void ArraySequence<T>::InsertAt(T item,int index)
{
    //OSHIBKA
    if (a_size!=0)
        a_array->resize(a_array->GetSize()*2);
    else
        a_array->resize(a_array->GetSize()+1);//just +1
    a_size++;
    T ptr=(*a_array)[index];
    T tmp;
    for (int i= index+1;i<a_size;i++)
    {
        tmp=(*a_array)[i];
        (*a_array)[i]=ptr;
        ptr=tmp;
    }
    (*a_array)[index]=item;
}
template <class T>
void ArraySequence<T>::Append(T item)
{
    insertAt(item,a_size);
}

template <class T>
void ArraySequence<T>::Prepend(T item)
{
    InsertAt(item,0);
}

template <class T>
Sequence <T>* ArraySequence<T>::Concat(Sequence<T> * list)
{
    //проверка ошибок
    auto* resultArray = new ArraySequence<T>;
    resultArray->a_array=a_array;//*()=*()
    resultArray->a_size= a_size;

    for (int i=0;i<list->GetLength();i++)
    {
        resultArray->Append((*list)[i]);
    }
    return resultArray;
}

#endif //ARRAYSEQUENCE_H
