#include <iostream>
#include <cstdint>

int main() {
    // =========================================================
    // MEMORY ADDRESSES - WHAT ARE THEY?
    // =========================================================
    // A memory address is a unique identifier for a location in memory
    // where data is stored. Think of it like a house number on a street.
    // Every variable you create occupies space in RAM, and that space
    // has an address.

    // The & (address-of) operator gives you the memory address of a variable

    std::cout << "================== MEMORY ADDRESSES ==================\n\n";

    // =========================================================
    // EXAMPLE 1: Basic variable addresses
    // =========================================================
    std::cout << "----- EXAMPLE 1: Basic Variable Addresses -----\n";

    int x = 5;
    double y = 10.5;
    char z = 'A';
    bool w = true;

    std::cout << "Value of x: " << x << std::endl;
    std::cout << "Address of x: " << &x << " (in hexadecimal)" << std::endl;
    std::cout << "Size of x: " << sizeof(x) << " bytes\n\n";

    std::cout << "Value of y: " << y << std::endl;
    std::cout << "Address of y: " << &y << std::endl;
    std::cout << "Size of y: " << sizeof(y) << " bytes\n\n";

    std::cout << "Value of z: " << z << std::endl;
    std::cout << "Address of z: " << &z << " (notice this might look weird)" << std::endl;
    std::cout << "Size of z: " << sizeof(z) << " bytes\n\n";

    std::cout << "Value of w: " << w << std::endl;
    std::cout << "Address of w: " << &w << std::endl;
    std::cout << "Size of w: " << sizeof(w) << " bytes\n\n";

    // =========================================================
    // EXAMPLE 2: Displaying addresses in different formats
    // =========================================================
    std::cout << "----- EXAMPLE 2: Addresses in Different Formats -----\n";

    int number = 42;

    std::cout << "Variable 'number' contains: " << number << std::endl;
    std::cout << "Its memory address (hex): " << &number << std::endl;
    std::cout << "Its memory address (decimal): " << reinterpret_cast<std::uintptr_t>(&number) << std::endl;

    // Store address in a pointer
    int* ptr = &number;
    std::cout << "Pointer 'ptr' stores the address: " << ptr << std::endl;
    std::cout << "Pointer 'ptr' points to value: " << *ptr << std::endl;
    std::cout << "Pointer's OWN address: " << &ptr << std::endl;  // Pointers also have addresses!

    std::cout << std::endl;

    // =========================================================
    // EXAMPLE 3: Address spacing and alignment
    // =========================================================
    std::cout << "----- EXAMPLE 3: Address Spacing & Alignment -----\n";

    int a = 10;
    int b = 20;
    int c = 30;

    std::cout << "Address of a: " << &a << std::endl;
    std::cout << "Address of b: " << &b << std::endl;
    std::cout << "Address of c: " << &c << std::endl;
    std::cout << "Notice the spacing between addresses: "
              << reinterpret_cast<std::uintptr_t>(&b) - reinterpret_cast<std::uintptr_t>(&a) << " bytes" << std::endl;
    std::cout << "This spacing matches sizeof(int): " << sizeof(int) << " bytes\n\n";

    // =========================================================
    // EXAMPLE 4: Array addresses (contiguous memory)
    // =========================================================
    std::cout << "----- EXAMPLE 4: Array Addresses (Contiguous Memory) -----\n";

    int numbers[5] = {100, 200, 300, 400, 500};

    std::cout << "Array 'numbers' itself is a pointer to first element" << std::endl;
    std::cout << "numbers = " << numbers << " (address of first element)" << std::endl;
    std::cout << "&numbers[0] = " << &numbers[0] << " (same address)" << std::endl;
    std::cout << "&numbers[1] = " << &numbers[1] << std::endl;
    std::cout << "&numbers[2] = " << &numbers[2] << std::endl;
    std::cout << "&numbers[3] = " << &numbers[3] << std::endl;
    std::cout << "&numbers[4] = " << &numbers[4] << std::endl;

    std::cout << "\nEach element is " << sizeof(int) << " bytes apart:" << std::endl;
    for(int i = 0; i < 4; i++) {
        std::uintptr_t addr1 = reinterpret_cast<std::uintptr_t>(&numbers[i]);
        std::uintptr_t addr2 = reinterpret_cast<std::uintptr_t>(&numbers[i+1]);
        std::cout << "Address[" << i << "] to [" << i+1 << "]: " << (addr2 - addr1) << " bytes" << std::endl;
    }

    std::cout << std::endl;

    // =========================================================
    // EXAMPLE 5: Strings and char arrays
    // =========================================================
    std::cout << "----- EXAMPLE 5: Strings & Char Arrays -----\n";

    char name[] = "C++";
    char* namePtr = name;

    std::cout << "String literal: " << name << std::endl;
    std::cout << "Address of name[0]: " << static_cast<void*>(&name[0]) << std::endl;
    std::cout << "Address of name[1]: " << static_cast<void*>(&name[1]) << std::endl;
    std::cout << "Address of name[2]: " << static_cast<void*>(&name[2]) << std::endl;
    std::cout << "Address of null terminator: " << static_cast<void*>(&name[3]) << std::endl;

    // Note: For char arrays, we need (void*) cast because cout treats char* as strings
    std::cout << "\nWithout (void*) cast, cout thinks char* is a string:" << std::endl;
    std::cout << "namePtr without cast: " << namePtr << " (prints the string, not address)" << std::endl;
    std::cout << "namePtr with cast: " << static_cast<void*>(namePtr) << " (prints the address)" << std::endl;

    std::cout << std::endl;

    // =========================================================
    // EXAMPLE 6: Stack vs Heap addresses
    // =========================================================
    std::cout << "----- EXAMPLE 6: Stack vs Heap Addresses -----\n";

    int stackVar = 100;  // Stack memory

    int* heapVar = new int(200);  // Heap memory

    std::cout << "Stack variable address: " << &stackVar << std::endl;
    std::cout << "Heap variable address: " << heapVar << std::endl;
    std::cout << "Pointer on stack points to heap: " << &heapVar << " (pointer's own address on stack)" << std::endl;

    delete heapVar;  // Always clean up heap memory

    std::cout << std::endl;

    // =========================================================
    // EXAMPLE 7: NULL pointers and addresses
    // =========================================================
    std::cout << "----- EXAMPLE 7: NULL Pointers -----\n";

    int* nullPtr = nullptr;  // Modern C++ way
    int* oldNullPtr = NULL;  // Old C-style

    std::cout << "nullptr address value: " << nullPtr << " (0, indicating no address)" << std::endl;
    std::cout << "NULL address value: " << oldNullPtr << " (also 0)" << std::endl;
    // std::cout << *nullPtr;  // NEVER DEREFERENCE NULL - CRASH!

    std::cout << "\n================== KEY TAKEAWAYS ==================" << std::endl;
    std::cout << "1. Use & to get a variable's memory address" << std::endl;
    std::cout << "2. Addresses are shown in hexadecimal (base-16)" << std::endl;
    std::cout << "3. Each variable type occupies a specific number of bytes" << std::endl;
    std::cout << "4. Array elements are stored contiguously in memory" << std::endl;
    std::cout << "5. The array name itself acts as a pointer to the first element" << std::endl;
    std::cout << "6. Pointers are variables that store addresses (they have their own addresses too!)" << std::endl;
    std::cout << "7. Use static_cast<void*> to print char* addresses instead of strings" << std::endl;
    std::cout << "8. Stack and heap memory are in different regions with different addresses" << std::endl;
    std::cout << "9. nullptr indicates a pointer points to nothing (don't dereference it!)" << std::endl;
    std::cout << "10. Memory addresses are the foundation of pointers and dynamic memory" << std::endl;
    std::cout << "===================================================\n";

    return 0;
}











// This C++ program provides a comprehensive demonstration of memory addresses, which are unique identifiers for locations in computer RAM where variables store data. Using the address-of operator (&) , the program retrieves and displays the hexadecimal addresses of various data types including integers, doubles, characters, and booleans, while also showing their sizes in bytes. It illustrates how addresses can be stored in pointers (variables that hold memory addresses) and demonstrates that pointers themselves have their own addresses. The program explores address spacing and alignment, showing how variables of the same type are typically spaced apart by their size in bytes. It highlights contiguous memory allocation in arrays, proving that array elements are stored sequentially with consistent spacing. Special attention is given to character arrays and strings, explaining why std::cout behaves differently with char* (printing the string rather than the address) and demonstrating the use of static_cast<void*> to force address display. The program distinguishes between stack memory (for local variables like stackVar) and heap memory (allocated with new), showing they reside in different address regions. It also covers null pointers (nullptr and NULL), which hold a value of zero indicating they point to nothing and should never be dereferenced. Throughout the examples, key concepts are reinforced including the relationship between arrays and pointers, the importance of type casting for accurate address display, and the fundamental role memory addresses play in understanding pointers and dynamic memory management.
