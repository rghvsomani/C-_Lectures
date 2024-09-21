#include "car.h"
#include <iostream>
int Car::totalCount = 0;
// delegating to constructor having 1 arg
Car::Car() : Car(0)
{
    std::cout<<"Car()"<<std::endl;
}

// delegating to constructor having both arg
Car::Car(float amount) : Car(amount , 0)
{
    std::cout<<"Car(float amount)"<<std::endl;
}

Car::Car(float amount , int count){
    ++totalCount;
    std::cout<<"Car(float amount , int count)"<<std::endl;
    fuel = amount;
    passengers = count;
    speed  = 0;
}

Car::~Car()
{
    --totalCount;
    std::cout<<"~Call()"<<std::endl;
}

void Foo(const Car &c){
    //
}

void Car::setPassengers(int passengers)
{
    this->passengers = passengers;

    // For Foo we have to pass object of class car , so we use `this` pointer 
    //Note :- this is pointer to we need to dereference it to get the value
    Foo(*this);
}

void Car::Accelerate()
{
    speed++;
    fuel -= 0.5f;
}

void Car::Fillfuel(float amount)
{
    fuel = amount;
}

void Car::Brake()
{
    speed = 0;
}

void Car::Dashboard()
{
    std::cout<<"Speed : "<<speed<<std::endl;
    std::cout<<"Passengers : "<<passengers<<std::endl;
    std::cout<<"Fuel : "<<fuel<<std::endl;
    std::cout<<"-----------------"<<std::endl;
}

void Car::DisplayTotalCarsObjects()
{
    std::cout<<"Total objs "<<totalCount<<std::endl;
}
