#include <iostream>
#include <vector>
#include <memory>
#include "AbstractShape.h"
#include "ConcreteShapes.h"
#include "IDrawable.h"
#include "IPrintable.h"

using namespace std;

// ============================================================================
// DEMONSTRATION FUNCTIONS
// ============================================================================

/**
 * Demonstrates what you CANNOT do with abstract classes/interfaces
 */
void demonstrateWhatNotToDo() {
    cout << "\n========================================" << endl;
    cout << "WHAT YOU CANNOT DO" << endl;
    cout << "========================================\n" << endl;
    
    cout << "The following would NOT compile (commented out):\n" << endl;
    cout << "// AbstractShape shape;              // ERROR: Cannot instantiate abstract class" << endl;
    cout << "// AbstractShape* ptr = new AbstractShape(\"test\"); // ERROR!" << endl;
    cout << "// IDrawable drawable;                // ERROR: Cannot instantiate interface" << endl;
    cout << "// IDrawable* ptr = new IDrawable();  // ERROR!" << endl;
    cout << "\nYou MUST create objects of concrete classes!\n" << endl;
}

/**
 * Demonstrates correct ways to create and use objects
 */
void demonstrateCorrectInitialization() {
    cout << "\n========================================" << endl;
    cout << "CORRECT INITIALIZATION METHODS" << endl;
    cout << "========================================\n" << endl;
    
    // Method 1: Direct instantiation of concrete class
    cout << "--- Method 1: Direct Instantiation ---" << endl;
    Circle circle(5.0, "red");
    circle.display();
    cout << endl;
    
    // Method 2: Pointer to base (AbstractShape), object of derived
    cout << "--- Method 2: Base Pointer to Derived Object ---" << endl;
    AbstractShape* shapePtr = new Rectangle(10.0, 5.0, "blue");
    shapePtr->display();
    cout << "Area via base pointer: " << shapePtr->area() << endl;
    delete shapePtr;
    cout << endl;
    
    // Method 3: Interface pointer to concrete object
    cout << "--- Method 3: Interface Pointer ---" << endl;
    IDrawable* drawablePtr = new Circle(3.0, "green");
    drawablePtr->draw();
    drawablePtr->resize(2.0);
    drawablePtr->draw();
    delete drawablePtr;
    cout << endl;
    
    // Method 4: Reference to base
    cout << "--- Method 4: Reference to Base ---" << endl;
    Rectangle rect(8.0, 4.0, "yellow");
    AbstractShape& shapeRef = rect;
    cout << "Name: " << shapeRef.getName() << endl;
    cout << "Area: " << shapeRef.area() << endl;
    cout << endl;
    
    // Method 5: Smart pointers (modern C++)
    cout << "--- Method 5: Smart Pointers (Modern C++) ---" << endl;
    unique_ptr<AbstractShape> smartPtr = make_unique<Circle>(7.0, "purple");
    smartPtr->display();
    cout << "(Smart pointer will auto-delete, no memory leak!)" << endl;
    cout << endl;
}

/**
 * Demonstrates polymorphism with abstract classes
 */
void demonstratePolymorphism() {
    cout << "\n========================================" << endl;
    cout << "POLYMORPHISM DEMONSTRATION" << endl;
    cout << "========================================\n" << endl;
    
    // Create a collection of different shapes
    vector<AbstractShape*> shapes;
    shapes.push_back(new Circle(5.0, "red"));
    shapes.push_back(new Rectangle(10.0, 5.0, "blue"));
    shapes.push_back(new Triangle(3.0, 4.0, 5.0, "green"));
    
    cout << "Processing different shapes polymorphically:\n" << endl;
    
    // Process all shapes through base class pointer
    for (size_t i = 0; i < shapes.size(); i++) {
        cout << "Shape " << (i + 1) << ":" << endl;
        cout << "  Name: " << shapes[i]->getName() << endl;
        cout << "  Color: " << shapes[i]->getColor() << endl;
        cout << "  Area: " << shapes[i]->area() << endl;
        cout << "  Perimeter: " << shapes[i]->perimeter() << endl;
        cout << endl;
    }
    
    // Cleanup
    for (auto* shape : shapes) {
        delete shape;
    }
}

/**
 * Demonstrates multiple interface inheritance
 */
void demonstrateMultipleInterfaces() {
    cout << "\n========================================" << endl;
    cout << "MULTIPLE INTERFACE IMPLEMENTATION" << endl;
    cout << "========================================\n" << endl;
    
    cout << "Circle implements: AbstractShape + IDrawable + IPrintable\n" << endl;
    
    Circle circle(6.0, "orange");
    
    // Use as AbstractShape
    cout << "--- Using as AbstractShape ---" << endl;
    AbstractShape* shapePtr = &circle;
    cout << "Area: " << shapePtr->area() << endl;
    cout << endl;
    
    // Use as IDrawable
    cout << "--- Using as IDrawable ---" << endl;
    IDrawable* drawablePtr = &circle;
    drawablePtr->draw();
    drawablePtr->moveTo(10, 20);
    cout << endl;
    
    // Use as IPrintable
    cout << "--- Using as IPrintable ---" << endl;
    IPrintable* printablePtr = &circle;
    printablePtr->print();
    cout << "String representation: " << printablePtr->toString() << endl;
    cout << endl;
    
    cout << "Same object, multiple interfaces - This is the power of interfaces!\n" << endl;
}

