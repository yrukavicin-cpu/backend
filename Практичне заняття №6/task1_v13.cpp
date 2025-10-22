#include <iostream>
using namespace std;

class Triad {
    double a[3];
public:
    Triad(){a[0]=0;a[1]=0;a[2]=0;}
    Triad(double x,double y,double z){a[0]=x;a[1]=y;a[2]=z;}
    ~Triad(){cout<<"destroyed\n";}
    void read(){cin>>a[0]>>a[1]>>a[2];}
    void print(){cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<"\n";}
    double maxv(){double m=a[0]; if(a[1]>m)m=a[1]; if(a[2]>m)m=a[2]; return m;}
    double minv(){double m=a[0]; if(a[1]<m)m=a[1]; if(a[2]<m)m=a[2]; return m;}
    Triad operator+(const Triad& t){return Triad(a[0]+t.a[0],a[1]+t.a[1],a[2]+t.a[2]);}
    Triad operator-(const Triad& t){return Triad(a[0]-t.a[0],a[1]-t.a[1],a[2]-t.a[2]);}
};

int main(){
    Triad t1;
    t1.read();
    double x,y,z;
    cin>>x>>y>>z;
    Triad t2(x,y,z);
    t1.print();
    t2.print();
    cout<<t1.maxv()<<" "<<t1.minv()<<"\n";
    Triad s=t1+t2;
    Triad d=t1-t2;
    s.print();
    d.print();
    return 0;
}
