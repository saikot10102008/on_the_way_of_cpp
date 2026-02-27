#include<iostream>

int main(){

    std::cout<<"Your name: ";
    std::string name;
    std::getline(std::cin,name);
    int len = name.length(); // this length() method will give you the length of a string
    std::cout<<len<<" is the length of your name";

    // .empty() method returns bool value of true if string is empty otherwise false
    bool func = name.empty();
    if(func){std::cout<<"\nYou didn't enter anything";}else{std::cout<<"\nYour name: "<<name;}

    // .clear() method clears a string
    // In C++, the .clear() method is a member function primarily used
    // with standard library containers to remove all elements from 
    // the container, leaving it with a size of 0. However, the exact 
    // behavior depends on the type of container you are using. 

    name.clear();

    std::cout<<"\nYour name: "<<name;

    // In C++, the append() method is used to add characters, strings,
    // or substrings to the end of an existing std::string object, 
    // increasing its length accordingly.

    std::cout<<"\nYour nickname: ";
    std::cin>>name;
    name.append("@gmail.com");
    std::cout<<"From now your username: "<<name;
    std::string noBS = "@@@";
    name.append(noBS);
    std::cout<<"\nJust for fun: "<<name;

    // The .at() function in C++ is used to access an element in a 
    // container (like a string or vector) at a specific index 
    // position. Unlike the square brackets [], it performs a safety 
    // check: if you try to access an index that doesn't exist, it 
    // will throw an exception rather than causing unpredictable behavior. This makes 
    // your code safer and easier to debug when working with dynamic data.

    std::cout<<"\n1st character of you nickname is: "<<name.at(0);

    
    
    return 0;
}