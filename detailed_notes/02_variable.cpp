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
    return 0;
}
