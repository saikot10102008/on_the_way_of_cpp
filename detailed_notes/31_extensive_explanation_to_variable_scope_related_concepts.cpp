/**
 * ============================================================================
 * THE COMPLETE GUIDE TO C++ SCOPE, NAMESPACES & SCOPE RESOLUTION
 * ============================================================================
 * 
 * "Scope" is one of the most fundamental concepts in programming. This guide
 * will take you from zero to hero, explaining everything in detail with
 * practical examples.
 * 
 * ============================================================================
 */

#include <iostream>
#include <string>
#include <cmath>  // For mathematical functions

// ============================================================================
// PART 1: WHAT IS SCOPE? (THE FOUNDATION)
// ============================================================================
/*
 * ████████████████████████████████████████████████████████████████████████████
 * 
 * SCOPE DEFINITION:
 * ---------------
 * Scope refers to the region of a program where a particular variable or
 * function can be accessed. Think of it like visibility in real life:
 * 
 * 🌍 GLOBAL SCOPE  → Like a billboard - everyone can see it everywhere
 * 🏠 LOCAL SCOPE   → Like a room in a house - only visible inside that room
 * 📦 BLOCK SCOPE   → Like a closet - only visible inside that closet
 * 🏢 NAMESPACE     → Like a labeled building - you need the address to find it
 * 
 * KEY PRINCIPLE:
 * -------------
 * Code can only see what's in its current scope or in outer scopes.
 * It CANNOT see into inner scopes (like trying to see inside a closed room).
 * 
 * RULE OF THUMB:
 * -------------
 * { curly braces } define scope boundaries. Everything inside { } is its own world.
 * 
 * ████████████████████████████████████████████████████████████████████████████
 */

// ============================================================================
// PART 2: GLOBAL SCOPE (THE OUTERMOST LEVEL)
// ============================================================================

// These variables are in the GLOBAL SCOPE - they exist for the entire program
// Think of them as being written on a billboard that EVERYONE can see

int globalCounter = 1000;              // Accessible everywhere
std::string globalAppName = "ScopeMaster";  // Also accessible everywhere
const double GLOBAL_PI = 3.14159;       // Global constant

// Global function - also in global scope
void globalAnnouncement() {
    std::cout << "🌍 Global announcement from: " << globalAppName << "\n";
}

// ============================================================================
// PART 3: LOCAL SCOPE (INSIDE FUNCTIONS)
// ============================================================================

/**
 * Demonstrates LOCAL SCOPE - variables that only exist inside functions
 * Think of each function as its own room with its own furniture (variables)
 */
void demonstrateLocalScope() {
    std::cout << "\n";
    std::cout << "╔════════════════════════════════════════════════════════════╗\n";
    std::cout << "║                    LOCAL SCOPE DEMO                       ║\n";
    std::cout << "╚════════════════════════════════════════════════════════════╝\n";

    // These variables are LOCAL to this function
    // They are CREATED when the function starts, DESTROYED when it ends
    int localCounter = 42;              // Only exists inside this function
    std::string localMessage = "Hello from local scope!";
    
    std::cout << "🔹 LOCAL variable 'localCounter' = " << localCounter << "\n";
    std::cout << "🔹 LOCAL variable 'localMessage' = " << localMessage << "\n\n";
    
    std::cout << "🌍 Can also see GLOBAL variables: globalCounter = " << globalCounter << "\n";
    std::cout << "🌍 Global constants also visible: GLOBAL_PI = " << GLOBAL_PI << "\n\n";
    
    std::cout << "⛔ Cannot see into OTHER functions' local scopes\n";
    std::cout << "   (otherFunction()'s variables are invisible here)\n";
    
    // IMPORTANT: When the function ends, localCounter and localMessage disappear!
}

// ============================================================================
// PART 4: BLOCK SCOPE (INSIDE { } ANYWHERE)
// ============================================================================

/**
 * Shows how { } creates new scope levels anywhere in the code
 * Think of each { } block as a nested room inside a room
 */
