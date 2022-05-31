#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H
#include "iostream"
#include "exception"
#include "string"
using namespace std;
enum Error
{
    INDEX_OUT_OF_RANGE=1,
    NULL_POINTER=2,
    NEGATIVE_SIZE = 3,
};
//Error INDEX_OUT_OF_RANGE
class Myexception:public exception
{
public:
    string msg;
    Error number;
    Myexception(int code)
    {
        if (code==1) {
            msg = "List index out of range";
            number = ::INDEX_OUT_OF_RANGE;
        }
        if (code==2)
        {
            msg = "Pointer in NULL";
            number = ::NULL_POINTER;
        }
        if (code==3)
        {
            msg = "Size under zero";
            number = ::NEGATIVE_SIZE;
        }
    };

    void show()
    {
        cout<<msg<<endl;
    }
};




#endif //MYEXCEPTION_H
