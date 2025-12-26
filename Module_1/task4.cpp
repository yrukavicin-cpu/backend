#include <iostream>
using namespace std;

template <typename A, typename B>
class NumPair {
    A a;
    B b;
public:
    NumPair(A a, B b) : a(a), b(b) {}
    void print() const { cout << "Pair: (" << a << ", " << b << ")\n"; }
    auto sum() const -> decltype(a + b) { return a + b; }
};

int main() {
    NumPair<int, double> p(7, 2.5);
    p.print();
    cout << "sum = " << p.sum() << "\n";
}
