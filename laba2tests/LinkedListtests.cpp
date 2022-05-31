#include "Linkedlisttest.h"
using namespace std;

void List_from_array_test()
{
    int items[5]={123,312,412,45,12};
    list <int>* list1 = new list(items,5);
    for (int i=0;i<5;i++)
    {
        assert((*list1)[i]==items[i]);
    }
}
void List_from_list_test()
{
    int items[5]={123,312,412,45,12};
    list <int>* list1= new list<int>(items,5);
    list <int>* second=new list<int>(*list1);

    for (int i=0;i<4;i++)
    {
        assert((*list1)[i]==(*second)[i]);
    }
}
void List_Concat_test() {
    int items[5] = {123, 312, 412, 45, 12};
    list<int> *list1 = new list<int>(items, 5);
    list<int> *second = new list<int>(items,5);
    second = second->Concat(*list1);
    for (int i = 0; i < 10; i++)
    {
        if(i<5)
            assert(second->Get(i)==list1->Get(i));
        else
            assert(second->Get(i)==items[i-5]);
    }
}

void List_Prepend_test()
{
    int items[5]={123,312,412,45,12};
    list <int> *list1=new list<int>(items,5);
    list1->Prepend(42);
    assert(list1->Get(0)==42);
}
void List_Append_test()
{
    int items[5]={123,312,412,45,12};
    list <int> *list1=new list<int>(items,5);
    list1->Append(42);
    assert(list1->Get(5)==42);
}
void List_InsertAt_test()
{
    int items[5]={123,312,412,45,12};
    list <int> *list1=new list<int>(items,5);
    list1->Insert_at(2,42);
    assert(list1->Get(2)==42);
}

void List_Del_test()
{
    int items[5]={123,312,412,45,12};
    list <int> *list1=new list<int>(items,5);
    list1->del(2);
    for (int i=0;i<4;i++)
    {
        if (i<2){
            assert((*list1).Get(i)==items[i]);
        }
        else
        {
            assert((*list1).Get(i)==items[i+1]);
        }
    }

}
void List_GetSubList_test()
{
    int items[5]={123,312,412,45,12};
    list <int> *list1=new list<int>(items,5);
    list <int> list2=list1->GetSubList(1,3);
    for (int i=0;i<3;i++)
    {
        assert((*list1)[i+1]==list2[i]);
    }
}
void LinkedList_tests()
{
    List_from_array_test();
    List_from_list_test();
    List_Prepend_test();
    List_Append_test();
    List_InsertAt_test();
    List_Del_test();
    List_GetSubList_test();
    List_Concat_test();
    cout<<"Linkedlist tests successful";
}