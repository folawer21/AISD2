#include "ListSequencetests.h"
#include "ArraySequencetests.h"
#include "Dynamicarraytest.h"
#include "Linkedlisttest.h"
using namespace std;
int main()
{
    ListSequence_tests();
    cout<<"\n";
    DynamicArraytests();
    cout<<"\n";
    LinkedList_tests();
    cout<<"\n";
    ArraySequence_tests();
}

