#include <iostream>
#include <cmath>
using namespace std;

class Solid {
public:
    virtual ~Solid() {}
    virtual const char* type() const = 0;
    virtual double volume() const = 0;
    virtual void print() const = 0;
};

class Cone : public Solid {
    double r, h;
public:
    Cone(double r, double h) : r(r), h(h) {}
    const char* type() const override { return "Конус"; }
    double volume() const override { return M_PI * r * r * h / 3.0; }
    void print() const override { cout << "[" << type() << "] r=" << r << " h=" << h << " V=" << volume() << "\n"; }
};

class Cylinder : public Solid {
    double r, h;
public:
    Cylinder(double r, double h) : r(r), h(h) {}
    const char* type() const override { return "Циліндр"; }
    double volume() const override { return M_PI * r * r * h; }
    void print() const override { cout << "[" << type() << "] r=" << r << " h=" << h << " V=" << volume() << "\n"; }
};

int main() {
    Solid* arr[2];
    arr[0] = new Cone(3, 5);
    arr[1] = new Cylinder(3, 5);

    for (int i = 0; i < 2; i++) arr[i]->print();
    for (int i = 0; i < 2; i++) delete arr[i];
}
