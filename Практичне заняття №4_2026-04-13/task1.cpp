#include <cctype>
#include <iostream>
#include <vector>

int main() {
    std::vector<char> letters(10);

    std::cout << "Initial size = " << letters.size() << '\n';

    for (std::size_t i = 0; i < letters.size(); ++i) {
        letters[i] = static_cast<char>('a' + i);
    }

    std::cout << "Current content:\n";
    for (char ch : letters) {
        std::cout << ch << ' ';
    }
    std::cout << "\n\n";

    std::cout << "Expanded vector\n";
    for (int i = 0; i < 10; ++i) {
        letters.push_back(static_cast<char>('k' + i));
    }

    std::cout << "New size = " << letters.size() << '\n';
    std::cout << "Current content:\n";
    for (char ch : letters) {
        std::cout << ch << ' ';
    }
    std::cout << "\n\n";

    for (char& ch : letters) {
        ch = static_cast<char>(std::toupper(static_cast<unsigned char>(ch)));
    }

    std::cout << "Modified content:\n";
    for (char ch : letters) {
        std::cout << ch << ' ';
    }
    std::cout << '\n';

    return 0;
}
