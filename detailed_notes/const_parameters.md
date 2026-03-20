```markdown
# Const Parameters in C++

## What Are Const Parameters?

**Const parameters** are function parameters that are marked with the `const` keyword. This tells the compiler that the parameter is **read-only** and cannot be modified inside the function.

```cpp
void display(const int value) {
    // value = 10;  // ERROR! Cannot modify const parameter
    std::cout << value;  // OK - can read
}
```

---

## Why Use Const Parameters?

### 1. **Safety**
Prevents accidental modification of data that should remain unchanged.

### 2. **Self-Documenting Code**
Clearly shows that a function does not modify certain parameters.

### 3. **Allows Passing Const Arguments**
Without `const`, you cannot pass `const` variables to a function.

### 4. **Compiler Optimizations**
The compiler can generate better code when it knows data won't change.

---

## Const with Different Parameter Types

### 1. **Const with Pass by Value**

```cpp
void printNumber(const int x) {
    // x = 100;  // ERROR! Can't modify const
    std::cout << x;  // OK - can read
}

int main() {
    int a = 5;
    const int b = 10;
    
    printNumber(a);  // Works with non-const
    printNumber(b);  // Works with const
    printNumber(20); // Works with literal
    
    return 0;
}
```

**Note:** Const with pass-by-value is less common because the parameter is a copy anyway. The const only protects the copy, not the original.

---

### 2. **Const with Pass by Reference (Most Important!)**

```cpp
void display(const std::string &text) {
    // text = "new";  // ERROR! Can't modify const reference
    std::cout << text;  // OK - can read
}

int main() {
    std::string message = "Hello";
    const std::string constant = "World";
    
    display(message);   // Works with non-const
    display(constant);  // Works with const
    display("Temp");    // Works with literal
    
    return 0;
}
```

**Why this is important:**
- Pass by reference avoids copying (efficient for large objects)
- `const` prevents accidental modification of the original
- This is the **default choice** for passing objects

---

### 3. **Const with Pass by Pointer**

```cpp
void display(const int *ptr) {
    if (ptr) {
        // *ptr = 100;  // ERROR! Can't modify what ptr points to
        std::cout << *ptr;  // OK - can read
    }
}

int main() {
    int value = 42;
    const int constant = 99;
    
    display(&value);    // Works with non-const
    display(&constant); // Works with const
    
    return 0;
}
```

---

## Const and Function Overloading

Functions can be overloaded based on `const`:

```cpp
void process(int &x) {
    std::cout << "Non-const version\n";
    x = 100;  // Can modify
}

void process(const int &x) {
    std::cout << "Const version\n";
    // x = 100;  // ERROR! Can't modify
}

int main() {
    int a = 10;
    const int b = 20;
    
    process(a);  // Calls non-const version
    process(b);  // Calls const version
    process(30); // Calls const version (temporary)
    
    return 0;
}
```

---

## Common Use Cases

### 1. **Printing/Display Functions**
```cpp
void printUser(const std::string &name, const int &age) {
    std::cout << "Name: " << name << ", Age: " << age << '\n';
}
```

### 2. **Getter Functions**
```cpp
class Person {
    std::string name;
public:
    std::string getName() const {  // Const member function
        return name;  // Promises not to modify object
    }
};
```

### 3. **Search/Find Functions**
```cpp
bool contains(const std::string &text, char ch) {
    for (char c : text) {
        if (c == ch) return true;
    }
    return false;
}
```

### 4. **Large Data Structures**
```cpp
void calculateTotal(const std::vector<int> &numbers) {
    int sum = 0;
    for (int n : numbers) {
        sum += n;  // Reading only, not modifying
    }
    std::cout << "Sum: " << sum << '\n';
}
```

---

## Const Correctness Rules

### Rule 1: Use Const When You Don't Need to Modify
```cpp
// BAD - may accidentally modify
void display(std::string &text) {
    std::cout << text;
}

// GOOD - clearly shows read-only intent
void display(const std::string &text) {
    std::cout << text;
}
```

### Rule 2: Const Reference for Large Objects
```cpp
// BAD - copies entire object
void process(std::string text) { ... }

// GOOD - no copy, read-only
void process(const std::string &text) { ... }
```

### Rule 3: Pass by Value for Small Types
```cpp
// OK for small types (int, char, bool, double)
void increment(int x) { ... }
```

---

## Common Mistakes

### Mistake 1: Forgetting Const in Getters
```cpp
class Student {
    std::string name;
public:
    // BAD - can't be called on const objects
    std::string getName() { return name; }
    
    // GOOD - works on const and non-const objects
    std::string getName() const { return name; }
};
```

### Mistake 2: Using Const When You Need to Modify
```cpp
// WRONG - can't modify because of const
void updateValue(const int &x) {
    x = 100;  // ERROR!
}

// CORRECT - remove const if modification is needed
void updateValue(int &x) {
    x = 100;  // OK
}
```

### Mistake 3: Returning Const Values Unnecessarily
```cpp
// POINTLESS - return value is a copy anyway
const int getValue() { return 42; }

// BETTER - remove const from return type
int getValue() { return 42; }
```

---

## Visual Comparison

| Parameter Type | Copy? | Can Modify Original? | Can Pass Const? | Use Case |
|----------------|-------|---------------------|-----------------|----------|
| `int x` | Yes | No | Yes | Small types, no modification needed |
| `int &x` | No | Yes | No | Need to modify original |
| `const int &x` | No | No | Yes | Large types, read-only access (BEST) |
| `int *x` | Yes (pointer) | Yes | No | C-style, optional parameters |
| `const int *x` | Yes (pointer) | No | Yes | Read-only, optional parameters |

---

## Summary

**Const parameters** are a fundamental part of **const correctness** in C++:

- They **prevent accidental modification** of data
- They **self-document** that a function won't change certain parameters
- They **allow const variables** to be passed as arguments
- They enable **compiler optimizations**
- **Pass by const reference** is the default choice for read-only access to objects
- **Const correctness** should be practiced from the beginning to avoid bugs

**Remember:** When in doubt about whether a function should modify a parameter, mark it `const`. You can always remove it later if needed, but adding it later may require changes everywhere the function is called.
```

This Markdown file covers everything about const parameters in C++ including definitions, why they're useful, different use cases, common mistakes, and best practices.