Structs in C++ are a way to group different types of variables together under a single name.  
Unlike an array which can only store multiple values of the **same** data type, a struct can store values of **different** data types. For example, you can store a student’s name (string), GPA (double), and enrollment status (bool) all inside one struct.  

A struct is like creating your own custom data type. You define it once outside the main function using the keyword `struct`, give it a name (identifier), and then list all the variables you want inside it. These variables inside the struct are called **members**.  

After defining the struct, you can create as many variables of that struct type as you want — each one will have its own copy of all the members. To access or change a member, you use the struct variable’s name followed by a dot (.) and then the member’s name. This dot is called the **member access operator** or **dot operator**.  

You can also give default values to members directly inside the struct so you don’t have to assign them every time you create a new variable. Structs are very useful whenever you need to keep related information together, such as details about a student, a book, a car, a player in a game, or an employee. They make your code more organized, easier to read, and help you avoid using many separate variables that are hard to manage. Structs do not involve any object-oriented programming concepts — they are simply a way to bundle related data.

### structs.cpp (Fully commented, single file)

```cpp
#include <iostream>
#include <string>

// =============================================
// STRUCT DEFINITION
// =============================================

// We define a struct named Student outside of main().
// This creates a new custom data type called Student.
struct Student {
    std::string name;        // member to store student's name
    double gpa;              // member to store grade point average
    bool enrolled = true;    // member with default value (true)
    // Any new Student will be enrolled by default unless we change it
};

int main() {

    // =============================================
    // CREATING STRUCT VARIABLES
    // =============================================

    // Create first student variable
    Student student1;
    student1.name = "Spongebob";   // assign value to name member
    student1.gpa = 3.2;            // assign value to gpa member
    // enrolled is already true because of default value

    // Create second student
    Student student2;
    student2.name = "Patrick";
    student2.gpa = 2.1;
    student2.enrolled = true;      // we can still change it if needed

    // Create third student
    Student student3;
    student3.name = "Squidward";
    student3.gpa = 1.5;
    student3.enrolled = false;

    // =============================================
    // ACCESSING AND DISPLAYING MEMBERS
    // =============================================

    // Accessing members using the dot operator (.)
    std::cout << "Student 1:\n";
    std::cout << "Name     : " << student1.name << "\n";
    std::cout << "GPA      : " << student1.gpa << "\n";
    std::cout << "Enrolled : " << student1.enrolled << "\n\n";

    std::cout << "Student 2:\n";
    std::cout << "Name     : " << student2.name << "\n";
    std::cout << "GPA      : " << student2.gpa << "\n";
    std::cout << "Enrolled : " << student2.enrolled << "\n\n";

    std::cout << "Student 3:\n";
    std::cout << "Name     : " << student3.name << "\n";
    std::cout << "GPA      : " << student3.gpa << "\n";
    std::cout << "Enrolled : " << student3.enrolled << "\n";

    // =============================================
    // IMPORTANT NOTES ABOUT STRUCTS
    // =============================================

    // 1. Struct definition must end with a semicolon ;
    // 2. Members are accessed with dot operator: variable.member
    // 3. Each struct variable has its own separate copy of all members
    // 4. You can give default values to members (like enrolled = true)
    // 5. Structs help group related data together and make code organized

    std::cout << "\nStructs allow us to keep related information together "
              << "under one meaningful name.\n";

    return 0;
}
```



**struct** is also commonly called a **structure** in C++.

### Simple Explanation:

- The keyword you write in code is **`struct`**.
- The full English name for this feature is **structure**.
- So when people say "C++ structures" or "define a structure", they are talking about the same thing as `struct`.

For example:
- Official tutorials often title their lesson: **"C++ Structures (struct)"**
- The video you watched says: "a struct is a **structure** that groups related variables under one name" and later "those are **structs** ... it's a **structure**..."

### In short:
- **struct** = the keyword you type in code.
- **structure** = the common name people use when speaking or writing about it.

They mean exactly the same thing.  
You can use the words **struct** and **structure** interchangeably when talking about this feature in C++.

### Updated structs.md (with this clarification added)

Structs in C++ are a way to group different types of variables together under a single name.  
A struct is also commonly called a **structure**. The keyword used in code is `struct`, but when explaining or talking about it, people often say "structure".

Unlike an array which can only store multiple values of the same data type, a structure can store values of different data types. For example, you can store a student’s name (string), GPA (double), and enrollment status (bool) all inside one structure.

A structure is like creating your own custom data type. You define it once outside the main function using the keyword `struct`, give it a name, and then list all the variables you want inside it. These variables inside the structure are called **members**.

After defining the structure, you can create as many variables of that structure type as you want — each one will have its own copy of all the members. To access or change a member, you use the structure variable’s name followed by a dot (.) and then the member’s name. This dot is called the **member access operator** or **dot operator**.

You can also give default values to members directly inside the structure so you don’t have to assign them every time you create a new variable. Structures are very useful whenever you need to keep related information together, such as details about a student, a book, a car, a player in a game, or an employee. They make your code more organized, easier to read, and help you avoid using many separate variables that are hard to manage.

