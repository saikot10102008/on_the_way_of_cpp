#include <iostream>
#include <algorithm>  // Required for std::fill

int main() {
    // Example 1: Basic fill on a C-style array
    // Declare an array of 5 integers (uninitialized)
    int numbers[5];

    std::cout << "Array before fill: ";
    for (int i = 0; i < 5; ++i) {
        std::cout << numbers[i] << " ";  // Output: garbage values
    }
    std::cout << std::endl;

    // Fill the entire array with the value 42
    // For arrays, we use pointers as iterators:
    // - 'numbers' is a pointer to the first element
    // - 'numbers + 5' is a pointer to one past the last element
    std::fill(numbers, numbers + 5, 42);

    std::cout << "Array after fill with 42: ";
    for (int i = 0; i < 5; ++i) {
        std::cout << numbers[i] << " ";  // Output: 42 42 42 42 42
    }
    std::cout << std::endl;

    // Example 2: Filling only a portion of an array
    int partial[10] = {0};  // Initialize all 10 elements to 0

    std::cout << "Partial array before fill: ";
    for (int i = 0; i < 10; ++i) {
        std::cout << partial[i] << " ";  // Output: 0 0 0 0 0 0 0 0 0 0
    }
    std::cout << std::endl;

    // Fill only the first 5 elements with 99
    // partial + 5 points to the 6th element (exclusive)
    std::fill(partial, partial + 5, 99);

    std::cout << "Partial array after fill (first 5 with 99): ";
    for (int i = 0; i < 10; ++i) {
        std::cout << partial[i] << " ";  // Output: 99 99 99 99 99 0 0 0 0 0
    }
    std::cout << std::endl;

    // Example 3: Fill a middle section of an array
    int middle[8] = {1, 2, 3, 4, 5, 6, 7, 8};

    std::cout << "Middle array before fill: ";
    for (int i = 0; i < 8; ++i) {
        std::cout << middle[i] << " ";  // Output: 1 2 3 4 5 6 7 8
    }
    std::cout << std::endl;

    // Fill elements from index 2 to 5 (positions 3 through 6) with 0
    // middle + 2 points to the 3rd element, middle + 6 points to the 7th element
    std::fill(middle + 2, middle + 6, 0);

    std::cout << "Middle array after fill (indices 2-5 with 0): ";
    for (int i = 0; i < 8; ++i) {
        std::cout << middle[i] << " ";  // Output: 1 2 0 0 0 0 7 8
    }
    std::cout << std::endl;

    // Example 4: Filling with different data types - double array
    double decimals[4];

    // Fill double array with 3.14159
    std::fill(decimals, decimals + 4, 3.14159);

    std::cout << "Double array filled with 3.14159: ";
    for (int i = 0; i < 4; ++i) {
        std::cout << decimals[i] << " ";  // Output: 3.14159 3.14159 3.14159 3.14159
    }
    std::cout << std::endl;

    // Example 5: Filling with characters
    char characters[6];

    // Fill character array with 'A'
    std::fill(characters, characters + 6, 'A');

    std::cout << "Character array filled with 'A': ";
    for (int i = 0; i < 6; ++i) {
        std::cout << characters[i] << " ";  // Output: A A A A A A
    }
    std::cout << std::endl;

    // Example 6: Using sizeof to calculate array size
    int largeArray[20];

    // Calculate number of elements using sizeof
    // sizeof(largeArray) returns total bytes (80 bytes for int[20] on most systems)
    // sizeof(largeArray[0]) returns bytes per element (4 bytes for int)
    int arraySize = sizeof(largeArray) / sizeof(largeArray[0]);

    // Fill using calculated size
    std::fill(largeArray, largeArray + arraySize, 100);

    std::cout << "First 5 elements of largeArray (calculated size): ";
    for (int i = 0; i < 5; ++i) {
        std::cout << largeArray[i] << " ";  // Output: 100 100 100 100 100
    }
    std::cout << "..." << std::endl;

    return 0;
}







// Short summary:
// std::fill(start,end,value);
// here start index is filled and end index is ignored
// for instance: start = array_name = 0 and end = array_name + 10 = 0+10
// so in this case fill function will fill from 0th index to 9th index not the 10th index or 11th element
// 10th index = 11th element
