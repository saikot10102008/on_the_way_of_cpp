#include <iostream>
template <typename T, typename U>
auto max(T x, U y){
    return (x > y) ? x : y;
}
int main()
{
    std::cout << max(1, 2) << '\n';
    std::cout << max(1.1, 2.2) << '\n';
    std::cout << max('1', '2') << '\n';

    return 0;
}

// summary:
// Function templates in C++ are a powerful mechanism for generic programming that let you write a single function definition 
// capable of working with any data type without duplicating code for each type. You declare a function template by placing 
// the keyword template followed by a list of template parameters in angle brackets usually using typename or class before the
// function signature where the parameters act as placeholders for actual types. When the template function is called the 
// compiler automatically performs template instantiation at compile time generating a specific concrete version of the 
// function for the exact types used in that call resulting in code that is just as efficient as if you had written separate 
// overloaded functions manually. This approach eliminates massive code repetition improves maintainability and provides full 
// type safety while delivering zero runtime overhead. Function templates support multiple type parameters non-type parameters 
// such as integers or compile-time constants variadic parameter packs for handling any number of arguments and in modern 
// C++20 concepts that allow clean readable constraints on what types are acceptable instead of complex enable-if tricks. They 
// form the foundation of the entire standard template library including algorithms like sort and find as well as containers 
// and utilities making generic reusable high-performance code natural and elegant in C++. Templates must generally be defined 
// in header files because instantiation happens in the translation units where they are used and while they offer tremendous 
// power they can sometimes lead to longer compilation times or verbose error messages if not used carefully. In essence 
// function templates shift the burden of writing type-specific code from the programmer to the compiler turning C++ into a 
// true generic programming language.