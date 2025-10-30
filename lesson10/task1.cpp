#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double f(int id, double x){
    if(id==1) return sin(x);
    if(id==2) return cos(x);
    if(id==3) return exp(x);
    return x*x;
}

int main(){
    cout.setf(ios::fixed); cout<<setprecision(6);
    int id; double a,b,h;
    if(!(cin>>id>>a>>b>>h)){ cout<<"bad\n"; return 0; }
    if(id<1||id>4||h<=0){ cout<<"bad\n"; return 0; }
    if(a>b){ double t=a; a=b; b=t; }
    cout<<"x f(x)\n";
    for(double x=a; x<=b+1e-12; x+=h) cout<<x<<" "<<f(id,x)<<"\n";
    return 0;
}
