#include "Integer.h"
#include <iostream>
using namespace std;

// Code crashes , not sure why  ?

class product {
    Integer i;
    public: 
    product(const Integer &a) : i{a}
    {
        std::cout<<"Product constructor called"<<std::endl;
    }
    const Integer & getInteger() const {
        return i;
    }
    operator Integer(){
        return i;
    }
};
int main()
{
    product p{10};
    Integer i{10};

    if(i == p.getInteger()){
        std::cout<<"i == p.getInteger()"<<std::endl;
    }
    if(i == p){
        std::cout<<"i == p"<<std::endl;
    }
}