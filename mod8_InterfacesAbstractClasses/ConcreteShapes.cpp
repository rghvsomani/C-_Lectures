#include "ConcreteShapes.h"
#include <iostream>
#include <sstream>
#include <cmath>

// ============================================================================
// Circle Implementation
// ============================================================================

Circle::Circle(double r, const std::string& color)
    : AbstractShape("Circle", color), radius(r), posX(0), posY(0) {
    std::cout << "Circle constructor called" << std::endl;
}

double Circle::area() const {
    return 3.14159 * radius * radius;
}

double Circle::perimeter() const {
    return 2 * 3.14159 * radius;
}

void Circle::display() const {
    std::cout << "=== Circle Display ===" << std::endl;
    AbstractShape::display();  // Call base class implementation
    std::cout << "Radius: " << radius << std::endl;
    std::cout << "Position: (" << posX << ", " << posY << ")" << std::endl;
}

void Circle::draw() const {
    std::cout << "Drawing Circle at (" << posX << ", " << posY 
              << ") with radius " << radius 
              << " in color " << getColor() << std::endl;
    std::cout << "    O" << std::endl;
    std::cout << "   O O" << std::endl;
    std::cout << "    O" << std::endl;
}

void Circle::resize(double factor) {
    radius *= factor;
    std::cout << "Circle resized by factor " << factor 
              << ". New radius: " << radius << std::endl;
}

void Circle::moveTo(int x, int y) {
    posX = x;
    posY = y;
    std::cout << "Circle moved to (" << x << ", " << y << ")" << std::endl;
}

std::string Circle::toString() const {
    std::ostringstream oss;
    oss << "Circle[radius=" << radius 
        << ", color=" << getColor() 
        << ", area=" << area() << "]";
    return oss.str();
}

void Circle::print() const {
    std::cout << toString() << std::endl;
}

double Circle::getRadius() const {
    return radius;
}

void Circle::setRadius(double r) {
    radius = r;
}

// ============================================================================
// Rectangle Implementation
// ============================================================================

Rectangle::Rectangle(double w, double h, const std::string& color)
    : AbstractShape("Rectangle", color), width(w), height(h), posX(0), posY(0) {
    std::cout << "Rectangle constructor called" << std::endl;
}

double Rectangle::area() const {
    return width * height;
}

double Rectangle::perimeter() const {
    return 2 * (width + height);
}

void Rectangle::display() const {
    std::cout << "=== Rectangle Display ===" << std::endl;
    AbstractShape::display();
    std::cout << "Width: " << width << ", Height: " << height << std::endl;
    std::cout << "Position: (" << posX << ", " << posY << ")" << std::endl;
}

void Rectangle::draw() const {
    std::cout << "Drawing Rectangle at (" << posX << ", " << posY 
              << ") with dimensions " << width << "x" << height 
              << " in color " << getColor() << std::endl;
    std::cout << "  +-----+" << std::endl;
    std::cout << "  |     |" << std::endl;
    std::cout << "  +-----+" << std::endl;
}

void Rectangle::resize(double factor) {
    width *= factor;
    height *= factor;
    std::cout << "Rectangle resized by factor " << factor 
              << ". New dimensions: " << width << "x" << height << std::endl;
}

void Rectangle::moveTo(int x, int y) {
    posX = x;
    posY = y;
    std::cout << "Rectangle moved to (" << x << ", " << y << ")" << std::endl;
}

std::string Rectangle::toString() const {
    std::ostringstream oss;
    oss << "Rectangle[width=" << width 
        << ", height=" << height 
        << ", color=" << getColor() 
        << ", area=" << area() << "]";
    return oss.str();
}

void Rectangle::print() const {
    std::cout << toString() << std::endl;
}

double Rectangle::getWidth() const {
    return width;
}

double Rectangle::getHeight() const {
    return height;
}

// ============================================================================
// Triangle Implementation
// ============================================================================

Triangle::Triangle(double s1, double s2, double s3, const std::string& color)
    : AbstractShape("Triangle", color), side1(s1), side2(s2), side3(s3) {
    std::cout << "Triangle constructor called" << std::endl;
}

double Triangle::area() const {
    // Using Heron's formula: A = sqrt(s(s-a)(s-b)(s-c))
    // where s = (a+b+c)/2
    double s = (side1 + side2 + side3) / 2.0;
    return std::sqrt(s * (s - side1) * (s - side2) * (s - side3));
}

double Triangle::perimeter() const {
    return side1 + side2 + side3;
}
