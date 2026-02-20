#include<iostream>

int main(){

    // The ternary operator (?:) is a concise conditional operator 
    // that evaluates a condition and returns one of two expressions.
    //  It's the only C++ operator that takes three operands.
    // condition ? expression_if_true : expression_if_false;
    // condition always results in truth or false , 
    // another way we can say 1 or 0
    // so if condition = 1/true in ternary first expression runs
    // otherwise condition = 0/false and second expression runs

    int a = 2, b = 3;
    bool test = true;
    bool testo = false;

    a < b ? std::cout<<"2<3\n" : std::cout<<"2>3, which is not possible\n";

    test ? std::cout<<"true\n":std::cout<<"false\n";

    std::cout<<(testo ? "true\n" : "false\n"); //operator '?:' has lower precedence than '<<'; '<<' will be evaluated first [-Wparentheses]

    return 0;
}