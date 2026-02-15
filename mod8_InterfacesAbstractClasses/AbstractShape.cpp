#include "AbstractShape.h"
#include <iostream>

// Constructor implementation
AbstractShape::AbstractShape(const std::string& shapeName, const std::string& shapeColor)
    : name(shapeName), color(shapeColor) {
    std::cout << "AbstractShape constructor called for: " << name << std::endl;
}

// Destructor implementation
AbstractShape::~AbstractShape() {
    std::cout << "AbstractShape destructor called for: " << name << std::endl;
}

// Default implementation of virtual function
void AbstractShape::display() const {
    std::cout << "Shape: " << name 
              << ", Color: " << color 
              << ", Area: " << area() 
              << ", Perimeter: " << perimeter() << std::endl;
}

// Regular member function implementations
std::string AbstractShape::getName() const {
    return name;
}

void AbstractShape::setColor(const std::string& newColor) {
    color = newColor;
}

std::string AbstractShape::getColor() const {
    return color;
}
