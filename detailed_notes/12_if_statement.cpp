#include<iostream>


int main(){
    // if statement = do something if a condition is true
    // if not then don't do it
    // comparison operators -> == , != , < , > , <= , >=
    // else statement = in case condition of if statement is not true then it runs
    // else if statement = when if statement is not true then we can add another condition based if statement, and this is how

    int age;
    std::cout<<"Your age: ";
    std::cin>>age;

    if(age >= 18){
        std::cout<<"Your are an adult";
    }else if(age < 0){
        std::cout<<"Invalid age";
    }else if(age == 0){
        std::cout<<"Invaild age";
    }else{std::cout<<"You are a minor";}

    return 0;
}