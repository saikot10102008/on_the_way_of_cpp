// ======================================================================
// C++ TYPEDEF & TYPE ALIASES (using) - Quick Reference & Examples
// ======================================================================
// Purpose:
//   - Create **custom names** (aliases) for existing types
//   - Makes code more readable, self-documenting, and easier to maintain
//   - Especially useful for:
//       • Long/complex types (pointers, templates, nested types)
//       • Improving clarity in large projects
//       • Changing a type in one place later (if needed)
//
// Two main ways in C++:
//   1. typedef     → older style (C heritage), still valid
//   2. using       → modern/preferred (C++11+), more flexible & powerful
// ======================================================================
#include <iostream>
#include <string>
#include <vector>

// ================================================
// 1. Old way: typedef  (still works, but older style)
// ================================================
typedef int Number;               // Number is now another name for int
typedef std::string Text;         // Text is now another name for std::string
typedef std::vector<int> Numbers; // Numbers is now a vector of ints

// ================================================
// 2. Modern way: using  (better, cleaner, preferred)
// ================================================
using Age       = int;            // Age means int
using Name      = std::string;    // Name means std::string
using ScoreList = std::vector<int>; // ScoreList means vector<int>

// ================================================
// Main - see how much nicer it looks
// ================================================
int main()
{
    // Without alias (ugly and long)
    std::vector<int> old_scores = {85, 92, 78};
    std::cout << "Old way first score: " << old_scores[0] << "\n";

    // With typedef (cleaner)
    Numbers game_scores = {100, 95, 88};
    std::cout << "Typedef scores: " << game_scores[0] << "\n";

    // With using (even better & modern)
    ScoreList player_scores = {99, 87, 76};
    std::cout << "Using scores: " << player_scores[0] << "\n\n";

    // Real-life like names (makes code easy to read)
    Age my_age = 20;
    Name my_name = "Sakhwat";

    std::cout << my_name << " is " << my_age << " years old.\n";

    return 0;
}