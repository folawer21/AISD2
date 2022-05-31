#include "Dynamicarraytest.h"
using namespace std;
void Dynamic_from_array_test()
{
    int items[5]={123,312,412,45,12};
    DynamicArray<int>* array = new DynamicArray(items,5);
    for (int i=0;i<5;i++)
    {
        assert((*array)[i]==items[i]);
    }
}
void Dynamic_from_dynamic_test()
{
    int items[5]={123,312,412,45,12};
    DynamicArray<int>* array = new DynamicArray<int>(items,5);
    DynamicArray<int>* second=new DynamicArray<int>(*array);

    for (int i=0;i<5;i++)
    {
        assert((*array)[i]==(*second)[i]);
    }
}

void Dynamic_resize_test()
{
    int items[5]={123,312,412,45,12};
    DynamicArray<int> *array=new DynamicArray<int>(items,5);
    array->resize(3);
    for (int i=0;i<3;i++)
    {
        assert((*array)[i]==items[i]);
    }
    DynamicArray<int> *array2=new DynamicArray<int>(items,5);
    array2->resize(10);
    for (int i=0;i<5;i++)
    {
        assert((*array2)[i]==items[i]);
    }
}


void Dynamic_Pushback_test()
{
    int items[5]={123,312,412,45,12};
    DynamicArray<int> *array=new DynamicArray<int>(items,5);
    array->push_back(42);
    assert(array->Get(5)==42);
}


void DynamicArraytests()
{
    Dynamic_from_array_test();
    Dynamic_from_dynamic_test();
    Dynamic_resize_test();
    Dynamic_Pushback_test();
    cout<<"Dynamic_array tests successful";
}