/**
 * Demonstrates interface collections
 */
void demonstrateInterfaceCollections() {
    cout << "\n========================================" << endl;
    cout << "INTERFACE COLLECTIONS" << endl;
    cout << "========================================\n" << endl;
    
    // Collection of drawable objects
    cout << "--- Collection of IDrawable objects ---" << endl;
    vector<IDrawable*> drawables;
    drawables.push_back(new Circle(4.0, "cyan"));
    drawables.push_back(new Rectangle(6.0, 3.0, "magenta"));
    
    for (size_t i = 0; i < drawables.size(); i++) {
        cout << "Drawing object " << (i + 1) << ":" << endl;
        drawables[i]->draw();
        cout << endl;
    }
    
    // Collection of printable objects
    cout << "--- Collection of IPrintable objects ---" << endl;
    vector<IPrintable*> printables;
    printables.push_back(new Circle(3.0, "pink"));
    printables.push_back(new Rectangle(5.0, 5.0, "brown"));
    
    for (size_t i = 0; i < printables.size(); i++) {
        cout << "Printable " << (i + 1) << ": ";
        printables[i]->print();
    }
    cout << endl;
    
    // Cleanup
    for (auto* d : drawables) delete d;
    for (auto* p : printables) delete p;
}

/**
 * Demonstrates practical use case: Shape factory
 */
AbstractShape* createShape(const string& type) {
    if (type == "circle") {
        return new Circle(5.0);
    } else if (type == "rectangle") {
        return new Rectangle(10.0, 5.0);
    } else if (type == "triangle") {
        return new Triangle(3.0, 4.0, 5.0);
    }
    return nullptr;
}

void demonstratePracticalUsage() {
    cout << "\n========================================" << endl;
    cout << "PRACTICAL USAGE: FACTORY PATTERN" << endl;
    cout << "========================================\n" << endl;
    
    vector<string> shapeTypes = {"circle", "rectangle", "triangle"};
    
    for (const auto& type : shapeTypes) {
        AbstractShape* shape = createShape(type);
        if (shape) {
            cout << "Created " << type << ":" << endl;
            shape->display();
            delete shape;
            cout << endl;
        }
    }
}

/**
 * Demonstrates the difference between abstract class and interface
 */
void demonstrateDifferences() {
    cout << "\n========================================" << endl;
    cout << "KEY DIFFERENCES DEMONSTRATED" << endl;
    cout << "========================================\n" << endl;
    
    cout << "1. ABSTRACT CLASS (AbstractShape):" << endl;
    cout << "   - Has data members (name, color)" << endl;
    cout << "   - Has constructor" << endl;
    cout << "   - Has regular methods (getName, setColor)" << endl;
    cout << "   - Has pure virtual methods (area, perimeter)" << endl;
    cout << "   - Provides partial implementation\n" << endl;
    
    Circle c(5.0, "red");
    cout << "   Circle uses AbstractShape's getName(): " << c.getName() << endl;
    cout << "   Circle implements its own area(): " << c.area() << endl;
    cout << endl;
    
    cout << "2. INTERFACE (IDrawable, IPrintable):" << endl;
    cout << "   - NO data members" << endl;
    cout << "   - NO implementation (only pure virtual)" << endl;
    cout << "   - Defines CONTRACT only" << endl;
    cout << "   - Safe for multiple inheritance\n" << endl;
    
    cout << "   Circle implements BOTH IDrawable AND IPrintable" << endl;
    cout << "   This demonstrates safe multiple inheritance with interfaces!" << endl;
    cout << endl;
}

// ============================================================================
// MAIN FUNCTION
// ============================================================================

int main() {
    cout << "\n**************************************************" << endl;
    cout << "*  INTERFACE vs ABSTRACT CLASS in C++          *" << endl;
    cout << "*  Comprehensive Tutorial with Examples        *" << endl;
    cout << "**************************************************" << endl;
    
    try {
        // 1. Show what NOT to do
        demonstrateWhatNotToDo();
        
        // 2. Show correct initialization methods
        demonstrateCorrectInitialization();
        
        // 3. Demonstrate polymorphism
        demonstratePolymorphism();
        
        // 4. Demonstrate multiple interfaces
        demonstrateMultipleInterfaces();
        
        // 5. Demonstrate interface collections
        demonstrateInterfaceCollections();
        
        // 6. Demonstrate practical usage
        demonstratePracticalUsage();
        
        // 7. Demonstrate key differences
        demonstrateDifferences();
        
        cout << "\n========================================" << endl;
        cout << "KEY TAKEAWAYS" << endl;
        cout << "========================================" << endl;
        cout << "✓ Cannot instantiate abstract classes or interfaces directly" << endl;
        cout << "✓ Must create concrete derived classes" << endl;
        cout << "✓ Use pointers/references to base for polymorphism" << endl;
        cout << "✓ Abstract classes provide shared implementation" << endl;
        cout << "✓ Interfaces define pure contracts" << endl;
        cout << "✓ Interfaces enable safe multiple inheritance" << endl;
        cout << "✓ Always use virtual destructors" << endl;
        cout << "✓ Use 'override' keyword for safety" << endl;
        cout << "\n**************************************************" << endl;
        cout << "*          Program Completed Successfully       *" << endl;
        cout << "**************************************************\n" << endl;
        
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }
    
    return 0;
}
