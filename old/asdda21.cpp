#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
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
    list()
    {
        head=NULL;
        count=0;
    }
    list(T* items,int k)
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
        //Append(items[i]); Почему нельзя аппенд
    }
    list(const list <T> & prevlist )
    {
        node* new_head=new node();
        new_head->val=prevlist.head->val;
        head=new_head;
        count=prevlist.getCount();
        for (int i=1;i<prevlist.getCount();i++)
        {
            node *to_add = new node();//()
            cout<<prevlist.Get(i);
            to_add->next=NULL;
            to_add->val=prevlist.Get(i);
            node *current;
            for(current=head;current->next!=NULL;current=current->next); //NULL or 0
            current->next=to_add;

        }
    }
    ~list()
    {
        clear();
    }

public:
    int getCount() const
    {
        return count;
    }
    T Get(int index) const
    {
        node *current;
        for(current=head;index>0;index--)
            current=current->next;
        return current->val;
    }
    T GetFirst()
    {
        if (count>0)
            return head->val;
    }
    T GetLast()
    {
        if (count>0)
            return Get(count-1);
    }
    list <T> GetSubList(int startindex,int endindex) //Почему нужен указатель в задании????
    {
        list res=list();
        res.count=0;
        if (startindex < count && endindex< count)
        {
            for (int i=startindex;i<=endindex;i++)
            {
                res.Append(this->Get(i));
            }
        }
        return res;
    }

public:
    void Append(T data)
    {
        node *to_add = new node();//()
        to_add->next=NULL;
        to_add->val=data;
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

    void Prepend(T data)
    {
        node *to_add = new node();//()
        to_add->next=NULL;
        to_add->val=data;
        if(head==NULL) //Если в списке нет элементов
            head=to_add;
        else
        {
            to_add->next=head;
            head=to_add;
        }
        count++;
    }
    void Insert_at(int index,T data)
    {
        node *to_add=new node();
        to_add->val=data;
        node *cur=head;
        for (int i=0;i<index-1;i++) cur=cur->next;
        to_add->next=cur->next;
        cur->next= to_add;
        count++;
    }
    list <T>* Concat(list <T> prev)
    {
        node *cur=head;
        for (int i=0;i<count;i++) cur=cur->next;
        cur->next=prev.head;
        count=count+prev.count;
        return this;
    }

    int del(int x)
    {
        if (x>count) return -1;
        node *to_del=head;
        if (x==1)
        {
            head=head->next;
            delete to_del;
        }
        else
        {
            node *current=head;
            for(int i=1;i<x-1;i++)
                current=current->next;
            to_del=current->next;
            current->next=current->next->next;
            delete to_del;
        }
        count--;
        return 1;
    }

    void clear() //Очистка списка
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


};
template <class T>
list<T>::list()

#endif //LINKEDLIST_H


