#include"ListSequencetests.h"
using namespace std;

void ListSequence_from_array_test()
{
    int items[5]={123,312,412,45,12};
    ListSequence <int>* seq = new ListSequence(items,5);
    for (int i=0;i<5;i++)
    {
        assert((*seq)[i]==items[i]);
    }
}
void ListSequence_from_list_test()
{
    int items[5]={123,312,412,45,12};
    list <int>* list1= new list<int>(items,5);
    ListSequence <int>* second=new ListSequence<int>(*list1);
    for (int i=0;i<5;i++)
    {
        assert((*list1)[i]==(*second)[i]);
    }
}

void ListSequence_Prepend_test()
{
    int items[5]={123,312,412,45,12};
    ListSequence <int> *seq=new ListSequence<int>(items,5);
    seq->Prepend(42);
    assert(seq->Get(0)==42);
}
void ListSequence_Append_test()
{
    int items[5]={123,312,412,45,12};
    ListSequence <int> *seq=new ListSequence<int>(items,5);
    seq->Append(42);
    assert(seq->Get(5)==42);
}
void ListSequence_InsertAt_test()
{
    int items[5]={123,312,412,45,12};
    ListSequence <int> *seq=new ListSequence<int>(items,5);
    seq->InsertAt(52,2);
    assert(seq->Get(2)==52);
}

void ListSequence_GetSubSeq_test()
{
    int items[5]={123,312,412,45,12};
    ListSequence <int> *list1=new ListSequence<int>(items,5);
    Sequence <int> *list2=list1->GetSubsequence(1,3);
    for (int i=0;i<3;i++)
    {
        assert((*list1)[i+1]==(*list2)[i]);
    }
}
void ListSequence_Concat_tests()
{
    int items[5]={123,312,412,45,12};
    ListSequence <int>* list= new ListSequence<int>(items,5);
    Sequence<int>* second=new ListSequence <int>();
    second=second->Concat(list);
}
void ListSequence_tests()
{
    ListSequence_from_array_test();
    ListSequence_from_list_test();


    ListSequence_Prepend_test();
    ListSequence_Append_test();
    ListSequence_InsertAt_test();

    ListSequence_GetSubSeq_test();
    ListSequence_Concat_tests();
    cout<<"ListSequence tests successful";
}




