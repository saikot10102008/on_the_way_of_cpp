#include <iostream>
#include <string>

// A reference variable is an alias for an existing variable. It is created using the & operator:
// If you change the value of a reference variable, the original variable will also change (and vice versa), because they both refer to the same memory location

int main(){

    std::string a = "checking reference variable";
    std::string &b = a;
    // now both refer to the same value;
    // let's check
    std::cout<<a<<" "<<b;

    // changing value of any one of both will reflect to both
    // such as changing the value of b variable will also change the value of a variable and vice versa
}
