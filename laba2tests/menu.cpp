#ifndef CPP_MENU
#define CPP_MENU

#include <iostream>
#include "arraysequence.h"
#include "linkedlistsequence.h"

using namespace std;

template<class T>
void input(T* a)
{
    while (true)
    {
        cout << "Enter a value:";
        cin >> *a;
        break;
    }
}

void menu()
{   int data_type=0;
    printf("Enter 1 for int, 2 for double\n");
    while (data_type != 1 && data_type != 2)
        input(&data_type);
    if (data_type==1) {
        printf("Enter 1 for ListSequence, 2 for ArraySequence\n");
        int type = -1;
        while (type != 1 && type != 2)
            input(&type);

        Sequence<int> *seq;

        if (type == 1)
            seq = new ListSequence<int>;
        else
            seq = new ArraySequence<int>;

        printf("Enter 1 for append, 2 for prepend, 3 for insertAt,  4 for getLength, 5 for print,6 for get subseq 0 for exit program\n");
        while (true) {
            type = -1;
            int index;
            while (type < 0 || type > 6) {
                printf("Enter a command: \n");
                input(&type);
            }


            switch (type) {
                case 0:
                    exit(0);
                    break;

                case 1:
                    seq->Append(0);
                    printf("Enter append item\n");
                    input(&(*seq)[seq->Get_Length() - 1]);
                    break;

                case 2:
                    seq->Prepend(0);
                    printf("Enter prepend item\n");
                    input(&(*seq)[0]);
                    break;

                case 3:
                    printf("Enter insert index\n");
                    input(&index);
                    try {
                        seq->InsertAt(0, index);
                        printf("Enter insert item\n");
                        input(&(*seq)[index]);
                    }
                    catch (Myexception &abc) {

                        cout << "Process finished with error code = " << abc.number << endl;
                        exit(0);
                    }
                    break;


                case 4:
                    std::cout << "The length is: " << seq->Get_Length() << std::endl;
                    break;
                case 5:
                    cout << seq << endl;
                    break;
                case 6:
                    int startindex;
                    int endindex;
                    printf("Enter start index\n");
                    input(&startindex);
                    printf("Enter insert index\n");
                    input(&endindex);
                    Sequence<int> *seq2 = seq->GetSubsequence(startindex, endindex);
                    cout << "Subsequence : " << seq2 << endl;

            }
        }
    }
    else
    {
        printf("Enter 1 for ListSequence, 2 for ArraySequence\n");
        int type = -1;
        while (type != 1 && type != 2)
            input(&type);

        Sequence<double> *seq;

        if (type == 1)
            seq = new ListSequence<double>;
        else
            seq = new ArraySequence<double>;

        printf("Enter 1 for append, 2 for prepend, 3 for insertAt,  4 for getLength, 5 for print,6 for get subseq 0 for exit program\n");
        while (true) {
            type = -1;
            int index;
            while (type < 0 || type > 6) {
                printf("Enter a command: \n");
                input(&type);
            }


            switch (type) {
                case 0:
                    exit(0);
                    break;

                case 1:
                    seq->Append(0);
                    printf("Enter append item\n");
                    input(&(*seq)[seq->Get_Length() - 1]);
                    break;

                case 2:
                    seq->Prepend(0);
                    printf("Enter prepend item\n");
                    input(&(*seq)[0]);
                    break;

                case 3:
                    printf("Enter insert index\n");
                    input(&index);
                    try {
                        seq->InsertAt(0, index);
                        printf("Enter insert item\n");
                        input(&(*seq)[index]);
                    }
                    catch (Myexception &ex) {

                        cout << "Process finished with error code = " << ex.number << endl;
                        exit(0);
                    }
                    break;


                case 4:
                    cout << "The length is: " << seq->Get_Length() << std::endl;
                    break;
                case 5:
                    cout << seq << endl;
                    break;
                case 6:
                    int startindex;
                    int endindex;
                    printf("Enter start index\n");
                    input(&startindex);
                    printf("Enter insert index\n");
                    input(&endindex);
                    try {
                        Sequence<double> *seq2 = seq->GetSubsequence(startindex, endindex);
                        cout << "Subsequence : " << seq2 << endl;
                    }
                    catch (Myexception &ex)
                    {
                        cout << "Process finished with error code = " << ex.number << endl;
                        exit(0);
                    }

            }
        }
    }

}

#endif