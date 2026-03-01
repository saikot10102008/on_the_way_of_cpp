#include <iostream>
int main() {
    // Multiplication table from 1 to 3
    
    // Outer loop: multiplier (1 to 3)
    for (int i = 1; i <= 3; i++) {
        
        // Inner loop: multiplicand (1 to 3)
        for (int j = 1; j <= 3; j++) {
            std::cout << i << " x " << j << " = " << i * j << "  ";
        }
        
        std::cout << std::endl;  // New line after each row
    }
    
    // Output:
    // 1 x 1 = 1   1 x 2 = 2   1 x 3 = 3
    // 2 x 1 = 2   2 x 2 = 4   2 x 3 = 6
    // 3 x 1 = 3   3 x 2 = 6   3 x 3 = 9
    
    return 0;
}