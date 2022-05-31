#ifndef SEQUENCE_H
#define SEQUENCE_H
#include <iostream>
using namespace std;

template <class T> class Sequence
{
public:
    virtual T GetFirst()=0;
    virtual T GetLast()=0;
    virtual T Get(int index)=0;
    virtual Sequence<T> * GetSubsequence(int start_index,int end_index)=0;
    virtual int Get_Length()=0;
public:
    virtual T& operator[](int index) = 0;
    virtual void Append(T item)=0;
    virtual void Prepend(T item)=0;
    virtual void InsertAt(T item,int index)=0;
    virtual Sequence<T>* Concat(Sequence<T>*list)=0;
};
template <class T>
std::ostream& operator<<(std::ostream& out, Sequence<T>* seq)
{
    for (int i = 0; i < seq->Get_Length(); i++)
        out << seq->Get(i) << " ";
    return out;
}
#endif //SEQUENCE_H