void demonstrateBlockScope() {
    std::cout << "\n";
    std::cout << "╔════════════════════════════════════════════════════════════╗\n";
    std::cout << "║                    BLOCK SCOPE DEMO                       ║\n";
    std::cout << "╚════════════════════════════════════════════════════════════╝\n";
    
    int level = 1;  // Outer block variable
    std::cout << "📦 OUTER BLOCK (level " << level << "): x = " << level << "\n";
    
    {  // ← This { creates a NEW scope level (inner block 1)
        int level = 2;  // NEW variable, completely separate from outer 'level'
        std::cout << "   📦 INNER BLOCK 1 (level " << level << "): x = " << level << "\n";
        
        {  // ← Another nested scope (inner block 2)
            int level = 3;  // Yet ANOTHER new variable
            std::cout << "       📦 INNER BLOCK 2 (level " << level << "): x = " << level << "\n";
            
            // Can still see global scope if needed
            std::cout << "       🌍 Still can see global: globalCounter = " << globalCounter << "\n";
            
        }  // ← Inner block 2 ENDS - 'level=3' is destroyed here
        
        // Back to inner block 1 - 'level=2' is still alive
        std::cout << "   Back to INNER BLOCK 1: x = " << level << "\n";
        
    }  // ← Inner block 1 ENDS - 'level=2' is destroyed here
    
    // Back to outer block - 'level=1' is still alive
    std::cout << "Back to OUTER BLOCK: x = " << level << "\n\n";
    
    std::cout << "🔑 KEY INSIGHT: Each { } creates a new layer of scope.\n";
    std::cout << "   Variables are born at '{' and die at '}'.\n";
}

// ============================================================================
// PART 5: NAME HIDING (SHADOWING)
// ============================================================================

/**
 * Demonstrates what happens when same name exists in multiple scopes
 * This is called "name hiding" or "shadowing"
 */
void demonstrateNameHiding() {
    std::cout << "\n";
    std::cout << "╔════════════════════════════════════════════════════════════╗\n";
    std::cout << "║                    NAME HIDING DEMO                       ║\n";
    std::cout << "╚════════════════════════════════════════════════════════════╝\n";
    
    int value = 10;  // Local variable
    std::cout << "📌 Local 'value' = " << value << "\n";
    
    {
        int value = 20;  // This HIDES the outer 'value'
        std::cout << "   📌 Inner block 'value' = " << value << " (hides outer)\n";
        value = 30;  // Modifies inner 'value' only
        std::cout << "   📌 Modified inner 'value' = " << value << "\n";
    }
    
    std::cout << "📌 Outer 'value' still = " << value << " (unchanged!)\n\n";
    
    std::cout << "⚠️ CRITICAL RULE: Inner scopes HIDE outer scopes!\n";
    std::cout << "   When you have the same name, the innermost wins.\n";
    std::cout << "   This can cause bugs if you're not careful!\n";
}

// ============================================================================
// PART 6: THE SCOPE RESOLUTION OPERATOR (::)
// ============================================================================

/**
 * Shows how to use :: to access hidden or specific scopes
 * The scope resolution operator is like having a key to any room
 */
void demonstrateScopeResolution() {
    std::cout << "\n";
    std::cout << "╔════════════════════════════════════════════════════════════╗\n";
    std::cout << "║              SCOPE RESOLUTION OPERATOR (::) DEMO          ║\n";
    std::cout << "╚════════════════════════════════════════════════════════════╝\n";
    
    int value = 5;  // Local variable hides the global (if any existed)
    std::cout << "📌 Local 'value' = " << value << "\n";
    
    // But what if we want the GLOBAL version? Use :: with nothing in front
    std::cout << "🌍 Global '::globalCounter' = " << ::globalCounter << "\n";
    std::cout << "🌍 Global '::globalAppName' = " << ::globalAppName << "\n\n";
    
    std::cout << "🔧 The :: operator has several uses:\n";
    std::cout << "   1. ::name        → Access GLOBAL scope\n";
    std::cout << "   2. Namespace::name → Access NAMESPACE scope\n";
    std::cout << "   3. Class::name    → Access CLASS scope (seen in OOP)\n\n";
    
    // Demonstrate accessing something that's hidden
    int globalCounter = 999;  // This LOCAL hides the GLOBAL globalCounter
    std::cout << "📌 Created local 'globalCounter' = " << globalCounter << "\n";
    std::cout << "🌍 But global still exists: ::globalCounter = " << ::globalCounter << "\n";
    std::cout << "   (The :: lets us bypass the hiding!)\n";
}

// ============================================================================
// PART 7: INTRODUCTION TO NAMESPACES
// ============================================================================

