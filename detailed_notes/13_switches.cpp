#include<iostream>

int main (){

    // what is a switch:
    // A switch statement in C++ provides a way to execute different blocks of code based on 
    // the value of an integer expression (like int, char, or enum).
    //  When the switch is triggered, it evaluates the expression and jumps to the matching 
    // case label, then executes code from that point onward. The break statement is crucial 
    // because it exits the switch entirely; without it, execution "falls through" to the next 
    // case, continuing until a break is encountered or the switch ends. This fall-through 
    // behavior can be used intentionally to let multiple cases share the same code. 
    // The optional default case acts as a catch-all that runs when no other case matches, 
    // typically placed at the end of the switch.


    // but here is the explanation what actually happens:
    // if a case is true then that part is run by the compiler and that part is the entry point
    // and if you enter there then the code block of that case will be run but if there is no
    // break statement then the compiler won't exit switch statement and will start running 
    // other cases even if that doesn't match original expression until there is a break 
    // statement or the switch statement is run to the exact end.
    // not that your compiler won't enter unless it finds a case match but won't exit until
    // a break statement and will run every case even if it doesn't run match the expression
    char grade;

    std::cout<<"Your grade: ";
    std::cin>>grade;

    switch (grade)
    {
        case 'A':
            std::cout<<"You did great";
            break;
        case 'B':
            std::cout<<"You did okay";
            break;
        case 'C':
        case 'D':
        case 'F':
            std::cout<<"You have to do better";
            break;
        default:
            std::cout<<"Your grade is not what you think, Please enter your exact grade";
    }

    // this is the example of using fall-through
    return 0;
}