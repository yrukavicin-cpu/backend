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
    int id,n; double a,b;
    if(!(cin>>id>>a>>b>>n)){ cout<<"bad\n"; return 0; }
    if(id<1||id>4||n<=0){ cout<<"bad\n"; return 0; }
    if(a>b){ double t=a; a=b; b=t; }
    if(n%2) n++;
    double h=(b-a)/n;
    double s=f(id,a)+f(id,b);
    for(int k=1;k<n;k++){
        double x=a+h*k;
        if(k%2) s+=4*f(id,x); else s+=2*f(id,x);
    }
    double I=s*h/3.0;
    cout<<I<<"\n";
    return 0;
}