/*
 * ████████████████████████████████████████████████████████████████████████████
 * 
 * WHAT ARE NAMESPACES?
 * -------------------
 * Namespaces are NAMED SCOPE containers. They let you group related code
 * together and prevent naming conflicts.
 * 
 * REAL-WORLD ANALOGY:
 * ------------------
 * Imagine two different families both have a daughter named "Sarah":
 * - Smith family's Sarah
 * - Jones family's Sarah
 * 
 * Without last names (namespaces), you couldn't tell them apart!
 * 
 * NAMESPACE = Last name
 * MEMBER = First name
 * :: = "from the family of"
 * 
 * So "Smith::Sarah" means "Sarah from the Smith family"
 * 
 * ████████████████████████████████████████████████████████████████████████████
 */

// ============================================================================
// PART 8: CREATING AND USING NAMESPACES
// ============================================================================

/**
 * First namespace: Mathematics
 * Groups together all math-related code
 */
namespace Mathematics {
    // These are all inside the Mathematics namespace
    // They have the "last name" Mathematics::
    
    // Constants
    const double PI = 3.141592653589793;
    const double E = 2.718281828459045;
    
    // Variables
    int calculationCount = 0;
    std::string version = "2.0.0";
    
    // Functions
    double circleArea(double radius) {
        calculationCount++;  // Increments Mathematics::calculationCount
        return PI * radius * radius;
    }
    
    double circleCircumference(double radius) {
        calculationCount++;
        return 2 * PI * radius;
    }
    
    void showStats() {
        std::cout << "   📊 Mathematics stats:\n";
        std::cout << "      - Calculations: " << calculationCount << "\n";
        std::cout << "      - Version: " << version << "\n";
        std::cout << "      - PI: " << PI << "\n";
    }
}

/**
 * Second namespace: Database
 * Groups together all database-related code
 * NOTICE: Uses SAME variable names as Mathematics - NO CONFLICT!
 */
namespace Database {
    // These names are IDENTICAL to ones in Mathematics
    // But they're in DIFFERENT namespaces, so they're completely separate
    int calculationCount = 0;        // Tracks queries, not math ops
    std::string version = "3.1.4";   // Different version
    std::string connectionString = "postgresql://localhost:5432/mydb";
    
    void connect() {
        calculationCount++;
        std::cout << "   🔌 Connected to: " << connectionString << "\n";
    }
    
    void query(const std::string& sql) {
        calculationCount++;
        std::cout << "   📝 Executing query: " << sql << "\n";
    }
    
    void showStats() {
        std::cout << "   📊 Database stats:\n";
        std::cout << "      - Queries executed: " << calculationCount << "\n";
        std::cout << "      - Version: " << version << "\n";
        std::cout << "      - Connection: " << connectionString << "\n";
    }
}

/**
 * Shows how to use namespaces
 */
void demonstrateNamespaceBasics() {
    std::cout << "\n";
    std::cout << "╔════════════════════════════════════════════════════════════╗\n";
    std::cout << "║                 NAMESPACE BASICS DEMO                     ║\n";
    std::cout << "╚════════════════════════════════════════════════════════════╝\n";
    
    std::cout << "Accessing Mathematics namespace:\n";
    std::cout << "   Mathematics::PI = " << Mathematics::PI << "\n";
    std::cout << "   Mathematics::version = " << Mathematics::version << "\n";
    
    std::cout << "\nAccessing Database namespace:\n";
    std::cout << "   Database::connectionString = " << Database::connectionString << "\n";
    std::cout << "   Database::version = " << Database::version << "\n\n";
    
    std::cout << "🔑 KEY POINT: Both namespaces have 'version' and 'calculationCount'\n";
    std::cout << "   But they're different variables because they're in different namespaces!\n\n";
    
    // Using functions from namespaces
    std::cout << "Calling Mathematics::circleArea(5):\n";
    double area = Mathematics::circleArea(5.0);
    std::cout << "   Area = " << area << "\n\n";
    
    std::cout << "Calling Database functions:\n";
    Database::connect();
    Database::query("SELECT * FROM users");
    
    // Show stats from both
    std::cout << "\n";
    Mathematics::showStats();
    std::cout << "\n";
    Database::showStats();
}

// ============================================================================
// PART 9: NESTED NAMESPACES
// ============================================================================

/**
 * Namespaces can be nested inside other namespaces
 * Like rooms inside a building
 */
