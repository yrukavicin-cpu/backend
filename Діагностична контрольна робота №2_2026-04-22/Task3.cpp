#include <cmath>
#include <iostream>
#include <memory>
#include <vector>

class Equation {
public:
    virtual ~Equation() = default;
    virtual void printRoots() const = 0;
};

class LinearEquation : public Equation {
private:
    double a;
    double b;

public:
    LinearEquation(double a, double b) : a(a), b(b) {}

    void printRoots() const override {
        std::cout << "Linear equation: ";

        if (a == 0) {
            std::cout << "no single root\n";
            return;
        }

        std::cout << "x = " << -b / a << "\n";
    }
};

class QuadraticEquation : public Equation {
private:
    double a;
    double b;
    double c;

public:
    QuadraticEquation(double a, double b, double c) : a(a), b(b), c(c) {}

    void printRoots() const override {
        std::cout << "Quadratic equation: ";

        if (a == 0) {
            LinearEquation linear(b, c);
            linear.printRoots();
            return;
        }

        double discriminant = b * b - 4 * a * c;

        if (discriminant < 0) {
            std::cout << "no real roots\n";
        } else if (discriminant == 0) {
            std::cout << "x = " << -b / (2 * a) << "\n";
        } else {
            double sqrtD = std::sqrt(discriminant);
            double x1 = (-b - sqrtD) / (2 * a);
            double x2 = (-b + sqrtD) / (2 * a);

            std::cout << "x1 = " << x1 << ", x2 = " << x2 << "\n";
        }
    }
};

int main() {
    std::vector<std::unique_ptr<Equation>> equations;

    equations.push_back(std::make_unique<LinearEquation>(2, -8));
    equations.push_back(std::make_unique<QuadraticEquation>(1, -5, 6));
    equations.push_back(std::make_unique<QuadraticEquation>(1, 2, 5));

    for (const auto& equation : equations) {
        equation->printRoots();
    }

    return 0;
}
