#include "complex_test.h"

void complex_from_input_test()
{
    double rl=1.24;
    double im=3.12;
    Complex cm=Complex(rl,im);
    assert(cm.Get_rl()==1.24);
    assert(cm.Get_im()==3.12);
}
void complex_from_complex_test()
{
    double rl=1.24;
    double im=3.12;
    Complex cm=Complex(rl,im);
    Complex cm2=Complex(cm);
    assert(cm.Get_rl()==cm2.Get_rl());
    assert(cm.Get_im()==cm2.Get_im());
}
void equality_operator_test()
{
    Complex cm=Complex(1.12,10.41);
    Complex cm2=Complex(1.12,10.41);
    assert((cm==cm2)==true);
}
void inequality_operator_test()
{
    Complex cm=Complex(1.12,10.41);
    Complex cm2=Complex(0.12,10.41);
    assert((cm>cm2)==true);
}

void plus_operator_test()
{
    Complex cm=Complex(1.12,10.41);
    Complex cm2=Complex(9.88,1.59);
    cm+=cm2;
    assert(cm.Get_rl()==11);
    assert(cm.Get_im()==12);
}
void minus_operator_test()
{
    Complex cm=Complex(10.88,21.60);
    Complex cm2=Complex(9.88,1.59);
    cm-=cm2;
    assert(cm.Get_rl()==1);
    assert(cm.Get_im()==20.01);
}
void multiply_operator_test()
{
    Complex cm=Complex(2,3);
    Complex cm2=Complex(1,4);
    cm*=cm2;
    assert(cm.Get_rl()==-10);
    assert(cm.Get_im()==11);
}
void multiply_on_not_complex_operator_test()
{
    Complex cm=Complex(10,21);
    int a=3;
    cm*=a;
    assert(cm.Get_rl()==30);
    assert(cm.Get_im()==63);
}
void abs_test()
{
    Complex cm=Complex(3,4);
    assert(cm.Abs()==5);
}

void angle_test()
{
    Complex cm=Complex(3,4);
    assert(cm.Angle()==atan2(3,4));
}
void toexp_test()
{
    Complex cm=Complex(3,4);
    double abs=cm.Abs();
    double angle=cm.Angle();
    cm.Toexp();
    assert(cm.Get_bexp()==true);
    assert(cm.Get_rl()==abs);
    assert(cm.Get_im()==angle);
}
void toalg_test()
{
    Complex cm=Complex(3,4);
    cm.Toexp();
    cm.Toalg();
    assert(cm.Get_bexp()==false);
    assert(cm.Get_rl()==4);
    assert(cm.Get_im()==3);

}

void power_test()
{
    Complex cm=Complex(3,4);
    cm.Power(3);

    assert((cm.Get_rl()-(-44))<0.0001==true);
    assert((cm.Get_im()-117)<0.0001==true);
}
void divide_test()
{
    Complex cm=Complex(4,2);
    Complex cm2=Complex(2,1);
    cm/=cm2;
    assert(cm.Get_rl()==2);
    assert(cm.Get_im()==0);
}

void set_test()
{
    Complex cm=Complex(3,4);
    cm.Set(23);
    assert(cm.Get_rl()==23);
    assert(cm.Get_im()==0);
}
void complex_tests()
{
    complex_from_input_test();
    complex_from_complex_test();
    equality_operator_test();
    plus_operator_test();
    minus_operator_test();
    multiply_operator_test();
    multiply_on_not_complex_operator_test();
    divide_test();
    inequality_operator_test();
    power_test();
    set_test();
    toalg_test();
    toexp_test();
    angle_test();
    abs_test();
    cout<<"Complex tests successful";
}