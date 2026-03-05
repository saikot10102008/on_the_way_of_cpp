/**
 * ============================================================================
 * C++ VARIABLE SCOPE - COMPLETE BEGINNER'S GUIDE
 * ============================================================================
 * 
 * WHAT IS SCOPE?
 * Scope = "Where can I use this variable?"
 * 
 * Think of it like different rooms in a house:
 * 🌍 GLOBAL  = Front yard (everyone can see it)
 * 🏠 LOCAL   = Your bedroom (only you inside your room)
 * 📦 BLOCK   = A closet (even more private)
 * 🏢 NAMESPACE = Different houses with same street name
 * 
 * GOLDEN RULE: You can see OUTSIDE your room, but not INSIDE others'
 * ============================================================================
 */

#include <iostream>
#include <string>
using namespace std;  // Let's us use cout without std:: (for simplicity)

// ============================================================================
// PART 1: GLOBAL SCOPE 🌍 (The Front Yard)
// ============================================================================
// Global variables are declared OUTSIDE all functions
// They live for the ENTIRE program and EVERYONE can see them

int globalScore = 100;              // Anyone can see/modify this
string globalGame = "C++ Adventure"; // Global string
const double GLOBAL_PI = 3.14;      // Global constant

void showGlobal() {
    // ✅ Global variables ARE visible inside functions
    cout << "Global score: " << globalScore << "\n";
    cout << "Global game: " << globalGame << "\n";
}

// ============================================================================
// PART 2: LOCAL SCOPE 🏠 (Your Bedroom)
// ============================================================================
// Local variables are declared INSIDE a function
// They are born when function starts, die when function ends

void demoLocalScope() {
    cout << "\n--- LOCAL SCOPE DEMO ---\n";
    
    // These variables are LOCAL to this function ONLY
    int localAge = 25;              // Created here
    string localName = "Alex";       // Created here
    
    cout << "Local age: " << localAge << "\n";
    cout << "Local name: " << localName << "\n";
    cout << "Can also see global: " << globalScore << "\n";
    
} // ❌ localAge and localName DIE here - gone forever!

void trySeeLocal() {
    // ❌ Cannot see demoLocalScope's variables!
    // cout << localAge;  // ERROR! localAge doesn't exist here
}

// ============================================================================
// PART 3: BLOCK SCOPE 📦 (Inside a Closet)
// ============================================================================
// Any { } creates a new scope level
// Variables inside { } only live until the closing }

void demoBlockScope() {
    cout << "\n--- BLOCK SCOPE DEMO ---\n";
    
    int x = 10;  // Outer block variable
    cout << "Outer x: " << x << "\n";
    
    {  // ← New block starts
        int x = 20;  // NEW variable, only inside these { }
        cout << "Inner x: " << x << " (different variable!)\n";
        
        {  // ← Another nested block
            int x = 30;  // Yet another new variable
            cout << "Deepest x: " << x << "\n";
        } // Deepest x dies here
        
        cout << "Back to inner x: " << x << "\n";
    } // Inner x dies here
    
    cout << "Back to outer x: " << x << "\n"; // Still 10!
}

// ============================================================================
// PART 4: NAME HIDING (When Names Collide)
// ============================================================================
// If same name exists in multiple scopes, the INNERMOST wins

int number = 999;  // Global number

void demoNameHiding() {
    cout << "\n--- NAME HIDING DEMO ---\n";
    
    int number = 10;  // 🚫 This HIDES the global number
    cout << "Local number (hides global): " << number << "\n";
    
    {  // Block scope
        int number = 5;  // 🚫 HIDES both global AND local!
        cout << "Block number (hides both): " << number << "\n";
    } // Block number dies
    
    cout << "Back to local number: " << number << "\n";
    
    // How to access the hidden GLOBAL number?
    cout << "Global number (using ::): " << ::number << "\n";  // :: means "global"
}

// ============================================================================
// PART 5: THE SCOPE RESOLUTION OPERATOR (::)
// ============================================================================
// :: = "Go find this in..." (like an address)

int value = 1000;  // Global

void demoScopeOperator() {
    cout << "\n--- SCOPE RESOLUTION OPERATOR (::) ---\n";
    
    int value = 1;  // Local hides global
    
    cout << "Local value: " << value << "\n";
    cout << "Global value (::value): " << ::value << "\n";
    // ::value = "find 'value' in GLOBAL scope"
    
    // :: can also access namespaces (see next section)
}

// ============================================================================
// PART 6: NAMESPACES 🏢 (Last Names for Variables)
// ============================================================================
// Namespace = A container with a name to group related stuff
// They prevent naming conflicts (like last names prevent confusion)

namespace MathStuff {
    // Everything here has the "last name" MathStuff::
    int calculations = 0;
    double pi = 3.14159;
    
