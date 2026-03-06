// Include the input/output stream library (needed for cin and cout)
#include <iostream>

// Include the input/output manipulation library (needed for std::fixed and std::setprecision)
#include <iomanip>

// Function prototypes (declarations) — tell the compiler these functions exist
void showBalance(double balance);
double deposit();
double withdraw(double balance);

int main()
{
    // Initialize the account balance to zero at the start
    double balance = 0;

    // Variable to store the user's menu choice (1–4)
    int choice = 0;

    // Start a do-while loop → menu will show at least once, and repeat until user chooses 4 (exit)
    do {
        // Print a simple separator line for better readability
        std::cout << "******************\n";

        // Prompt the user to make a selection
        std::cout << "Enter your choice:\n";

        // Another separator
        std::cout << "******************\n";

        // Display the menu options
        std::cout << "1. Show Balance\n";
        std::cout << "2. Deposit Money\n";
        std::cout << "3. Withdraw Money\n";
        std::cout << "4. Exit\n";

        // Read the user's integer choice from the keyboard
        std::cin >> choice;

        //std::cin.clear(); and fflush(stdin); not working as it should so I turned them into comments

        // Clear any error flags on cin (in case user entered letters instead of numbers)
        // std::cin.clear(); 

        // Discard (flush) everything left in the input buffer up to the newline
        // This helps prevent infinite loops when user enters invalid input
        // fflush(stdin);   // Note: fflush(stdin) is non-standard in C++ but commonly used in tutorials for simplicity

        // Decide what to do based on the user's choice (switch is cleaner than many if-else statements here)
        switch(choice) {
            case 1: 
                // Call function to display current balance
                showBalance(balance);
                break;   // Exit this case and go back to menu

            case 2: 
                // Call deposit function → it returns amount to add
                // Add that amount to balance
                balance += deposit();

                // Immediately show the updated balance (good user feedback)
                showBalance(balance);
                break;

            case 3: 
                // Call withdraw function → it returns amount to subtract (or 0 if invalid)
                // Subtract that amount from balance
                balance -= withdraw(balance);

                // Show updated balance again
                showBalance(balance);
                break;

            case 4: 
                // Friendly goodbye message when user wants to exit
                std::cout << "Thanks for visiting!\n";
                break;

            default:
                // Anything other than 1,2,3,4 is invalid
                std::cout << "Invalid choice\n";
                // No break needed here (falls through to end of switch)
        }

    // Keep looping as long as user did NOT choose 4 (exit condition)
    } while(choice != 4);

    // Program ends successfully
    return 0;
}

// Function that simply displays the current balance with nice formatting
void showBalance(double balance) {
    // Output message + balance formatted to 2 decimal places (like money)
    // std::fixed → forces decimal notation (not scientific)
    // std::setprecision(2) → shows exactly two digits after decimal point
    std::cout << "Your balance is: $" << std::setprecision(2) << std::fixed << balance << '\n';
}

// Function that handles depositing money
double deposit() {
    // Local variable to store the amount the user wants to deposit
    double amount = 0;

    // Ask user how much to deposit
    std::cout << "Enter amount to be deposited: ";

    // Read the number they typed
    std::cin >> amount;

    // Only accept positive amounts (basic validation)
    if(amount > 0) {
        // Return the valid amount so main() can add it to balance
        return amount;
    }
    else {
        // Tell user the input was bad
        std::cout << "That's not a valid amount:\n";
        // Return 0 → no change to balance
        return 0;
    }
}

// Function that handles withdrawing money
// Takes current balance as parameter so it can check if enough money exists
double withdraw(double balance) {
    // Local variable for withdrawal amount
    double amount = 0;

    // Prompt user
    std::cout << "Enter amount to be withdrawn: ";

    // Get input
    std::cin >> amount;

    // First check: trying to withdraw more than available?
    if(amount > balance) {
        std::cout << "insufficient funds\n";
        return 0;   // No withdrawal happens
    }
    // Second check: negative amount? (doesn't make sense)
    else if(amount < 0) {
        std::cout << "That's not a valid amount\n";
        return 0;
    }
    else {
        // Valid withdrawal → return the amount so main() can subtract it
        return amount;
    }
}