namespace Mathematics {
    // This ADDS to the existing Mathematics namespace
    // We're adding a nested namespace called "Geometry"
    namespace Geometry {
        // Now we have Mathematics::Geometry::something
        
        enum class Shape { CIRCLE, SQUARE, TRIANGLE };
        
        struct Point {
            double x;
            double y;
            
            void display() const {
                std::cout << "Point(" << x << ", " << y << ")";
            }
        };
        
        double distance(const Point& a, const Point& b) {
            return std::sqrt(std::pow(b.x - a.x, 2) + std::pow(b.y - a.y, 2));
        }
        
        // This function is inside two namespaces
        void describe() {
            std::cout << "   📐 Geometry utilities from Mathematics\n";
        }
    }
}

/**
 * Shows how to work with nested namespaces
 */
void demonstrateNestedNamespaces() {
    std::cout << "\n";
    std::cout << "╔════════════════════════════════════════════════════════════╗\n";
    std::cout << "║                 NESTED NAMESPACES DEMO                    ║\n";
    std::cout << "╚════════════════════════════════════════════════════════════╝\n";
    
    std::cout << "Accessing nested namespace:\n";
    std::cout << "   Full path: Mathematics::Geometry::Point\n\n";
    
    // Create a point using nested namespace
    Mathematics::Geometry::Point p1{0.0, 0.0};
    Mathematics::Geometry::Point p2{3.0, 4.0};
    
    std::cout << "   p1 = ";
    p1.display();
    std::cout << "\n   p2 = ";
    p2.display();
    
    double dist = Mathematics::Geometry::distance(p1, p2);
    std::cout << "\n\n   Distance between points = " << dist << "\n";
    
    Mathematics::Geometry::describe();
    
    std::cout << "\n🔑 Each :: goes one level deeper into the namespace hierarchy\n";
}

// ============================================================================
// PART 10: THE std NAMESPACE (STANDARD LIBRARY)
// ============================================================================

/**
 * Explains the most important namespace in C++
 */
void demonstrateStdNamespace() {
    std::cout << "\n";
    std::cout << "╔════════════════════════════════════════════════════════════╗\n";
    std::cout << "║                 THE STANDARD NAMESPACE (std)              ║\n";
    std::cout << "╚════════════════════════════════════════════════════════════╝\n";
    
    std::cout << "The C++ Standard Library puts EVERYTHING in the 'std' namespace:\n";
    std::cout << "   • std::cout  → console output\n";
    std::cout << "   • std::cin   → console input\n";
    std::cout << "   • std::string → text strings\n";
    std::cout << "   • std::vector → dynamic arrays\n";
    std::cout << "   • std::sort   → sorting algorithm\n";
    std::cout << "   • and hundreds more...\n\n";
    
    std::cout << "That's why we write:\n";
    std::cout << "   std::cout << \"Hello\";\n";
    std::cout << "   std::string name;\n";
    std::cout << "   std::vector<int> numbers;\n\n";
    
    std::cout << "Without 'std::', the compiler wouldn't know where to find them!\n";
}

// ============================================================================
// PART 11: THE 'using' KEYWORD (DIFFERENT FLAVORS)
// ============================================================================

/**
 * Shows all the ways to use 'using' to avoid typing namespace prefixes
 */
