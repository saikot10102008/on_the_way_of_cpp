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

    // The `.insert()` method in C++ is used to add elements into 
    // containers like strings, vectors, or maps at a specific 
    // position. For strings and vectors, you specify the location 
    // (often using an index or iterator) where the new element(s) 
    // should be placed, shifting existing elements to the right. For 
    // associative containers like maps, it inserts a key-value pair, 
    // automatically placing it in the correct order based on the key.

    std::cout<<"\n"<<name.insert(0,"@")<<"\n";

    // In C++, the .find() method is used to search for a specific 
    // value or character within a container like a string. For 
    // std::string, it returns the index position of the first 
    // occurrence of the substring or character you're looking for; 
    // if the item is not found, it returns the special constant 
    // std::string::npos. For associative containers like std::map or 
    // std::set, .find() returns an iterator pointing to the element 
    // if found, or an iterator to the end of the container 
    // (container.end()) if not found.

    std::cout<<name.find('@')<<" ";
    std::cout<<name.find("@");
    
    // In C++, the .erase() method can remove a characters 
    // by passing two iterators (a start and an end). When using the 
    // range version .erase(first, last), it removes all characters 
    // starting from first up to but not including last, following the 
    // standard half-open range convention [first, last). This means 
    // the character at the last position is not erased and remains 
    // in the string, ensuring that you only remove the exact segment 
    // you intend to.

    name.erase(0,1);
    std::cout<<"\n"<<name;
    name.erase(16,21);
    std::cout<<"\n"<<name;

    
    return 0;
}