#ifndef ABSTRACT_SHAPE_H
#define ABSTRACT_SHAPE_H

#include <string>

/**
 * AbstractShape - An ABSTRACT CLASS example
 * 
 * Key Features:
 * - Has data members (name, color)
 * - Has constructor
 * - Has regular member functions (getName, setColor)
 * - Has pure virtual functions (area, perimeter)
 * - Has virtual function with default implementation (display)
 * - Cannot be instantiated directly
 */
class AbstractShape {
protected:
    std::string name;
    std::string color;
    
public:
    // Constructor - abstract classes CAN have constructors
    AbstractShape(const std::string& shapeName, const std::string& shapeColor = "white");
    
    // Virtual destructor - ESSENTIAL for polymorphism
    virtual ~AbstractShape();
    
    // Pure virtual functions - MUST be implemented by derived classes
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    
    // Virtual function with default implementation - CAN be overridden
    virtual void display() const;
    
    // Regular member functions - inherited as-is
    std::string getName() const;
    void setColor(const std::string& newColor);
    std::string getColor() const;
};

#endif // ABSTRACT_SHAPE_H
