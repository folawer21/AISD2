#include <iostream>
#include "menu.cpp"
#include "vector.h"
#include "vectortests.h"
#include "complex_test.h"
#include "VectorList.hpp"
#include "VectorListTests.h"
using namespace std;

int main()
{
    Vector_tests();
    List_VectorList_tests();
    complex_tests();
    menu();
}

