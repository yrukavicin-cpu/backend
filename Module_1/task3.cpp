#include <iostream>
using namespace std;

template <typename T>
int findInRange(const T* a, int n, T lo, T hi, T* out) {
    int k = 0;
    for (int i = 0; i < n; i++)
        if (a[i] >= lo && a[i] <= hi) out[k++] = a[i];
    return k;
}

int main() {
    int ai[] = {1, 7, 3, 10, 5, 2};
    int outi[10];
    int ki = findInRange(ai, 6, 3, 7, outi);
    cout << "int [3..7]: ";
    for (int i = 0; i < ki; i++) cout << outi[i] << " ";
    cout << "\n";

    double ad[] = {0.5, 2.2, 3.14, 9.9, 4.0};
    double outd[10];
    int kd = findInRange(ad, 5, 2.0, 5.0, outd);
    cout << "double [2..5]: ";
    for (int i = 0; i < kd; i++) cout << outd[i] << " ";
    cout << "\n";
}
