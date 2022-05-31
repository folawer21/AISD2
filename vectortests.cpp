#include "vectortests.h"
#include "vector.h"
void Vector_from_array_test()
{
    int arr[4]={1,4,4,12};
    Vector <int> v1=Vector(arr,4);
    for (int i=0;i<4;i++)
        assert(arr[i]==v1.Get(i));
}
void Vector_from_vector_test()
{
    int arr[4]={1,4,4,12};
    Vector <int> v1=Vector(arr,4);
    Vector <int> v2=Vector(v1);
    for (int i=0;i<4;i++)
        assert(v1.Get(i)==v2.Get(i));
}
void Append_test()
{
    int arr[4]={1,4,4,12};
    Vector <int> v1=Vector(arr,4);
    v1.Append(23);
    for (int i=0;i<4;i++)
        assert(v1.Get(i)==arr[i]);
    assert(v1.Get(4)==23);
}
void Sum_with_zero_test()
{
    int arr[4]={1,4,4,12};
    int zer[4]={0,0,0,0};
    Vector <int> v1=Vector(arr,4);
    Vector <int> v2=Vector(zer,4);
    Vector <int> *res=v1.Sum_vectors(v2);
    for (int i=0;i<4;i++)
        assert(v1.Get(i)==res->Get(i));
}

void Sum_vectors_test()
{
    int arr[4]={1,4,4,12};
    int zer[4]={3,12,5,-1};
    Vector <int> v1=Vector(arr,4);
    Vector <int> v2=Vector(zer,4);
    Vector <int> *res=v1.Sum_vectors(v2);
    for (int i=0;i<4;i++)
        assert(res->Get(i)==(v1.Get(i)+v2.Get(i)));
}

void Multiply_on_zero_test()
{
    int arr[4]={1,4,4,12};
    Vector <int> v1=Vector(arr,4);
    v1=v1.Multiply_on_scalar(0);
    for (int i=0;i<4;i++)
        assert(0==v1.Get(i));
}
void Multiply_on_negative_test()
{
    int arr[4]={1,4,4,12};
    Vector <int> v1=Vector(arr,4);
    v1=v1.Multiply_on_scalar(-1);
    for (int i=0;i<4;i++)
        assert(arr[i]*(-1)==v1.Get(i));
}
void Multiply_on_positive_test()
{
    int arr[4]={1,4,4,12};
    Vector <int> v1=Vector(arr,4);
    v1=v1.Multiply_on_scalar(21);
    for (int i=0;i<4;i++)
        assert(arr[i]*(21)==v1.Get(i));
}

void Vector_Norm_test()
{
    int arr[4]={1,4,4,12};
    Vector <int> v1=Vector(arr,4);
    int norma=v1.Norm();
    assert(norma==13);
}

void Dot_product_test()
{
    int arr[4]={1,4,4,12};
    Vector <int> v1=Vector(arr,4);
    int arr2[4]={2,10,0,1};
    Vector <int> v2=Vector(arr2,4);
    int product=v1.Dot_product(v2);
    assert(product==54);
}

void Vector_tests()
{
    Vector_from_array_test();
    Vector_from_vector_test();
    Append_test();
    Sum_with_zero_test();
    Sum_vectors_test();
    Multiply_on_zero_test();
    Multiply_on_negative_test();
    Multiply_on_positive_test();
    Vector_Norm_test();
    Dot_product_test();
    cout<<"Vector tests successful"<<endl;
}