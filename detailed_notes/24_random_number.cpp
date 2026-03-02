// ============================================
// RANDOM NUMBER GENERATION IN C++
// ============================================

// These are HEADER FILES (libraries we include)
#include <iostream>   // For input/output (cout, cin)
#include <cstdlib>    // For rand() and srand() functions
#include <ctime>      // For time() function

int main() {
    // ============================================
    // PART 1: SEEDING THE RANDOM GENERATOR
    // ============================================
    
    /* WHAT IS A SEED?
       - Computers can't create truly random numbers
       - They use mathematical formulas to generate "pseudo-random" numbers
       - A SEED is the starting point for this formula
       - Same seed = same sequence of "random" numbers
    */
    
    // time(NULL) gets the current time in seconds since Jan 1, 1970
    // This number is constantly changing (different every second)
    // Using it as a seed ensures different numbers each program run
    
    srand(time(NULL));  // Seed the random generator with current time
    
    /* WITHOUT srand(time(NULL)):
       - You'd get the SAME numbers every time you run the program
       - Try commenting out the line above and see what happens!
    */
    
    // ============================================
    // PART 2: HOW rand() WORKS
    // ============================================
    
    /* rand() generates a random number between 0 and RAND_MAX
       RAND_MAX is a large constant (usually 32767 on many systems)
    */
    
    int randomNumber = rand();  // Gets a random number like 12753, 28901, etc.
    std::cout << "Raw random number (0 to " << RAND_MAX << "): " << randomNumber << std::endl;
    
    // ============================================
    // PART 3: THE % (MODULO) OPERATOR
    // ============================================
    
    /* The % operator gives you the REMAINDER after division
       
       Examples:
       10 % 3 = 1  (10 divided by 3 is 3 with remainder 1)
       15 % 5 = 0  (15 divided by 5 is 3 with remainder 0)
       7 % 10 = 7  (7 divided by 10 is 0 with remainder 7)
    */
    
    std::cout << "\n--- Understanding % (modulo) ---" << std::endl;
    std::cout << "10 % 3 = " << (10 % 3) << std::endl;
    std::cout << "15 % 5 = " << (15 % 5) << std::endl;
    std::cout << "7 % 10 = " << (7 % 10) << std::endl;
    
    // ============================================
    // PART 4: LIMITING RANDOM NUMBERS TO A RANGE
    // ============================================
    
    /* To get numbers in a specific range:
       
       rand() % N         → gives 0 to N-1
       (rand() % N) + 1   → gives 1 to N
       (rand() % (max - min + 1)) + min  → gives min to max
    */
    
    std::cout << "\n--- Random numbers in different ranges ---" << std::endl;
    
    // Range 0-9
    int zeroToNine = rand() % 10;
    std::cout << "0-9: " << zeroToNine << std::endl;
    
    // Range 1-10
    int oneToTen = (rand() % 10) + 1;
    std::cout << "1-10: " << oneToTen << std::endl;
    
    // Range 50-100 (51 possible numbers: 50 to 100)
    int fiftyToOneHundred = (rand() % 51) + 50;
    std::cout << "50-100: " << fiftyToOneHundred << std::endl;
    
    // ============================================
    // PART 5: DICE ROLL EXAMPLE (YOUR CODE)
    // ============================================
    
    std::cout << "\n--- Rolling three dice (1-6) ---" << std::endl;
    
    // Rolling a die: numbers 1 through 6
    // rand() % 6 gives 0,1,2,3,4,5
    // +1 gives 1,2,3,4,5,6
    
    int die1 = (rand() % 6) + 1;
    int die2 = (rand() % 6) + 1;
    int die3 = (rand() % 6) + 1;
    
    std::cout << "Die 1: " << die1 << std::endl;
    std::cout << "Die 2: " << die2 << std::endl;
    std::cout << "Die 3: " << die3 << std::endl;
    std::cout << "Total: " << (die1 + die2 + die3) << std::endl;
    
    // ============================================
    // PART 6: GENERATING MULTIPLE RANDOM NUMBERS
    // ============================================
    
    std::cout << "\n--- 5 random dice rolls in a row ---" << std::endl;
    
    for (int roll = 1; roll <= 5; roll++) {
        int dice = (rand() % 6) + 1;
        std::cout << "Roll " << roll << ": " << dice << std::endl;
    }
    
    // ============================================
    // PART 7: WHY WE USE srand() ONLY ONCE
    // ============================================
    
    /* IMPORTANT: Call srand() ONLY ONCE at the beginning of your program
       
       If you call srand() before EACH rand():
       - You might reset the seed to the same value (if time hasn't changed)
       - This can give you REPEATING or IDENTICAL numbers
       
       CORRECT:                      WRONG:
       srand(time(NULL));             for (int i=0; i<5; i++) {
       for (int i=0; i<5; i++) {          srand(time(NULL));
           int x = rand();                  int x = rand();
       }                                }
    */
    
    // ============================================
    // PART 8: COMMON RANDOM NUMBER FORMULAS
    // ============================================
    
    std::cout << "\n--- Common random ranges ---" << std::endl;
    
    // Coin flip: 0 or 1
    int coin = rand() % 2;
    std::cout << "Coin flip (0=heads, 1=tails): " << coin << std::endl;
    
    // Percentage: 0 to 100
    int percentage = rand() % 101;
    std::cout << "Random percentage: " << percentage << "%" << std::endl;
    
    // Dice (already did)
    
    // Card: 1 to 52
    int card = (rand() % 52) + 1;
    std::cout << "Random card (1-52): " << card << std::endl;
    
    // Temperature: -20 to 40 degrees Celsius
    int temp = (rand() % 61) - 20;  // 61 numbers: -20 to 40
    std::cout << "Random temperature: " << temp << "°C" << std::endl;
    
    return 0;
}