void demonstrateUsingKeyword() {
    std::cout << "\n";
    std::cout << "╔════════════════════════════════════════════════════════════╗\n";
    std::cout << "║                 THE 'using' KEYWORD                       ║\n";
    std::cout << "╚════════════════════════════════════════════════════════════╝\n";
    
    std::cout << "There are THREE ways to use 'using':\n\n";
    
    // ------------------------------------------------------------------------
    // TYPE 1: Using Directive (DANGEROUS - use sparingly!)
    // ------------------------------------------------------------------------
    std::cout << "1️⃣ USING DIRECTIVE: 'using namespace Name;'\n";
    std::cout << "   Brings EVERY name from a namespace into current scope\n";
    std::cout << "   ⚠️ DANGEROUS - can cause naming conflicts!\n";
    std::cout << "   Example: using namespace std;\n";
    std::cout << "   Now you can write 'cout' instead of 'std::cout'\n";
    std::cout << "   But if you have your own 'cout' variable, CONFLICT!\n\n";
    
    // ------------------------------------------------------------------------
    // TYPE 2: Using Declaration (SAFER)
    // ------------------------------------------------------------------------
    std::cout << "2️⃣ USING DECLARATION: 'using Name::specific;'\n";
    std::cout << "   Brings ONE specific name into current scope\n";
    std::cout << "   ✅ SAFER - only brings what you need\n";
    std::cout << "   Example: using std::cout;\n";
    std::cout << "   Now 'cout' means std::cout, but nothing else from std\n\n";
    
    // Let's demonstrate
    std::cout << "   DEMONSTRATION:\n";
    {
        using std::cout;  // Only cout is brought in
        using std::endl;  // Only endl is brought in
        
        cout << "   This uses std::cout without the std:: prefix!" << endl;
        // string s;  // This would FAIL - string wasn't brought in
    }
    std::cout << "\n";
    
    // ------------------------------------------------------------------------
    // TYPE 3: Type Alias (Modern typedef)
    // ------------------------------------------------------------------------
    std::cout << "3️⃣ TYPE ALIAS: 'using NewName = ExistingType;'\n";
    std::cout << "   Creates a new name for an existing type\n";
    std::cout << "   Example: using String = std::string;\n";
    std::cout << "   Now 'String' means 'std::string'\n\n";
    
    // Demonstrate type alias
    using Text = std::string;
    Text message = "This uses the 'Text' alias for std::string";
    std::cout << "   " << message << "\n";
}

// ============================================================================
// PART 12: REAL-WORLD SCENARIO - LIBRARY CONFLICT RESOLUTION
// ============================================================================

/**
 * Shows a practical example of why namespaces are essential
 * Imagine using two different graphics libraries
 */

// Library 1: SimpleGraphics
namespace SimpleGraphics {
    class Renderer {
    public:
        void drawCircle(int x, int y, int radius) {
            std::cout << "   [Simple] Drawing circle at (" << x << "," << y << ")\n";
        }
        
        void drawSquare(int x, int y, int size) {
            std::cout << "   [Simple] Drawing square at (" << x << "," << y << ")\n";
        }
    };
    
    void initialize() {
        std::cout << "   [Simple] Initializing SimpleGraphics...\n";
    }
}

// Library 2: AdvancedGraphics (has SAME function names!)
namespace AdvancedGraphics {
    class Renderer {  // Same class name as SimpleGraphics!
    private:
        int quality = 100;
    public:
        void setQuality(int q) { quality = q; }
        
        void drawCircle(int x, int y, int radius, bool antiAlias = true) {
            std::cout << "   [Advanced] Drawing high-quality circle at (" << x << "," << y << ")\n";
            std::cout << "              Quality: " << quality << "%, Anti-aliasing: " << (antiAlias ? "ON" : "OFF") << "\n";
        }
        
        void drawSquare(int x, int y, int size, bool filled = true) {
            std::cout << "   [Advanced] Drawing " << (filled ? "filled" : "outline") << " square\n";
        }
    };
    
    void initialize(bool verbose = false) {
        std::cout << "   [Advanced] Initializing AdvancedGraphics";
        if (verbose) std::cout << " (verbose mode)";
        std::cout << "...\n";
    }
}

/**
 * Shows how namespaces let you use both libraries together
 */
void demonstrateRealWorldScenario() {
    std::cout << "\n";
    std::cout << "╔════════════════════════════════════════════════════════════╗\n";
    std::cout << "║              REAL-WORLD: LIBRARY CONFLICTS                ║\n";
    std::cout << "╚════════════════════════════════════════════════════════════╝\n";
    
    std::cout << "SCENARIO: Two graphics libraries with identical class/function names\n";
    std::cout << "Without namespaces, this would be IMPOSSIBLE!\n\n";
    
    // Initialize both libraries (same function name, different namespaces)
    std::cout << "Initializing libraries:\n";
    SimpleGraphics::initialize();
    AdvancedGraphics::initialize(true);
    
    std::cout << "\nUsing both renderers together:\n";
    
    // Create renderers from both libraries
    SimpleGraphics::Renderer simpleRenderer;
    AdvancedGraphics::Renderer advancedRenderer;
    
    // Use them side by side - no confusion!
    simpleRenderer.drawCircle(10, 20, 5);
    advancedRenderer.setQuality(200);
    advancedRenderer.drawCircle(10, 20, 5);
    
    simpleRenderer.drawSquare(30, 40, 15);
    advancedRenderer.drawSquare(30, 40, 15, true);
    
    std::cout << "\n🔑 Without namespaces, you couldn't use both libraries!\n";
    std::cout << "   Namespaces let them coexist peacefully.\n";
}

