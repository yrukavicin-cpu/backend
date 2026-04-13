#include <iostream>

double power(double n, int p = 2) {
    double result = 1.0;

    for (int i = 0; i < p; ++i) {
        result *= n;
    }

    return result;
}

void zeroSmaller(int& first, int& second) {
    if (first < second) {
        first = 0;
    } else if (second < first) {
        second = 0;
    } else {
        second = 0;
    }
}

struct Distance {
    int meters;
    int centimeters;
};

int toCentimeters(const Distance& value) {
    return value.meters * 100 + value.centimeters;
}

Distance maxDistance(Distance first, Distance second) {
    if (toCentimeters(first) >= toCentimeters(second)) {
        return first;
    }
    return second;
}

void printDistance(const Distance& value) {
    std::cout << value.meters << " m " << value.centimeters << " cm";
}

int main() {
    double number = 0.0;
    int exponent = 0;

    std::cout << "Task 1. Enter a number and exponent: ";
    std::cin >> number >> exponent;
    std::cout << "power(" << number << ", " << exponent << ") = "
              << power(number, exponent) << '\n';
    std::cout << "power(" << number << ") = " << power(number) << '\n';

    int a = 0;
    int b = 0;
    std::cout << "\nTask 2. Enter two integers: ";
    std::cin >> a >> b;
    zeroSmaller(a, b);
    std::cout << "After zeroSmaller: a = " << a << ", b = " << b << '\n';

    Distance d1{};
    Distance d2{};
    std::cout << "\nTask 3. Enter first distance (meters centimeters): ";
    std::cin >> d1.meters >> d1.centimeters;
    std::cout << "Enter second distance (meters centimeters): ";
    std::cin >> d2.meters >> d2.centimeters;

    Distance largest = maxDistance(d1, d2);
    std::cout << "Largest distance: ";
    printDistance(largest);
    std::cout << '\n';

    return 0;
}
