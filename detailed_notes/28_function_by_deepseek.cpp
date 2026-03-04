/**
 * C++ FUNCTIONS - COMPLETE GUIDE
 * This file demonstrates all concepts related to functions in C++
 */

#include <iostream>
#include <string>
#include <vector>
#include <functional>
using namespace std;

// ============================================================================
// PART 1: BASIC FUNCTION STRUCTURE
// ============================================================================

/**
 * FUNCTION STRUCTURE:
 * return_type function_name(parameter_list) {
 *     // function body
 *     return value; // if return_type is not void
 * }
 */

// Simple function with no parameters and no return value
void greet() {
    cout << "Hello, World!" << endl;
}

// Function with parameters and return value
int add(int a, int b) {
    return a + b;
}

// Function with default parameters
void displayInfo(string name, int age = 25, string city = "Unknown") {
    cout << "Name: " << name << ", Age: " << age << ", City: " << city << endl;
}

// ============================================================================
// PART 2: FUNCTION OVERLOADING
// ============================================================================

/**
 * FUNCTION OVERLOADING: Multiple functions with the same name but different parameters
 * Compiler determines which function to call based on arguments
 */

// Overloaded add functions
int add(int a, int b, int c) {
    return a + b + c;
}

double add(double a, double b) {
    return a + b;
}

string add(string a, string b) {
    return a + " " + b;
}

// ============================================================================
// PART 3: PASSING PARAMETERS
// ============================================================================

// 1. Pass by value (creates a copy)
void passByValue(int x) {
    x = 100; // This won't affect the original variable
    cout << "Inside passByValue: " << x << endl;
}

// 2. Pass by reference (works with original variable)
void passByReference(int &x) {
    x = 100; // This modifies the original variable
    cout << "Inside passByReference: " << x << endl;
}

// 3. Pass by const reference (read-only, efficient for large objects)
void passByConstReference(const string &str) {
    cout << "Inside passByConstReference: " << str << endl;
    // str = "New value"; // ERROR: Cannot modify const reference
}

// 4. Pass by pointer
void passByPointer(int *ptr) {
    if (ptr) { // Always check for null pointers
        *ptr = 100;
        cout << "Inside passByPointer: " << *ptr << endl;
    }
}

// 5. Pass by array (decays to pointer)
void processArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] *= 2; // Modifies original array
    }
}

// ============================================================================
// PART 4: RETURN VALUES
// ============================================================================

// Returning by value
int getValue() {
    return 42;
}

// Returning by reference (be careful with local variables!)
int& getReference(int &x) {
    return x; // Safe: x is a reference parameter
}

// NEVER DO THIS: returning reference to local variable
/*
int& badFunction() {
    int local = 10;
    return local; // ERROR: local variable destroyed after function ends
}
*/

// Returning pointer (similar caution needed)
int* getPointer(int *ptr) {
    return ptr; // Safe if pointer points to valid memory
}

// ============================================================================
// PART 5: INLINE FUNCTIONS
// ============================================================================

/**
 * INLINE FUNCTIONS: Suggest to compiler to insert function code directly
 * Useful for small, frequently called functions to avoid function call overhead
 */
inline int square(int x) {
    return x * x;
}

// ============================================================================
// PART 6: RECURSIVE FUNCTIONS
// ============================================================================

// Factorial using recursion
int factorial(int n) {
    // Base case
    if (n <= 1) {
        return 1;
    }
    // Recursive case
    return n * factorial(n - 1);
}

// Fibonacci sequence using recursion
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// ============================================================================
// PART 7: FUNCTION POINTERS
// ============================================================================

// Function pointer syntax: return_type (*pointer_name)(parameter_types)
int multiply(int a, int b) {
    return a * b;
}

// Function taking function pointer as parameter
int operate(int a, int b, int (*operation)(int, int)) {
    return operation(a, b);
}

// Using typedef for function pointer
typedef int (*OperationPtr)(int, int);

// ============================================================================
// PART 8: LAMBDA FUNCTIONS (C++11 and later)
// ============================================================================

/**
 * LAMBDA SYNTAX: [capture](parameters) -> return_type { body }
 * Capture: how to access variables from surrounding scope
 */

