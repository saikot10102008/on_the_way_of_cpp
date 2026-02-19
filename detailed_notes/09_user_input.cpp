#include<iostream>



// << -> insertion operator; It inserts (sends) data into an output stream like cout, cerr, or a file stream.
// >> -> extraction operator; It extracts (reads) data from an input stream like cin or a file stream into variables.


int main(){
    // simple input

    int age;
    std::cout<<"Enter your age: ";
    std::cin>>age; // cin takes input and places it in a variable given after extraction operator
    // after cin takes the input it also gives a newline same as cout<<"\n";
    std::cout<<"Here your age: "<<age<<"\n";

    // input for a string

    std::string nick_name;
    std::cout<<"Your nickname: ";
    std::cin>>nick_name;
    std::cout<<"Your nickname is "<<nick_name;

    // input with space in a string
    // for this case if we use cin then we will lose the part that is after a space and will get only the part that is before the space
    // so we have to use getline function which could contain spaces

    std::string name;
    std::cout<<"\nYour full name: ";
    std::getline(std::cin>>std::ws , name); // normal getline function: std::getline(std::cin , variable_name); but if any newline or whitespace is left by the last input then it will take that as input and won't take input from user , so we use std::cin>>std::ws instead of std::cin
    std::cout<<"Your full name: "<<name<<"\n";

    // normal getline function: std::getline(std::cin , variable_name); 
    // but if any newline or whitespace is left by the last input then it will take that as input and won't take input from user , 
    // so we use std::cin>>std::ws instead of std::cin
    // std::ws eliminates any newline or whitespace before user input
    // std::ws is after extraction operator of cin
  

    return 0;
}