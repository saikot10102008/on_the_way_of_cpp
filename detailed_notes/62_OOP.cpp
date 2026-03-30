#include <iostream>
#include <string>

/*
================================================================================
1. OBJECT ORIENTED PROGRAMMING (OOP) - EXTENSIVE EXPLANATION
================================================================================

Definition:
Object-Oriented Programming (OOP) is a programming paradigm that organizes software
design around objects rather than functions and logic alone. An object is a
self-contained unit that combines data (attributes or properties) and behavior
(methods or functions). A class serves as the blueprint or template from which
objects are created.

Extensive Explanation:
OOP models real-world entities by bundling related data and operations together.
This approach makes code more modular (broken into independent pieces),
reusable (write once, use many times), maintainable (easier to update without
breaking everything), and scalable for large projects.

The four fundamental pillars of OOP are:
- Encapsulation: Wrapping data and methods into a single unit (class) and hiding
  internal details using access specifiers like private.
- Abstraction: Hiding complex implementation details and exposing only essential
  features through simple interfaces.
- Inheritance: Allowing classes to inherit and reuse properties and behaviors
  from other classes (explained later in this file).
- Polymorphism: Enabling objects of different classes to be treated uniformly,
  often through method overriding or overloading.

In C++, OOP revolves entirely around classes and objects. Instead of writing
procedural code with scattered variables and functions, you create classes that
represent real-world concepts. Each object maintains its own independent state.
*/

class Car {
public:                    // Public access specifier: members are accessible from outside the class
    std::string brand;     // Data member (attribute) - stores state
    std::string model;
    int year;

    // Member function (method) - defines the behavior of the object
    void displayInfo() {
        std::cout << "Brand: " << brand << std::endl;
        std::cout << "Model: " << model << std::endl;
        std::cout << "Year: " << year << std::endl;
    }
};

/*
================================================================================
2. CONSTRUCTORS - EXTENSIVE EXPLANATION
================================================================================

Definition:
A constructor is a special member function of a class that is automatically
invoked whenever a new object of that class is created. Its sole purpose is to
initialize the object's data members to a valid starting state.

Extensive Explanation:
Constructors ensure that every object starts with proper values instead of random
garbage memory. They run only once per object at the moment of creation.
Key rules:
- The constructor name must be exactly the same as the class name.
- It has no return type (not even void).
- It can accept parameters (parameterized constructor) or none (default constructor).
- If you define no constructor at all, the compiler automatically provides a
  default (empty) constructor.
- Constructors are ideal for resource allocation, setting default values, or
  performing any setup logic.
- They can be called only during object creation — you cannot call them manually
  later.

Using an initializer list (after the colon :) is more efficient than assignment
inside the body, especially for large objects or constant members.
*/

class Student {
public:
    std::string name;
    int age;
    double gpa;

    // Default Constructor (zero parameters)
    Student() {
        // Initialize with safe default values to avoid garbage data
        name = "Unknown";
        age = 0;
        gpa = 0.0;
        std::cout << "Default constructor called - object initialized safely" << std::endl;
    }

    // Parameterized Constructor - accepts arguments to set initial values
    Student(std::string n, int a, double g) {
        name = n;   // this->name = n; can also be used if parameter names conflict
        age = a;
        gpa = g;
        std::cout << "Parameterized constructor called for student: " << name << std::endl;
    }
};

/*
================================================================================
3. CONSTRUCTOR OVERLOADING - EXTENSIVE EXPLANATION
================================================================================

Definition:
Constructor overloading is the ability to define multiple constructors within
the same class that share the same name but have different parameter lists
(different number, types, or order of parameters).

Extensive Explanation:
This feature provides flexibility when creating objects in different ways.
The compiler automatically selects the correct constructor based on the number
and type of arguments passed during object creation (this is a form of
compile-time polymorphism). It is extremely useful when objects can be
initialized with varying amounts of information.
- You can overload as many times as needed.
- A default constructor is often included when other overloaded versions exist.
- Default argument values can sometimes replace overloading for simpler cases.
*/

class Pizza {
public:
    std::string topping1;
    std::string topping2;

    // Overloaded Constructor 1: Default (no arguments)
    Pizza() {
        topping1 = "None";
        topping2 = "None";
        std::cout << "Default constructor (no toppings) called" << std::endl;
    }

    // Overloaded Constructor 2: One argument
    Pizza(std::string t1) {
        topping1 = t1;
        topping2 = "None";
        std::cout << "One-topping constructor called" << std::endl;
    }

    // Overloaded Constructor 3: Two arguments (different signature)
    Pizza(std::string t1, std::string t2) {
        topping1 = t1;
        topping2 = t2;
        std::cout << "Two-topping constructor called" << std::endl;
    }

    void showToppings() {
        std::cout << "Pizza toppings: " << topping1 << " and " << topping2 << std::endl;
    }
};

