#include <iostream>

// =========================================================
// CONST PARAMETERS - Making parameters read-only
// =========================================================
// The 'const' keyword makes a parameter read-only
// It prevents the function from modifying the parameter

void printInfo(const std::string &name, const int &age) {
    // name = "Something else";  // ERROR! Can't modify const parameter
    // age = 100;                // ERROR! Can't modify const parameter

    std::cout << "Name: " << name << '\n';
    std::cout << "Age: " << age << '\n';
    // You can only READ const parameters, not change them
}

int main() {
    std::string myName = "Saikot";
    int myAge = 18;

    printInfo(myName, myAge);

    return 0;
}




// summary:
// In C++, adding the const keyword before a function parameter (especially when passing by reference) prevents the function from modifying the original argument, making your code safer, more readable, and often more efficient — especially for large objects like strings or structs that you don't want copied but also don't want accidentally changed. For example, instead of void print(const std::string &str) (passes reference to avoid copy, but const blocks any modifications inside the function), you protect the caller's data while still getting the performance benefit of reference passing. This is very common for read-only parameters in functions (getters, display functions, etc.), helps catch bugs early at compile time if you try to modify something you shouldn't, and is a key habit for writing clean, const-correct C++ code. Bro Code likely shows simple examples contrasting non-const vs const parameters, perhaps with a swap-like function or string printer to demonstrate the difference.
