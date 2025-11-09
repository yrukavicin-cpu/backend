#include <iostream>
using namespace std;

int add(int a, int b) { return a + b; }
double add(double a, double b) { return a + b; }

int sum(int a, int b) { return a + b; }
int sum(int a, int b, int c) { return a + b + c; }

int main() {
    cout << add(2, 3) << "\n";
    cout << add(2.5, 3.1) << "\n";
    cout << sum(1, 2) << "\n";
    cout << sum(1, 2, 3) << "\n";
    return 0;
}
