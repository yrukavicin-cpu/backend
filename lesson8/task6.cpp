#include <iostream>
using namespace std;

class Counter {
    int vals[3];
public:
    Counter(int l=0,int h=9,int v=0){
        vals[0]=l; vals[1]=h;
        if(v<l) v=l;
        if(v>h) v=h;
        vals[2]=v;
    }
    void inc(){ if(vals[2]<vals[1]) vals[2]++; }
    void dec(){ if(vals[2]>vals[0]) vals[2]--; }
    int value(){ return vals[2]; }
};

int main(){
    Counter c(0,5,2);
    cout<<c.value()<<"\n";
    c.inc();
    c.inc();
    cout<<c.value()<<"\n";
    c.dec();
    cout<<c.value()<<"\n";
    return 0;
}
