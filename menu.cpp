#ifndef CPP_MENU
#define CPP_MENU

#include <iostream>
#include "vector.h"
#include "VectorList.hpp"


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
{   int Vector_type=0;
    cout<<"\nEnter 1 for array, 2 for list\n";
    while (Vector_type != 1 && Vector_type != 2 )
        input(&Vector_type);
    if (Vector_type==1) {
        int data_type = 0;
        cout << "\nEnter 1 for double, 2 for int\n";
        while (data_type != 1 && data_type != 2)
            input(&data_type);
        if (data_type == 1) {
            int type;

            Vector<double> *v1 = new Vector<double>();


            while (true) {
                type = -1;
                int index;
                while (type < 0 || type > 6) {
                    printf("Enter 1 to append,2 to get Norm ,3 to get Dot_Product,4 to multiply on scalar, 5 for getLength,6 for print,  0 for exit program\n");
                    input(&type);
                }

                switch (type) {
                    case 0:
                        exit(0);
                        break;
                    case 1:

                        double nw;
                        input(&nw);
                        v1->Append(nw);
                        break;
                    case 2: {
                        double a = v1->Norm();
                        cout << "Norm of vector : " << a << endl;
                        break;
                    }
                    case 3: {
                        cout << "Введите длину второго вектора: ";
                        int len;
                        input(&len);
                        Vector<double> *v2 = new Vector<double>();
                        cout << "Enter items for second vector: ";
                        for (int i = 0; i < len; i++) {
                            double nw;
                            input(&nw);
                            v2->Append(nw);
                        }
                        double prod = v1->Dot_product(*v2);
                        cout << "Dot product = " << prod;
                        break;
                    }
                    case 4:
                        cout << "Enter a number to multiply: ";
                        double scalar;
                        input(&scalar);
                        *v1 = v1->Multiply_on_scalar(scalar);
                        break;
                    case 5:
                        cout << "The length is: " << v1->Get_Length() << endl;
                        break;
                    case 6:
                        v1->Print_vector();
                        break;

                }
            }
        } else {
            if (data_type == 2) {

                int type;


                Vector<int> *v1 = new Vector<int>();


                while (true) {
                    type = -1;
                    int index;
                    while (type < 0 || type > 6) {
                        printf("Enter 1 to append,2 to get Norm ,3 to get Dot_Product,4 to multiply on scalar, 5 for getLength,6 for print,  0 for exit program\n");
                        input(&type);
                    }

                    switch (type) {
                        case 0:
                            exit(0);
                            break;
                        case 1:
                            printf("Enter append item\n");
                            int nw;
                            input(&nw);
                            v1->Append(nw);
                            break;
                        case 2: {
                            double a = v1->Norm();
                            cout << "Norm of vector : " << a << endl;
                            break;
                        }
                        case 3: {
                            cout << "Введите длину второго вектора: ";
                            int len;
                            input(&len);
                            Vector<int> *v2 = new Vector<int>();
                            cout << "Enter items for second vector: ";
                            for (int i = 0; i < len; i++) {
                                int nw;
                                input(&nw);
                                v2->Append(nw);
                            }
                            int prod = v1->Dot_product(*v2);
                            cout << "Dot product = " << prod;
                            break;
                        }
                        case 4:
                            cout << "Enter a number to multiply: ";
                            int scalar;
                            input(&scalar);
                            *v1 = v1->Multiply_on_scalar(scalar);
                            break;
                        case 5:
                            cout << "The length is: " << v1->Get_Length() << endl;
                            break;
                        case 6:
                            v1->Print_vector();
                            break;

                    }
                }
            }
        }
    }
    else
    {
        int data_type = 0;
        cout << "\nEnter 1 for double, 2 for int\n";
        while (data_type != 1 && data_type != 2)
            input(&data_type);
        if (data_type == 1) {
            int type;

            VectorList  <double> *v1 = new VectorList<double>();


            while (true) {
                type = -1;
                int index;
                while (type < 0 || type > 6) {
                    printf("Enter 1 to append,2 to get Norm ,3 to get Dot_Product,4 to multiply on scalar, 5 for getLength,6 for print,  0 for exit program\n");
                    input(&type);
                }

                switch (type) {
                    case 0:
                        exit(0);
                        break;
                    case 1:

                        double nw;
                        input(&nw);
                        v1->Append(nw);
                        break;
                    case 2: {
                        double a = v1->Norm();
                        cout << "Norm of vector : " << a << endl;
                        break;
                    }
                    case 3: {
                        cout << "Введите длину второго вектора: ";
                        int len;
                        input(&len);
                        VectorList<double> *v2 = new VectorList<double>();
                        cout << "Enter items for second vector: ";
                        for (int i = 0; i < len; i++) {
                            double nw;
                            input(&nw);
                            v2->Append(nw);
                        }
                        double prod = v1->Dot_product(*v2);
                        cout << "Dot product = " << prod;
                        break;
                    }
                    case 4:
                        cout << "Enter a number to multiply: ";
                        double scalar;
                        input(&scalar);
                        *v1 = v1->Multiply_on_scalar(scalar);
                        break;
                    case 5:
                        cout << "The length is: " << v1->Get_Length() << endl;
                        break;
                    case 6:
                        v1->Print_VectorList();
                        break;

                }
            }
        } else {
            if (data_type == 2) {

                int type;


                VectorList<int> *v1 = new VectorList<int>();


                while (true) {
                    type = -1;
                    int index;
                    while (type < 0 || type > 6) {
                        printf("Enter 1 to append,2 to get Norm ,3 to get Dot_Product,4 to multiply on scalar, 5 for getLength,6 for print,  0 for exit program\n");
                        input(&type);
                    }

                    switch (type) {
                        case 0:
                            exit(0);
                            break;
                        case 1:
                            printf("Enter append item\n");
                            int nw;
                            input(&nw);
                            v1->Append(nw);
                            break;
                        case 2: {
                            double a = v1->Norm();
                            cout << "Norm of vector : " << a << endl;
                            break;
                        }
                        case 3: {
                            cout << "Введите длину второго вектора: ";
                            int len;
                            input(&len);
                            VectorList<int> *v2 = new VectorList<int>();
                            cout << "Enter items for second vector: ";
                            for (int i = 0; i < len; i++) {
                                int nw;
                                input(&nw);
                                v2->Append(nw);
                            }
                            int prod = v1->Dot_product(*v2);
                            cout << "Dot product = " << prod;
                            break;
                        }
                        case 4:
                            cout << "Enter a number to multiply: ";
                            int scalar;
                            input(&scalar);
                            *v1 = v1->Multiply_on_scalar(scalar);
                            break;
                        case 5:
                            cout << "The length is: " << v1->Get_Length() << endl;
                            break;
                        case 6:
                            v1->Print_VectorList();
                            break;

                    }
                }
            }
        }
    }

}

#endif