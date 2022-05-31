#ifndef VECTOR_H
#define VECTOR_H
#include "arraysequence.h"
#include <cmath>
#include "complex.h"
#include <complex>
#include <iostream>
Complex sqrt(Complex  &comp);
template <class T> class Vector
{
private:
    ArraySequence<T> *seq;
public:
    Vector();
    Vector(int size);
    Vector(T* arr,int count);
    Vector(Vector& v2);
    void Append(T item);
    T Get(int index);
    T& operator[](int index);
    Vector* Sum_vectors(Vector& v2);
    Vector* Minus_vectors(Vector& v2);
    Vector&  Multiply_on_scalar(int scalar);
    T Norm();
    T Dot_product(Vector& v2);
    void Print_vector();
    int Get_Length();
    Vector& operator+=(Vector& v2);
    Vector& operator+(Vector& v2);
    Vector& operator-(Vector& v2);
    Vector& operator-=(Vector& v2);

};

template <class T>
Vector<T>::Vector()
{
    seq=new ArraySequence<T>();
}
template <class T>
Vector<T>::Vector(int size)
{
    seq=new ArraySequence<T>(size);
}
template <class T>
Vector<T>::Vector(T* arr,int count)
{
    seq=new ArraySequence<T>(arr,count);
}
template <class T>
Vector<T>::Vector(Vector& v2)
{
    seq=new ArraySequence<T>((*v2.seq));
}
template <class T>
int Vector <T>::Get_Length()
{
    return seq->Get_Length();
}

template <class T>
T Vector<T>::Get(int index) {
    return seq->Get(index);
}
template <class T>
void Vector<T>::Append(T item)
{
    this->seq->Append(item);
}
template <class T>
T& Vector<T>::operator[](int index)
{
    try {
        return (this->seq)[index];
    }
    catch(Myexception ex)
    {
        throw ex;
    }
}
template <class T>
Vector<T>& Vector<T>::operator+=(Vector& v2)
{

    this->seq=this->Sum_vectors(v2)->seq;
    return *this;
}
template <class T>
Vector<T>& Vector<T>::operator-(Vector& v2)
{
    this->seq=this->Minus_vectors(v2)->seq;
    return *this;
}
template <class T>
Vector<T>& Vector<T>::operator-=(Vector& v2)
{
    this->seq=this->Minus_vectors(v2)->seq;
    return *this;
}
template <class T>
Vector<T> & Vector<T>::operator+(Vector& v2)
{
    this->seq=this->Sum_vectors(v2)->seq;
    return *this;
}


template <class T>
Vector<T>* Vector<T>::Sum_vectors(Vector& v2)
{
    int mx=max(v2.seq->Get_Length(),this->seq->Get_Length());
    Vector<T> *res=new Vector<T>();
    if (v2.seq->Get_Length()>this->seq->Get_Length())
    {
        for (int i=0;i<v2.seq->Get_Length();i++)
            if (i<this->seq->Get_Length())
                res->Append(v2.seq->Get(i)+this->seq->Get(i));
             else
                res->Append(v2.seq->Get(i));

    }
    else
    {
        for (int i=0;i<this->seq->Get_Length();i++)
            if (i<v2.seq->Get_Length())
                res->Append(this->seq->Get(i)+v2.seq->Get(i));
            else
                res->Append(this->seq->Get(i));
    }
    return res;
}
template <class T>
Vector<T>* Vector<T>::Minus_vectors(Vector& v2)
{
    int mx=max(v2.seq->Get_Length(),this->seq->Get_Length());
    Vector<T> *res=new Vector<T>();
    if (v2.seq->Get_Length()>this->seq->Get_Length())
    {
        for (int i=0;i<v2.seq->Get_Length();i++)
            if (i<this->seq->Get_Length())
                res->Append(this->seq->Get(i)-v2.seq->Get(i));
            else
                res->Append((-1)*v2.seq->Get(i));

    }
    else
    {
        for (int i=0;i<this->seq->Get_Length();i++)
            if (i<v2.seq->Get_Length())
                res->Append(this->seq->Get(i)-v2.seq->Get(i));
            else
                res->Append(this->seq->Get(i));
    }
    return res;
}
template <class T>
Vector<T>& Vector<T>::Multiply_on_scalar(int scalar)
{
    Vector<T> res= Vector<T>();
    for (int i=0;i< this->seq->Get_Length();i++)
        res.Append(this->Get(i)*scalar);
    return res;
}

template<class T>
T Vector<T>::Norm(){
  T sm;
  sm=0;
  for (int i=0;i< this->seq->Get_Length();i++)
  {
      sm+=this->Get(i)*this->Get(i);
  }
  return sqrt(sm);
}
template<class T>
T Vector<T>::Dot_product(Vector& v2){
    T sm=0;

    try {
        if (v2.seq->Get_Length() > this->seq->Get_Length()) {
            for (int i = 0; i < this->seq->Get_Length(); i++)
                sm += this->Get(i) * v2.Get(i);
        }
        else {
            for (int i = 0; i < v2.seq->Get_Length(); i++) {

                sm += this->Get(i) * v2.Get(i);

            }
        }
        return sm;
    }
    catch(Myexception Ex)
    {
        Ex.show();
    }
}
template <class T>
void Vector<T>::Print_vector()
{
    for (int i=0;i<this->seq->Get_Length();i++)
        cout<< this->seq->Get(i)<<" ";
    cout<<endl;
}
#endif //VECTOR_H