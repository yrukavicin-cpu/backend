#include <iostream>
#include <cmath>
using namespace std;
int main(){
    double R,r; 
    if(!(cin>>R>>r)){ cout<<"bad\n"; return 0; }
    if(R<=0||r<0||R<=r){ cout<<"bad\n"; return 0; }
    double A=M_PI*(R*R - r*r);
    cout<<A<<"\n";
    return 0;
}
