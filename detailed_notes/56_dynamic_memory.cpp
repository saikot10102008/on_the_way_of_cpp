// DYNAMIC MEMORY ALLOCATION IN C++
// ================================
// Dynamic memory allocation allows programs to request memory at runtime
// (while the program is executing) rather than at compile time.
// This is essential when you don't know how much memory you'll need beforehand.

#include <iostream>

int main() {

    // =========================================================================
    // PART 1: STACK MEMORY ALLOCATION (Automatic)
    // =========================================================================
    // The following variables are allocated on the STACK:
    // - Stack memory is automatically managed by the compiler
    // - Memory is allocated when variables are declared
    // - Memory is automatically freed when variables go out of scope
    // - Stack has limited size (typically 1-8 MB)
    // - Access is very fast

    // pGrades is a POINTER variable stored on the STACK
    // A pointer is a variable that stores a memory address
    // Size of pointer: 4 bytes on 32-bit system, 8 bytes on 64-bit system
    // NULL means it points to nothing (address 0)
    char *pGrades = NULL;  // Currently points to nothing - "null pointer"

    // 'size' is an integer variable stored on the STACK
    // Regular variable that holds a value directly
    int size;  // Typically 4 bytes on most systems

    // =========================================================================
    // PART 2: DETERMINING MEMORY NEEDS AT RUNTIME
    // =========================================================================
    // This is WHY we need dynamic memory:
    // We don't know how many grades the user will enter until the program runs
    // If we used a fixed-size array on the stack:
    //   char grades[100];  // Wastes space if user enters only 5
    //   char grades[5];    // Not enough space if user enters 10

    std::cout << "How many grades to enter in?: ";
    std::cin >> size;  // User decides the required size at RUNTIME

    // =========================================================================
    // PART 3: HEAP MEMORY ALLOCATION (Dynamic)
    // =========================================================================
    // 'new' operator allocates memory on the HEAP
    // Heap characteristics:
    // - Much larger than stack (limited by available RAM)
    // - Memory persists until explicitly freed with 'delete'
    // - Must be manually managed (no automatic cleanup)
    // - Slower to allocate/deallocate than stack
    // - Can cause memory leaks if not properly deallocated

    // SYNTAX: new type[size]
    // This allocates 'size' number of characters (1 byte each) contiguously on HEAP
    // Returns a pointer to the FIRST element of the allocated block
    pGrades = new char[size];

    // VISUAL REPRESENTATION OF MEMORY AFTER ALLOCATION:
    //
    // STACK (Automatic)                    HEAP (Dynamic)
    // ┌──────────────────────┐            ┌──────────────────────┐
    // │ pGrades (8 bytes)    │───────────→│ [0] [1] [2] [3] ... │
    // │ contains address:    │            │  ↑   ↑   ↑   ↑       │
    // │ 0x7fff5fbff730       │            │  │   │   │   │       │
    // ├──────────────────────┤            │  └───┴───┴───┴───────┘
    // │ size (4 bytes) = 5   │            │  Contiguous block of 'size' chars
    // └──────────────────────┘            │  Each char = 1 byte
    //                                      │  Total = size * 1 bytes
    //                                      └──────────────────────┘

    // =========================================================================
    // PART 4: USING DYNAMIC MEMORY
    // =========================================================================
    // Now we can use pGrades like an array!
    // This works because of how C++ handles pointers and arrays:
    // - Array notation pGrades[i] is equivalent to *(pGrades + i)
    // - The compiler calculates the address: base_address + (i * sizeof(char))
    // - This is called "pointer arithmetic"

    std::cout << "\n--- Entering grades ---\n";
    for(int i = 0; i < size; i++) {
        std::cout << "Enter grade #" << i + 1 << ": ";

        // IMPORTANT: We're using ARRAY NOTATION with a POINTER
        // This is valid because pGrades points to a contiguous block of memory
        // pGrades[i] is equivalent to: *(pGrades + i)
        std::cin >> pGrades[i];  // Storing data in HEAP memory
    }

    // =========================================================================
    // PART 5: ACCESSING DYNAMIC MEMORY
    // =========================================================================
    std::cout << "\n--- Your grades ---\n";
    for(int i = 0; i < size; i++) {
        // Reading data from HEAP memory
        // Both notations work:
        std::cout << pGrades[i] << " ";     // Array notation
        // std::cout << *(pGrades + i) << " ";  // Pointer arithmetic notation (same result)
    }
    std::cout << "\n";

    // =========================================================================
    // PART 6: DYNAMIC MEMORY CLEANUP - CRITICAL!
    // =========================================================================
    // EVERY 'new' MUST have a matching 'delete'
    // If we don't delete, we create a MEMORY LEAK:
    // - Heap memory remains allocated even after program ends
    // - In long-running programs, memory leaks can consume all available RAM
    // - Program may crash or system may become unstable

    // SYNTAX: delete[] pointer_name
    // The [] is IMPORTANT! It tells the compiler to delete an array
    // Using 'delete' without [] would only delete the first element
    delete[] pGrades;  // Frees the entire array on the HEAP

    // =========================================================================
    // PART 7: PREVENTING DANGLING POINTERS
    // =========================================================================
    // After delete[], pGrades still contains the address of the freed memory
    // This is called a "dangling pointer" - it points to invalid memory
    // Using pGrades after deletion would cause UNDEFINED BEHAVIOR (crash)

    // Good practice: Set pointer to NULL after deletion
    pGrades = NULL;  // Now pGrades points to nothing (safe)

    // =========================================================================
    // PART 8: AUTOMATIC CLEANUP (What happens at the end)
    // =========================================================================
    // - HEAP memory: We manually freed it with delete[]
    // - STACK memory: Automatically freed when main() ends
    //   - 'pGrades' pointer variable is destroyed (8 bytes)
    //   - 'size' integer variable is destroyed (4 bytes)
    // - No memory leaks! ✓

    std::cout << "\n--- Program ending ---\n";
    std::cout << "Stack memory automatically freed\n";
    std::cout << "Heap memory manually freed with delete[]\n";

    return 0;
}

