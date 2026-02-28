#include <iostream>
int main() {
    int num = 10;
    
    // DO-WHILE runs the code FIRST, THEN checks condition
    do {
        std::cout << "This runs at least once!" << std::endl;
        num++;
    } while (num < 5);  // Condition: num (11) < 5? FALSE
    
    // Even though condition is false, the code still ran once
    std::cout << "Loop is done. Num is now: " << num << std::endl;
    
    return 0;
}