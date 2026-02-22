#include<iostream>

int main(){

    // Logical operators ->
    // 1. && -> and operator which performs and operation, 
    // in other words if both operand is true then it will 
    // result in true otherwise false
    // 2. || -> or operator which performs or operation
    // or operator returns true if one of two operands is true
    // 3. ! -> not operator which revreses the logical state of its operator

    int a = 1 , b = 2 , c =3;

    if(a<b && a<c){
        std::cout<<"it is true\n";
    }else{std::cout<<"it is not true\n";}

    if(a == 1 || a == b){
        std::cout<<"It is true\n";
    }else{std::cout<<"It is false\n";}

    (!false) ? std::cout<<"True" : std::cout<<"False";


}