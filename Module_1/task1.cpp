#include <iostream>
#include <string>
using namespace std;

class University {
protected:
    string uni;
public:
    University(string u="") : uni(u) {}
    virtual ~University() {}
    virtual void print() const { cout << "[Університет] " << uni << "\n"; }
};

class Faculty : public University {
protected:
    string fac, dean;
public:
    Faculty(string u="", string f="", string d="") : University(u), fac(f), dean(d) {}
    void print() const override {
        cout << "[Факультет] " << uni << ", " << fac << ", декан: " << dean << "\n";
    }
};

class Department : public Faculty {
    string dep, head;
public:
    Department(string u="", string f="", string d="", string dp="", string h="")
        : Faculty(u,f,d), dep(dp), head(h) {}
    void print() const override {
        cout << "[Кафедра] " << uni << ", " << fac << ", " << dep << ", зав.: " << head << "\n";
    }
};

int main() {
    University* arr[3];
    arr[0] = new University("КПІ");
    arr[1] = new Faculty("КПІ", "ФІОТ", "Петров");
    arr[2] = new Department("КПІ", "ФІОТ", "Петров", "КН", "Іваненко");

    for (int i = 0; i < 3; i++) arr[i]->print();
    for (int i = 0; i < 3; i++) delete arr[i];
}
