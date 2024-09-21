#include "Integer.h"
#include <iostream>
using namespace std;

//overloading operator as a global function
Integer operator +(int a ,const Integer &i2) {
    Integer temp;
    temp.setValue(a + i2.getValue());
    return temp;
}

//Overloading operator << :- as it is definded in iostream library , this need to be overloaded as a global function
std::ostream & operator <<(std::ostream & out , const Integer &a){
    out << a.getValue();
    return out;
}

// What is difference when we return in of istream & in or a of Integer &a object , as in both cases code works ? 
// Answer is it will resist chaning of input , cin >>a>>b ; will not work if  a obj is returned 
std::istream & operator >>(std::istream & in , Integer &a){
    int temp;
    in >> temp;
    /**
     * Imagine while using a.setValue(temp) we dont have setValue function in class 
     * and we cannot do *ptr = temp; as ptr is private 
     * so we can make this function as friend function in class Integer
     */
    //a.setValue(temp);
    *a.ptr = temp;
    return in;
}

int main(){
    Integer i1(10) , i2(20) , i4(10);
    Integer i3  = i1 + i2;
    //++i3;
    if(i1 == i4){
        std::cout<<"i1 and i4 are equal"<<std::endl;
    }
    //Not working for now
    //std::cout<<"value of i3 is "<<(i3++).getValue()<<std::endl;

    // operator + overload works for below case , as it is considered as a.operator+(5)
    Integer i5 = i1 + 5; 

    // But if we want to do 5 + i1 , we need to overload operator as a global function
    Integer i6 = 5 + i1;
    cout<<"Value of i6 is "<<i6.getValue()<<endl;

    // for above cout we are using i6.getValue() , but we can also use operator overloading for << operator
    cout<<"Value of i6 is "<<i6<<endl; // This is resolved as operator <<(std::cout , i6).operator <<(std::endl);
    cout<<"Enter a value for i6"<<endl;
    cin >> i6;
    cout<<"New of i6 is "<<i6<<endl;
    i2();

    // Type cast operator overloading -> cast user-defined type to premitive type 
    int x = i1;
    cout<<"Value of x is "<<x<<endl;
}