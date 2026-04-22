#include <iostream>
#include <stdexcept>

template <typename T>
class CircularList {
private:
    struct Node {
        T value;
        Node* next;

        explicit Node(const T& value) : value(value), next(nullptr) {}
    };

    Node* tail;
    int listSize;

public:
    CircularList() : tail(nullptr), listSize(0) {}

    ~CircularList() {
        while (listSize > 0) {
            removeFront();
        }
    }

    void pushBack(const T& value) {
        Node* node = new Node(value);

        if (tail == nullptr) {
            tail = node;
            tail->next = tail;
        } else {
            node->next = tail->next;
            tail->next = node;
            tail = node;
        }

        ++listSize;
    }

    void removeFront() {
        if (tail == nullptr) {
            throw std::runtime_error("List is empty");
        }

        Node* head = tail->next;

        if (head == tail) {
            tail = nullptr;
        } else {
            tail->next = head->next;
        }

        delete head;
        --listSize;
    }

    void print() const {
        if (tail == nullptr) {
            std::cout << "List is empty\n";
            return;
        }

        Node* current = tail->next;

        do {
            std::cout << current->value << " ";
            current = current->next;
        } while (current != tail->next);

        std::cout << "\n";
    }

    int size() const {
        return listSize;
    }
};

int main() {
    CircularList<int> numbers;

    numbers.pushBack(10);
    numbers.pushBack(20);
    numbers.pushBack(30);

    std::cout << "Elements: ";
    numbers.print();
    std::cout << "Count: " << numbers.size() << "\n";

    numbers.removeFront();

    std::cout << "After removing first element: ";
    numbers.print();
    std::cout << "Count: " << numbers.size() << "\n";

    return 0;
}
