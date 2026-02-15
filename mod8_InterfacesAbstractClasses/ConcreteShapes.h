#ifndef CONCRETE_SHAPES_H
#define CONCRETE_SHAPES_H

#include "AbstractShape.h"
#include "IDrawable.h"
#include "IPrintable.h"

/**
 * Circle - Concrete class inheriting from abstract class
 * and implementing multiple interfaces
 * 
 * Demonstrates:
 * - Inheriting from abstract class (AbstractShape)
 * - Implementing multiple interfaces (IDrawable, IPrintable)
 * - Providing concrete implementations for all pure virtual functions
 */
class Circle : public AbstractShape, public IDrawable, public IPrintable {
private:
    double radius;
    int posX, posY;  // For IDrawable position
    
public:
    Circle(double r, const std::string& color = "red");
    
    // Must implement AbstractShape pure virtual functions
    double area() const override;
    double perimeter() const override;
    
    // Can override virtual functions
    void display() const override;
    
    // Must implement IDrawable interface
    void draw() const override;
    void resize(double factor) override;
    void moveTo(int x, int y) override;
    
    // Must implement IPrintable interface
    std::string toString() const override;
    void print() const override;
    
    // Circle-specific methods
    double getRadius() const;
    void setRadius(double r);
};

/**
 * Rectangle - Another concrete class
 * 
 * Demonstrates:
 * - Different implementation of same abstract class
 * - Same interfaces with different behavior
 */
class Rectangle : public AbstractShape, public IDrawable, public IPrintable {
private:
    double width;
    double height;
    int posX, posY;
    
public:
    Rectangle(double w, double h, const std::string& color = "blue");
    
    // AbstractShape implementations
    double area() const override;
    double perimeter() const override;
    void display() const override;
    
    // IDrawable implementations
    void draw() const override;
    void resize(double factor) override;
    void moveTo(int x, int y) override;
    
    // IPrintable implementations
    std::string toString() const override;
    void print() const override;
    
    // Rectangle-specific methods
    double getWidth() const;
    double getHeight() const;
};

/**
 * Triangle - Concrete class with minimal interface implementation
 * 
 * Demonstrates:
 * - Implementing only what's needed
 * - Not all classes need all interfaces
 */
class Triangle : public AbstractShape {
private:
    double side1, side2, side3;
    
public:
    Triangle(double s1, double s2, double s3, const std::string& color = "green");
    
    // AbstractShape implementations (required)
    double area() const override;  // Using Heron's formula
    double perimeter() const override;
    
    // Note: Triangle doesn't implement IDrawable or IPrintable
    // This shows flexibility in design
};

#endif // CONCRETE_SHAPES_H
