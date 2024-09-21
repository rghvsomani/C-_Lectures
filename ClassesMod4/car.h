#pragma once

class Car {
    private :
        int speed ;
        int passengers;
        int fuel; 
        static int totalCount;
    public:
        Car();
        Car(float amount);
        Car(float amount , int count);
        ~Car();
        void setPassengers(int count);
        void Accelerate();
        void Fillfuel(float amount);
        void Brake();
        void Dashboard();
        static void DisplayTotalCarsObjects();
};