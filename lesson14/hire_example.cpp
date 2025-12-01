#include <iostream>
#include <string>
using namespace std;

struct Person {
    string _name;
    Person() {}
    Person(const string& n):_name(n){}
    string getName() const { return _name; }
};

struct Position {
    string _title;
    double _salary;
    Position() : _salary(0) {}
    Position(const string& t,double s):_title(t),_salary(s){}
    string getTitle() const { return _title; }
};

struct Employee {
    Person _p;
    Position _pos;
    Employee(const Person& p,const Position& pos):_p(p),_pos(pos){}
    string info() const {
        return _p.getName() + " (" + _pos.getTitle() + ")";
    }
};

struct Workplace {
    bool _free;
    Employee* _e;
    Workplace():_free(true),_e(0){}
};

class Employer {
    Workplace* _office;
    size_t _vol;
public:
    Employer(size_t v){
        _vol=v;
        _office=new Workplace[_vol];
    }
    ~Employer(){
        for(size_t i=0;i<_vol;i++){
            if(!_office[i]._free) delete _office[i]._e;
        }
        delete [] _office;
    }

    void hire(const Person& p,const Position& pos){
        size_t i=0;
        while(i<_vol && !_office[i]._free) i++;
        if(i==_vol){
            cout<<"Немає вакантних посад для "<<p.getName()<<endl;
            return;
        }
        _office[i]._e=new Employee(p,pos);
        _office[i]._free=false;
        cout<<"Найнято: "<<p.getName()<<" --> "<<pos.getTitle()<<" (місце "<<i<<")"<<endl;
    }

    void print(){
        for(size_t i=0;i<_vol;i++){
            cout<<"Місце "<<i<<": ";
            if(_office[i]._free) cout<<"вільно";
            else cout<<_office[i]._e->info();
            cout<<endl;
        }
    }
};

int main(){
    Employer emp(3);

    Person p1("Юра");
    Person p2("Оля");
    Person p3("Петя");
    Person p4("Марійка");

    Position dev("Dev",30000);
    Position qa("QA",20000);

    emp.hire(p1,dev);
    emp.hire(p2,qa);
    emp.hire(p3,dev);
    emp.hire(p4,qa); // немає місць

    cout<<endl<<"Стан офісу:"<<endl;
    emp.print();
}
