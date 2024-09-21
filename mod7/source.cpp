#include "Integer.h"
#include <memory>

void Display(Integer *p1){
    if(p1 == nullptr){
        return;
    }
    std::cout << p1->getValue() << std::endl;
}

//By value will invoke copy constructor which is deleted in unique ptr
//void store(std::unique_ptr<Integer> p){ -----> Not Allowed
void store(std::unique_ptr<Integer> &p){
    // operations
}

int main(){
    std::unique_ptr<Integer> p1(new Integer);
    if(p1 == nullptr){
        //normally we would do p1 = new Integer but in unique ptr this cannot be done 
        p1.reset(new Integer);
    }
    p1->setValue(10);
    // as we know p1 is object of unique ptr so to get underlinning type Integer we use get()
    Display(p1.get());
    //.. operations
    /**
     * after use we would generally do these operations 
     * delete p1;
     * p1 = nullptr;
     * p1 = new Integer;
     * but unique ptr does this automatically
     */
    p1.reset(new Integer);
    // * operator is overloaded , so we 
    *p1 = __Line__;

    /**
     * Copy constructor is deleted in unique ptr , so store(p1) cannot be performed]
     * If we dont want that p1 here anymore then it can be moved while calling a function like below 
     * store(std::move(p1));
     * It can also be passed by reference , in that case this p1 can still be used in this function
     * store(p1);
     */
    store(std::move(p1));
    store(p1);
}