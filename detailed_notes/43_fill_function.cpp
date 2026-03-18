#include <iostream>
#include <algorithm>    // Required for std::fill()
using namespace std;

// syntax for fill function:
// #include <algorithm>   // ← required for std::fill
// std::fill( beginning_of_range, end_of_range, value );
// beginning_of_range → pointer/iterator to first element (e.g. arr or arr + 0)
// end_of_range → pointer/iterator to one past the last element (e.g. arr + size)
// value → what you want to fill everything with

int main()
{
    cout << "Demonstration of std::fill() function\n";
    cout << "=====================================\n\n";

    // =================================================================
    // What does std::fill() do?
    // It assigns the same value to every element in a range
    // Very useful for initializing or resetting arrays / containers
    // =================================================================

    // ───────────────────────────────────────────────────────────────
    // Example 1: Fill an entire array with zeros
    // ───────────────────────────────────────────────────────────────
    const int SIZE = 12;
    int numbers[SIZE];

    // Before fill → array contains random garbage values
    cout << "1. Array before fill (undefined values):\n";
    for(int i = 0; i < SIZE; i++) {
        cout << numbers[i] << " ";
    }
    cout << "\n\n";

    // Fill the whole array with 0
    fill(numbers, numbers + SIZE, 0);

    cout << "After fill(numbers, numbers + SIZE, 0):\n";
    for(int i = 0; i < SIZE; i++) {
        cout << numbers[i] << " ";
    }
    cout << "\n\n";


    // ───────────────────────────────────────────────────────────────
    // Example 2: Fill only part of the array
    // ───────────────────────────────────────────────────────────────
    int scores[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

    cout << "2. Original scores:\n";
    for(int s : scores) cout << s << " ";
    cout << "\n\n";

    // Set first 5 elements to 999
    fill(scores, scores + 5, 999);

    cout << "After fill(scores, scores + 5, 999):\n";
    for(int s : scores) cout << s << " ";
    cout << "\n\n";


    // ───────────────────────────────────────────────────────────────
    // Example 3: Common real-world use – preparing a game board
    // ───────────────────────────────────────────────────────────────
    char board[9];                  // 3×3 grid (tic-tac-toe style)

    // Fill with '.' to represent empty cells
    fill(board, board + 9, '.');

    cout << "3. Fresh game board:\n";
    for(int i = 0; i < 9; i++)
    {
        cout << board[i] << " ";
        if((i + 1) % 3 == 0) cout << "\n";
    }
    cout << "\n";


    // ───────────────────────────────────────────────────────────────
    // Example 4: Filling with different types (double, etc.)
    // ───────────────────────────────────────────────────────────────
    double temperatures[7];
    fill(temperatures, temperatures + 7, 25.5);

    cout << "4. Week temperatures initialized to 25.5°C:\n";
    for(double t : temperatures) {
        cout << t << " ";
    }
    cout << "\n\n";


    // ───────────────────────────────────────────────────────────────
    // Key points about std::fill()
    // ───────────────────────────────────────────────────────────────
    cout << "Important notes:\n";
    cout << "• Needs #include <algorithm>\n";
    cout << "• Syntax: fill(first, last, value)\n";
    cout << "• 'last' is ONE PAST the last element (classic C++ range)\n";
    cout << "• Works on arrays, vectors, deques, raw pointers...\n";
    cout << "• Linear time → O(n) where n is number of elements\n";
    cout << "• Much cleaner than writing for-loop every time:\n";
    cout << "  Instead of: for(int i=0; i<size; i++) arr[i]=0;\n";
    cout << "  Just write: fill(arr, arr+size, 0);\n\n";

    cout << "That's the main idea behind fill() — simple, readable, useful.\n";

    cout << "\nPress Enter to exit...\n";
    cin.get();

    return 0;
}
