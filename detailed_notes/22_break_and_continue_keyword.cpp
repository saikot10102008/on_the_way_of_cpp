#include <iostream>
int main() {
    
    // BREAK: Exits the loop immediately
    std::cout << "BREAK example:" << std::endl;
    for (int i = 1; i <= 5; i++) {
        if (i == 3) {
            break;  // Loop stops completely when i = 3
        }
        std::cout << i << " ";
    }
    // Output: 1 2
    
    std::cout << "\n\nCONTINUE example:" << std::endl;
    // CONTINUE: Skips the current iteration, moves to next
    for (int i = 1; i <= 5; i++) {
        if (i == 3) {
            continue;  // Skip printing 3, go to i = 4
        }
        std::cout << i << " ";
    }
    // Output: 1 2 4 5
    
    return 0;
}