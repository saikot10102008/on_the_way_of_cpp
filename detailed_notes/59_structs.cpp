// Structs in C++ are used to group different types of variables together under one name.
// Think of an array — it can hold many values but all must be of the same type.
// A struct can hold many values of different types such as string, double, int, bool, etc.
// A struct is like a custom data type that you create yourself.
// Inside a struct, the variables are called members.
// You access these members using a dot (.) between the struct variable name and the member name. That dot . is called "Class Member Access Operator"
// You define a struct outside the main function.
// After defining it, you can create as many variables of that struct type as you want.
// Each variable will have its own copy of all the members.
// You can also give default values to members inside the struct so you don’t have to set them every time.
// Structs are very useful when you want to keep related information together, for example, all information about one student.

#include <iostream>
#include <string>

struct Student {
    std::string name;
    double gpa;
    bool enrolled = true;     // default value
};

int main() {

    // Creating first student
    Student student1;
    student1.name = "Spongebob";
    student1.gpa = 3.2;
    // enrolled is already true by default

    // Creating second student
    Student student2;
    student2.name = "Patrick";
    student2.gpa = 2.1;
    student2.enrolled = true;

    // Creating third student
    Student student3;
    student3.name = "Squidward";
    student3.gpa = 1.5;
    student3.enrolled = false;

    // Displaying student1
    std::cout << student1.name << "\n";
    std::cout << student1.gpa << "\n";
    std::cout << student1.enrolled << "\n\n";

    // Displaying student2
    std::cout << student2.name << "\n";
    std::cout << student2.gpa << "\n";
    std::cout << student2.enrolled << "\n\n";

    // Displaying student3
    std::cout << student3.name << "\n";
    std::cout << student3.gpa << "\n";
    std::cout << student3.enrolled << "\n";

    return 0;
}