/*
================================================================================
4. GETTERS AND SETTERS - EXTENSIVE EXPLANATION
================================================================================

Definition:
Getters (also called accessors) are public member functions that return the
value of private data members.
Setters (also called mutators) are public member functions that modify the
value of private data members, often with built-in validation or logic.

Extensive Explanation:
They are the foundation of encapsulation. By declaring data members as private,
you prevent direct external access or modification (which could lead to invalid
object states). Getters and setters act as controlled gateways.
- Setters can include checks (range limits, data validation, logging, or
  triggering other actions).
- Getters are often marked const because they only read data and should not
  modify the object.
- This design makes classes safer, more maintainable, and easier to debug.
*/

class Stove {
private:                   // Data is hidden - only accessible via getters/setters (encapsulation)
    int temperature;

public:
    // Constructor using initializer list for efficiency
    Stove() : temperature(0) {}

    // Setter - controls how temperature is changed with validation
    void setTemperature(int temp) {
        if (temp < 0) {
            temperature = 0;
            std::cout << "Warning: Temperature too low. Set to minimum (0)." << std::endl;
        }
        else if (temp > 10) {
            temperature = 10;
            std::cout << "Warning: Temperature too high. Set to maximum (10)." << std::endl;
        }
        else {
            temperature = temp;
        }
    }

    // Getter - safely reads the private value (const because it doesn't change anything)
    int getTemperature() const {
        return temperature;
    }
};

/*
================================================================================
5. INHERITANCE - EXTENSIVE EXPLANATION
================================================================================

Definition:
Inheritance is a feature that allows a derived class (child or subclass) to
acquire all the data members and member functions of a base class (parent or
superclass), establishing an "is-a" relationship.

Extensive Explanation:
Inheritance promotes massive code reuse — common functionality is written once
in the base class and automatically available to all derived classes. The
derived class can:
- Use inherited members directly.
- Override (redefine) inherited methods for specialized behavior.
- Add new members unique to itself.

In C++, inheritance is declared with a colon : and an access specifier (public
is the most common — it preserves the original access levels of base class
members). The base class constructor is automatically called before the derived
class constructor. This concept helps build hierarchical relationships
(e.g., Animal → Dog, Animal → Cat).
*/

 // Base class (Parent) - contains common features
class Animal {
public:
    bool isAlive = true;   // Inherited data member

    void eat() {           // Inherited method
        std::cout << "This animal is eating." << std::endl;
    }

    void sleep() {         // Inherited method
        std::cout << "This animal is sleeping." << std::endl;
    }
};

// Derived class (Child) - inherits everything from Animal
class Dog : public Animal {     // public inheritance
public:
    // New method specific to Dog only
    void bark() {
        std::cout << "Woof! Woof!" << std::endl;
    }
};

// Another derived class
class Cat : public Animal {
public:
    void meow() {
        std::cout << "Meow!" << std::endl;
    }
};

int main() {
    std::cout << "=== Demonstrating all OOP concepts in one program ===\n\n";

    // 1. OOP - Basic class and objects
    std::cout << "1. Object Oriented Programming (OOP) example:\n";
    Car car1;
    car1.brand = "Toyota";
    car1.model = "Corolla";
    car1.year = 2022;
    car1.displayInfo();
    std::cout << std::endl;

    // 2. Constructors
    std::cout << "2. Constructors example:\n";
    Student s1;                    // Default constructor
    Student s2("Alice", 20, 3.8);  // Parameterized constructor
    std::cout << "Student 2 details: " << s2.name << ", Age: " << s2.age
              << ", GPA: " << s2.gpa << std::endl << std::endl;

    // 3. Constructor Overloading
    std::cout << "3. Constructor Overloading example:\n";
    Pizza p1;                    // Default constructor (0 arguments)
    Pizza p2("Pepperoni");       // One-argument constructor
    Pizza p3("Mushrooms", "Olives");  // Two-argument constructor
    p3.showToppings();
    std::cout << std::endl;

    // 4. Getters and Setters
    std::cout << "4. Getters and Setters example:\n";
    Stove myStove;
    myStove.setTemperature(15);          // Setter applies validation automatically
    std::cout << "Current stove temperature: " << myStove.getTemperature() << std::endl << std::endl;

    // 5. Inheritance
    std::cout << "5. Inheritance example:\n";
    Dog myDog;
    myDog.eat();           // Inherited from Animal (no need to rewrite)
    myDog.sleep();         // Inherited from Animal
    myDog.bark();          // Dog's own specialized method
    std::cout << "Is dog alive? " << (myDog.isAlive ? "Yes" : "No") << std::endl;

    Cat myCat;
    myCat.eat();           // Also inherited from Animal
    myCat.meow();

    std::cout << "\n=== End of demonstration ===\n";
    std::cout << "All five topics (OOP, Constructors, Constructor Overloading,\n";
    std::cout << "Getters/Setters, Inheritance) have been explained and demonstrated\n";
    std::cout << "in this single C++ file using extensive comments.\n";

    return 0;
}
