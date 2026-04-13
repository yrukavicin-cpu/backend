#include <iostream>
#include <memory>

class Base {
public:
    virtual ~Base() = default;

    virtual void vfunc() const {
        std::cout << "Base::vfunc()\n";
    }
};

class Derived1 : public Base {
public:
    void vfunc() const override {
        std::cout << "Derived1::vfunc()\n";
    }
};

class Derived2 : public Base {
public:
    void vfunc() const override {
        std::cout << "Derived2::vfunc()\n";
    }
};

void callByReference(const Base& obj) {
    obj.vfunc();
}

class Number {
protected:
    int value{};

public:
    virtual ~Number() = default;

    void setValue(int newValue) {
        value = newValue;
    }

    virtual void show() const = 0;
};

class DecType : public Number {
public:
    void show() const override {
        std::cout << "dec: " << std::dec << value << '\n';
    }
};

class HexType : public Number {
public:
    void show() const override {
        std::cout << "hex: " << std::hex << value << '\n';
    }
};

int main() {
    std::cout << "Example 1: call through pointer\n";
    Base* ptr = nullptr;
    Base base;
    Derived1 d1;
    Derived2 d2;

    ptr = &base;
    ptr->vfunc();
    ptr = &d1;
    ptr->vfunc();
    ptr = &d2;
    ptr->vfunc();

    std::cout << "\nExample 2: call through reference\n";
    callByReference(base);
    callByReference(d1);
    callByReference(d2);

    std::cout << "\nExample 3: abstract class with pure virtual function\n";
    DecType decNumber;
    HexType hexNumber;
    decNumber.setValue(20);
    hexNumber.setValue(20);
    decNumber.show();
    hexNumber.show();

    return 0;
}
