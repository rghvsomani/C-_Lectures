#pragma once
#include <iostream>

class Integer {
    int *ptr;
public: 
    Integer();
    Integer(int value);
    ~Integer();
    int getValue() const;
    void setValue(const int value);
    // Reference is imp warna yeh argument ke aane ke liye integer object ka phir ek copy banega so recursive ho jaayega
    Integer(const Integer &obj);
    //Move Constructor
    Integer(Integer && obj);
    // Move contructor

    // Operator overloading as a memeber function
   Integer operator+(const Integer &a) const;

   // overloading operator preincrement 

   Integer & operator ++() ; 

   // overloading post operator -- code not working for now 
   Integer operator ++(int);

   // overloading ==

   bool operator ==(const Integer &a) const;

    // overloading assignment operator 
    Integer & operator = (const Integer &a);

    // Move assignment operator
    Integer & operator =(Integer && a);

    //Overloading fnction call operator -- > for now we are just print val of obj
    void operator ()();

    friend std::istream & operator >>(std::istream & in , Integer &a);

    // we can also make a class friend of another class
    friend class print;

    // overload type cast operator
    operator int();
};

class print {
    // Have access to private protected public members of Integer class
};
/**
 * Note :- As friend function gives access to all members of class , so it should be used carefully
 * using this as last solution for a problem
*/