#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

template <typename T>
class Stack {
private:
    std::vector<T> items;

public:
    void push(const T& value) {
        items.push_back(value);
    }

    T pop() {
        if (items.empty()) {
            throw std::runtime_error("Stack is empty");
        }

        T value = items.back();
        items.pop_back();
        return value;
    }

    bool empty() const {
        return items.empty();
    }

    const T& top() const {
        if (items.empty()) {
            throw std::runtime_error("Stack is empty");
        }

        return items.back();
    }

    T longest() const {
        if (items.empty()) {
            throw std::runtime_error("Stack is empty");
        }

        T result = items[0];

        for (const T& item : items) {
            if (item.size() > result.size()) {
                result = item;
            }
        }

        return result;
    }
};

int main() {
    Stack<std::string> stack;

    stack.push("cat");
    stack.push("programming");
    stack.push("C++");
    stack.push("university");

    std::cout << "Top row: " << stack.top() << "\n";
    std::cout << "Longest row: " << stack.longest() << "\n";

    std::cout << "Reading from stack:\n";
    while (!stack.empty()) {
        std::cout << stack.pop() << "\n";
    }

    return 0;
}