// ============================================================================
// PART 13: ANONYMOUS NAMESPACES (FILE-PRIVATE)
// ============================================================================

/**
 * Anonymous namespaces make everything inside them private to this file
 * Like a "secret" scope that only this file can see
 */
namespace {
    // These are ONLY visible within this .cpp file
    // Other files cannot see or access these
    
    int internalCounter = 0;
    
    void internalHelper(const std::string& msg) {
        std::cout << "   🔒 [Internal] " << msg << "\n";
        internalCounter++;
    }
    
    class SecretClass {
    public:
        void doSecretStuff() {
            internalHelper("Doing something top secret");
        }
    };
}

void demonstrateAnonymousNamespace() {
    std::cout << "\n";
    std::cout << "╔════════════════════════════════════════════════════════════╗\n";
    std::cout << "║              ANONYMOUS (UNNAMED) NAMESPACE                ║\n";
    std::cout << "╚════════════════════════════════════════════════════════════╝\n";
    
    std::cout << "Anonymous namespace members are PRIVATE to this file:\n";
    std::cout << "   • Other .cpp files CANNOT see them\n";
    std::cout << "   • Like 'static' in C, but better in C++\n\n";
    
    SecretClass secret;
    secret.doSecretStuff();
    secret.doSecretStuff();
    
    std::cout << "\n   internalCounter = " << internalCounter << " (only this file can touch it)\n";
}

// ============================================================================
// PART 14: COMMON PITFALLS AND BEST PRACTICES
// ============================================================================

/**
 * Shows what to avoid and what to do instead
 */
void demonstrateBestPractices() {
    std::cout << "\n";
    std::cout << "╔════════════════════════════════════════════════════════════╗\n";
    std::cout << "║              PITFALLS & BEST PRACTICES                    ║\n";
    std::cout << "╚════════════════════════════════════════════════════════════╝\n";
    
    std::cout << "❌ COMMON MISTAKES:\n\n";
    
    // Pitfall 1: using namespace std
    std::cout << "1. 'using namespace std;' at top of file\n";
    std::cout << "   ⚠️ Problem: Pollutes global namespace\n";
    std::cout << "   ✅ Better: using std::cout; using std::string;\n";
    std::cout << "   ✅ Best: Explicitly write std:: every time\n\n";
    
    // Pitfall 2: Accidental name hiding
    std::cout << "2. Accidentally hiding variables\n";
    int data = 100;
    {
        int data = 200;  // Hides outer data - often unintentional
        data += 50;      // Modifies inner only
    }
    std::cout << "   ⚠️ Outer data still = " << data << " (not 250!)\n";
    std::cout << "   ✅ Use different names or avoid deep nesting\n\n";
    
    // Pitfall 3: Forgetting namespace qualification
    std::cout << "3. Forgetting to qualify namespace members\n";
    std::cout << "   ⚠️ Compiler error: 'version' is ambiguous\n";
    std::cout << "   ✅ Always use Mathematics::version or Database::version\n\n";
    
    // Pitfall 4: Overusing 'using' in headers
    std::cout << "4. Putting 'using' in header files\n";
    std::cout << "   ⚠️ Forces everyone including your header to use those names\n";
    std::cout << "   ✅ Never put 'using namespace' in headers!\n";
    std::cout << "   ✅ Put 'using' only in .cpp files\n";
}

// ============================================================================
// PART 15: COMPLETE REFERENCE TABLE
// ============================================================================

