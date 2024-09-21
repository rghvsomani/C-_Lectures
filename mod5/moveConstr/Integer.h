#pragma once

class Integer {
    int *ptr;
public: 
    Integer();
    Integer(int value);
    // Reference is imp warna yeh argument ke aane ke liye integer object ka phir ek copy banega so recursive ho jaayega
    Integer(const Integer &obj);
    //Move Constructor
    Integer(Integer && obj);
    // Move contructor
    int getValue() const;
    void setValue(const int value);
    ~Integer();
};