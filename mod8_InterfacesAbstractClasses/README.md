# Interface vs Abstract Class in C++

## Overview
C++ doesn't have a native `interface` keyword like Java or C#, but we can create interfaces using abstract classes. Understanding the difference between interfaces and abstract classes is crucial for good object-oriented design.

---

## Abstract Class

### Definition
An **abstract class** is a class that:
- Contains at least one **pure virtual function** (function with `= 0`)
- **Cannot be instantiated** directly
- Can have data members, constructors, and regular member functions
- Can provide partial implementation that derived classes inherit
- Used to establish a common base with shared functionality

### Syntax
```cpp
class AbstractClass {
protected:
    int data;  // Can have data members
    
public:
    AbstractClass(int val) : data(val) {}  // Can have constructors
    
    virtual void pureVirtualFunction() = 0;  // Pure virtual (must override)
    
    virtual void virtualFunction() {  // Regular virtual (can override)
        // Default implementation
    }
    
    void regularFunction() {  // Non-virtual function
        // Inherited as-is
    }
    
    virtual ~AbstractClass() {}  // Virtual destructor
};
```

---

## Interface

### Definition
An **interface** in C++ is a special case of abstract class that:
- Contains **ONLY pure virtual functions**
- **No data members** (except static const)
- **No implementation** of methods (except virtual destructor)
- Defines a contract/behavior that classes must implement
- Allows multiple inheritance without diamond problem issues

### Syntax
```cpp
class IInterface {
public:
    virtual void method1() = 0;
    virtual void method2() = 0;
    virtual void method3() = 0;
    
    virtual ~IInterface() {}  // Virtual destructor (required)
};
```

**Naming Convention**: Prefix interface names with 'I' (e.g., IDrawable, IPrintable, ISerializable)

---

## Key Differences

| Feature | Abstract Class | Interface |
|---------|---------------|-----------|
| Pure Virtual Functions | At least one | All functions |
| Regular Functions | Can have | Should not have |
| Data Members | Can have | Should not have (except static const) |
| Constructors | Can have | Typically don't have |
| Multiple Inheritance | Complex (diamond problem) | Safe and common |
| Purpose | Share implementation + behavior | Define contract only |
| Flexibility | Less flexible for MI | More flexible for MI |

---

## When to Use What

### Use Abstract Class When:
1. **Shared Implementation**: You have common code that multiple derived classes should share
2. **Common State**: You need shared data members
3. **Partial Implementation**: Some methods have default behavior, others are abstract
4. **Single Inheritance**: You're designing a single inheritance hierarchy
5. **Template Method Pattern**: You want to define the skeleton of an algorithm

**Example Use Cases:**
- Shape hierarchy (Shape → Circle, Rectangle)
- Animal hierarchy (Animal → Dog, Cat)
- Document classes with common file handling

### Use Interface When:
1. **Contract Definition**: You want to define what a class can do, not how
2. **Multiple Capabilities**: A class needs to implement multiple unrelated behaviors
3. **Decoupling**: You want loose coupling between components
4. **Multiple Inheritance**: You need to inherit from multiple sources
5. **Plugin Architecture**: You're defining contracts for external implementations

**Example Use Cases:**
- Comparable interface (IComparable)
- Drawable interface (IDrawable)
- Serializable interface (ISerializable)
- Clonable interface (IClonable)

---

## Object Initialization

### IMPORTANT: You CANNOT instantiate abstract classes or interfaces directly!

```cpp
// ❌ WRONG - This will NOT compile
IInterface* obj = new IInterface();  // ERROR!
AbstractClass obj;                    // ERROR!
```

### Correct Ways to Use:

#### 1. Create Concrete Derived Class
```cpp
class ConcreteClass : public IInterface {
public:
    void method1() override { /* implementation */ }
    void method2() override { /* implementation */ }
    void method3() override { /* implementation */ }
};

// ✓ Correct - Create object of concrete class
ConcreteClass obj;
```

#### 2. Use Pointers/References to Base
```cpp
// ✓ Correct - Pointer to base, object of derived
IInterface* ptr = new ConcreteClass();
ptr->method1();  // Calls ConcreteClass implementation
delete ptr;

// ✓ Correct - Reference to base
ConcreteClass concrete;
IInterface& ref = concrete;
ref.method2();  // Calls ConcreteClass implementation
```

#### 3. Polymorphic Collections
```cpp
// ✓ Correct - Store different implementations via base pointer
std::vector<IInterface*> objects;
objects.push_back(new ConcreteClass1());
objects.push_back(new ConcreteClass2());

for (auto* obj : objects) {
    obj->method1();  // Polymorphic call
}
```

---

## Complete Example Structure

This module contains the following examples:

1. **AbstractShape.h/cpp** - Abstract class example with shared implementation
2. **IDrawable.h** - Pure interface example
3. **IPrintable.h** - Another interface example
4. **ConcreteShapes.h/cpp** - Concrete implementations demonstrating both
5. **main.cpp** - Comprehensive usage examples and demonstrations

---

## Key Takeaways

✅ **Abstract classes** provide partial implementation and shared state  
✅ **Interfaces** define pure contracts without implementation  
✅ Neither can be instantiated directly  
✅ Always use pointers/references to base for polymorphism  
✅ Interfaces enable safe multiple inheritance  
✅ Virtual destructors are essential in both cases  
✅ Use `override` keyword in C++11+ for clarity and safety  

---

## Compilation Instructions

```bash
# Compile all examples
g++ -std=c++11 *.cpp -o program

# Run the program
./program
```

---

## Additional Resources

- **Pure Virtual Functions**: Must be overridden in derived classes
- **Virtual Destructor**: Ensures proper cleanup in polymorphic hierarchies
- **Override Keyword**: C++11 feature that catches override mistakes at compile time
- **Multiple Inheritance**: Use interfaces to avoid diamond problem complexity