void demonstrateLambdas() {
    int multiplier = 3;
    int offset = 5;
    
    // Basic lambda
    auto addLambda = [](int a, int b) {
        return a + b;
    };
    
    // Lambda with capture by value
    auto multiplyByValue = [multiplier](int x) {
        return x * multiplier; // Can use multiplier (read-only)
    };
    
    // Lambda with capture by reference
    auto addWithOffset = [&offset](int x) {
        offset += x; // Can modify offset
        return x + offset;
    };
    
    // Lambda with mixed capture
    auto complexLambda = [multiplier, &offset](int x) {
        offset += multiplier;
        return x * multiplier + offset;
    };
    
    // Lambda with explicit return type
    auto divide = [](double a, double b) -> double {
        if (b != 0) {
            return a / b;
        }
        return 0;
    };
    
    // Generic lambda (C++14)
    auto genericLambda = [](auto a, auto b) {
        return a + b;
    };
    
    cout << "Lambda results:" << endl;
    cout << "addLambda(5,3): " << addLambda(5, 3) << endl;
    cout << "multiplyByValue(10): " << multiplyByValue(10) << endl;
    cout << "addWithOffset(7): " << addWithOffset(7) << endl;
    cout << "divide(10,3): " << divide(10, 3) << endl;
    cout << "genericLambda(5,3.14): " << genericLambda(5, 3.14) << endl;
}

// ============================================================================
// PART 9: FUNCTION TEMPLATES
// ============================================================================

/**
 * FUNCTION TEMPLATES: Generic functions that work with any data type
 */

template <typename T>
T maximum(T a, T b) {
    return (a > b) ? a : b;
}

// Template with multiple types
template <typename T, typename U>
auto addGeneric(T a, U b) -> decltype(a + b) { // C++11 trailing return type
    return a + b;
}

// Template specialization
template <>
string maximum<string>(string a, string b) {
    return (a.length() > b.length()) ? a : b;
}

// ============================================================================
// PART 10: VARIADIC FUNCTIONS (C++11)
// ============================================================================

// Base case for recursion
void printAll() {
    cout << endl;
}

// Variadic template function
template <typename T, typename... Args>
void printAll(T first, Args... args) {
    cout << first << " ";
    printAll(args...); // Recursive call
}

// ============================================================================
// PART 11: CONSTEXPR FUNCTIONS (C++11/14)
// ============================================================================

/**
 * CONSTEXPR FUNCTIONS: Can be evaluated at compile time
 */