void showReferenceTable() {
    std::cout << "\n";
    std::cout << "╔════════════════════════════════════════════════════════════╗\n";
    std::cout << "║                 QUICK REFERENCE GUIDE                     ║\n";
    std::cout << "╠════════════════════════════════════════════════════════════╣\n";
    std::cout << "║  CONCEPT           │  SYNTAX            │  MEANING        ║\n";
    std::cout << "╠════════════════════┼════════════════════╼══════════════════╣\n";
    std::cout << "║  Global scope      │  ::variable        │  Access global  ║\n";
    std::cout << "║  Local scope       │  { int x; }        │  x only in {}   ║\n";
    std::cout << "║  Namespace member  │  Namespace::member │  Member from NS ║\n";
    std::cout << "║  Nested namespace  │  A::B::C::member   │  Deep access    ║\n";
    std::cout << "║  Using directive   │  using namespace N;│  All of N       ║\n";
    std::cout << "║  Using declaration │  using N::x;       │  Just x from N  ║\n";
    std::cout << "║  Type alias        │  using T = U;      │  T means U      ║\n";
    std::cout << "║  Anonymous NS      │  namespace { ... } │  File-private   ║\n";
    std::cout << "╚════════════════════┴════════════════════╧══════════════════╝\n";
}

// ============================================================================
// MAIN FUNCTION - ORCHESTRATES EVERYTHING IN LOGICAL ORDER
// ============================================================================

int main() {
    // Welcome banner
    std::cout << "\n";
    std::cout << "╔════════════════════════════════════════════════════════════════════╗\n";
    std::cout << "║                                                                            ║\n";
    std::cout << "║     C++ SCOPE, NAMESPACES & SCOPE RESOLUTION OPERATOR                    ║\n";
    std::cout << "║     Complete Guide - From Basics to Advanced                              ║\n";
    std::cout << "║                                                                            ║\n";
    std::cout << "╚════════════════════════════════════════════════════════════════════╝\n";
    
    // PART 1-2: Basic scope concepts
    globalAnnouncement();              // Show global function working
    demonstrateLocalScope();           // Local vs global
    demonstrateBlockScope();           // Nested blocks
    demonstrateNameHiding();           // Shadowing concept
    
    // PART 3: Scope resolution
    demonstrateScopeResolution();      // The :: operator
    
    // PART 4-5: Namespaces introduction and basics
    demonstrateNamespaceBasics();      // First look at namespaces
    
    // PART 6: Advanced namespace features
    demonstrateNestedNamespaces();     // Namespaces inside namespaces
    
    // PART 7: Standard library
    demonstrateStdNamespace();         // The all-important std namespace
    
    // PART 8: Using keyword variations
    demonstrateUsingKeyword();         // Different 'using' forms
    
    // PART 9-10: Real-world applications
    demonstrateRealWorldScenario();    // Practical library conflict
    demonstrateAnonymousNamespace();   // File-private code
    
    // PART 11: Best practices
    demonstrateBestPractices();        // What to avoid
    
    // PART 12: Reference
    showReferenceTable();              // Quick summary
    
    // Final output showing persistent effects
    std::cout << "\n";
    std::cout << "╔════════════════════════════════════════════════════════════════════╗\n";
    std::cout << "║                 FINAL STATISTICS                                    ║\n";
    std::cout << "╚════════════════════════════════════════════════════════════════════╝\n";
    std::cout << "Mathematics calculations: " << Mathematics::calculationCount << "\n";
    std::cout << "Database queries: " << Database::calculationCount << "\n";
    std::cout << "Global counter: " << globalCounter << "\n";
    std::cout << "Internal counter: " << internalCounter << "\n";
    
    std::cout << "\n╔════════════════════════════════════════════════════════════════════╗\n";
    std::cout << "║                 DEMONSTRATION COMPLETE                              ║\n";
    std::cout << "║     You now understand C++ scope, namespaces, and :: operator       ║\n";
    std::cout << "╚════════════════════════════════════════════════════════════════════╝\n\n";
    
    return 0;
}

// ============================================================================
// APPENDIX: GLOSSARY OF TERMS
// ============================================================================
/*
 * 📚 GLOSSARY:
 * 
 * SCOPE          : The region of code where a name is visible
 * GLOBAL SCOPE   : The outermost scope, visible everywhere
 * LOCAL SCOPE    : Scope inside a function, visible only there
 * BLOCK SCOPE    : Scope inside { }, visible only there
 * NAMESPACE      : A named container for declarations
 * ::             : Scope resolution operator - specifies which scope to use
 * NAME HIDING    : When an inner scope name hides an outer one
 * SHADOWING      : Same as name hiding
 * using directive : using namespace NS; - brings all names
 * using declaration : using NS::name; - brings one name
 * type alias     : using NewName = OldType; - creates a synonym
 * ANONYMOUS NAMESPACE : namespace { } - creates file-private scope
 * std            : The C++ Standard Library namespace
 */