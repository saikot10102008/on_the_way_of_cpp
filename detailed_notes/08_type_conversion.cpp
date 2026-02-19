#include <iostream>

int main()
{
    // =====================================================================
    // TYPE CONVERSION in C++
    // =====================================================================
    // Changing a value from one data type → another data type
    //
    // Two main types:
    // 1. Implicit   (automatic)  ← C++ does it for you
    // 2. Explicit   (manual)     ← YOU tell C++ to do it

    std::cout << "\n=== 1. IMPLICIT CONVERSION (Automatic / Widening) ===\n\n";

    // Smaller type → larger type  (usually safe, no data loss)
    int    num   = 100;
    double d_num = num;               // int → double  (automatic)
    std::cout << "int " << num << " → double = " << d_num << "\n";

    char   letter = 'A';              // ASCII 65
    int    code   = letter;           // char → int  (automatic)
    std::cout << "char '" << letter << "' → int = " << code << "\n";

    float  f = 3.14f;
    double d = f;                     // float → double (automatic)
    std::cout << "float " << f << " → double = " << d << "\n\n";


    std::cout << "\n=== 2. EXPLICIT CONVERSION (Type Casting) ===\n\n";

    // You force the conversion using (type) or static_cast<type>(value)

    // Most common cases:

    // double → int   (loses decimal part – truncates / cuts off)
    double price = 49.99;
    int    int_price = (int)price;                // old C-style cast
    std::cout << "double " << price << " → int = " << int_price << "  (decimal lost)\n";

    // Better & modern way (C++ recommended)
    int modern_price = static_cast<int>(price);
    std::cout << "static_cast: " << modern_price << "\n";

    // int → double (when doing division – very important!)
    int a = 10;
    int b = 3;

    // Wrong (integer division)
    std::cout << "10 / 3   = " << (10 / 3)   << "   (integer division)\n";

    // Correct – make at least one operand double
    std::cout << "10.0 / 3 = " << (10.0 / 3) << "   (implicit)\n";
    std::cout << "10 / 3.0 = " << (10 / 3.0) << "   (implicit)\n";

    // Explicit cast
    std::cout << "(double)10 / 3 = " << (static_cast<double>(10) / 3) << "\n\n";


    // =================================================================
    // Very common real-life examples
    // =================================================================

    // 1. Getting whole number from decimal
    double temperature = 23.78;
    int    whole_temp  = static_cast<int>(temperature);
    std::cout << "Temp: " << temperature << " → whole = " << whole_temp << " °C\n";

    // 2. Calculating average correctly
    int score1 = 85, score2 = 92, score3 = 78;
    double average;

    // Wrong way
    // average = (score1 + score2 + score3) / 3;     // → 85 (integer division!)

    // Correct ways
    average = (score1 + score2 + score3) / 3.0;                  // implicit
    // or
    average = static_cast<double>(score1 + score2 + score3) / 3; // explicit

    std::cout << "Average = " << average << "\n";


    // =================================================================
    // Quick Summary Table
    // =================================================================
    // What you want           → How to write it
    // -----------------------------------------------------------------
    // int    → double         → automatic (just assign)
    // char   → int            → automatic
    // double → int            → (int) or static_cast<int>()
    // int    → double (division) → write 3.0  or  static_cast<double>(x)
    // safest modern style     → use static_cast<desired_type>(value)
    // =================================================================

    std::cout << "\nRemember:\n";
    std::cout << "• When dividing → at least one number must be double/float\n";
    std::cout << "• Use static_cast<>  (modern & safe) instead of old (int)\n";
    std::cout << "• Casting double → int  always **truncates** (cuts decimal)\n";

    return 0;
}