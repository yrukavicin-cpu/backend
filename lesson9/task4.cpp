#include <iostream>
using namespace std;
int main(){
    int n; 
    if(!(cin>>n)){ cout<<"bad\n"; return 0; }
    if(n<10||n>99){ cout<<"bad\n"; return 0; }
    int t=n/10;
    int o=n%10;
    cout<<t<<"\n"<<o<<"\n"<<(t+o)<<"\n"<<(t*o)<<"\n";
    return 0;
}
