#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "n (<=1000): ";
    if (!(cin >> n)) return 0;
    if (n < 0) n = 0;
    if (n > 1000) n = 1000;

    int a[1000];
    cout << "enter " << n << " integers:\n";
    for (int i = 0; i < n; i++) cin >> a[i];

    int target;
    cout << "target: ";
    cin >> target;

    int pos = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] == target) { pos = i; break; }
    }
    if (pos == -1) cout << "Not found\n";
    else cout << pos << "\n";
    return 0;
}