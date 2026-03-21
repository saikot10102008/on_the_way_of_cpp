#include <iostream>
#include <string>

// CORE LOGIC:
// =========================================================
// CREDIT CARD VALIDATOR PROGRAM
// =========================================================
// This program validates credit card numbers using Luhn's Algorithm
// Luhn's Algorithm (also called the "mod 10 algorithm") is used by
// all major credit card companies to validate card numbers
//
// HOW LUHN'S ALGORITHM WORKS:
// 1. Start from the RIGHTMOST digit (check digit)
// 2. Move left, double every SECOND digit
// 3. If doubling results in a number > 9, subtract 9 from it
// 4. Sum all digits (both doubled and non-doubled)
// 5. If total % 10 == 0, the card number is VALID

int main(){

    std::string cardNumber;

    std::cout<<"Enter Your Card Number: ";
    std::cin>>cardNumber;
    int size = cardNumber.size();
    int sum = 0;
    int a = 1;
    for(int i = size; i > 0;i--){
        if(a%2 != 0){
            sum += cardNumber[i-1]-48;
            a++;
        }else {
            if (((cardNumber[i-1]-48)*2) > 9) {
                sum += (((cardNumber[i-1]-48)*2) - 9);
                a++;
            }else {
                sum += ((cardNumber[i-1]-48)*2);
                a++;
            }
        }
    }
    if(sum % 10 == 0){
        std::cout<<"Card Number is Valid!\n";
    }else {
        std::cout<<"Card Number is invalid!\n";
    }
    return 0;
}



// // simplified by grok
// // From right to left, double every 2nd digit (starting from 2nd position)
// int sum = 0;
// bool shouldDouble = false;  // rightmost = false

// for (int i = size - 1; i >= 0; --i) {
//     int digit = cardNumber[i] - '0';

//     if (shouldDouble) {
//         int doubled = digit * 2;
//         sum += (doubled > 9) ? doubled - 9 : doubled;
//     } else {
//         sum += digit;
//     }

//     shouldDouble = !shouldDouble;  // toggle each step
// }
