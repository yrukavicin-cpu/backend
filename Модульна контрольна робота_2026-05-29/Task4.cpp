#include <cstdarg>
#include <iostream>

void sumPointerOverload(int* result, int a, int b) {
    *result = a + b;
}

void sumPointerOverload(int* result, int a, int b, int c) {
    *result = a + b + c;
}

void sumReferenceOverload(int& result, int a, int b) {
    result = a + b;
}

void sumReferenceOverload(int& result, int a, int b, int c) {
    result = a + b + c;
}

void sumPointerDefault(int* result, int a, int b = 0, int c = 0) {
    *result = a + b + c;
}

void sumReferenceDefault(int& result, int a, int b = 0, int c = 0) {
    result = a + b + c;
}

void sumPointerVar(int* result, int count, ...) {
    *result = 0;
    va_list args;
    va_start(args, count);
    for (int i = 0; i < count; ++i) {
        *result += va_arg(args, int);
    }
    va_end(args);
}

void sumReferenceVar(int& result, int count, ...) {
    result = 0;
    va_list args;
    va_start(args, count);
    for (int i = 0; i < count; ++i) {
        result += va_arg(args, int);
    }
    va_end(args);
}

int main() {
    int result1 = 0;
    int result2 = 0;

    sumPointerOverload(&result1, 2, 3);
    sumReferenceOverload(result2, 2, 3, 4);
    std::cout << "Overload pointer: " << result1 << '\n';
    std::cout << "Overload reference: " << result2 << '\n';

    sumPointerDefault(&result1, 5, 6);
    sumReferenceDefault(result2, 5, 6, 7);
    std::cout << "Default pointer: " << result1 << '\n';
    std::cout << "Default reference: " << result2 << '\n';

    sumPointerVar(&result1, 4, 1, 2, 3, 4);
    sumReferenceVar(result2, 5, 1, 2, 3, 4, 5);
    std::cout << "Var args pointer: " << result1 << '\n';
    std::cout << "Var args reference: " << result2 << '\n';

    return 0;
}
