#include <iostream>

void print(int &a){
    std::cout<<"print(int &a) ---> l-value"<<std::endl;
}
void print(const int &a){
    std::cout<<"print(const int &a) ----> const literals"<<std::endl;
}
void print(int &&a){
    std::cout<<"print(int &&a) ----> r-value"<<std::endl;
}
int main(){
    //Case-1 when 3rd function is commented 
    int x = 10;
    print(x);
    print(3);

    /**
     * Case-2 when all functions are uncommented
     * then print(3) calls third value becausethe compiler looks for the best match among the overloaded functions.
     * 3 is an r-value (a temporary value).
     * The function void print(const int &a) can take both l-values and r-values, but it is not as specific as the r-value reference version.
    */
}