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

Integer::Integer(Integer &&obj)
{
    ptr= obj.ptr;
    obj.ptr = nullptr;
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