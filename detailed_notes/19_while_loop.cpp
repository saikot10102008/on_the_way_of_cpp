#include<iostream>

int main() {

    std::string name; //string is initialized but now it is empty

    while (name.empty())
    {
        std::cout<<"Your Name: ";
        std::getline(std::cin>>std::ws,name);
    }

    std::cout<<"Your name is: "<<name;

    // an infinite while loop: while(true){std::cout<<"Infinite loop";}
    return 0;
}