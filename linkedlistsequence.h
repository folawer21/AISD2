#ifndef LINKEDLISTSEQUENCE_H
#define LINKEDLISTSEQUENCE_H
#include <iostream>
#include "sequence.h"
#include "linkedlist.h"
#include "myexception.h"
using namespace std;

template <class T> class ListSequence: public Sequence <T>
{
private:
    list<T> * a_list;
public:

    ListSequence();
    ListSequence(int count);
    ListSequence(T *items,int count);
    ListSequence(const list <T> &list );
public:
    int Get_Length() override;
    T GetFirst() override;
    T GetLast() override;
    T Get(int index) override;
    Sequence<T>* GetSubsequence(int startindex,int endindex ) override;
    void InsertAt(T item,int index) override;
    void Append(T item) override;
    void Prepend(T item) override;
    T& operator[](int index)override;
    Sequence <T> * Concat(Sequence <T> * list)override;

};
template <class T>
T& ListSequence<T>::operator[](int index)
{
    if (index<0 || index>a_list->getCount()){
        Myexception(1).show();
    }
    else {
        return (*a_list)[index];
    }
}
template<typename T>
ostream & operator << (ostream & out, ListSequence<T> a)
{
    for (int i = 0; i < a.Get_Length(); ++i)
        out << a.Get(i) << " ";
    return out;
}
template<class T>
ListSequence<T>::ListSequence(int count)
{
    a_list=new list<T> (count);

}template<class T>
ListSequence<T>::ListSequence()
{
    a_list=new list<T> (0);

}

template<class T>
ListSequence<T>::ListSequence(T *items,int count)
{
    a_list=new list<T>(items,count);

}
template<class T>
ListSequence<T>::ListSequence(const list <T> &list1 )
{
    a_list=new list <T>(list1);

}
template<class T>
int ListSequence<T>::Get_Length()
{
    return a_list->getCount();
}

template<class T>
T ListSequence<T>::GetFirst()
{
    if (a_list->getCount()>0)
        return a_list->Get(0);
}

template <class T>
T ListSequence<T>::GetLast()
{
    if (a_list->getCount()>0)
        return a_list->Get(a_list->getCount()-1);
}
template <class T>
T ListSequence<T>::Get(int index)
{

    try {
        T a=a_list->Get(index);
        return a;
    }
    catch(Myexception ex)
    {
      ex.show();
        //throw ex;
    }
}
template <class T>
Sequence <T>* ListSequence<T>::GetSubsequence(int startindex,int endindex )
{
    auto* res= new ListSequence<T>(a_list->GetSubList(startindex,endindex));
    return res;


}
template <class T>
void ListSequence<T>::InsertAt(T item,int index)
{
    try {a_list->Insert_at(index,item);}
    catch(Myexception &ex)
    {
        throw ex;
    }


}
template <class T>
void ListSequence<T>::Append(T item)
{
    try {InsertAt(item,a_list->getCount());}
    catch(Myexception ex)
    {
        ex.show();
    };
}

template <class T>
void ListSequence<T>::Prepend(T item)
{
    try {InsertAt(item,0);}
    catch(Myexception ex)
    {
        ex.show();
    };
}

template <class T>
Sequence <T>* ListSequence<T>::Concat(Sequence<T> * list)
{
    if (list==NULL)
    {
        Myexception(2).show();

    }
    else {
        try {
            auto *resultList = new ListSequence<T>;
            *(resultList->a_list) = *(a_list);

            for (int i = 0; i < list->Get_Length(); i++) {
                resultList->Append(list->Get(i));
            }
            return resultList;
        }
        catch (Myexception ex) {
            ex.show();

        }
    }
}

#endif //LINKEDLISTSEQUENCE_H
