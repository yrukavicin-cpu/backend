#include <iostream>
#include <string>
using namespace std;

int main() {
    char x;  
    string n;
    cout << "digit (0-9): ";
    if (!(cin >> x)) return 0;
    cout << "number: ";
    if (!(cin >> n)) return 0;

    int cnt = 0;
    for (size_t i = 0; i < n.size(); i++) {
        if (n[i] == x) cnt++;
    }
    cout << cnt << endl;
    return 0;
}