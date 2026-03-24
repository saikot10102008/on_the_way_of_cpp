#include <iostream>
int factorial(int num);

// Recursion -> Recursion in C++ is a function calling itself to solve smaller instances of the same problem until a base case stops it.
int main () {

    std::cout << factorial(10);

    return 0;
}
int factorial(int num){
    if(num > 1){
        return num * factorial(num - 1);
    }
    else{
        return 1;
    }
}

// summary:
// Recursion in C++ is a programming technique where a function calls itself directly or indirectly to solve a problem by breaking it down into smaller, similar sub-problems.
// A recursive function typically consists of two essential parts: the base case (a terminating condition that stops the recursion and returns a result without further calls) and the recursive case (where the function calls itself with a reduced or modified input to progress toward the base case).
// For example, computing the factorial of a number n can be done recursively as:
// fact(n) = n * fact(n-1) with base case fact(0) = 1.
// While recursion often leads to elegant and readable code (especially for problems like tree traversals, Fibonacci series, Tower of Hanoi, or binary search), it can consume significant stack memory due to each call adding a new stack frame. Deep recursion may cause stack overflow.
// To use recursion effectively in C++, always ensure a proper base case, keep the recursion depth reasonable, and consider iterative alternatives or tail recursion optimization (though C++ does not guarantee tail call optimization) when performance and memory are critical.
//
//
//
// Stack Overflow:
// Stack Overflow in C++ (and most programming languages) occurs when a program consumes more memory on the call stack than has been allocated for it, causing the stack to "overflow" its fixed limit.
// The call stack is a special region of memory that stores information about active function calls, including local variables, parameters, and return addresses. Every time a function (including a recursive one) is called, a new stack frame is pushed onto the stack. When the function returns, the frame is popped.
// In recursion, if the depth becomes too deep — for example, a recursive function without a proper base case or one that reduces the problem too slowly — hundreds of thousands of stack frames can accumulate rapidly. Eventually, the stack pointer exceeds the allocated stack size (typically 1MB to 8MB depending on the compiler and OS settings), triggering a stack overflow runtime error.
// This usually crashes the program with a segmentation fault or "stack overflow" exception. Common causes include infinite recursion, very large recursive depth (like computing Fibonacci recursively without memoization), or allocating large local arrays inside recursive functions. To prevent it, ensure a solid base case, limit recursion depth, or convert the algorithm to an iterative version using a loop and explicit stack when needed.
