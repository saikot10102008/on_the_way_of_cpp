#include <iostream>

void swap(std::string &x, std::string &y);

int main()
{
    std::string x = "Kool-Aid";
    std::string y = "Water";

    swap(x, y);

    std::cout << "X: " << x << '\n';
    std::cout << "Y: " << y << '\n';

    return 0;
}

void swap(std::string &x, std::string &y)
{
    std::string temp = x;
    x = y;
    y = temp;
}




// summary:
// In C++, pass by value creates a copy of an argument inside a function, so any modifications affect only the copy and leave the original variable unchanged. Pass by reference, denoted by the & symbol in the function parameter, passes the original variable's memory address into the function, allowing direct modification of the original. This is essential when a function needs to permanently change variable values, such as in a swap function, or when working with large data structures where copying would be inefficient. The choice between them determines whether functions operate on copies or originals.
