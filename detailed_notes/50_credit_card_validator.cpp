#include <iostream>
#include <string>

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

// Function to get the sum of doubled digits
int getDoubleDigitSum(int digit) {
    // Double the digit
    int doubled = digit * 2;

    // If doubled >= 10, sum its individual digits
    // Example: 7 * 2 = 14, then 1 + 4 = 5
    if (doubled >= 10) {
        return (doubled / 10) + (doubled % 10);
    }

    // Otherwise just return the doubled value
    return doubled;
}

// Function to validate credit card number using Luhn's Algorithm
bool isValidCreditCard(const std::string &cardNumber) {
    int sum = 0;
    bool doubleDigit = false;  // Flag to alternate which digits to double

    // Loop through the card number from RIGHT to LEFT
    for (int i = cardNumber.length() - 1; i >= 0; i--) {
        // Get the current digit as an integer
        int digit = cardNumber[i] - '0';  // Convert char to int

        if (doubleDigit) {
            // Double this digit and add its digit sum
            sum += getDoubleDigitSum(digit);
        } else {
            // Just add the digit as is
            sum += digit;
        }

        // Flip the flag for the next digit (every second digit)
        doubleDigit = !doubleDigit;
    }

    // Card is valid if sum is divisible by 10
    return (sum % 10 == 0);
}

// Function to get card type based on first digits
std::string getCardType(const std::string &cardNumber) {
    if (cardNumber.empty()) return "Unknown";

    // Get first digit
    int firstDigit = cardNumber[0] - '0';

    // Get first two digits if card has at least 2 digits
    int firstTwoDigits = 0;
    if (cardNumber.length() >= 2) {
        firstTwoDigits = (cardNumber[0] - '0') * 10 + (cardNumber[1] - '0');
    }

    // Check card type based on first digits
    if (firstDigit == 4) {
        return "Visa";
    }
    else if (firstDigit == 5 && firstTwoDigits >= 51 && firstTwoDigits <= 55) {
        return "MasterCard";
    }
    else if (firstDigit == 3 && (firstTwoDigits == 34 || firstTwoDigits == 37)) {
        return "American Express";
    }
    else if (firstDigit == 6 && firstTwoDigits >= 6011 && firstTwoDigits <= 6012) {
        return "Discover";
    }
    else {
        return "Unknown";
    }
}

// Function to display the validation process step by step
void displayValidationProcess(const std::string &cardNumber) {
    std::cout << "\n========== VALIDATION PROCESS ==========\n";
    std::cout << "Card Number: " << cardNumber << "\n\n";

    int sum = 0;
    bool doubleDigit = false;

    std::cout << "Processing from RIGHT to LEFT:\n";
    std::cout << "----------------------------------------\n";

    // Loop through from right to left
    for (int i = cardNumber.length() - 1; i >= 0; i--) {
        int digit = cardNumber[i] - '0';
        int position = i + 1;

        std::cout << "Position " << position << " (digit: " << digit << "): ";

        if (doubleDigit) {
            int doubled = digit * 2;
            int contribution = getDoubleDigitSum(digit);

            if (doubled >= 10) {
                std::cout << "Double -> " << doubled << " -> sum digits -> " << contribution << "\n";
            } else {
                std::cout << "Double -> " << doubled << " -> add " << contribution << "\n";
            }
            sum += contribution;
        } else {
            std::cout << "Keep as is -> add " << digit << "\n";
            sum += digit;
        }

        doubleDigit = !doubleDigit;
    }

    std::cout << "----------------------------------------\n";
    std::cout << "TOTAL SUM: " << sum << "\n";
    std::cout << "Sum % 10 = " << (sum % 10) << "\n";

    if (sum % 10 == 0) {
        std::cout << "RESULT: VALID ✓\n";
    } else {
        std::cout << "RESULT: INVALID ✗\n";
    }
    std::cout << "========================================\n";
}

// Function to clean the card number (remove spaces and dashes)
std::string cleanCardNumber(const std::string &input) {
    std::string cleaned = "";

    for (char c : input) {
        // Only keep digits (0-9)
        if (c >= '0' && c <= '9') {
            cleaned += c;
        }
    }

    return cleaned;
}

