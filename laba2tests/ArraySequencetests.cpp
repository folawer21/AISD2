#include"ArraySequencetests.h"
using namespace std;

void ArraySequence_from_array_test()
{
    int items[5]={123,312,412,45,12};
    ArraySequence <int>* array = new ArraySequence(items,5);
    for (int i=0;i<5;i++)
    {
        assert((*array)[i]==items[i]);
    }
}
void ArraySequence_from_Dynamicarray_test() {
    int items[5] = {123, 312, 412, 45, 12};
    DynamicArray<int> *array = new DynamicArray<int>(items, 5);
    ArraySequence<int> *second = new ArraySequence<int>(*array);

    for (int i = 0; i < 4; i++) {
        assert((*array)[i] == (*second)[i]);
    }
}
void ArraySequence_Prepend_test()
{
    int items[5]={123,312,412,45,12};
    ArraySequence <int> *array=new ArraySequence<int>(items,5);
    array->Prepend(42);
    assert(array->Get(0)==42);
}
void ArraySequence_Append_test()
{
    int items[5]={123,312,412,45,12};
    ArraySequence <int> *array=new ArraySequence<int>(items,5);
    array->Append(42);
    assert(array->Get(5)==42);
}
void ArraySequence_InsertAt_test()
{
    int items[5]={123,312,412,45,12};
    ArraySequence <int> *array=new ArraySequence<int>(items,5);
    array->InsertAt(52,2);
    assert(array->Get(2)==52);
}


void ArraySequence_GetSubSeq_test()
{
    int items[5]={123,312,412,45,12};
    ArraySequence <int> *array1=new ArraySequence<int>(items,5);
    Sequence <int> *array2=array1->GetSubsequence(1,3);
    for (int i=0;i<3;i++)
    {
        assert((*array1)[i+1]==(*array2)[i]);
    }
}
void ArraySequence_Concat_tests()
{
    int items[5]={123,312,412,45,12};
    ArraySequence <int>* array= new ArraySequence<int>(items,5);
    Sequence<int>* second=new ArraySequence <int>();
    second=second->Concat(array);
}
void ArraySequence_tests()
{
    ArraySequence_from_array_test();
    ArraySequence_from_Dynamicarray_test();
    ArraySequence_Prepend_test();
    ArraySequence_Append_test();
    ArraySequence_InsertAt_test();
    ArraySequence_GetSubSeq_test();
    ArraySequence_Concat_tests();
    cout<<"ArraySequence tests successful";
}




