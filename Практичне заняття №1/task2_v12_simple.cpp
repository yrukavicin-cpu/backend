// task2_v12_simple.cpp
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    const double m=3.0, n=-2.2, k=0.8, PI=3.141592653589793;

    double y = sqrt(fabs(m + n*n*n));
    double x = cbrt(fabs(k*m - 3.0)) + PI/6.0;

    // простые проверки, чтобы не ловить бесконечности/NaN
    if (fabs(y - 2.0) < 1e-12 || fabs((k+1.0)*x) < 1e-12) {
        cout << "domain error\n";
        return 0;
    }

    double gamma = tan((x + 1.0) / (y - 2.0)) + log10(fabs((k+1.0)*x));

    cout << "x=" << x << "\n";
    cout << "y=" << y << "\n";
    cout << "gamma=" << gamma << "\n";
    return 0;
}