#include<iostream>

int main(){
    // declaration first , initialization later
    // type_of_variable name;
    // type_of_variable name = value;
    /*
    type_of_variable name;
    name = value;
    */
    // type name1 = value1 , name2 = value2 , name3 = value3;
    int a = 9;
    int b;
    b = 10;
    int c = 11 , d = 12;

    // int type -> whole number
    // double data type -> number including decimal
    // int type truncates what it is after decimal point

    int e = 15.9;

    std::cout<<e;

    // char type -> single character in single quotation
    char currency = '$';

    // boolean variable -> only true or false

    bool power = true;

    // string data type -> objects that represents a sequence of text -> sequence of characters 
    std::string name = "\nSaikot ";
    std::string name21 = "BH KJ MN 32";
    std::cout<<name<<" and string with space: "<<name21;


    // variable can be changed after initialization




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
    return 0;
}
