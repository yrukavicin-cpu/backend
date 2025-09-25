#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
    srand(time(0));
    int a[6][7];
    for(int i=0;i<6;i++){
        for(int j=0;j<7;j++){
            a[i][j]=rand()%10;
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
    for(int i=0;i<6;i++){
        int mx=a[i][0], pos=0;
        for(int j=1;j<7;j++){
            if(a[i][j]>mx){
                mx=a[i][j];
                pos=j;
            }
        }
        int t=a[i][0];
        a[i][0]=a[i][pos];
        a[i][pos]=t;
    }
    for(int i=0;i<6;i++){
        for(int j=0;j<7;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}