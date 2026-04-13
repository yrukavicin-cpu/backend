#include <cmath>
#include <iomanip>
#include <iostream>
#include <list>

int main() {
    std::size_t n = 0;
    std::list<double> numbers;

    std::cout << "Enter n: ";
    std::cin >> n;

    std::cout << "Enter " << n << " real numbers:\n";
    for (std::size_t i = 0; i < n; ++i) {
        double value = 0.0;
        std::cin >> value;
        numbers.push_back(value);
    }

    bool has_less_than_minus_three = false;
    for (double value : numbers) {
        if (value < -3.0) {
            has_less_than_minus_three = true;
            break;
        }
    }

    for (double& value : numbers) {
        if (has_less_than_minus_three) {
            if (value < 0.0) {
                value = value * value;
            }
        } else {
            value += 0.1;
        }
    }

    std::cout << "\nResult in reverse order:\n";
    std::cout << std::fixed << std::setprecision(2);
    for (auto it = numbers.rbegin(); it != numbers.rend(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << '\n';

    return 0;
}
