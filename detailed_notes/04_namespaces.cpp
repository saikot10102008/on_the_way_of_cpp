// ======================================================================
// C++ NAMESPACES - Quick Reference & Examples
// ======================================================================
// Purpose:
//   - Prevent **name conflicts** (especially in large projects / when using libraries)
//   - Allow same name (variable, function, class) to exist in different "spaces"
//   - Most important built-in namespace →  std  (contains cout, cin, string, vector, etc.)
//
// Key rule in modern C++:
//   → AVOID "using namespace std;" in .h / header files
//   → Prefer explicit std:: or selective using declarations
// ======================================================================

#include <iostream>
// #include <string>    // we'll use it later

// ────────────────────────────────────────────────
// 1. Defining your own namespaces
// ────────────────────────────────────────────────
namespace First {
    int x = 100;
    double pi = 3.14159;

    void sayHello() {
        std::cout << "Hello from First namespace!\n";
    }
}

namespace Second {
    int x = 999;               // same name 'x' → no conflict!
    double pi = 3.0;

    void sayHello() {
        std::cout << "Hello from Second namespace!\n";
    }
}

// ────────────────────────────────────────────────
// 2. Nested namespaces (C++11 and later – very common)
// ────────────────────────────────────────────────
namespace Company {
    namespace ProjectA {
        int version = 1;
    }

    namespace ProjectB {
        int version = 2;
    }
}

// You can also write it shorter (C++17 inline nested):
// namespace Company::Utils {
//     int debugLevel = 0;
// }

// ────────────────────────────────────────────────
// 3. Main function – how to USE namespaces
// ────────────────────────────────────────────────
int main()
{
    // Option A: Fully qualified name (most recommended & clearest)
    std::cout << "First::x  = " << First::x << "\n";
    std::cout << "Second::x = " << Second::x << "\n";

    First::sayHello();
    Second::sayHello();

    // Very common pattern you will see everywhere:
    std::cout << "Company::ProjectA::version = " << Company::ProjectA::version << "\n";


    // ────────────────────────────────────────────────
    // Option B: using declaration (import ONE name only – safe)
    // ────────────────────────────────────────────────
    using std::cout;    // now we can write cout instead of std::cout
    using std::endl;

    cout << "\nUsing selective import:\n";
    cout << "First::pi = " << First::pi << endl;


    // ────────────────────────────────────────────────
    // Option C: using directive (brings ALL names – convenient but DANGEROUS)
    // ────────────────────────────────────────────────
    // using namespace First;     // ← now x means First::x

    // int x = 777;               // local x shadows First::x
    // cout << x << "\n";         // prints 777 (local)
    // cout << First::x << "\n";  // still can access original with ::

    // WARNING: Avoid blanket "using namespace std;" in:
    //   • header files (.h / .hpp)
    //   • global scope in large projects
    // Reason: name collisions become very hard to debug later


    // ────────────────────────────────────────────────
    // Quick demo: what happens if two namespaces have same function name?
    // ────────────────────────────────────────────────
    // First::sayHello();      // different function
    // Second::sayHello();     // different function – no problem


    cout << "\nEnd of namespace examples.\n";
    return 0;
}