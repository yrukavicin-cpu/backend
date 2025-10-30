#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Shape{
public:
    virtual ~Shape(){}
    virtual double area()=0;
    virtual void print()=0;
    virtual void edit()=0;
    virtual string type()=0;
};

class Rect: public Shape{
public:
    double w,h;
    Rect():w(1),h(1){}
    Rect(double a,double b):w(a),h(b){}
    double area(){ return w*h; }
    void print(){ cout<<"[Rect] w="<<w<<" h="<<h<<" area="<<area()<<"\n"; }
    void edit(){ cout<<"new w h: "; cin>>w>>h; }
    string type(){ return "rect"; }
};

class Square: public Shape{
public:
    double a;
    Square():a(1){}
    Square(double x):a(x){}
    double area(){ return a*a; }
    void print(){ cout<<"[Square] a="<<a<<" area="<<area()<<"\n"; }
    void edit(){ cout<<"new a: "; cin>>a; }
    string type(){ return "square"; }
};

int main(){
    vector<Shape*> v;
    cout<<"Simple Shapes. type 'h' for help.\n";
    while(true){
        cout<<"> ";
        string c; if(!(cin>>c)) break;
        if(c=="q"){ break; }
        else if(c=="h"){
            cout<<"h help\n";
            cout<<"ar add-rect\n";
            cout<<"as add-square\n";
            cout<<"l list\n";
            cout<<"t total-area\n";
            cout<<"e edit <idx>\n";
            cout<<"d del <idx>\n";
            cout<<"q quit\n";
        } else if(c=="ar"){
            double w,h; cout<<"w h: "; cin>>w>>h;
            v.push_back(new Rect(w,h));
            cout<<"ok\n";
        } else if(c=="as"){
            double a; cout<<"a: "; cin>>a;
            v.push_back(new Square(a));
            cout<<"ok\n";
        } else if(c=="l"){
            if(v.empty()) cout<<"empty\n";
            for(size_t i=0;i<v.size();++i){ cout<<i<<" "; v[i]->print(); }
        } else if(c=="t"){
            double s=0; for(auto p:v) s+=p->area();
            cout<<"total="<<s<<"\n";
        } else if(c=="e"){
            size_t i; if(!(cin>>i)){ cout<<"bad\n"; cin.clear(); continue; }
            if(i<v.size()){ v[i]->edit(); cout<<"ok\n"; } else cout<<"bad index\n";
        } else if(c=="d"){
            size_t i; if(!(cin>>i)){ cout<<"bad\n"; cin.clear(); continue; }
            if(i<v.size()){ delete v[i]; v.erase(v.begin()+i); cout<<"ok\n"; } else cout<<"bad index\n";
        } else {
            cout<<"unknown. h\n";
        }
    }
    for(auto p:v) delete p;
    return 0;
}