    void add(int a, int b) {
        calculations++;
        cout << "Sum: " << a + b << "\n";
    }
}

namespace GameStuff {
    // Same names as MathStuff? NO PROBLEM! Different namespace
    int calculations = 0;  // This is GameStuff::calculations
    string playerName = "Hero";
    
    void add(int score) {  // Different from MathStuff::add
        calculations++;
        cout << "Adding score: " << score << "\n";
    }
}

void demoNamespaces() {
    cout << "\n--- NAMESPACES DEMO ---\n";
    
    // Same name, different namespace = different variables!
    cout << "Math calculations: " << MathStuff::calculations << "\n";
    cout << "Game calculations: " << GameStuff::calculations << "\n\n";
    
    // Call functions from different namespaces
    MathStuff::add(5, 3);
    GameStuff::add(100);
    
    MathStuff::add(10, 20);
    
    cout << "\nMath calculations now: " << MathStuff::calculations << "\n";
    cout << "Game calculations now: " << GameStuff::calculations << "\n";
}

// ============================================================================
// PART 7: NESTED NAMESPACES (Namespaces Inside Namespaces)
// ============================================================================

namespace School {
    string name = "City High";
    
    namespace Room101 {
        int students = 25;
        string teacher = "Ms. Smith";
    }
    
    namespace Room102 {
        int students = 30;
        string teacher = "Mr. Jones";
    }
}

void demoNestedNamespaces() {
    cout << "\n--- NESTED NAMESPACES DEMO ---\n";
    
    cout << "School: " << School::name << "\n";
    cout << "Room101 teacher: " << School::Room101::teacher << "\n";
    cout << "Room102 students: " << School::Room102::students << "\n";
    
    // Each :: goes one level deeper
}

// ============================================================================
// PART 8: THE 'using' KEYWORD (3 Ways to Use It)
// ============================================================================

namespace Tools {
    int hammer = 1;
    int saw = 2;
    int drill = 3;
}

void demoUsingKeyword() {
    cout << "\n--- THE 'using' KEYWORD (3 WAYS) ---\n";
    
    // WAY 1: using namespace (DANGEROUS - brings EVERYTHING)
    cout << "WAY 1: 'using namespace Tools;' - brings ALL tools\n";
    cout << "⚠️ Can cause conflicts if names clash!\n\n";
    
    // WAY 2: using declaration (SAFER - brings just ONE thing)
    {
        using Tools::hammer;  // Only hammer is brought in
        cout << "WAY 2: 'using Tools::hammer;' - only hammer\n";
        cout << "hammer = " << hammer << " (no Tools:: needed)\n";
        // cout << saw;  // ❌ ERROR! saw not brought in
    }
    
    // WAY 3: type alias (Give types nicknames)
    using Text = std::string;  // Text now means std::string
    Text message = "This uses the 'Text' alias!";
    cout << "\nWAY 3: 'using Text = std::string;'\n";
    cout << message << "\n";
}

// ============================================================================
// PART 9: THE STANDARD NAMESPACE (std)
// ============================================================================

void demoStdNamespace() {
    cout << "\n--- THE STANDARD NAMESPACE (std) ---\n";
    
    cout << "Everything from C++ standard library is in 'std':\n";
    cout << "• std::cout - console output\n";
    cout << "• std::cin - console input\n";
    cout << "• std::string - text\n";
    cout << "• std::vector - arrays\n";
    cout << "• And hundreds more...\n\n";
    
    cout << "That's why we write: std::cout << \"Hello\";\n";
    cout << "The 'using namespace std;' at top lets us skip 'std::'\n";
}

// ============================================================================
// PART 10: ANONYMOUS NAMESPACE (File-Private)
// ============================================================================

namespace {
    // This stuff is PRIVATE to this file only
    // Other .cpp files CANNOT see this!
    int secretCounter = 0;
    
    void secretFunction() {
        secretCounter++;
        cout << "🔒 Secret function called " << secretCounter << " times\n";
    }
}

void demoAnonymousNamespace() {
    cout << "\n--- ANONYMOUS NAMESPACE DEMO ---\n";
    cout << "This namespace has no name - it's PRIVATE to this file\n";
    
    secretFunction();
    secretFunction();
    cout << "Secret counter: " << secretCounter << "\n";
}

// ============================================================================
// PART 11: COMMON MISTAKES TO AVOID
// ============================================================================

