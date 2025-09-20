#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double x; 
    cout << "x=";
    if (!(cin >> x)) return 0;

    // нужно |x| > e, иначе подкоренное < 0
    if (fabs(x) <= exp(1.0)) { 
        cout << "domain error\n"; 
        return 0; 
    }

    double u = 0.3 * log10(exp(-x)) + atan(x)
             - (sin(x)*sin(x)) / (4.0 * sqrt(log(fabs(x)) - 1.0));

    cout << "u=" << u << "\n";
    return 0;
}