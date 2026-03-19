```markdown
# Multidimensional Arrays in C++ – Quick Reference

Multidimensional arrays let you store data in a grid-like structure (tables, matrices, volumes, etc.).

## 1. Declaration & Basic Syntax

Fixed-size arrays (size must be known at compile time):

```cpp
// 2D – most common
int matrix[ROWS][COLS];                // e.g. int board[3][3];

// 3D
double volume[LAYERS][ROWS][COLS];     // e.g. double cube[2][5][5];

// 4D (very rare in beginner code)
float tensor[BATCH][CHANNELS][H][W];
```

## 2. Initialization Examples

```cpp
// 2D – row-major order (rows first)
int grades[2][3] = {
    {85, 92, 78},      // student 0
    {64, 91, 88}       // student 1
};

// Can omit inner braces if filling sequentially (but less readable)
int seq[2][3] = {85, 92, 78, 64, 91, 88};

// 3D example
int cube[2][2][3] = {
    { {1,2,3}, {4,5,6} },     // layer 0
    { {7,8,9}, {10,11,12} }   // layer 1
};
```

## 3. Accessing Elements

Always: **outermost dimension first**

```cpp
matrix[row][col]          // 2D
volume[layer][row][col]   // 3D
tensor[b][c][h][w]        // 4D
```

## 4. Looping Patterns (Nested Loops)

Classic pattern: outermost loop = first index, innermost = last index

```cpp
// 2D – rows then columns
for(int r = 0; r < ROWS; r++) {
    for(int c = 0; c < COLS; c++) {
        std::cout << matrix[r][c] << " ";
    }
    std::cout << '\n';
}

// 3D – layers → rows → columns
for(int z = 0; z < LAYERS; z++) {
    std::cout << "Layer " << z << ":\n";
    for(int y = 0; y < ROWS; y++) {
        for(int x = 0; x < COLS; x++) {
            std::cout << volume[z][y][x] << "\t";
        }
        std::cout << '\n';
    }
    std::cout << "------------------------\n";
}
```

## 5. Common Real-World Uses

| Dimensions | Typical Name       | Typical Uses (beginner → intermediate)                  |
|------------|--------------------|----------------------------------------------------------|
| 1D         | array / list       | scores, names, temperatures                              |
| 2D         | matrix / table     | tic-tac-toe, chessboard, gradebook, pixel grid (image)   |
| 3D         | volume / cube      | voxel terrain, RGB image + depth, simple 3D grid         |
| 4D+        | tensor / hypercube | image batches (ML), spacetime grids, rarely hand-written |

## 6. Modern & Recommended Alternatives (C++11+)

Raw multidimensional arrays have many limitations (fixed size, no bounds checking, manual memory management).

Better choices in most real programs:

```cpp
#include <vector>
#include <array>

// Dynamic 2D (jagged possible)
std::vector<std::vector<int>> dynamicGrid(rows, std::vector<int>(cols));

// Fixed-size, safer (stack or member variable)
#include <array>
std::array<std::array<int, COLS>, ROWS> safeGrid{};

// Flattened 1D – often fastest (great cache locality)
int flat[ROWS * COLS];
int& at(int r, int c) { return flat[r * COLS + c]; }
// usage: at(2, 3) = 99;
```

## 7. Quick Rules of Thumb

- Use **2D arrays** freely in small learning projects  
- Prefer **std::vector** when size is runtime or can change  
- Use **flattened 1D + math** when performance matters  
- Avoid raw **3D+ arrays** unless the problem clearly requires them  
- For serious math/graphics/ML → use libraries (Eigen, GLM, OpenCV, xtensor, etc.)  
- Cache performance tip: innermost loop should vary the **last index** (column-major in math, but row-major is C++ default)

Last updated style: friendly for C++11 – C++20  
Happy coding!
```

You can now save the entire block above (starting from the first `#` line) into a `.md` file.

Let me know if you want to add sections (performance comparison, common pitfalls, more examples, etc.).