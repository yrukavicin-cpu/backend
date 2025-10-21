#include <iostream>
using namespace std;

class Two {
    int a[2];
public:
    Two(int x=0,int y=0){a[0]=x;a[1]=y;}
    void set(int x,int y){a[0]=x;a[1]=y;}
    void print(){cout<<a[0]<<" "<<a[1]<<"\n";}
    int sum(){return a[0]+a[1];}
    int maxv(){return a[0]>a[1]?a[0]:a[1];}
};

int main(){
    Two t(3,7);
    t.print();
    cout<<t.sum()<<"\n"<<t.maxv()<<"\n";
    t.set(9,4);
    t.print();
    cout<<t.sum()<<"\n"<<t.maxv()<<"\n";
    return 0;
}
