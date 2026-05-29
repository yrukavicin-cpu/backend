#include <iostream>
#include <memory>
#include <string>
#include <vector>

class Figure {
protected:
    double centerX;
    double centerY;
    double angle;
    double scale;
    bool visible;

public:
    Figure(double x, double y, double a = 0.0, double s = 1.0)
        : centerX(x), centerY(y), angle(a), scale(s), visible(false) {}

    virtual ~Figure() = default;

    virtual void draw() = 0;

    virtual void hide() {
        visible = false;
        std::cout << "Figure hidden\n";
    }

    virtual void rotate(double delta) {
        angle += delta;
        std::cout << "Rotated to " << angle << " degrees\n";
    }

    virtual void move(double dx, double dy) {
        centerX += dx;
        centerY += dy;
        std::cout << "Moved to (" << centerX << ", " << centerY << ")\n";
    }
};

class Triangle : public Figure {
public:
    Triangle(double x, double y) : Figure(x, y) {}

    void draw() override {
        visible = true;
        std::cout << "Triangle shown at (" << centerX << ", " << centerY
                  << "), angle = " << angle << ", scale = " << scale << '\n';
    }
};

class Quadrilateral : public Figure {
public:
    Quadrilateral(double x, double y) : Figure(x, y) {}

    void draw() override {
        visible = true;
        std::cout << "Quadrilateral shown at (" << centerX << ", " << centerY
                  << "), angle = " << angle << ", scale = " << scale << '\n';
    }
};

class Polygon : public Figure {
private:
    int sides;

public:
    Polygon(double x, double y, int count) : Figure(x, y), sides(count) {}

    void draw() override {
        visible = true;
        std::cout << "Polygon with " << sides << " sides shown at (" << centerX
                  << ", " << centerY << "), angle = " << angle
                  << ", scale = " << scale << '\n';
    }
};

int main() {
    std::vector<std::unique_ptr<Figure>> figures;
    figures.push_back(std::make_unique<Triangle>(1, 1));
    figures.push_back(std::make_unique<Quadrilateral>(4, 2));
    figures.push_back(std::make_unique<Polygon>(0, 0, 6));

    for (auto& fig : figures) {
        fig->draw();
        fig->rotate(15);
        fig->move(2, 3);
        fig->hide();
        std::cout << '\n';
    }

    return 0;
}
