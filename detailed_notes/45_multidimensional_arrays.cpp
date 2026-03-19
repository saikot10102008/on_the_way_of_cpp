#include <iostream>

int main() {
    // Topic 41: Multidimensional arrays (mostly 2D in beginner tutorials)

    // Syntax: type name[rows][columns];
    // Think of it as: rows first, then columns (like matrix[row][col])

    // Example 1: Simple 2x3 array of integers (2 rows, 3 columns)
    int matrix[2][3] = {
        {1, 2, 3},   // row 0
        {4, 5, 6}    // row 1
    };

    std::cout << "Example 1 - Hard-coded 2x3 matrix:\n";
    // Print it nicely (nested loops: outer = rows, inner = columns)
    for(int row = 0; row < 2; row++) {
        for(int col = 0; col < 3; col++) {
            std::cout << matrix[row][col] << " ";
        }
        std::cout << "\n";  // new line after each row
    }
    // Output:
    // 1 2 3
    // 4 5 6


    // Example 2: 3x4 array filled with zeros, then user input
    const int ROWS = 3;
    const int COLS = 4;
    double grades[ROWS][COLS];   // we'll store student grades

    std::cout << "\nExample 2 - Enter grades for " << ROWS << " students, each with " << COLS << " subjects:\n";

    // Get input with nested loops
    for(int i = 0; i < ROWS; i++) {
        std::cout << "Student " << (i + 1) << ":\n";
        for(int j = 0; j < COLS; j++) {
            std::cout << "  Subject " << (j + 1) << ": ";
            std::cin >> grades[i][j];
        }
    }

    // Show what was entered
    std::cout << "\nGrades table:\n";
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            std::cout << grades[i][j] << "\t";  // tab for spacing
        }
        std::cout << "\n";
    }


    // Example 3: Very common real use → tic-tac-toe board (3x3 char array)
    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };

    // Simulate placing some moves
    board[0][0] = 'X';
    board[1][1] = 'O';
    board[2][2] = 'X';

    std::cout << "\nExample 3 - Tic-tac-toe board:\n";
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            std::cout << board[i][j];
            if(j < 2) std::cout << " | ";  // separator
        }
        std::cout << "\n";
        if(i < 2) std::cout << "---------\n";  // horizontal line
    }
    // Looks like:
    // X |   |
    // ---------
    //   | O |
    // ---------
    //   |   | X

    return 0;
}
