#include <iostream>

int main()
{
    // =====================================================================
    // OPERATOR PRECEDENCE = which operator is evaluated FIRST
    // ASSOCIATIVITY   = when same precedence → which direction (left→right or right→left)
    // =====================================================================

    int a = 10, b = 4, c = 2;

    // ---------------------------------------------------------------
    // Precedence: * / %   are HIGHER than   + -
    // ---------------------------------------------------------------
    std::cout << "10 + 4 * 2   = " << (10 + 4 * 2)   << "   // * first → 10 + 8 = 18\n";
    std::cout << "(10 + 4) * 2 = " << ((10 + 4) * 2) << "   // () forces + first\n\n";

    // ---------------------------------------------------------------
    // Left-to-right associativity (most common: + - * / % << >> & ^ |)
    // ---------------------------------------------------------------
    std::cout << "20 - 8 + 3   = " << (20 - 8 + 3)   << "   // (20-8) first, then +3 → 15\n";
    std::cout << "100 / 10 / 5 = " << (100 / 10 / 5) << "   // (100/10) first, then /5 → 2\n\n";

    // ---------------------------------------------------------------
    // Right-to-left associativity (important for: = += -= *= /= %= ++ -- unary + - ! ~)
    // ---------------------------------------------------------------
    int x = 5, y = 0, z = 0;
    z = y = x = 42;           // right-to-left: x=42 first, then y gets x's value, then z gets y's value
    std::cout << "z = y = x = 42  →  x:" << x << " y:" << y << " z:" << z << "\n\n";

    // ---------------------------------------------------------------
    // Unary operators (++, --, -, !, ~) → right-to-left
    // ---------------------------------------------------------------
    int n = 10;
    std::cout << "- - n   = " << - -n << "   // right-to-left: first -n → -10, then -(-10) → 10\n";

    int m = 5;
    std::cout << "++ -- m   → undefined behavior! Never mix like ++m-- or m++ + ++m\n\n";

    // ---------------------------------------------------------------
    // Logical && and || → left-to-right + short-circuit
    // ---------------------------------------------------------------
    bool p = true, q = false, r = true;
    std::cout << "p || q && r   = " << (p || q && r) << "   // && higher → p || (q && r) → true || false → true\n";

    int val = 0;
    std::cout << "(val != 0) && (100 / val > 0)   → safe because of short-circuit\n";
    // if val == 0 → first part false → second part NOT evaluated → no division by zero

    // ---------------------------------------------------------------
    // Assignment = has very LOW precedence → almost last
    // ---------------------------------------------------------------
    int result;
    std::cout << "result = 5 + 3 * 2   → " << (result = 5 + 3 * 2) << "   // * first, then = \n";

    // Very common mistake:
    std::cout << "a == b = c   is   a == (b = c)   NOT   (a == b) = c\n";
    // (a == b) = c  → error (cannot assign to temporary/rvalue)

    // ---------------------------------------------------------------
    // Best rule ever: USE PARENTHESES when mixing operators
    // ---------------------------------------------------------------
    std::cout << "\nAlways safe:   ((a + b) * c - d) / e\n";

    std::cout << "\nQuick reminder table inside comments:\n";
    // Highest ────────────────────────────────────────────────
    // ++ -- (post)  ()  []  .  -> 
    // ++ -- + - ! ~ (pre)  * & (address)  sizeof  new  delete
    // * / %
    // + -
    // << >>
    // < <= > >=
    // == !=
    // &   (bitwise)
    // ^ 
    // | 
    // && 
    // || 
    // ?:   (ternary)
    // = += -= *= /= %= <<= >>= &= ^= |=    ← lowest (right-to-left)
    // ,   (comma operator)
    // ───────────────────────────────────────────────────────────

    return 0;
}