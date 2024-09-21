#include "Integer.h"
#include <iostream>
using namespace std;

int main(){
    Integer i1(10);

    // Calls the parameterized constructor
    i1 = 20;

    int x = i1;
    cout<<"Value of x is "<<x<<endl;
}