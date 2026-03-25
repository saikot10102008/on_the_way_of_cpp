### enums

Enums (short for Enumerations) in C++ are a user-defined data type that allows you to define a set of named integer constants. The main purpose of enums is to make your code much more readable, self-documenting, and less error-prone by replacing “magic numbers” with meaningful names. For example, instead of using numbers like 0, 1, 2 to represent days of the week, you can create an enum called Day with names Sunday, Monday, Tuesday, etc. When you define an enum, the compiler automatically assigns integer values starting from 0 to each name unless you specify otherwise. You can also manually assign any integer values you want. Once the enum is defined, you can create variables of that enum type, and the compiler will only allow you to assign the named constants defined in that enum — this provides type safety and prevents accidental use of invalid values. Enums are extremely useful whenever you have a fixed, limited set of possible values such as days of the week, months, colors, game states (playing, paused, game over), order statuses (pending, approved, shipped, delivered), directions (north, south, east, west), or boolean-like states (success, failure). Enums improve code clarity, make debugging easier, and reduce bugs compared to using plain integers. In modern C++ you can also create scoped enums (enum class) which are even safer because they do not pollute the global namespace and require you to use the scope operator (::) to access the values, but for beginners the classic un-scoped enum is the simplest to start with.

### enums.cpp (Fully commented, single file, ready to copy)

```cpp
#include <iostream>
#include <string>

// =============================================
// ENUM DEFINITION
// =============================================

// This is a classic (unscoped) enum.
// It creates a new data type called "Day"
// that can only hold one of the listed values.
enum Day {
    Sunday,     // automatically assigned 0
    Monday,     // automatically assigned 1
    Tuesday,    // automatically assigned 2
    Wednesday,  // automatically assigned 3
    Thursday,   // automatically assigned 4
    Friday,     // automatically assigned 5
    Saturday    // automatically assigned 6
};

// Another enum where we manually assign values.
// This is useful when the numbers have special meaning.
enum Status {
    Pending   = 0,   // order is waiting
    Approved  = 1,   // order is approved
    Rejected  = 2,   // order is rejected
    Completed = 3    // order is finished
};

int main() {

    // =============================================
    // CREATING AND USING ENUM VARIABLES
    // =============================================

    // Declare a variable of type Day and assign one of the allowed values
    Day today = Wednesday;

    // When you print an enum variable, it prints its underlying integer value
    std::cout << "Today is day number: " << today << "\n";

    // Enums are perfect for comparisons and conditions
    if (today == Wednesday) {
        std::cout << "It's Wednesday! Mid-week already.\n";
    }

    // Using the Status enum
    Status orderStatus = Approved;

    std::cout << "\nOrder status code: " << orderStatus << "\n";

    if (orderStatus == Approved) {
        std::cout << "The order has been approved and is being processed.\n";
    } 
    else if (orderStatus == Rejected) {
        std::cout << "Sorry, the order was rejected.\n";
    }

    // You can declare a variable first and assign a value later
    Day tomorrow;
    tomorrow = Thursday;

    std::cout << "\nTomorrow is day number: " << tomorrow << "\n";

    // =============================================
    // IMPORTANT NOTES
    // =============================================

    // 1. You can only assign values that are defined in the enum
    // today = 10;          // This line would cause a compile error

    // 2. By default, values start from 0 and increase by 1
    // 3. You can assign any integer you want manually (as shown in Status enum)

    // 4. Enums make code readable and prevent mistakes
    //    Instead of writing if(status == 1), you write if(status == Approved)

    std::cout << "\nEnums help us avoid using magic numbers and make code clearer.\n";

    return 0;
}
```


## Unscoped Enums (Traditional C++)

```cpp
enum Color { RED, GREEN, BLUE };
```

**What this actually creates:**
- `RED` becomes a constant integer with value 0
- `GREEN` becomes a constant integer with value 1  
- `BLUE` becomes a constant integer with value 2

```cpp
Color myColor = RED;     // myColor stores the integer 0
int x = RED;             // x becomes 0 - works automatically!
```

**Important:** Enums are just integers with names. The compiler treats them as integers.
