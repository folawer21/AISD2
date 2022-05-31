#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
#include "myexception.h"
using namespace std;

template <class T> class list
{
private:
    class node
    {
        friend class list<T>;
    private:
        node *next;
        T val;

        node(): next(NULL){};
        ~node(){}
    };

    node *head;
    int count;
public:
//    list(): head(NULL), count(0){};
    list();
    list(int k);
    list(T* items,int k);
    list(const list <T> & prevlist );
    ~list();

public:
    int getCount() const;
    T Get(int index) const;
    T GetFirst();
    T GetLast();
    list <T> GetSubList(int startindex,int endindex);
public:
    void Append(T data);
    void Prepend(T data);
    void Insert_at(int index,T data);
    list <T>* Concat(list <T> prev);
    void del(int x);
    void del(node* pointer);
    void clear();
    T& operator[](int index);


};
template <class T>
list<T>::list()
{
    head=NULL;
    count=0;
}

template <class T>
list<T>::list(int k)
{
    head=NULL;
    count=k;
}
template <class T>
list<T>::list(T* items,int k)
{
    list<T> list;
    head=NULL;
    count=0;

    for (int i=0;i<k;i++)
    {
        node *to_add = new node();//()
        to_add->next=NULL;
        to_add->val=items[i];
        if(head==NULL)
            head=to_add;
        else
        {
            node *current;
            for(current=head;current->next!=NULL;current=current->next); //NULL or 0
            current->next=to_add;
        }
        count++;
    }
}
template <class T>
T& list<T>::operator[](int index)
{
    if (index < 0 || index >= count){
        throw Myexception(1);
    }
    else {
        node *current = head;

        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        return current->val;
    }
}

template <class T>
list<T>::list(const list <T> & prevlist )
{
    node* new_head=new node();
    new_head->val=prevlist.head->val;
    head=new_head;
    count=prevlist.getCount();
    for (int i=1;i<prevlist.getCount();i++)
    {
        node *to_add = new node();//()
        to_add->next=NULL;
        to_add->val=prevlist.Get(i);
        node *current;
        for(current=head;current->next!=NULL;current=current->next); //NULL or 0
        current->next=to_add;

    }
}
template <class T>
list<T>::~list()
{
    clear();
}
template <class T>
int list<T>::getCount() const
{
    return count;
}
template <class T>
T list<T>::Get(int index) const
{
    if (index<0 || index > count)
        throw Myexception(1);
    node *current=head;
    for(int i=0;index>i;i++)
        current=current->next;
    return current->val;
}
template <class T>
T list<T>::GetFirst()
{
    if (count==0)
        throw Myexception(1);
    if (count>0)
        return head->val;
}
template <class T>
T list<T>::GetLast()
{
    {
        if (count==0)
            throw Myexception(1);
        if (count>0)
            return Get(count-1);
    }
}
template <class T>
list <T> list<T>::GetSubList(int startindex,int endindex)
{
    if (startindex<0 || endindex <startindex || endindex>count){
        Myexception ex = Myexception(1);
        ex.show();
        throw ex;
    }
    try {


        list res = list();
        res.count = 0;
        if (startindex < count && endindex < count) {
            for (int i = startindex; i <= endindex; i++) {
                res.Append(this->Get(i));
            }
        }
        return res;
    }
    catch (Myexception ex){
        ex.show();
        throw ex;
    }
}
template <class T>
void list<T>::Append(T data)
{
    node *to_add = new node();//()
    to_add->next=NULL;
    to_add->val=data;
    if(count==0)
        head=to_add;
    else
    {
        node *current;
        for(current=head;current->next!=NULL;current=current->next); //NULL or 0
        current->next=to_add;
    }
    count++;
}
template <class T>
void list<T>::Prepend(T data)
{
    node *to_add = new node();
    to_add->next=nullptr;
    to_add->val=data;
    if (count==0)
    {
        head=to_add;
    }
    else
    {
        to_add->next=head;
        head=to_add;
    }
    count++;
}

template <class T>
void list<T>::Insert_at(int index,T data)
{
    if (index<0 || index >count)
    {
        throw Myexception(1);

    }
    if (index==0){Prepend(data);}
    else if (index==count){Append(data);}
    else
    {
        node *cur=head;
        node *to_add=new node();
        to_add->val=data;
        for (int i=0;i<index-1;i++) cur=cur->next;
        node *tmp=cur->next;
        cur->next=to_add;
        to_add->next=tmp;
        count++;
    }

}

template <class T>
list <T>* list<T>::Concat(list<T> prev)
{

    auto* result = new list<T>;
    *result = *this;
    for (int i = 0; i < prev.getCount(); i++)
        result->Append(prev[i]);
    return result;
}
template <class T>
void list<T>::del(int index){
    if (index>count || index<0)
    {
        Myexception(1).show();
    }
    node *to_del=head;
    if (index==0)
    {
        head=head->next;
        delete to_del;
    }
    else
    {
        node *current=head;
        for(int i=0;i<index-1;i++)
            current=current->next;
        to_del=current->next;
        current->next=current->next->next;
        delete to_del;
    }
    count--;

}
template<class T>
void list<T>::del(node* pointer)
{
    if (pointer->next->next!=nullptr) {
        pointer->val = pointer->next->val;
        node *tmp = pointer->next;
        pointer->next = pointer->next->next;
        delete tmp;
        count--;
    }
    else {
        del(this->count-1);
    }
}
template <class T>
void list<T>::clear()
{
    node *current = head;
    node *to_del = head;
    while(to_del!=NULL)
    {

        current=current->next;
        delete to_del;
        to_del=current;
    }
    head=NULL;
    count=0;
}

#endif //LINKEDLIST_H

