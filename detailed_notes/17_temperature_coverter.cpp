#include <iostream>

int main(){

    double C,F;
    char input;

    std::cout<<"In which scale do you want to convert to? (Celcius = C)/(Fahrenheit = F)\n";
    std::cin>>input;

    if(input == 'C' || input == 'c'){
        std::cout<<"Enter your Farenheit temperature: ";
        std::cin>>F;
        C = ((F-32)/9)*5;
        std::cout<<F<<"F is "<<C<<"C";
    }else if (input == 'F' || input == 'f') {
        std::cout<<"Enter your Celcius temperature: ";
        std::cin>>C;
        F = ((C/5)*9)+32;
        std::cout<<C<<"C is "<<F<<"F";
    }else {
        std::cout<<"Please Enter C for Celcius and F for Farenheit";
    }


    return 0;
}
