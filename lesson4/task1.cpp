#include <iostream>
using namespace std;

int main() {
    int array[] = {0, 1, 3, 4, 5, 2, 1, -4, -1, 10, 55};
    int n = sizeof(array) / sizeof(array[0]);

    // Блок 1: виводимо усі елементи масиву
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    // Блок 2: виводимо елементи у зворотному порядку
    for (int i = n - 1; i >= 0; i--) {
        cout << array[i] << " ";
    }
    cout << endl;

    // Блок 3: виводимо тільки парні елементи
    for (int i = 0; i < n; i++) {
        if (array[i] % 2 == 0) {
            cout << array[i] << " ";
        }
    }
    cout << endl;

    // Блок 4: виводимо елементи через один (тобто індекси 0,2,4,...)
    for (int i = 0; i < n; i += 2) {
        cout << array[i] << " ";
    }
    cout << endl;

    // Блок 5: виводимо елементи поки не зустрінемо -1
    for (int i = 0; i < n; i++) {
        if (array[i] == -1) break;
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}