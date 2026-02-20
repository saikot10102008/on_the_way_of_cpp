#include<iostream>

int main(){

    double a,b,ans;
    char op;

    std::cout<<"Chose one of the operations (+,-,/,*): ";
    std::cin>>op;

    std::cout<<"Enter 1st number: ";
    std::cin>>a;

    std::cout<<"Enter 2nd number: ";
    std::cin>>b;

    switch (op)
    {
    case '+':
        ans = a+b;
        break;
    
    case '-':
        ans = a-b;
        break;

    case '*':
        ans = a*b;
        break;

    case '/':
        ans = a/b;
        break;
    
    default:
        std::cout<<"Operator not valid";
        break;
    }

    std::cout<<"Your answer is: "<<ans;

    return 0;
}






    // A **float** and a **double** are both data types used to 
    // store decimal numbers (floating-point values) in C++. The 
    // main difference lies in their precision and memory size: 
    // a **float** typically occupies 4 bytes and offers about 6-7 
    // decimal digits of precision, while a **double** occupies 8 
    // bytes and provides about 15-16 decimal digits of precision, 
    // making it more accurate for complex calculations. In practice,
    //  **double** is the default choice for most programmers because 
    // modern computers handle it efficiently and the extra precision
    //  helps avoid rounding errors, especially in scientific or 
    // financial applications. Use **float** only when memory is 
    // limited (like in embedded systems or processing large arrays) 
    // or when working with graphics libraries that specifically 
    // require it. As a general rule, if unsure, just use 
    // **double**—it's safer and the performance difference is usually negligible.
