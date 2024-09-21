//how this returns r-value
int add(int a, int b){
    return a+b;
}
//and below function returns l-value
int& add(int &a){
    a *= a;
    return a;
}

int main(){
    //x,y are l-value and 10,20 are r-value
    int x = 10 , y = 20;
    //z is l-value and add(x,y) is r-value
    int z = add(x,y);
    //expression returns r-value
    int a = (x + y ) *z;
    //expression returns l-value
    ++x = 6;
}

