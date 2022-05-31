#include "VectorList.hpp"
#include "VectorListTests.h"
void VectorList_from_array_test()
{
    int arr[4]={1,4,4,12};
    VectorList <int> v1=VectorList(arr,4);
    for (int i=0;i<4;i++)
        assert(arr[i]==v1.Get(i));
}
void VectorList_from_Vector_test()
{
    int arr[4]={1,4,4,12};
    VectorList <int> v1=VectorList(arr,4);
    VectorList <int> v2=VectorList(v1);
    for (int i=0;i<4;i++)
        assert(v1.Get(i)==v2.Get(i));
}
void List_Append_test()
{
    int arr[4]={1,4,4,12};
    VectorList <int> v1=VectorList(arr,4);
    v1.Append(23);
    for (int i=0;i<4;i++)
        assert(v1.Get(i)==arr[i]);
    assert(v1.Get(4)==23);
}
void List_Sum_with_zero_test()
{
    int arr[4]={1,4,4,12};
    int zer[4]={0,0,0,0};
    VectorList <int> v1=VectorList(arr,4);
    VectorList <int> v2=VectorList(zer,4);
    VectorList <int> *res=v1.Sum_VectorLists(v2);
    for (int i=0;i<4;i++)
        assert(v1.Get(i)==res->Get(i));
}

void List_Sum_VectorLists_test()
{
    int arr[4]={1,4,4,12};
    int zer[4]={3,12,5,-1};
    VectorList <int> v1=VectorList(arr,4);
    VectorList <int> v2=VectorList(zer,4);
    VectorList <int> *res=v1.Sum_VectorLists(v2);
    for (int i=0;i<4;i++)
        assert(res->Get(i)==(v1.Get(i)+v2.Get(i)));
}

void List_Multiply_on_zero_test()
{
    int arr[4]={1,4,4,12};
    VectorList <int> v1=VectorList(arr,4);
    v1=v1.Multiply_on_scalar(0);
    for (int i=0;i<4;i++)
        assert(0==v1.Get(i));
}
void List_Multiply_on_negative_test()
{
    int arr[4]={1,4,4,12};
    VectorList <int> v1=VectorList(arr,4);
    v1=v1.Multiply_on_scalar(-1);
    for (int i=0;i<4;i++)
        assert(arr[i]*(-1)==v1.Get(i));
}
void List_Multiply_on_positive_test()
{
    int arr[4]={1,4,4,12};
    VectorList <int> v1=VectorList(arr,4);
    v1=v1.Multiply_on_scalar(21);
    for (int i=0;i<4;i++)
        assert(arr[i]*(21)==v1.Get(i));
}

void VectorList_Norm_test()
{
    int arr[4]={1,4,4,12};
    VectorList <int> v1=VectorList(arr,4);
    int norma=v1.Norm();
    assert(norma==13);
}

void List_Dot_product_test()
{
    int arr[4]={1,4,4,12};
    VectorList <int> v1=VectorList(arr,4);
    int arr2[4]={2,10,0,1};
    VectorList <int> v2=VectorList(arr2,4);
    int product=v1.Dot_product(v2);
    assert(product==54);
}

void List_VectorList_tests()
{
    VectorList_from_array_test();
    VectorList_from_Vector_test();
    List_Append_test();
    List_Sum_with_zero_test();
    List_Sum_VectorLists_test();
    List_Multiply_on_zero_test();
    List_Multiply_on_negative_test();
    List_Multiply_on_positive_test();
    VectorList_Norm_test();
    List_Dot_product_test();
    cout<<"VectorList tests successful"<<endl;
}