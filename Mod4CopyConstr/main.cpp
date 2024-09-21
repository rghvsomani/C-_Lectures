#include "Integer.h"
#include <iostream>
using namespace std;

// copy constructor is called to copy the object to i from passed argument
void print(Integer i){
    cout<<i.getValue()<<endl;
}

Integer add(Integer i1 , Integer i2){
    //copy constructor is called as we are return Integer object
    return Integer(i1.getValue() + i2.getValue());
}
int main(){
    int *p2  = new int(10);
    //Shallow copy , matlab p1 me yeh p2 ka address store karta hai , so any changes done in p2 reflects in p1
    int *p1 = p2;
    //deep copy , p3 address me p2 ka value copy kar rhe hai , so p2 me koi bhi changes p3 me nahi aayenge
    int *p3 = new int(*p2);

    // Copy 
    Integer i1(10);
    Integer i2;
}