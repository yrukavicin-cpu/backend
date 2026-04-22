#include <iostream>
#include <vector>

class FactorialBase {
protected:
    int number;

public:
    explicit FactorialBase(int number = 0) : number(number) {}
    virtual ~FactorialBase() = default;

    void setNumber(int value) {
        number = value;
    }

    virtual unsigned long long factorial() const {
        unsigned long long result = 1;

        for (int i = 2; i <= number; ++i) {
            result *= i;
        }

        return result;
    }
};

class FactorialTable : public FactorialBase {
private:
    std::vector<int> numbers;

public:
    explicit FactorialTable(const std::vector<int>& numbers) : numbers(numbers) {}

    void printTable() {
        std::cout << "Number | Factorial\n";
        std::cout << "------------------\n";

        for (int value : numbers) {
            setNumber(value);
            std::cout << value << "      | " << factorial() << "\n";
        }
    }
};

int main() {
    FactorialTable table({0, 1, 3, 5, 7});
    table.printTable();

    return 0;
}
