#include <iostream>
#include <string>
using namespace std;

struct Person { 
    string n; 
    Person(string s=""):n(s){} 
    string getName() const { return n; } 
};

struct Position { 
    string t; double s; 
    Position(string tt="",double ss=0):t(tt),s(ss){} 
    string getTitle() const { return t; } 
};

struct Employee {
    Person p;
    Position pos;
    Employee(const Person& pp,const Position& ps):p(pp),pos(ps){}
    string info() const {
        return p.getName()+" ("+pos.getTitle()+")";
    }
};

struct Workplace {
    bool free;
    Employee* e;
    Workplace():free(true),e(0){}
};

class Employer {
    Workplace* off;
    size_t vol;
public:
    Employer(size_t v){ vol=v; off=new Workplace[vol]; }
    ~Employer(){
        for(size_t i=0;i<vol;i++) if(!off[i].free) delete off[i].e;
        delete [] off;
    }

    void hire(const Person& p,const Position& pos){
        size_t i=0;
        while(i<vol && !off[i].free) i++;
        if(i==vol){
            cout<<"Немає вакансій для "<<p.getName()<<endl;
            return;
        }
        off[i].e=new Employee(p,pos);
        off[i].free=false;
        cout<<"Найнято: "<<p.getName()<<" --> "<<pos.getTitle()<<" (місце "<<i<<")"<<endl;
    }

    void fire(size_t i){
        if(i>=vol){ cout<<"Такої позиції немає"<<endl; return; }
        if(off[i].free){ cout<<"Місце "<<i<<" вже вільне"<<endl; return; }

        cout<<"Звільнено "<<off[i].e->info()<<" з позиції "<<i<<endl;
        delete off[i].e;
        off[i].e=0;
        off[i].free=true;
    }

    void print(){
        for(size_t i=0;i<vol;i++){
            cout<<"Місце "<<i<<": ";
            if(off[i].free) cout<<"вільно";
            else cout<<off[i].e->info();
            cout<<endl;
        }
    }
};

int main(){
    Employer emp(3);

    Person p1("Іван"), p2("Оля"), p3("Петро"), p4("Марія");
    Position dev("Dev",30000), qa("QA",20000);

    emp.hire(p1,dev);
    emp.hire(p2,qa);
    emp.hire(p3,dev);

    cout<<endl;
    emp.print();

    cout<<endl<<"Звільнення"<<endl;
    emp.fire(1);

    cout<<endl;
    emp.print();

    cout<<endl<<"Повторний найм"<<endl;
    emp.hire(p4,qa);

    cout<<endl;
    emp.print();
}
