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

    std::string cardNumber; // cardNumber is for storing the card number

    std::cout<<"Enter Your Card Number: ";
    std::cin>>cardNumber; // here we get the card number which we have to check
    int size = cardNumber.size(); // storing size of cardNumber variable
    int sum = 0; // for storing total number after addition according to Luhn's algorithm
    // we have to start from the right most side and double the every 2nd digit ,
    // if the doubled digit > 9, then minus 9 from that digit
    // count the total sum of the doubled digits along with the digits that were not doubled
    // now the total will be saved on sum variable
    // So, we have to add the every 1st digit from the right most side as it is and for every 2nd digit we have double and then add
    // To decide whether to add as it is or double and then add is by the serial number of the digit
    // To establish a serial number we use variable a
    // a is 1 when we start from the right most side
    // then we gradually add 1 to the variable as we advance to the left side
    // if a is odd then we just add the value
    // if a is even then we double it and add the value or minus 9 if doubled value is more than 9 and then add the value
    int a = 1;
    // string is in a way an array of characters
    // and characters are stored as integers in C++
    // the integer value of a character is decided according to the ASCII value of the character
    // ASCII value for 0(ZERO) is 48, so if we want to get the exact number we have to:
    //                                                                                  minus 48 or '0'
    // by doing this we will get the exact integer value
    for(int i = size; i > 0;i--){
        if(a%2 != 0){
            sum += cardNumber[i-1]-48; // can also be written as sum += cardNumber[i-1]-'0';
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