// =============================================================================
// ADDITIONAL IMPORTANT CONCEPTS
// =============================================================================

/*
 * WHY POINTERS CAN BE USED AS ARRAYS:
 * ----------------------------------
 * In C++, arrays and pointers are closely related:
 * - An array name is essentially a constant pointer to its first element
 * - The [] operator is just syntactic sugar for pointer arithmetic
 *
 * Example:
 *   char arr[5] = "Hello";
 *   char *ptr = arr;  // ptr points to first element
 *
 *   arr[0] == *ptr        // true
 *   arr[1] == *(ptr + 1)  // true
 *   arr[2] == ptr[2]      // true (ptr can use array notation)
 *
 * This is why we can use pGrades[i] even though pGrades is a pointer!
 */

/*
 * STACK vs HEAP - DETAILED COMPARISON:
 * -----------------------------------
 *
 * STACK:
 * - Automatic allocation/deallocation
 * - Fixed size (determined at compile time)
 * - LIFO (Last In, First Out) structure
 * - Stores local variables, function parameters, return addresses
 * - Memory fragmentation is not an issue
 * - Allocation is just moving the stack pointer (very fast)
 * - Lifetime: until the variable goes out of scope
 *
 * HEAP:
 * - Manual allocation/deallocation (new/delete)
 * - Dynamic size (grows as needed, limited by RAM)
 * - No automatic organization (can be fragmented)
 * - Stores dynamically allocated objects
 * - Memory fragmentation can occur
 * - Allocation requires searching for free blocks (slower)
 * - Lifetime: until explicitly freed with delete
 */

/*
 * COMMON DYNAMIC MEMORY MISTAKES:
 * ------------------------------
 *
 * 1. MEMORY LEAK:
 *    char *ptr = new char[100];
 *    // Forgot to delete[] ptr
 *    // Memory stays allocated until program ends
 *
 * 2. DANGLING POINTER:
 *    char *ptr = new char[100];
 *    delete[] ptr;
 *    ptr[0] = 'A';  // ERROR! Using freed memory
 *
 * 3. DOUBLE DELETE:
 *    char *ptr = new char[100];
 *    delete[] ptr;
 *    delete[] ptr;  // ERROR! Deleting already freed memory
 *
 * 4. WRONG DELETE:
 *    char *ptr = new char[100];
 *    delete ptr;  // ERROR! Should be delete[] for arrays
 *
 * 5. BUFFER OVERFLOW:
 *    char *ptr = new char[5];
 *    strcpy(ptr, "Too long string");  // ERROR! Writing beyond allocated memory
 */

/*
 * MODERN C++ ALTERNATIVES:
 * -----------------------
 * Instead of raw pointers and manual new/delete, modern C++ recommends:
 *
 * 1. std::vector (for dynamic arrays):
 *    std::vector<char> grades(size);  // Automatically manages memory
 *    // No delete needed!
 *
 * 2. Smart pointers (std::unique_ptr, std::shared_ptr):
 *    std::unique_ptr<char[]> grades = std::make_unique<char[]>(size);
 *    // Automatically deleted when unique_ptr goes out of scope
 *
 * These alternatives prevent memory leaks and dangling pointers automatically!
 */

/*
 * VISUAL MEMORY LAYOUT EXAMPLE:
 * ----------------------------
 * When the program runs with size = 5:
 *
 * MEMORY ADDRESS      STACK (High addresses)
 * 0x7fff5fbff730 ┌────────────────────────┐
 *                 │ pGrades = 0x7f8a1c000000 │ (8 bytes)
 * 0x7fff5fbff728 ├────────────────────────┤
 *                 │ size = 5                │ (4 bytes)
 * 0x7fff5fbff724 └────────────────────────┘
 *
 *                 ... gap ...
 *
 * MEMORY ADDRESS      HEAP (Low addresses)
 * 0x7f8a1c000005 ┌────────────────────────┐
 *                 │ grades[4] = ?          │
 * 0x7f8a1c000004 ├────────────────────────┤
 *                 │ grades[3] = ?          │
 * 0x7f8a1c000003 ├────────────────────────┤
 *                 │ grades[2] = ?          │
 * 0x7f8a1c000002 ├────────────────────────┤
 *                 │ grades[1] = ?          │
 * 0x7f8a1c000001 ├────────────────────────┤
 *                 │ grades[0] = ?          │
 * 0x7f8a1c000000 └────────────────────────┘
 *
 * pGrades (on stack) stores the address 0x7f8a1c000000
 * So pGrades[0] accesses memory at 0x7f8a1c000000
 * pGrades[1] accesses memory at 0x7f8a1c000001, etc.
 */






 