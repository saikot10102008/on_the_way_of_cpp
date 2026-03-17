#include <iostream>
#include <string>

int main() {
    std::cout << "=== C++ Notes - Search an Array for an Element ===\n\n";

    // =================================================================
    // What is searching an array?
    // =================================================================
    std::cout << "1. What is searching an array?\n";
    std::cout << "   - We check every element one by one (linear search)\n";
    std::cout << "   - Compare each element with the value we are looking for\n";
    std::cout << "   - If we find a match, we can return the index or just say \"found\"\n";
    std::cout << "   - If we finish the loop without a match, the element is not present\n";
    std::cout << "   - This works for both int arrays and std::string arrays\n\n";

    // =================================================================
    // Important: Always calculate array size using sizeof()
    // (from previous topic)
    // =================================================================
    std::cout << "2. Always get array size automatically:\n";
    std::cout << "   int size = sizeof(array) / sizeof(array[0]);\n";
    std::cout << "   This prevents hardcoding the length and works even if you change the array\n\n";

    // =================================================================
    // DEMO 1: Searching an integer array
    // =================================================================
    std::cout << "3. Demo - Searching integer array:\n";

    int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    int target = 7;                    // value we are searching for

    std::cout << "   Array : ";
    for(int i = 0; i < size; i++) std::cout << numbers[i] << " ";
    std::cout << "\n   Searching for : " << target << "\n";

    bool found = false;                // flag to remember if we found it
    int index = -1;                    // will store the position if found

    // Linear search starts here
    for(int i = 0; i < size; i++) {    // loop through every element
        if(numbers[i] == target) {     // comparison
            found = true;
            index = i;
            break;                     // stop early once found (optional but faster)
        }
    }

    if(found) {
        std::cout << "   Result: Found at index " << index << "\n\n";
    } else {
        std::cout << "   Result: Not found\n\n";
    }

    // =================================================================
    // DEMO 2: Searching a string array
    // =================================================================
    std::cout << "4. Demo - Searching string array:\n";

    std::string foods[] = {"pizza", "hamburger", "hotdog", "sushi", "ramen"};
    int foodSize = sizeof(foods) / sizeof(foods[0]);

    std::string foodTarget = "sushi";

    std::cout << "   Array : ";
    for(int i = 0; i < foodSize; i++) std::cout << foods[i] << " ";
    std::cout << "\n   Searching for : " << foodTarget << "\n";

    bool foodFound = false;

    for(int i = 0; i < foodSize; i++) {
        if(foods[i] == foodTarget) {     // std::string supports == operator
            foodFound = true;
            std::cout << "   Result: Found at index " << i << "\n\n";
            break;
        }
    }

    if(!foodFound) {
        std::cout << "   Result: Not found\n\n";
    }

    // =================================================================
    // Key points & best practices
    // =================================================================
    std::cout << "5. Key points to remember:\n";
    std::cout << "   - This is called linear search (O(n) time in worst case)\n";
    std::cout << "   - Use a bool flag (found) to track success\n";
    std::cout << "   - break; once found to avoid unnecessary checks\n";
    std::cout << "   - Always calculate size with sizeof() - never hardcode\n";
    std::cout << "   - Works with int, double, char, std::string, etc.\n";
    std::cout << "   - For very large arrays, more advanced methods (like binary search) exist but not covered here\n\n";

    std::cout << "=== End of Search an Array notes ===\n";
    std::cout << "Compile and run this file to see the live demos.\n";
    std::cout << "You can change the 'target' or 'foodTarget' values to test different searches.\n";

    return 0;
}