#include <iostream>
#include <memory>
#include <string>
#include <vector>

class Father {
protected:
    std::string firstName;

public:
    explicit Father(std::string name) : firstName(std::move(name)) {}
    virtual ~Father() = default;

    virtual void printInfo() const {
        std::cout << "Batko: " << firstName << '\n';
    }
};

class Child : public Father {
private:
    std::string childName;

public:
    Child(std::string fatherName, std::string name)
        : Father(std::move(fatherName)), childName(std::move(name)) {}

    void printInfo() const override {
        std::cout << "Dytyna: " << childName << ", po batkovi: " << firstName << '\n';
    }
};

int main() {
    std::vector<std::unique_ptr<Father>> family;
    family.push_back(std::make_unique<Father>("Petro"));
    family.push_back(std::make_unique<Child>("Ivanovych", "Oleh"));
    family.push_back(std::make_unique<Child>("Petrovych", "Maksym"));

    std::cout << "Demonstration of late binding:\n";
    for (const auto& member : family) {
        member->printInfo();
    }

    return 0;
}
