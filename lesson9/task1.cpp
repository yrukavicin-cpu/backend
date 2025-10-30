#include <iostream>
#include <cmath>
using namespace std;
int main(){
    double S; 
    if(!(cin>>S)){ cout<<"bad\n"; return 0; }
    if(S<0){ cout<<"bad\n"; return 0; }
    double P=4*sqrt(S);
    cout<<P<<"\n";
    return 0;
}