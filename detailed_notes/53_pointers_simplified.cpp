#include <iostream>

// ============================================================
// POINTERS IN C++ - SIMPLE EXPLANATION
// ============================================================
// A pointer is just a variable that stores a memory address
// instead of storing a regular value.
//
// Think of it like:
// - Regular variable = a house (contains stuff)
// - Pointer = the address of that house (tells you where it is)
// ============================================================

int main() {

    // ------------------------------------------------
    // 1. BASIC POINTERS
    // ------------------------------------------------

    int myNumber = 42;        // Regular variable
    int* myPointer = &myNumber;  // Pointer stores address of myNumber

    // & = "address of" - gets where the variable lives
    // * = "value at" - gets what's stored at that address

    std::cout << "=== BASIC POINTERS ===\n";
    std::cout << "myNumber = " << myNumber << "\n";           // 42
    std::cout << "&myNumber = " << &myNumber << "\n";         // memory address (like 0x7fff)
    std::cout << "myPointer = " << myPointer << "\n";         // same address
    std::cout << "*myPointer = " << *myPointer << "\n\n";     // 42 (value at that address)


    // ------------------------------------------------
    // 2. CHANGING VALUES USING POINTERS
    // ------------------------------------------------

    std::cout << "=== CHANGING VALUES ===\n";
    std::cout << "Original: " << myNumber << "\n";

    *myPointer = 100;  // Change value at the address myPointer points to

    std::cout << "After *myPointer = 100: " << myNumber << "\n\n";


    // ------------------------------------------------
    // 3. WHY USE POINTERS? - WORKING WITH ARRAYS
    // ------------------------------------------------
    // Array names are actually pointers to the first element

    int numbers[] = {10, 20, 30};
    int* ptr = numbers;  // points to first element (no & needed)

    std::cout << "=== POINTERS WITH ARRAYS ===\n";
    std::cout << "numbers[0] = " << numbers[0] << "\n";
    std::cout << "*ptr = " << *ptr << "\n";           // 10 (first element)
    std::cout << "*(ptr + 1) = " << *(ptr + 1) << "\n"; // 20 (second element)
    std::cout << "*(ptr + 2) = " << *(ptr + 2) << "\n\n"; // 30 (third element)


    // ------------------------------------------------
    // 4. NULL POINTERS (pointers that point to nothing)
    // ------------------------------------------------

    std::cout << "=== NULL POINTERS ===\n";
    int* nullPointer = nullptr;  // points to nothing, safe to check

    if(nullPointer == nullptr) {
        std::cout << "nullPointer points to nothing\n";
    }

    // NEVER do this: *nullPointer = 5;  // This will crash your program!


    // ------------------------------------------------
    // QUICK SUMMARY
    // ------------------------------------------------
    /*
    &  = "address of"  →  int* p = &x;  // p gets x's address
    *  = "value at"    →  int y = *p;   // y gets value at that address

    Regular variable: stores data
    Pointer variable: stores memory address

    Use pointers to:
    - Pass large data efficiently (no copying)
    - Work with dynamic memory (new/delete)
    - Create linked lists, trees, etc.
    */
    // ------------------------------------------------

    return 0;
}