constexpr int factorial_constexpr(int n) {
    // In C++11, constexpr functions were limited to single return statement
    // In C++14, they can be more complex
    int result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

// ============================================================================
// PART 12: NOEXCEPT SPECIFICATION
// ============================================================================

/**
 * NOEXCEPT: Specifies that function doesn't throw exceptions
 * Helps compiler optimize code
 */

int divideNoExcept(int a, int b) noexcept {
    if (b == 0) {
        // This will call std::terminate() instead of throwing
        // Use with caution!
        return 0;
    }
    return a / b;
}

// Conditional noexcept
template <typename T>
void moveObject(T& dest, T&& src) noexcept(noexcept(dest = std::move(src))) {
    dest = std::move(src);
}

// ============================================================================
// PART 13: STATIC AND FRIEND FUNCTIONS
// ============================================================================

class MyClass {
private:
    int value = 0;
    static int staticCount; // Static member variable
    
public:
    // Static member function - can be called without object
    static int getStaticCount() {
        return staticCount;
    }
    
    // Const member function - doesn't modify object
    int getValue() const {
        return value;
    }
    
    // Friend function - can access private members
    friend void friendFunction(MyClass &obj);
};

int MyClass::staticCount = 0; // Initialize static member

// Friend function definition
void friendFunction(MyClass &obj) {
    obj.value = 999; // Can access private member
    cout << "Friend function accessed private value: " << obj.value << endl;
}

// ============================================================================
// PART 14: MAIN FUNCTION VARIATIONS
// ============================================================================

// Standard main function
int main() {
    cout << "========== C++ FUNCTIONS COMPLETE GUIDE ==========\n" << endl;
    
    // ------------------------------------------------------------------------
    // Basic Function Calls
    // ------------------------------------------------------------------------
    cout << "1. BASIC FUNCTIONS:" << endl;
    greet();
    cout << "add(5,3) = " << add(5, 3) << endl;
    
    displayInfo("Alice"); // Uses default parameters
    displayInfo("Bob", 30, "New York");
    cout << endl;
    
    // ------------------------------------------------------------------------
    // Function Overloading
    // ------------------------------------------------------------------------
    cout << "2. FUNCTION OVERLOADING:" << endl;
    cout << "add(5,3,2) = " << add(5, 3, 2) << endl;
    cout << "add(5.5,3.3) = " << add(5.5, 3.3) << endl;
    cout << "add(\"Hello\", \"World\") = " << add("Hello", "World") << endl;
    cout << endl;
    
    // ------------------------------------------------------------------------
    // Parameter Passing
    // ------------------------------------------------------------------------
    cout << "3. PARAMETER PASSING:" << endl;
    int num = 50;
    
    cout << "Original num: " << num << endl;
    
    passByValue(num);
    cout << "After passByValue: " << num << endl;
    
    passByReference(num);
    cout << "After passByReference: " << num << endl;
    
    num = 50;
    passByPointer(&num);
    cout << "After passByPointer: " << num << endl;
    
    string str = "Hello";
    passByConstReference(str);
    cout << endl;
    
    // ------------------------------------------------------------------------
    // Recursive Functions
    // ------------------------------------------------------------------------
    cout << "4. RECURSIVE FUNCTIONS:" << endl;
    cout << "factorial(5) = " << factorial(5) << endl;
    cout << "fibonacci(10) = " << fibonacci(10) << endl;
    cout << endl;
    
    // ------------------------------------------------------------------------
    // Function Pointers
    // ------------------------------------------------------------------------
    cout << "5. FUNCTION POINTERS:" << endl;
    int (*funcPtr)(int, int) = multiply;
    cout << "Using function pointer: " << funcPtr(6, 7) << endl;
    
    OperationPtr op = multiply;
    cout << "Using typedef: " << operate(8, 9, op) << endl;
    cout << endl;
    
    // ------------------------------------------------------------------------
    // Lambda Functions
    // ------------------------------------------------------------------------
    cout << "6. LAMBDA FUNCTIONS:" << endl;
    demonstrateLambdas();
    cout << endl;
    
    // ------------------------------------------------------------------------
    // Function Templates
    // ------------------------------------------------------------------------
    cout << "7. FUNCTION TEMPLATES:" << endl;
    cout << "maximum(10, 20) = " << maximum(10, 20) << endl;
    cout << "maximum(3.14, 2.71) = " << maximum(3.14, 2.71) << endl;
    cout << "maximum('A', 'Z') = " << maximum('A', 'Z') << endl;
    cout << "addGeneric(5, 3.14) = " << addGeneric(5, 3.14) << endl;
    cout << endl;
    
    // ------------------------------------------------------------------------
    // Variadic Functions
    // ------------------------------------------------------------------------
    cout << "8. VARIADIC FUNCTIONS:" << endl;
    cout << "printAll(1, 2, 3, \"hello\", 3.14): ";
    printAll(1, 2, 3, "hello", 3.14);
    cout << endl;
    
    // ------------------------------------------------------------------------
    // Constexpr Functions
    // ------------------------------------------------------------------------
    cout << "9. CONSTEXPR FUNCTIONS:" << endl;
    constexpr int fact = factorial_constexpr(5); // Compile-time evaluation
    cout << "factorial_constexpr(5) = " << fact << endl;
    cout << endl;
    
    // ------------------------------------------------------------------------
    // Static and Friend Functions
    // ------------------------------------------------------------------------
    cout << "10. STATIC AND FRIEND FUNCTIONS:" << endl;
    cout << "Static count: " << MyClass::getStaticCount() << endl;
    
    MyClass obj;
    friendFunction(obj);
    cout << endl;
    
    // ------------------------------------------------------------------------
    // Practical Example: Function Composition
    // ------------------------------------------------------------------------
    cout << "11. PRACTICAL EXAMPLE - FUNCTION COMPOSITION:" << endl;
    
    // Using std::function (C++11)
    vector<function<int(int)>> operations;
    operations.push_back([](int x) { return x * 2; });
    operations.push_back([](int x) { return x + 5; });
    operations.push_back([](int x) { return x * x; });
    
    int result = 3;
    cout << "Starting with 3, applying operations: ";
    for (auto &op : operations) {
        result = op(result);
        cout << "-> " << result << " ";
    }
    cout << endl;
    
    cout << "\n========== END OF FUNCTIONS GUIDE ==========" << endl;
    
    return 0; // Indicates successful program execution
}

/**
 * ============================================================================
 * SUMMARY: KEY POINTS ABOUT C++ FUNCTIONS
 * ============================================================================
 * 
 * 1. Function Declaration/Prototype: Tells compiler about function before definition
 * 2. Function Definition: Actual implementation
 * 3. Function Call: Executes the function
 * 4. Parameters: Input to functions
 * 5. Return Value: Output from functions
 * 6. Scope: Local variables vs global variables
 * 7. Storage Class: auto, static, register, extern
 * 8. Function Overloading: Same name, different parameters
 * 9. Inline Functions: Request to avoid function call overhead
 * 10. Recursion: Function calling itself
 * 11. Function Pointers: Store address of functions
 * 12. Lambda Expressions: Anonymous functions
 * 13. Templates: Generic functions for multiple types
 * 14. Variadic Templates: Functions with variable number of arguments
 * 15. constexpr: Compile-time evaluation
 * 16. noexcept: Exception specification
 * 
 * ============================================================================
 */