#include <iostream>
#include <cmath>
using namespace std;
int main(){
    double a,b; 
    if(!(cin>>a>>b)){ cout<<"bad\n"; return 0; }
    if(a<=0||b<=0){ cout<<"bad\n"; return 0; }
    double c=sqrt(a*a+b*b);
    double P=a+b+c;
    cout<<P<<"\n";
    return 0;
}
