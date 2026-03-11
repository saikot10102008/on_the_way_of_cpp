/**
 * ============================================================================
 * COMPLETE C++ ARRAY GUIDE
 * Based on "C++ Full Course for free ⚡️" by Bro Code
 * All array-related chapters extracted and explained
 * Video: https://youtu.be/-TkoO8Z07hI
 * ============================================================================
 * This file follows the exact order of array topics from the video:
 * 32. Arrays (2:51:11)
 * 33. sizeof() operator (2:56:40)
 * 34. Iterate over an array (3:01:34)
 * 35. Foreach loop (3:05:40)
 * 36. Pass array to a function (3:08:36)
 * 37. Search an array for an element (3:13:07)
 * 38. Sort an array (3:20:43)
 * 39. fill() function (3:26:37)
 * 40. Fill an array with user input (3:31:19)
 * 41. Multidimensional arrays (3:38:17)
 */

#include <iostream>
#include <string>

// Function prototypes (explained in Chapter 36)
void printArray(int array[], int size);
void applyTax(double prices[], int size);
int searchArray(std::string array[], int size, std::string element);
void bubbleSort(int array[], int size);

int main() {
    std::cout << "========== ARRAY TUTORIAL - ALL CHAPTERS ==========\n\n";

    // ==================== CHAPTER 32: ARRAYS (2:51:11) ====================
    std::cout << "=== CHAPTER 32: ARRAYS ===\n";
    std::cout << "An array is a collection of variables of the SAME type.\n";
    std::cout << "Think of it as a list of items with numbered positions (indices).\n";
    std::cout << "IMPORTANT: Array indices ALWAYS start at 0!\n\n";

    // Different ways to declare arrays
    std::cout << "1. Declaring arrays:\n";
    
    // Method 1: Declare first, then assign
    std::string cars[3];  // Creates array that can hold 3 strings
    cars[0] = "Corvette"; // First element (index 0)
    cars[1] = "Mustang";  // Second element (index 1)
    cars[2] = "Camry";    // Third element (index 2)
    
    std::cout << "   Method 1 (declare then assign): ";
    std::cout << cars[0] << ", " << cars[1] << ", " << cars[2] << "\n";
    
    // Method 2: Declare and initialize together
    double prices[4] = {5.99, 10.49, 2.50, 15.00};
    std::cout << "   Method 2 (declare & initialize): $";
    std::cout << prices[0] << ", $" << prices[1] << ", $" << prices[2] << ", $" << prices[3] << "\n";
    
    // Method 3: Let compiler count elements
    char vowels[] = {'a', 'e', 'i', 'o', 'u'}; // Size automatically becomes 5
    std::cout << "   Method 3 (compiler counts): ";
    std::cout << vowels[0] << vowels[1] << vowels[2] << vowels[3] << vowels[4] << "\n\n";

    // Modifying array elements
    std::cout << "2. Modifying array elements:\n";
    int scores[5] = {85, 90, 78, 92, 88};
    std::cout << "   Original scores: " << scores[0] << " " << scores[1] << " "
              << scores[2] << " " << scores[3] << " " << scores[4] << "\n";
    
    scores[1] = 95; // Change second element (index 1)
    scores[3] = 100; // Change fourth element (index 3)
    std::cout << "   After modifying indices 1 and 3: ";
    std::cout << scores[0] << " " << scores[1] << " " << scores[2] << " "
              << scores[3] << " " << scores[4] << "\n\n";

    // ==================== CHAPTER 33: SIZEOF() OPERATOR (2:56:40) ====================
    std::cout << "\n=== CHAPTER 33: SIZEOF() OPERATOR ===\n";
    std::cout << "sizeof() tells you how many BYTES something uses in memory.\n";
    std::cout << "This is useful for finding out how many elements are in an array.\n\n";
    
    std::cout << "   Size of entire 'scores' array: " << sizeof(scores) << " bytes\n";
    std::cout << "   Size of one integer: " << sizeof(int) << " bytes\n";
    
    // The trick to find array length
    int numElements = sizeof(scores) / sizeof(scores[0]);
    // Alternative: sizeof(scores) / sizeof(int)
    std::cout << "   Number of elements in 'scores': " << numElements << "\n";
    std::cout << "   Formula: total_bytes / bytes_of_one_element\n\n";

    // ==================== CHAPTER 34: ITERATE OVER AN ARRAY (3:01:34) ====================
    std::cout << "\n=== CHAPTER 34: ITERATE OVER AN ARRAY ===\n";
    std::cout << "Iterating means going through each element one by one.\n";
    std::cout << "The most common way is using a for loop with an index.\n\n";
    
    std::cout << "   All scores: ";
    for (int i = 0; i < numElements; i++) {
        std::cout << scores[i] << " ";
    }
    std::cout << "\n";
    
    // Using loop to fill an array
    int numbers[10];
    std::cout << "   Filling array with 1-10: ";
    for (int i = 0; i < 10; i++) {
        numbers[i] = i + 1;
        std::cout << numbers[i] << " ";
    }
    std::cout << "\n\n";

    // ==================== CHAPTER 35: FOREACH LOOP (3:05:40) ====================
    std::cout << "\n=== CHAPTER 35: FOREACH LOOP ===\n";
    std::cout << "A simpler way to loop through arrays when you don't need the index.\n";
    std::cout << "Syntax: for (type variableName : arrayName)\n\n";
    
    std::cout << "   Using foreach to read values: ";
    for (double price : prices) {
        std::cout << "$" << price << " ";
    }
    std::cout << "\n";
    
    std::cout << "   To MODIFY values, use a reference '&':\n";
    std::cout << "   Original prices: ";
    for (double price : prices) std::cout << "$" << price << " ";
    
    for (double &price : prices) {  // The '&' means we're working with the actual element
        price = price * 2;  // This changes the original array
    }
    
    std::cout << "\n   After doubling (using reference): ";
    for (double price : prices) std::cout << "$" << price << " ";
    std::cout << "\n\n";

    // ==================== CHAPTER 36: PASS ARRAY TO A FUNCTION (3:08:36) ====================
    std::cout << "\n=== CHAPTER 36: PASS ARRAY TO A FUNCTION ===\n";
    std::cout << "When you pass an array to a function, you're actually passing its memory address.\n";
    std::cout << "This means the function can MODIFY the original array!\n";
    std::cout << "Always pass the size along with the array.\n\n";
    
    std::cout << "   Original prices (before tax): ";
    for (double price : prices) std::cout << "$" << price << " ";
    
    applyTax(prices, 5);  // Pass array and its size
    
    std::cout << "\n   After calling applyTax() function: ";
    for (double price : prices) std::cout << "$" << price << " ";
    std::cout << "\n\n";

    // ==================== CHAPTER 37: SEARCH AN ARRAY (3:13:07) ====================
    std::cout << "\n=== CHAPTER 37: SEARCH AN ARRAY ===\n";
    std::cout << "To find an element, loop through and check each value.\n\n";
    
    std::string fruits[] = {"apple", "banana", "orange", "grape", "mango"};
    int fruitSize = sizeof(fruits)/sizeof(fruits[0]);
    std::string searchFor = "orange";
    
    int index = searchArray(fruits, fruitSize, searchFor);
    
    if (index != -1) {
        std::cout << "   Found '" << searchFor << "' at index " << index << "\n";
    } else {
        std::cout << "   '" << searchFor << "' not found\n";
    }
    
    searchFor = "kiwi";
    index = searchArray(fruits, fruitSize, searchFor);
    if (index != -1) {
        std::cout << "   Found '" << searchFor << "' at index " << index << "\n";
    } else {
        std::cout << "   '" << searchFor << "' not found\n";
    }
    std::cout << "\n";

    // ==================== CHAPTER 38: SORT AN ARRAY (3:20:43) ====================
    std::cout << "\n=== CHAPTER 38: SORT AN ARRAY ===\n";
    std::cout << "Sorting arranges elements in order (smallest to largest, etc.)\n";
    std::cout << "This example uses Bubble Sort - simple but not the fastest.\n\n";
    
    int unsorted[] = {7, 2, 9, 1, 5, 3};
    int sortSize = sizeof(unsorted)/sizeof(unsorted[0]);
    
    std::cout << "   Unsorted array: ";
    printArray(unsorted, sortSize);
    
    bubbleSort(unsorted, sortSize);
    
    std::cout << "   Sorted array (ascending): ";
    printArray(unsorted, sortSize);
    std::cout << "\n";

    // ==================== CHAPTER 39: FILL() FUNCTION (3:26:37) ====================
    std::cout << "\n=== CHAPTER 39: FILL() FUNCTION ===\n";
    std::cout << "fill() lets you set a range of elements to a specific value.\n";
    std::cout << "Syntax: fill(startAddress, endAddress, value)\n";
    std::cout << "Note: endAddress is EXCLUSIVE (stops before that position)\n\n";
    
    const int SIZE = 10;
    int myArray[SIZE];
    
    // Fill entire array
    std::fill(myArray, myArray + SIZE, 100);
    std::cout << "   Entire array filled with 100: ";
    printArray(myArray, SIZE);
    
    // Fill part of array (indices 2, 3, 4, 5)
    std::fill(myArray + 2, myArray + 6, 777);
    std::cout << "   After filling indices 2-5 with 777: ";
    printArray(myArray, SIZE);
    
    // Fill another part
    std::fill(myArray + 7, myArray + 9, 999);
    std::cout << "   After filling indices 7-8 with 999: ";
    printArray(myArray, SIZE);
    std::cout << "\n";

    // ==================== CHAPTER 40: FILL ARRAY WITH USER INPUT (3:31:19) ====================
    std::cout << "\n=== CHAPTER 40: FILL ARRAY WITH USER INPUT ===\n";
    std::cout << "You can use a loop to get values from the user.\n\n";
    
    std::string names[5];
    int nameCount = sizeof(names)/sizeof(names[0]);
    
    std::cout << "   Enter " << nameCount << " names:\n";
    for (int i = 0; i < nameCount; i++) {
        std::cout << "   Name " << (i + 1) << ": ";
        std::getline(std::cin >> std::ws, names[i]); // std::ws removes whitespace
    }
    
    std::cout << "\n   You entered: ";
    for (int i = 0; i < nameCount; i++) {
        std::cout << names[i];
        if (i < nameCount - 1) std::cout << ", ";
    }
    std::cout << "\n\n";

    // ==================== CHAPTER 41: MULTIDIMENSIONAL ARRAYS (3:38:17) ====================
    std::cout << "\n=== CHAPTER 41: MULTIDIMENSIONAL ARRAYS ===\n";
    std::cout << "Think of these as 'arrays of arrays' - like a table with rows and columns.\n";
    std::cout << "Syntax: type name[rows][columns]\n\n";
    
    // Declare and initialize a 2D array (3 rows, 4 columns)
    int matrix[3][4] = {
        {1, 2, 3, 4},    // Row 0
        {5, 6, 7, 8},    // Row 1
        {9, 10, 11, 12}  // Row 2
    };
    
    std::cout << "   Access element: matrix[row][column]\n";
    std::cout << "   matrix[1][2] = " << matrix[1][2] << " (row 1, column 2)\n\n";
    
    // Nested loops to print 2D array
    std::cout << "   Printing entire matrix:\n";
    for (int row = 0; row < 3; row++) {
        std::cout << "   Row " << row << ": ";
        for (int col = 0; col < 4; col++) {
            std::cout << matrix[row][col] << "\t";
        }
        std::cout << "\n";
    }
    
    // Practical example: Tic-Tac-Toe board
    std::cout << "\n   Practical example - Tic-Tac-Toe board:\n";
    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
    
    // Make some moves
    board[0][0] = 'X';
    board[1][1] = 'O';
    board[2][2] = 'X';
    board[0][2] = 'O';
    
    std::cout << "     |0    |1    |2\n";
    std::cout << "   ---+-----+-----+----\n";
    for (int row = 0; row < 3; row++) {
        std::cout << "   " << row << " |";
        for (int col = 0; col < 3; col++) {
            std::cout << " " << board[row][col] << "  |";
        }
        std::cout << "\n   ---+-----+-----+----\n";
    }
    
    // ==================== SUMMARY ====================
    std::cout << "\n========== ARRAY QUICK REFERENCE ==========\n";
    std::cout << "✓ Arrays store multiple values of SAME type\n";
    std::cout << "✓ Index always starts at 0\n";
    std::cout << "✓ Use sizeof(array)/sizeof(array[0]) to get length\n";
    std::cout << "✓ For loop: use when you need the index\n";
    std::cout << "✓ Foreach loop: use for simple reading\n";
    std::cout << "✓ Arrays passed to functions CAN be modified\n";
    std::cout << "✓ Use fill() to set ranges of values\n";
    std::cout << "✓ 2D arrays need nested loops\n";
    std::cout << "==========================================\n";
    
    return 0;
}

// ==================== FUNCTION DEFINITIONS ====================

// Chapter 36: Function that modifies an array
void applyTax(double prices[], int size) {
    for (int i = 0; i < size; i++) {
        prices[i] *= 1.10; // Add 10% tax
    }
}

// Chapter 36: Helper function to print array
void printArray(int array[], int size) {
    std::cout << "[ ";
    for (int i = 0; i < size; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << "]";
}

// Chapter 37: Search function
int searchArray(std::string array[], int size, std::string element) {
    for (int i = 0; i < size; i++) {
        if (array[i] == element) {
            return i; // Return index if found
        }
    }
    return -1; // Return -1 if not found
}

// Chapter 38: Bubble Sort implementation
void bubbleSort(int array[], int size) {
    int temp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                // Swap elements
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}