void demoMistakes() {
    cout << "\n--- COMMON MISTAKES TO AVOID ---\n";
    
    // MISTAKE 1: Thinking inner changes affect outer
    cout << "MISTAKE 1: Modifying inner doesn't change outer\n";
    int a = 5;
    {
        int a = 10;  // This is a DIFFERENT a!
        a = 20;      // Changes inner a only
    }
    cout << "a is still " << a << " (not 20!)\n\n";
    
    // MISTAKE 2: Forgetting :: for global
    cout << "MISTAKE 2: Forgetting to use :: for global\n";
    int value = 1;
    cout << "Local value = " << value << "\n";
    cout << "To get global, use ::value\n\n";
    
    // MISTAKE 3: overusing 'using namespace'
    cout << "MISTAKE 3: 'using namespace std;' everywhere\n";
    cout << "Can cause conflicts if you make variables named 'cout'\n";
    cout << "Better to use std:: or specific 'using std::cout;'\n";
}

// ============================================================================
// QUICK REFERENCE TABLE
// ============================================================================

void showReference() {
    cout << "\n";
    cout << "╔════════════════════════════════════════════════════════╗\n";
    cout << "║                 QUICK REFERENCE                        ║\n";
    cout << "╠══════════════════╦════════════════╦════════════════════╣\n";
    cout << "║ SCOPE TYPE       ║ SYNTAX         ║ VISIBLE TO         ║\n";
    cout << "╠══════════════════╬════════════════╬════════════════════╣\n";
    cout << "║ GLOBAL 🌍        ║ Outside all {} ║ Everyone           ║\n";
    cout << "║ LOCAL 🏠         ║ Inside function║ That function only ║\n";
    cout << "║ BLOCK 📦         ║ Inside { }     ║ That block only    ║\n";
    cout << "║ NAMESPACE 🏢     ║ namespace N {} ║ Need N:: to see    ║\n";
    cout << "╚══════════════════╩════════════════╩════════════════════╝\n";
    
    cout << "\n";
    cout << "╔════════════════════════════════════════════════════════╗\n";
    cout << "║                 SCOPE OPERATOR (::)                   ║\n";
    cout << "╠════════════════════════════════════════════════════════╣\n";
    cout << "║ ::name     → Find 'name' in GLOBAL scope              ║\n";
    cout << "║ Space::name → Find 'name' in 'Space' namespace        ║\n";
    cout << "║ A::B::name → Find 'name' in nested namespace          ║\n";
    cout << "╚════════════════════════════════════════════════════════╝\n";
}

// ============================================================================
// MAIN FUNCTION - See Everything in Action
// ============================================================================

int main() {
    cout << "\n";
    cout << "╔════════════════════════════════════════════════════════╗\n";
    cout << "║     C++ VARIABLE SCOPE - COMPLETE BEGINNER'S GUIDE    ║\n";
    cout << "╚════════════════════════════════════════════════════════╝\n";
    
    // Run through all demonstrations in order
    showGlobal();
    demoLocalScope();
    demoBlockScope();
    demoNameHiding();
    demoScopeOperator();
    demoNamespaces();
    demoNestedNamespaces();
    demoUsingKeyword();
    demoStdNamespace();
    demoAnonymousNamespace();
    demoMistakes();
    showReference();
    
    // Show final state of all variables
    cout << "\n--- FINAL STATE ---\n";
    cout << "Global score: " << globalScore << "\n";
    cout << "MathStuff::calculations: " << MathStuff::calculations << "\n";
    cout << "GameStuff::calculations: " << GameStuff::calculations << "\n";
    cout << "Secret counter: " << secretCounter << "\n";
    
    cout << "\n╔════════════════════════════════════════════════════════╗\n";
    cout << "║                 YOU NOW UNDERSTAND SCOPE!             ║\n";
    cout << "║     🌍 Global • 🏠 Local • 📦 Block • 🏢 Namespace    ║\n";
    cout << "╚════════════════════════════════════════════════════════╝\n\n";
    
    return 0;
}

// ============================================================================
// THE 30-SECOND SUMMARY
// ============================================================================
/*
 * 
 * 🌍 GLOBAL    = Outside all functions - everyone can see it
 * 🏠 LOCAL     = Inside a function - only that function
 * 📦 BLOCK     = Inside { } - only until the }
 * 🏢 NAMESPACE = Group with a "last name" - need Name:: to see
 * 
 * 📌 RULE #1: Inner can see Outer, but Outer CANNOT see Inner
 * 📌 RULE #2: Same name? The INNERMOST wins (hides outer ones)
 * 📌 RULE #3: Use :: to force which scope (:: = "go find in...")
 * 
 * :: Examples:
 *   ::x      → Find x in GLOBAL scope
 *   Math::x  → Find x in Math namespace
 * 
 * using Examples:
 *   using namespace std;    → BRINGS EVERYTHING (dangerous)
 *   using std::cout;        → Brings JUST cout (safer)
 *   using Text = std::string; → Makes Text an alias (clean)
 */