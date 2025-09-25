#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));
    int a[15];
    int k=0;
    for(int i=0;i<15;i++){
        a[i]=rand()%10;
        cout<<a[i]<<" ";
        if(a[i]%2==0) k++;
    }
    cout<<"\n"<<k;
    return 0;
}