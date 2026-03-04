/**
 * FUNCTION PROTOTYPE AND PARAMETER QUESTIONS - SUMMARY
 * This file summarizes answers to common function-related questions
 */

#include <iostream>
#include <string>
using namespace std;

// ============================================================================
// QUESTION 1: Can we use different parameter names in prototype and definition?
// ANSWER: YES - parameter names are for documentation only, compiler ignores them
// ============================================================================

// Prototype with names
int addNumbers(int firstValue, int secondValue);

// Also valid: prototype with different names (or no names)
int subtractNumbers(int a, int b);  // Different names from definition below
int multiplyNumbers(int, int);       // Valid: only types specified

int main() {
    cout << "=== FUNCTION PARAMETER QUESTIONS SUMMARY ===\n" << endl;
    
    // These work despite different parameter names in definitions
    cout << "addNumbers(5, 3) = " << addNumbers(5, 3) << endl;
    cout << "subtractNumbers(10, 4) = " << subtractNumbers(10, 4) << endl;
    cout << "multiplyNumbers(6, 7) = " << multiplyNumbers(6, 7) << endl;
    
    // ========================================================================
    // QUESTION 2: Can we pass int to function expecting double?
    // ANSWER: YES - implicit type conversion (promotion) happens automatically
    // ========================================================================
    
    cout << "\n--- Passing int to double parameters ---" << endl;
    
    int intValue = 42;
    float floatValue = 3.14f;
    char charValue = 'A';  // ASCII 65
    
    cout << "int " << intValue << " passed to double function: ";
    displayDouble(intValue);  // int → double
    
    cout << "float " << floatValue << " passed to double function: ";
    displayDouble(floatValue);  // float → double
    
    cout << "char '" << charValue << "' passed to double function: ";
    displayDouble(charValue);  // char → int → double
    
    // Practical example
    int radius = 7;
    cout << "\nCircle area with int radius " << radius << ": " 
         << calculateCircleArea(radius) << endl;  // int promoted to double
    
    // ========================================================================
    // QUESTION 3: What about passing double to int?
    // ANSWER: YES but risky - truncation occurs (decimal part lost)
    // ========================================================================
    
    cout << "\n--- Passing double to int (truncation warning) ---" << endl;
    
    double doubleValue = 3.14159;
    cout << "double " << doubleValue << " passed to int function: ";
    truncateExample(doubleValue);  // 3.14159 → 3 (decimal lost)
    
    return 0;
}

// ============================================================================
// FUNCTION DEFINITIONS (with different parameter names than prototypes)
// ============================================================================

// Definition with names different from prototype
int addNumbers(int num1, int num2) {  // Different from prototype's firstValue,secondValue
    return num1 + num2;
}

// Definition with different names
int subtractNumbers(int x, int y) {  // Different from prototype's a,b
    return x - y;
}

// Definition with names (prototype had no names)
int multiplyNumbers(int factor1, int factor2) {
    return factor1 * factor2;
}

// ============================================================================
// FUNCTIONS DEMONSTRATING TYPE CONVERSION
// ============================================================================

// Function expecting double parameter
void displayDouble(double value) {
    cout << value << " (as double)" << endl;
}

// Function demonstrating implicit conversion in calculations
double calculateCircleArea(double radius) {  // double parameter
    return 3.14159 * radius * radius;
}

// Function demonstrating double to int conversion (truncation)
void truncateExample(int value) {  // int parameter
    cout << value << " (decimal part lost!)" << endl;
}

// ============================================================================
// SUMMARY TABLE (as code comments)
// ============================================================================

/*
 * ----------------------------------------------------------------------------
 * QUESTION                                | ANSWER | EXPLANATION
 * ----------------------------------------------------------------------------
 * Different parameter names in prototype  |  YES  | Names are ignored by 
 * and definition?                         |       | compiler, only types matter
 * ----------------------------------------------------------------------------
 * Only parameter types in prototype?      |  YES  | int add(int, int); is valid
 * ----------------------------------------------------------------------------
 * Pass int to double parameter?           |  YES  | Automatic promotion:
 *                                         |       | int → double (safe)
 * ----------------------------------------------------------------------------
 * Pass double to int parameter?           |  YES  | But truncation occurs:
 *                                         |       | 3.14 → 3 (loss of data)
 * ----------------------------------------------------------------------------
 * Pass string to int parameter?           |  NO   | No implicit conversion
 * ----------------------------------------------------------------------------
 */

// ============================================================================
// BEST PRACTICES REMINDER
// ============================================================================

/*
 * 1. Use consistent parameter names in prototype and definition for clarity
 * 2. Include parameter names in prototypes (better documentation)
 * 3. Be aware of implicit conversions - they happen automatically
 * 4. Use explicit casts when conversion might lose data
 * 5. Enable compiler warnings to catch risky conversions (-Wconversion)
 * 
 * Example of explicit cast to avoid warning:
 * double d = 3.14;
 * int i = static_cast<int>(d);  // Explicit: "I know I'm losing data"
 */