int main() {
    std::cout << "=========================================\n";
    std::cout << "   CREDIT CARD VALIDATOR PROGRAM\n";
    std::cout << "   Using Luhn's Algorithm\n";
    std::cout << "=========================================\n\n";

    std::string input;

    // Example 1: Valid Visa card
    std::cout << "EXAMPLE 1: Valid Visa Card\n";
    std::cout << "-----------------------------------------\n";
    std::string visaCard = "4111 1111 1111 1111";  // Valid test Visa number
    std::cout << "Input: " << visaCard << "\n";

    std::string cleaned = cleanCardNumber(visaCard);
    std::cout << "Cleaned: " << cleaned << "\n";
    std::cout << "Length: " << cleaned.length() << " digits\n";

    std::string cardType = getCardType(cleaned);
    std::cout << "Card Type: " << cardType << "\n";

    bool isValid = isValidCreditCard(cleaned);
    if (isValid) {
        std::cout << "VALID ✓ - This is a real credit card number pattern\n";
    } else {
        std::cout << "INVALID ✗\n";
    }

    displayValidationProcess(cleaned);

    // Example 2: Valid MasterCard
    std::cout << "\n\nEXAMPLE 2: Valid MasterCard\n";
    std::cout << "-----------------------------------------\n";
    std::string masterCard = "5555 5555 5555 4444";  // Valid test MasterCard number
    std::cout << "Input: " << masterCard << "\n";

    cleaned = cleanCardNumber(masterCard);
    std::cout << "Cleaned: " << cleaned << "\n";
    cardType = getCardType(cleaned);
    std::cout << "Card Type: " << cardType << "\n";

    isValid = isValidCreditCard(cleaned);
    if (isValid) {
        std::cout << "VALID ✓\n";
    } else {
        std::cout << "INVALID ✗\n";
    }

    displayValidationProcess(cleaned);

    // Example 3: Valid American Express
    std::cout << "\n\nEXAMPLE 3: Valid American Express\n";
    std::cout << "-----------------------------------------\n";
    std::string amexCard = "3782 8224 6310 005";  // Valid test American Express number
    std::cout << "Input: " << amexCard << "\n";

    cleaned = cleanCardNumber(amexCard);
    std::cout << "Cleaned: " << cleaned << "\n";
    cardType = getCardType(cleaned);
    std::cout << "Card Type: " << cardType << "\n";

    isValid = isValidCreditCard(cleaned);
    if (isValid) {
        std::cout << "VALID ✓\n";
    } else {
        std::cout << "INVALID ✗\n";
    }

    displayValidationProcess(cleaned);

    // Example 4: Invalid card number
    std::cout << "\n\nEXAMPLE 4: Invalid Card Number\n";
    std::cout << "-----------------------------------------\n";
    std::string invalidCard = "1234 5678 9012 3456";
    std::cout << "Input: " << invalidCard << "\n";

    cleaned = cleanCardNumber(invalidCard);
    std::cout << "Cleaned: " << cleaned << "\n";
    cardType = getCardType(cleaned);
    std::cout << "Card Type: " << cardType << "\n";

    isValid = isValidCreditCard(cleaned);
    if (isValid) {
        std::cout << "VALID ✓\n";
    } else {
        std::cout << "INVALID ✗ - This number fails Luhn's algorithm\n";
    }

    displayValidationProcess(cleaned);

    // Interactive mode
    std::cout << "\n\n=========================================\n";
    std::cout << "INTERACTIVE MODE\n";
    std::cout << "=========================================\n";
    std::cout << "Enter a credit card number to validate\n";
    std::cout << "(You can enter with spaces or dashes): ";
    std::getline(std::cin, input);

    if (!input.empty()) {
        cleaned = cleanCardNumber(input);

        if (cleaned.empty()) {
            std::cout << "No valid digits found!\n";
        } else {
            std::cout << "\nCleaned number: " << cleaned << "\n";
            std::cout << "Length: " << cleaned.length() << " digits\n";

            cardType = getCardType(cleaned);
            std::cout << "Card Type: " << cardType << "\n";

            isValid = isValidCreditCard(cleaned);

            if (isValid) {
                std::cout << "\n✓ VALID CREDIT CARD NUMBER ✓\n";
            } else {
                std::cout << "\n✗ INVALID CREDIT CARD NUMBER ✗\n";
            }

            displayValidationProcess(cleaned);
        }
    }

    // Summary
    std::cout << "\n=========================================\n";
    std::cout << "              SUMMARY\n";
    std::cout << "=========================================\n";
    std::cout << "Luhn's Algorithm Steps:\n";
    std::cout << "1. Start from the rightmost digit (check digit)\n";
    std::cout << "2. Move left, double every second digit\n";
    std::cout << "3. If doubling gives a number > 9, subtract 9 (or sum digits)\n";
    std::cout << "4. Sum all digits (both doubled and regular)\n";
    std::cout << "5. If total % 10 == 0, the number is VALID\n\n";

    std::cout << "Card Type Detection:\n";
    std::cout << "  - Visa: Starts with 4\n";
    std::cout << "  - MasterCard: Starts with 51-55\n";
    std::cout << "  - American Express: Starts with 34 or 37\n";
    std::cout << "  - Discover: Starts with 6011\n";
    std::cout << "=========================================\n";

    return 0;
}
