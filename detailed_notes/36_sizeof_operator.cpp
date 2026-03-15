// ========================================================
// C++ Notes - sizeof() Operator
// ========================================================

#include <iostream>
#include <string>

int main() {
    std::cout << "=== C++ Notes - sizeof() Operator ===\n\n";

    // What does sizeof() do?
    // Returns the size (in bytes) of a data type or variable at compile time.
    // Extremely useful with arrays to calculate number of elements automatically.

    std::cout << "1. Size of basic data types:\n";
    std::cout << "   sizeof(int)    = " << sizeof(int)    << " bytes\n";
    std::cout << "   sizeof(double) = " << sizeof(double) << " bytes\n";
    std::cout << "   sizeof(char)   = " << sizeof(char)   << " bytes\n";
    std::cout << "   sizeof(bool)   = " << sizeof(bool)   << " bytes\n";
    std::cout << "   sizeof(float)  = " << sizeof(float)  << " bytes\n\n";

    // =================================================================
    // MOST IMPORTANT USE CASE: Finding size of an ARRAY
    // =================================================================
    std::cout << "2. sizeof() with arrays:\n";

    int grades[] = {90, 85, 78, 92, 88};                    // 5 elements
    std::string students[] = {"SpongeBob", "Patrick", "Squidward", "Sandy", "MrKrabs"};

    std::cout << "   int grades[] has " << sizeof(grades) << " bytes total\n";
    std::cout << "   One int element = " << sizeof(grades[0]) << " bytes\n";
    std::cout << "   Number of elements = " << sizeof(grades) / sizeof(grades[0]) << "\n\n";

    std::cout << "   std::string students[] has " << sizeof(students) << " bytes total\n";
    std::cout << "   Number of students  = " << sizeof(students) / sizeof(students[0]) << "\n\n";

    // =================================================================
    // Why we divide: sizeof(array) / sizeof(array[0])
    // =================================================================
    std::cout << "3. Why sizeof(array) / sizeof(array[0]) works:\n";
    std::cout << "   - sizeof(array)     = total bytes of the entire array\n";
    std::cout << "   - sizeof(array[0])  = bytes of ONE element\n";
    std::cout << "   - Division gives exact count of elements (no hardcoding!)\n\n";

    // =================================================================
    // Special note about std::string
    // =================================================================
    std::string name = "Example Name";
    std::cout << "4. sizeof() with std::string:\n";
    std::cout << "   std::string name = \"" << name << "\"\n";
    std::cout << "   sizeof(name) = " << sizeof(name) << " bytes\n";
    std::cout << "   (Note: std::string usually shows 32 bytes because it stores a pointer,\n";
    std::cout << "    not the actual text characters)\n\n";

    // =================================================================
    // Important warning about arrays in functions
    // =================================================================
    std::cout << "5. Important warning:\n";
    std::cout << "   When you pass an array to a function, it decays to a pointer.\n";
    std::cout << "   Inside the function: sizeof(array) becomes sizeof(pointer) = usually 8 bytes!\n";
    std::cout << "   Always pass the array size as a separate parameter.\n\n";

    std::cout << "=== End of sizeof() notes ===\n";
    std::cout << "Compile and run this file to see actual sizes on your system.\n";
    std::cout << "Sizes may vary slightly depending on compiler and OS (32-bit vs 64-bit).\n";

    return 0;
}