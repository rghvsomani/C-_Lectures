#include "Integer.h"
#include <iostream>

Integer::Integer(){
    std::cout<<"Default constructor called"<<std::endl;
    ptr = new int(0);
}

Integer::Integer(int value){
    std::cout<<"Parameterized constructor called"<<std::endl;
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
    std::cout<<"Value set to "<<*ptr<<std::endl;
}

Integer::~Integer()
{
    std::cout<<"Default destructor called"<<std::endl;
    delete ptr;
}

Integer Integer::operator+(const Integer &a) const
{
    Integer temp;
    *temp.ptr = *ptr + *a.ptr;
    return temp;
}

Integer &  Integer::operator++() 
{
    std::cout<<"Preincrement operator called"<<std::endl;
    ++(*ptr);
    return *this;
    // TODO: insert return statement here
}

Integer Integer::operator++(int)
{
    Integer temp(*this);
    ++(*ptr);
    std::cout<<"Postincrement operator called"<<std::endl;
    return temp;
}

bool Integer::operator==(const Integer &a) const
{
    return (*ptr == *a.ptr);
}

Integer &Integer::operator=(const Integer &a)
{
    // check if the lhs and rhs object are same;
    if(this == &a){
        delete ptr;
        ptr = new int(*a.ptr);
    }
    return *this;
    // TODO: insert return statement here
}

//Move assignment operator -> delete the target loc memory , point target pointer to src loc , src pointer to nullptr 
Integer &Integer::operator=(Integer &&a)
{
    if(this == &a){
        delete ptr;
        ptr = a.ptr;
        a.ptr = nullptr;
    }
    return *this;
}

void Integer::operator()()
{
    std::cout<<"operator()() "<<*ptr<<std::endl;
}

Integer::operator int()
{
    return *ptr;
}
