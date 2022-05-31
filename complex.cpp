#include "complex.h"
#include <cmath>
using namespace std;


Complex::Complex() {this->real=0; this->imag=0;}
Complex::Complex(double rl,double im)
{
    this->real=rl;
    this->imag=im;
    this->bexp= false;
}
double Complex::Get_im()
{
    return this->imag;
}
double Complex::Get_rl()
{
    return this->real;
}
//Complex::Complex(const complex  comp)
//{
//    this->real=comp.real();
//    this->imag=comp.imag();
//    this->bexp= false;
//}
Complex::Complex(double a)
{
    this->real=a;
    this->imag=0;
    this->bexp=false;
}
Complex::Complex( const Complex &comp)
{
    this->real=comp.real;
    this->imag=comp.imag;
    this->bexp= false;
}
double Complex::Abs()
{
    if (bexp)
        return this->real;
    else
        return std::sqrt(this->real* this->real + this->imag*this->imag);
}
double Complex::Angle()
{
    if (bexp)
        return this->imag;
    else
        return atan2(real,imag);
}
void Complex::Toexp()
{
    if (!bexp)
    {
        double abs= this->Abs();
        double angle= this->Angle();
        this->real=abs;
        this->imag=angle;
        this->bexp=true;
    }
}
bool Complex::Get_bexp()
{
    return this->bexp;
}
void Complex::Toalg()
{
    if (bexp)
    {
        double abs = this->real;
        double phi = this->imag;
        this->real = abs*cos(phi);
        this->imag = abs*sin(phi);
        bexp = false;
    }
}
void Complex::Power(double a)
{
    if (bexp)
    {
        this->real=pow(this->real,a);
        this->imag=this->imag*a;
    }
    else
    {
        Toexp();
        Power(a);
        Toalg();
    }
}
void Complex::Power(Complex& comp, double a)
{
    if (comp.bexp)
    {
        comp.real=pow(comp.real,a);
        comp.imag=comp.imag*a;
    }
    else
    {
        comp.Toexp();
        comp.Power(a);
        comp.Toalg();
    }
}

void Complex::Set(int a)
{
    this->real=a;
    this->imag=0;
}
bool Complex::operator>(Complex &com)
{
    if (this->real>com.real)
        return true;
    else
    {
        if (this->real==com.real && this->imag>com.imag)
            return true;
        else
            return false;
    }
}

bool Complex::operator<(Complex &com)
{
    if (this->real<com.real)
        return true;
    else
    {
        if (this->real==com.real && this->imag<com.imag)
            return true;
        else
            return false;
    }
}

Complex Complex::operator+(Complex com)
{

    this->real=com.real+this->real;
    this->imag=com.imag+this->imag;
    return *this;
}

Complex Complex::operator-(Complex com)
{

    this->real=this->real-com.real;
    this->imag=this->imag-com.imag;
    return *this;
}
Complex& Complex::operator=(double a)
{
    this->real=a;
    this->imag=0;
    return *this;
}
Complex& Complex::operator=(Complex com)
{

    this->real=com.real;
    this->imag=com.imag;
    return *this;
}
bool Complex::operator==(Complex com)
{
    if (this->real==com.real && this->imag==com.imag)
        return true;
    else
        return false;
}

bool Complex::operator!=(Complex &com)
{
    if (this->real==com.real && this->imag==com.imag)
        return false;
    else
        return true;
}

Complex Complex::operator*(Complex Complex)
{
    double i, j;
    i = this->real * Complex.real - this->imag * Complex.imag;
    j = this->real * Complex.imag + Complex.real * this->imag;
    this->real = i;
    this->imag = j;
    return *this;
}
Complex Complex::operator*(double comp)
{
    double i, j;
    i = this->real * comp;
    j = this->imag * comp;
    this->real = i;
    this->imag = j;
    return *this;
}
Complex Complex::operator/(Complex &comp)
{
    double i, j, k;
    k = comp.real * comp.real + comp.imag * comp.imag;
    i = (this->real * comp.real + this->imag * comp.imag) / k;
    j = (comp.real * this->imag - this->real * comp.imag) / k;
    this->real = i;
    this->imag = j;
    return *this;
}

Complex& Complex::operator-=(Complex comp)
{
    this->real-=comp.real;
    this->imag-=comp.imag;
    return *this;
}
Complex& Complex::operator+=(Complex comp)
{
    this->real+=comp.real;
    this->imag=this->imag+comp.imag;
    return *this;
}
Complex& Complex::operator*=(Complex Complex)
{
    double i, j;
    i = this->real * Complex.real - this->imag * Complex.imag;
    j = this->real * Complex.imag + Complex.real * this->imag;
    this->real = i;
    this->imag = j;
    return *this;
}
Complex& Complex::operator*=(double comp)
{
    double i, j;
    i = this->real * comp;
    j = this->imag * comp;
    this->real = i;
    this->imag = j;
    return *this;
}
Complex& Complex::operator/=(Complex comp)
{
    double i, j, k;
    k = comp.real * comp.real + comp.imag * comp.imag;
    i = (this->real * comp.real + this->imag * comp.imag) / k;
    j = (comp.real * this->imag - this->real * comp.imag) / k;
    this->real = i;
    this->imag = j;
    return *this;
}

void Complex::print()
{
    if (bexp)
        cout<<"EXP FORM : "<<this->real<<"*exp(j*"<<this->imag<<")"<<endl;
    else
        cout<<"ALG FORM : "<<this->real<<" + j*("<<this->imag<<")"<<endl;
}
ostream& operator << (ostream& out, const Complex& Complex)
{
    if (!Complex.bexp) {
        if (Complex.imag < 0)
            out << Complex.real << "+i*(" << Complex.imag << ")";
        else {
            if (Complex.imag == 0)
                out << Complex.real << endl;
            else
                out << Complex.real << "+i*" << Complex.imag;
        }
    }
    else
        out<<"EXP FORM : "<<Complex.real<<"*exp(j*"<<Complex.imag<<")"<<endl;
    return out;
}
istream& operator >> (istream& in, Complex& Complex)
{
    cout << "Input real part: ";
    in >> Complex.real;
    cout << "Input imaginary part: ";
    in >> Complex.imag;
    return in;
}
