#include <iostream>
#include <string>

class Shape {
public:
    virtual double getArea() const = 0;
    virtual double getPerimeter() const = 0;
    virtual void printInfo() const = 0;
};

class Polygon : public Shape {
public:
    virtual double getArea() const override {
        // Вычисление площади многоугольника
        return 0.0;
    }

    virtual double getPerimeter() const override {
        // Вычисление периметра многоугольника
        return 0.0;
    }

    virtual void printInfo() const override {
        std::cout << "Polygon Info\n";
    }
};

class Ellipse : public Shape {
public:
    virtual double getArea() const override {
        // Вычисление площади эллипса
        return 0.0;
    }

    virtual double getPerimeter() const override {
        // Вычисление периметра эллипса
        return 0.0;
    }

    virtual void printInfo() const override {
        std::cout << "Ellipse Info\n";
    }
};

int main() {
    Polygon polygon;
    Ellipse ellipse;

    Shape* shape1 = &polygon;
    Shape* shape2 = &ellipse;

    shape1->printInfo();
    std::cout << "Area: " << shape1->getArea() << ", Perimeter: " << shape1->getPerimeter() << std::endl;

    shape2->printInfo();
    std::cout << "Area: " << shape2->getArea() << ", Perimeter: " << shape2->getPerimeter() << std::endl;

    return 0;
}
