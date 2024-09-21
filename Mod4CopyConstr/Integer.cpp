#include "Integer.h"
#include <iostream>

Integer::Integer(){
    ptr = new int(0);
}

Integer::Integer(int value){
    ptr = new int(value);
}

Integer::Integer(const Integer &obj){
    int *ptr2 = new int(*obj.ptr);
}

int Integer::getValue() const
{
    return *ptr;
}

void Integer::setValue(int value){
    *ptr  = value;
}

Integer::~Integer()
{
    delete ptr;
}

class Integer2{
    int m_val;
    public :
    /**
     * When paramtized constructor is defined and default construct is not defined then 
     * we will gwt error as compiler will not able to generate default constructor
     * SO , we can set Normal constructor as default constructor by setting default value to the parameter
     */
    // Integer2()
    // {
    //     m_val= 0 ;
    // }
    Integer2() = default;
    Integer2(int value){
        m_val = value;
    }
    /**
     * Suppose we dont want to copy the object , then we can delete the copy constructor
     */
    Integer2(const Integer2 & obj) = delete;

    /**
     * Suppose we dont want to set float value to the object , then we can delete the function
     */
    void setValue(int value){
        m_val = value;
    }
    void setValue(float value) = delete;
};

int main(){
    Integer2 i1;
    Integer i2(2);
}
