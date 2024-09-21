#include "Integer.h"
#include <iostream>
using namespace std;

Integer Add(Integer i1 , Integer i2){
    Integer temp;
    temp.setValue(i1.getValue() + i2.getValue());
    /**
     * When move contructor is not defined return an object temp will create a copy and invoke copy constructor 
     */
    return temp;
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