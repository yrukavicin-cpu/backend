#include <iostream>
#include <map>
#include <string>

int main() {
    std::map<int, std::string> months = {
        {1, "January"},
        {2, "February"},
        {3, "March"},
        {4, "April"},
        {5, "May"},
        {6, "June"},
        {7, "July"},
        {8, "August"},
        {9, "September"},
        {10, "October"},
        {11, "November"},
        {12, "December"}
    };

    int monthNumber = 0;
    std::cout << "Enter month number (1-12): ";
    std::cin >> monthNumber;

    auto it = months.find(monthNumber);
    if (it != months.end()) {
        std::cout << "Month: " << it->second << '\n';
    } else {
        std::cout << "Incorrect month number\n";
    }

    return 0;
}
