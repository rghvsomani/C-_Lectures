#ifndef IPRINTABLE_H
#define IPRINTABLE_H

#include <string>

/**
 * IPrintable - Another INTERFACE example (Pure Interface)
 * 
 * Key Features:
 * - Defines ability to print/convert to string
 * - No implementation, no data
 * - Can be combined with other interfaces (Multiple Inheritance)
 * 
 * Use Case: Any object that can be printed or serialized to string
 */
class IPrintable {
public:
    // Pure virtual functions
    virtual std::string toString() const = 0;
    virtual void print() const = 0;
    
    // Virtual destructor
    virtual ~IPrintable() {}
};

#endif // IPRINTABLE_H
