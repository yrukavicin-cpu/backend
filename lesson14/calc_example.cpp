#include <iostream>
using namespace std;

struct Calc {
    double _a;
    double _x;
    Calc(double a=0,double x=0):_a(a),_x(x){}
    double add(){ return _a+=_x; }
    double sub(){ return _a-=_x; }
    double mul(){ return _a*=_x; }
    double div(){ if(_x!=0) _a/=_x; return _a; }
};

typedef double (Calc::*Op)();

double exe(Calc& c, Op op){
    return (c.*op)();
}

int main(){
    Calc c(10,5);

    cout<<"Акумулятор: "<<c._a<<", x="<<c._x<<endl;
    cout<<"add: "<<exe(c,&Calc::add)<<endl;
    cout<<"mul: "<<exe(c,&Calc::mul)<<endl;

    c._x=3;
    cout<<"sub: "<<exe(c,&Calc::sub)<<endl;

    c._x=2;
    cout<<"div: "<<exe(c,&Calc::div)<<endl;
}
