#include <iostream>

int main() 
{
    // =================================================================
    // ARITHMETIC OPERATORS in C++
    // =================================================================
    // These are the basic math symbols you already know from school
    // They work mostly the same way in C++ as in real life

    int a = 10;
    int b = 3;

    std::cout << "a = " << a << ", b = " << b << "\n\n";

    // 1. Addition          +
    int sum = a + b;
    std::cout << "Addition:       " << a << " + " << b << " = " << sum << "\n";

    // 2. Subtraction       -
    int difference = a - b;
    std::cout << "Subtraction:    " << a << " - " << b << " = " << difference << "\n";

    // 3. Multiplication    *
    int product = a * b;
    std::cout << "Multiplication: " << a << " * " << b << " = " << product << "\n";

    // 4. Division          /
    // IMPORTANT: integer / integer → gives integer (cuts off decimal)
    int division = a / b;               // 10 / 3 = 3   (decimal part removed!)
    std::cout << "Division (int): " << a << " / " << b << " = " << division << "\n";

    // To get decimal result → use float or double
    double real_division = (double)a / b;   // 10.0 / 3 = 3.333...
    std::cout << "Real division:  " << a << " / " << b << " = " << real_division << "\n";

    // 5. Modulus (remainder)   %
    // Gives what's left after division
    int remainder = a % b;              // 10 ÷ 3 = 3 remainder 1
    std::cout << "Remainder:      " << a << " % " << b << " = " << remainder << "\n\n";

    // Quick examples people use a lot:
    std::cout << "Is 25 even?     " << (25 % 2) << " (0 = even, 1 = odd)\n";
    std::cout << "Last digit of 1234: " << (1234 % 10) << "\n\n";

    // 6. Increment / Decrement (very common!)
    int x = 5;

    std::cout << "x starts as: " << x << "\n";

    x++;          // same as x = x + 1
    std::cout << "After x++:   " << x << "\n";

    ++x;          // same as x = x + 1 (but can matter in expressions)
    std::cout << "After ++x:   " << x << "\n";

    x--;          // x = x - 1
    std::cout << "After x--:   " << x << "\n";

    --x;
    std::cout << "After --x:   " << x << "\n\n";

    // Difference between x++ and ++x (very important!)
    int y = 10;
    std::cout << "y = " << y << "\n";

    std::cout << "Post-increment (y++): " << y++ << "  → now y = " << y << "\n";
    // prints 10 first, THEN increases y to 11

    std::cout << "Pre-increment (++y):  " << ++y << "  → now y = " << y << "\n";
    // increases y to 12 first, THEN prints 12

    // =================================================================
    // Summary Table (easy to remember)
    // =================================================================
    // +    addition
    // -    subtraction
    // *    multiplication
    // /    division          (int/int → drops decimal)
    // %    modulus (remainder)
    // ++   increment by 1
    // --   decrement by 1
    // =================================================================
    std::cout << "\nThat's all basic arithmetic operators!\n";
    std::cout << "Next topic usually: assignment operators (+= -= *= /= %=)\n";

    return 0;
}