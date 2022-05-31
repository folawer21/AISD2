#ifndef Complex_H
#define Complex_H
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <complex>
#include <cmath>

using namespace std;
class Complex
        {
        private:
            double real;
            double imag;
            bool bexp; //число в экспоненциальной форме или нет
        public:
            Complex();
            Complex(double rl,double im);
            Complex(const complex <double> comp);
            Complex(const Complex& comp);
            Complex(double a);
            Complex& operator=(double a);
            Complex& operator =(Complex comp);
            Complex operator -(Complex comp);
            Complex operator +(Complex comp);
            Complex operator *(Complex comp);
            Complex operator*(double comp);
            Complex operator /(Complex& comp);
            Complex& operator -=(Complex comp);
            Complex& operator +=(Complex comp);
            Complex& operator *=(Complex comp);
            Complex& operator *=(double comp);
            Complex& operator /=(Complex comp);
            friend std::istream& operator >>(std::istream&, Complex&);
            friend std::ostream& operator << (std::ostream&, const Complex&);
            bool operator == (Complex com);
            bool operator != (Complex& com);
            bool operator > (Complex& com);
            bool operator < (Complex& com);
            void Set(int a);
            bool Get_bexp();
            double Get_im();
            double Get_rl();
            void Power(double a);
            void Toalg();
            void Toexp();
            double Angle();
            double Abs();
            void Power(Complex& comp, double a);

            void print();


        };
#endif //Complex_H
