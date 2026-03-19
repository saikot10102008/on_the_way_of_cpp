#include <iostream>
#include <string>

using namespace std;

int main() {
    // Array of questions
    string questions[] = {
        "1. What year was C++ created?: ",
        "2. Who invented C++?: ",
        "3. What is the predecessor of C++?: ",
        "4. Is C++ an object-oriented language? (yes/no): "
    };

    // 2D array of options (each question has 4 options)
    string options[4][4] = {
        {"A. 1969", "B. 1975", "C. 1985", "D. 1989"},
        {"A. Guido van Rossum", "B. Bjarne Stroustrup", "C. John Carmack", "D. Mark Zuckerburg"},
        {"A. C", "B. C++", "C. C--", "D. B"},
        {"A. yes", "B. no", "C. sometimes", "D. what's OOP?"}
    };

    // Array of correct answers (corresponding to each question)
    char answerKey[] = {'C', 'B', 'A', 'A'};

    int size = sizeof(questions)/sizeof(questions[0]);
    char guess;
    int score = 0;

    for(int i = 0; i < size; i++) {
        cout << "*******************************\n";
        cout << questions[i] << "\n";
        cout << "*******************************\n";

        // Display options for current question
        for(int j = 0; j < 4; j++) {
            cout << options[i][j] << "\n";
        }

        cout << "Enter your answer (A, B, C, or D): ";
        cin >> guess;
        guess = toupper(guess); // Convert to uppercase

        // Check if answer is correct
        if(guess == answerKey[i]) {
            cout << "CORRECT!\n";
            score++;
        } else {
            cout << "WRONG! The correct answer was " << answerKey[i] << "\n";
        }
    }

    // Display final score
    cout << "\n*******************************\n";
    cout << "*           RESULTS           *\n";
    cout << "*******************************\n";
    cout << "CORRECT GUESSES: " << score << "\n";
    cout << "# of QUESTIONS: " << size << "\n";
    cout << "SCORE: " << (score/(double)size)*100 << "%\n";

    return 0;
}









// In the C++ quiz game code, two specific techniques are used to make the program more accurate and user-friendly: type casting with (double) and the character function toupper().

// First, (double)size is an example of explicit type casting. In C++, when you divide two integers (like our score and size variables), the language performs integer division, which truncates the result and discards any fractional part. For example, if the player has a score of 3 out of 4, the calculation score/size would be 3/4, which equals 0 in integer division, not 0.75. By writing (double)size, we temporarily convert the integer variable size into a double-precision floating-point number. This forces the compiler to perform floating-point division instead, preserving the decimal. So, score/(double)size becomes 3/4.0, which correctly evaluates to 0.75. This accurate decimal is then multiplied by 100 to display a proper percentage score (like 75%) to the player.

// Second, toupper(guess) is a built-in function from the <cctype> header that handles character standardization. When a player inputs an answer, they might type a lowercase letter (like 'a') or an uppercase one (like 'A'). The toupper() function takes a character as an argument and, if it is a lowercase letter, returns its uppercase equivalent. If the character is already uppercase or is a non-letter (like a number or symbol), it returns the character unchanged. So, after getting the player's guess with cin >> guess;, the line guess = toupper(guess); converts the input to uppercase. This simplifies the subsequent logic because the program only needs to check if the player's guess matches the uppercase letters stored in the answerKey array, without having to write separate conditions for both cases. It makes the input validation both robust and case-insensitive.
