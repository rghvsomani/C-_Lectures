#include "Integer.h"
#include <iostream>
using namespace std;

class Intptr{
    Integer *ptr;
    public:
    Intptr(Integer *p) : ptr(p){
        
    }
    ~Intptr(){
        delete ptr;
    }
    // To Access getVakue and setValue functions we need access to ptr which is pointer to Integer class 
    // Hence we need to overload -> operator and return ptr , so that we can acces Integer members
    Integer * operator -> (){
        return ptr;
    }
    //Overload dereference operator to access value of Integer object
    Integer & operator * (){
        return *ptr;
    }
};

void unique_process(std::unique_ptr<Integer> p){
    cout<<p->getValue()<<endl;
}

void shared_process(std::shared_ptr<Integer> p){
   cout<<"shared count "<<p.use_count()<<endl; 
    cout<<p->getValue()<<endl;
}

int main(){
    Intptr p = new Integer;
    p->setValue(10);
    (*p).setValue(20);
    cout<<p->getValue()<<endl;

    // Unique pointer
    std::unique_ptr<Integer> u_ptr(new Integer);
    u_ptr->setValue(30);
    /**
     * Below code gets error because unique pointer is not copyable , so we cannot pass it to function
     * but it can be moved to function , using std::move 
     */
    //process(u_ptr);
    /**
     * Note the on moving u_ptr to process function , u_ptr will be nullptr , so we cannot use it after moving
     */
    unique_process(std::move(u_ptr));

    // Shared pointer
    std::shared_ptr<Integer> s_ptr(new Integer );
    s_ptr->setValue(40);
    cout<<"shared count "<<s_ptr.use_count()<<endl; 
    shared_process(s_ptr);
    cout<<"shared count "<<s_ptr.use_count()<<endl;
    cout<<"Value in shared pointer " << s_ptr->getValue()<<endl;
    return 0;
}