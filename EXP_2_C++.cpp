#include <iostream>
#include <memory>
#include <vector>

class Shape {
    public:
        virtual double area() const = 0;
        virtual ~Shape() = default;
};
class Circle : public Shape {
    double radius;
    public:
        explicit Circle(double r) : radius(r) {}
        double area() const override { return 3.141592653589793 * radius * radius; }
};
class Rectangle : public Shape {
    double length, breadth;
    public:
        Rectangle(double l, double b) : length(l), breadth(b) {}
        double area() const override { return length * breadth; }
};
class Triangle : public Shape {
    double base, height;
    public:
        Triangle(double b, double h) : base(b), height(h) {}
        double area() const override { return 0.5 * base * height; }
};
int main() {
    double radius, length, breadth, base, height;

    std::cout << "Enter circle radius: ";
    std::cin >> radius;

    std::cout << "Enter rectangle length and breadth: ";
    std::cin >> length >> breadth;

    std::cout << "Enter triangle base and height: ";
    std::cin >> base >> height;

    Circle circle(radius);
    Rectangle rectangle(length, breadth);
    Triangle triangle(base, height);

    std::cout << "Area of Circle: " << circle.area() << '\n';
    std::cout << "Area of Rectangle: " << rectangle.area() << '\n';
    std::cout << "Area of Triangle: " << triangle.area() << '\n';
}