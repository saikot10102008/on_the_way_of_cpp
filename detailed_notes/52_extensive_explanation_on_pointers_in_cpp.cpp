#include <iostream>
#include <string>

// ============================================================
// POINTERS IN C++
// ============================================================
// A pointer is a variable that stores the memory address of another variable
// Think of it like a "signpost" that tells you where data is stored in memory
//
// KEY CONCEPTS:
// 1. & (address-of operator) - gets the memory address of a variable
// 2. * (dereference operator) - accesses the value at a memory address
// 3. Pointers must be declared with the data type they point to
// ============================================================

int main() {

    // ============================================================
    // PART 1: BASIC POINTER DECLARATION AND USAGE
    // ============================================================

    std::cout << "========== PART 1: BASIC POINTERS ==========\n\n";

    // Regular variables
    int age = 25;
    double price = 19.99;
    char grade = 'A';
    std::string name = "John";

    // Pointer variables (stores memory addresses)
    // Syntax: dataType* pointerName;
    int* pAge = &age;           // pAge stores the address of age
    double* pPrice = &price;    // pPrice stores the address of price
    char* pGrade = &grade;      // pGrade stores the address of grade
    std::string* pName = &name; // pName stores the address of name

    std::cout << "Regular variable values:\n";
    std::cout << "age = " << age << "\n";
    std::cout << "price = " << price << "\n";
    std::cout << "grade = " << grade << "\n";
    std::cout << "name = " << name << "\n\n";

    std::cout << "Memory addresses (using & operator):\n";
    std::cout << "&age = " << &age << "\n";
    std::cout << "&price = " << &price << "\n";
    std::cout << "&grade = " << &grade << "\n";
    std::cout << "&name = " << &name << "\n\n";

    std::cout << "Pointer values (stored addresses):\n";
    std::cout << "pAge = " << pAge << "\n";
    std::cout << "pPrice = " << pPrice << "\n";
    std::cout << "pGrade = " << pGrade << "\n";
    std::cout << "pName = " << pName << "\n\n";

    std::cout << "Values at addresses (using * dereference operator):\n";
    std::cout << "*pAge = " << *pAge << "\n";
    std::cout << "*pPrice = " << *pPrice << "\n";
    std::cout << "*pGrade = " << *pGrade << "\n";
    std::cout << "*pName = " << *pName << "\n\n";


    // ============================================================
    // PART 2: MODIFYING VALUES THROUGH POINTERS
    // ============================================================

    std::cout << "========== PART 2: MODIFYING VALUES ==========\n\n";

    std::cout << "Original age: " << age << "\n";

    // Modify the value using the pointer
    *pAge = 30;
    std::cout << "After *pAge = 30, age = " << age << "\n\n";

    // You can also modify directly through the variable
    age = 35;
    std::cout << "After age = 35, *pAge = " << *pAge << "\n\n";


    // ============================================================
    // PART 3: NULL POINTERS
    // ============================================================
    // A null pointer points to "nothing" (address 0)
    // Always initialize pointers that don't have an address yet

    std::cout << "========== PART 3: NULL POINTERS ==========\n\n";

    int* pNull = nullptr;  // Modern C++ way (preferred)
    // int* pNull = NULL;  // Old C-style way
    // int* pNull = 0;     // Also works

    if(pNull == nullptr) {
        std::cout << "pNull is a null pointer (points to nothing)\n";
    }

    // WARNING: Dereferencing a null pointer crashes the program!
    // std::cout << *pNull; // DON'T DO THIS - causes segmentation fault


    // ============================================================
    // PART 4: POINTERS WITH ARRAYS
    // ============================================================
    // Array names act like pointers to the first element

    std::cout << "\n========== PART 4: POINTERS WITH ARRAYS ==========\n\n";

    int numbers[] = {10, 20, 30, 40, 50};
    int* pNumbers = numbers;  // No & needed - array name is already an address

    std::cout << "Array elements:\n";
    for(int i = 0; i < 5; i++) {
        std::cout << "numbers[" << i << "] = " << numbers[i];
        std::cout << " | Address: " << &numbers[i];
        std::cout << " | Using pointer: " << *(pNumbers + i) << "\n";
    }

    std::cout << "\nPointer arithmetic:\n";
    std::cout << "*pNumbers = " << *pNumbers << " (first element)\n";
    std::cout << "*(pNumbers + 1) = " << *(pNumbers + 1) << " (second element)\n";
    std::cout << "*(pNumbers + 2) = " << *(pNumbers + 2) << " (third element)\n";


    // ============================================================
    // PART 5: POINTERS WITH STRINGS
    // ============================================================

    std::cout << "\n========== PART 5: POINTERS WITH STRINGS ==========\n\n";

    std::string message = "Hello, Pointers!";
    std::string* pMessage = &message;

    std::cout << "Original string: " << message << "\n";
    std::cout << "Via pointer: " << *pMessage << "\n";

    // Modify through pointer
    *pMessage = "Modified via pointer!";
    std::cout << "After modification: " << message << "\n";


    // ============================================================
    // PART 6: PRACTICE - CREDIT CARD VALIDATOR WITH POINTERS
    // ============================================================
    // Let's rewrite the credit card validator using pointers to demonstrate

    std::cout << "\n========== PART 6: CREDIT CARD VALIDATOR (WITH POINTERS) ==========\n\n";

    std::string cardNumber;
    std::cout << "Enter your card number: ";
    std::cin >> cardNumber;

    int size = cardNumber.size();
    int sum = 0;
    int position = 1;

    // Using a pointer to traverse the string from the end
    // char* ptr = &cardNumber[size - 1];  // Points to last character

    // Alternative: use const char* since we're not modifying the string
    const char* ptr = cardNumber.c_str() + size - 1;  // Points to last character

    for(int i = size; i > 0; i--) {
        // Get the digit value by dereferencing the pointer and subtracting '0'
        int digit = *ptr - '0';  // *ptr gives the character, subtract ASCII '0' to get number

        if(position % 2 != 0) {
            // Odd position from right - add digit directly
            sum += digit;
        } else {
            // Even position from right - double the digit
            int doubled = digit * 2;
            if(doubled > 9) {
                sum += doubled - 9;
            } else {
                sum += doubled;
            }
        }

        position++;
        ptr--;  // Move pointer left to previous character
    }

    if(sum % 10 == 0) {
        std::cout << "Card Number is VALID!\n";
    } else {
        std::cout << "Card Number is INVALID!\n";
    }


    // ============================================================
    // QUICK REFERENCE CARD
    // ============================================================
    /*
    SYMBOL    MEANING                           EXAMPLE
    ------    -------                           -------
    &         Address-of operator               &variable → returns memory address
    *         Dereference operator              *pointer → returns value at address
    nullptr   Null pointer value                int* p = nullptr;
    type*     Pointer declaration               int* ptr;

    COMMON POINTER PATTERNS:
    1. Declare:     int* ptr;
    2. Initialize:  ptr = &variable;
    3. Access:      *ptr = newValue;
    4. Null check:  if(ptr != nullptr) { ... }

    WHY USE POINTERS?
    - Pass large data structures efficiently (by reference)
    - Dynamic memory allocation (new/delete)
    - Working with arrays and strings
    - Creating complex data structures (linked lists, trees)
    */
    // ============================================================

    return 0;
}
