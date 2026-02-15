#ifndef IDRAWABLE_H
#define IDRAWABLE_H

/**
 * IDrawable - An INTERFACE example (Pure Interface)
 * 
 * Key Features:
 * - ONLY pure virtual functions
 * - NO data members
 * - NO implementation (except virtual destructor)
 * - Defines a CONTRACT that implementing classes must fulfill
 * - Prefix 'I' indicates this is an interface
 * 
 * Use Case: Any object that can be drawn on screen
 */
class IDrawable {
public:
    // Pure virtual functions - define the contract
    virtual void draw() const = 0;
    virtual void resize(double factor) = 0;
    virtual void moveTo(int x, int y) = 0;
    
    // Virtual destructor - REQUIRED for proper cleanup
    virtual ~IDrawable() {}
};

#endif // IDRAWABLE_H
