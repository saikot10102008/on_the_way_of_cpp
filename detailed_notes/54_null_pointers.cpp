#include <iostream>

// ============================================================
// NULL POINTERS - SIMPLE EXPLANATION
// ============================================================
// A null pointer is a pointer that points to NOTHING (address 0)
// It's like an empty container - it doesn't point to any valid memory
//
// WHY DO WE NEED NULL POINTERS?
// - To indicate a pointer is not yet assigned
// - To check if a pointer is valid before using it
// - To prevent crashes when accessing invalid memory
// ============================================================

int main() {

    // ------------------------------------------------
    // 1. WHAT IS A NULL POINTER?
    // ------------------------------------------------

    std::cout << "=== NULL POINTER BASICS ===\n";

    int* ptr1 = nullptr;      // MODERN C++ way (C++11 and later)
    int* ptr2 = NULL;         // OLD C-style way
    int* ptr3 = 0;            // Also works (0 means null)

    std::cout << "ptr1 (nullptr) = " << ptr1 << "\n";  // prints 0 or (nil)
    std::cout << "ptr2 (NULL) = " << ptr2 << "\n";     // prints 0
    std::cout << "ptr3 (0) = " << ptr3 << "\n\n";      // prints 0


    // ------------------------------------------------
    // 2. CHECKING IF A POINTER IS NULL
    // ------------------------------------------------
    // Always check before using a pointer!

    std::cout << "=== CHECKING NULL POINTERS ===\n";

    int* myPtr = nullptr;

    if(myPtr == nullptr) {
        std::cout << "myPtr is NULL - safe to check, NOT safe to use\n";
    }

    // This is SAFE - we're checking, not using
    if(myPtr != nullptr) {
        std::cout << "*myPtr = " << *myPtr << "\n";  // This line NEVER runs
    }


    // ------------------------------------------------
    // 3. THE DANGER: DEREFERENCING NULL POINTERS
    // ------------------------------------------------
    // WARNING: This will CRASH your program!

    std::cout << "\n=== WHAT NOT TO DO ===\n";
    std::cout << "NEVER do this:\n";
    std::cout << "int* badPtr = nullptr;\n";
    std::cout << "*badPtr = 5;  // CRASH! (segmentation fault)\n\n";

    // Uncommenting the lines below would crash the program:
    // int* badPtr = nullptr;
    // *badPtr = 5;  // PROGRAM CRASHES!


    // ------------------------------------------------
    // 4. CORRECT USAGE PATTERN
    // ------------------------------------------------

    std::cout << "=== CORRECT PATTERN ===\n";

    int value = 100;
    int* correctPtr = nullptr;

    std::cout << "Step 1: Pointer is null\n";
    // Can't use it yet

    std::cout << "Step 2: Assign a valid address\n";
    correctPtr = &value;  // Now it points to something

    std::cout << "Step 3: Check before using\n";
    if(correctPtr != nullptr) {
        std::cout << "*correctPtr = " << *correctPtr << "\n";  // SAFE to use
    }


    // ------------------------------------------------
    // 5. PRACTICAL EXAMPLE - SAFE POINTER FUNCTION
    // ------------------------------------------------

    std::cout << "\n=== PRACTICAL EXAMPLE ===\n";

    int score = 85;
    int* scorePtr = &score;   // Valid pointer

    // Function-like pattern (without actually making a function)
    if(scorePtr != nullptr) {
        std::cout << "Score is: " << *scorePtr << "\n";
        *scorePtr = 90;  // Modify through pointer
        std::cout << "Updated score: " << score << "\n";
    } else {
        std::cout << "Pointer is null, cannot access\n";
    }

    // Now make it null
    scorePtr = nullptr;

    if(scorePtr != nullptr) {
        std::cout << "Score is: " << *scorePtr << "\n";  // This won't run
    } else {
        std::cout << "Pointer is null, cannot access (safe!)\n";
    }


    // ------------------------------------------------
    // QUICK REFERENCE CARD
    // ------------------------------------------------
    /*
    WHAT IS NULL POINTER?
    ====================
    A pointer that stores address 0 (points to nothing)

    THREE WAYS TO DECLARE:
    int* ptr = nullptr;  // Modern C++ (BEST)
    int* ptr = NULL;     // Old C-style
    int* ptr = 0;        // Also works

    RULE #1: ALWAYS initialize pointers
    RULE #2: ALWAYS check before dereferencing
    RULE #3: NEVER dereference a null pointer

    CHECK PATTERN:
    if(ptr != nullptr) {
        // SAFE to use *ptr
        *ptr = something;
    }

    WHY USE NULL POINTERS?
    ======================
    1. Initialize pointers that don't have a target yet
    2. Indicate "no valid data" (like returning nullptr from a function)
    3. Prevent crashes by checking before use
    4. Create linked lists (last node points to nullptr)

    COMMON MISTAKES:
    ===============
    ❌ int* ptr;        // Uninitialized - contains garbage address!
    ❌ *ptr = 5;        // Dereferencing without checking
    ❌ if(ptr) { ... }  // Works but nullptr is clearer

    ✅ int* ptr = nullptr;
    ✅ if(ptr != nullptr) { *ptr = 5; }
    */
    // ------------------------------------------------

    return 0;
}
