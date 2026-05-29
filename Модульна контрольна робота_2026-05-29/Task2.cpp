#include <iostream>

class Counter {
private:
    int minValue;
    int maxValue;
    int currentValue;

public:
    Counter(int minV, int maxV, int start)
        : minValue(minV), maxValue(maxV), currentValue(start) {
        if (currentValue < minValue || currentValue > maxValue) {
            currentValue = minValue;
        }
    }

    void increment() {
        ++currentValue;
        if (currentValue > maxValue) {
            currentValue = minValue;
        }
    }

    int getValue() const {
        return currentValue;
    }

    void setLimits(int minV, int maxV) {
        minValue = minV;
        maxValue = maxV;
        if (currentValue < minValue || currentValue > maxValue) {
            currentValue = minValue;
        }
    }
};

int main() {
    Counter counter(0, 5, 3);

    std::cout << "Start value: " << counter.getValue() << '\n';
    for (int i = 0; i < 6; ++i) {
        counter.increment();
        std::cout << "Current value: " << counter.getValue() << '\n';
    }

    counter.setLimits(10, 12);
    std::cout << "After changing limits: " << counter.getValue() << '\n';
    counter.increment();
    std::cout << "After increment: " << counter.getValue() << '\n';

    return 0;
}
