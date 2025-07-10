# CodeAlpha_Sudoku-Solver

✅ Overview
=
This program solves a standard 9×9 Sudoku puzzle using backtracking — a depth-first search algorithm that tries numbers, and backtracks when it encounters a dead end.

The solution is encapsulated in a single class SudokuSolver for encapsulation & modularity.

🔷 Components
=
1️⃣ Includes & Namespace
=
Standard C++ input-output library for cout, endl.

Use std namespace for convenience.

🔷 Class: SudokuSolver
=
Holds the puzzle and solving logic.

🔷 Private Members
=
int grid[9][9]
Stores the current state of the Sudoku board.
0 represents an empty cell.

🔷 Private Methods
=
a) canPlaceNumber(int row, int col, int number)
Checks if number can be placed at position (row, col) without violating Sudoku rules:

Checks row.

Checks column.

Checks 3×3 box.

b) findEmptyCell(int &row, int &col)
Finds the next empty cell (with 0) and assigns its coordinates to row & col.
Returns true if found, false if puzzle is full (solved).

🔷 Public Methods
=
a) Constructor

SudokuSolver(int startingPuzzle[9][9])

b) solve()
Recursive backtracking:

If no empty cell → puzzle is solved → return true.

Try numbers 1–9 in empty cell:

If number is valid → place it & call solve() recursively.

If recursive call fails → reset cell to 0 and try next number.

If no number works → return false.

c) show()
Prints the current board state in a neat format:

Draws lines every 3 rows & columns for 3×3 boxes.

🔷 main() Function
=
Steps:
Defines the initial puzzle as a 2D array (0 = blank cell).

Creates a SudokuSolver object with the puzzle.

Prints the starting puzzle.

Calls solve():

If solved → prints solution.

If no solution → prints error message.

🧩 Algorithm
=
The algorithm is a classic backtracking algorithm:

Choose an empty cell.

Try placing each number 1–9 in it.

If valid, recurse.

If not valid, or future steps fail, undo & try next.

🖋️ Sample Output:
=

Starting Puzzle:
-------------------------
| 5 3 0 | 0 7 0 | 0 0 0 | 
| 6 0 0 | 1 9 5 | 0 0 0 | 
...
-------------------------

Solution Found:
-------------------------
| 5 3 4 | 6 7 8 | 9 1 2 | 
| 6 7 2 | 1 9 5 | 3 4 8 | 
...
-------------------------

🔷 Key OOP Principles:
=
Encapsulation: Board and logic are encapsulated in SudokuSolver.

Abstraction: User only interacts with solve() and show(), hiding details.

Could extend further to show inheritance or polymorphism if needed.

🧹 Improvements Possible:
=
Add input validation.

Make it work for puzzles of different sizes (like 4×4 or 16×16).

Count number of solutions.

Add a GUI for interactive play.


CODE
=

                                #include <iostream>
                                using namespace std;

                                class SudokuSolver {
                                private:
                                int grid[9][9];

                                bool canPlaceNumber(int row, int col, int number) {
                                for(int x = 0; x < 9; x++) {
                                if(grid[row][x] == number) {
                                return false;
                                }
                                }

                                for(int x = 0; x < 9; x++) {
                                if(grid[x][col] == number) {
                                return false;
                                }
                                }

                                int boxStartRow = (row / 3) * 3;
                                int boxStartCol = (col / 3) * 3;

                                for(int i = 0; i < 3; i++) {
                                for(int j = 0; j < 3; j++) {
                                if(grid[boxStartRow + i][boxStartCol + j] == number) {
                                return false;
                                }
                                }
                                }

                                return true;
                                }

                                bool findEmptyCell(int &row, int &col) {
                                for(row = 0; row < 9; row++) {
                                for(col = 0; col < 9; col++) {
                                if(grid[row][col] == 0) {
                                return true;
                                }
                                }
                                }
                                return false;
                                }

                                 public:
                                SudokuSolver(int startingPuzzle[9][9]) {
                                for(int i = 0; i < 9; i++) {
                                for(int j = 0; j < 9; j++) {
                                grid[i][j] = startingPuzzle[i][j];
                                }
                                }
                                }

                                bool solve() {
                                int row, col;

                                if(!findEmptyCell(row, col)) {
                                return true;
                               }

                               for(int num = 1; num <= 9; num++) {
                               if(canPlaceNumber(row, col, num)) {
                               grid[row][col] = num;

                               if(solve()) {
                               return true;
                               }

                               grid[row][col] = 0;
                               }
                               }
                               return false;
                               }

                               void show() {
                               cout << "\n-------------------------" << endl;
                               for(int i = 0; i < 9; i++) {
                               cout << "| ";
                               for(int j = 0; j < 9; j++) {
                               cout << grid[i][j] << " ";
                               if((j + 1) % 3 == 0) {
                               cout << "| ";
                               }
                               }
                               cout << endl;
                               if((i + 1) % 3 == 0) {
                               cout << "-------------------------" << endl;
                               }
                               }
                               }
                               };

                               int main() {
                               int puzzle[9][9] = {
                               {5, 3, 0, 0, 7, 0, 0, 0, 0},
                               {6, 0, 0, 1, 9, 5, 0, 0, 0},
                               {0, 9, 8, 0, 0, 0, 0, 6, 0},

                               {8, 0, 0, 0, 6, 0, 0, 0, 3},
                               {4, 0, 0, 8, 0, 3, 0, 0, 1},
                               {7, 0, 0, 0, 2, 0, 0, 0, 6},

                               {0, 6, 0, 0, 0, 0, 2, 8, 0},
                               {0, 0, 0, 4, 1, 9, 0, 0, 5},
                               {0, 0, 0, 0, 8, 0, 0, 7, 9}
                               };

                               SudokuSolver solver(puzzle);
                               cout << "\nStarting Puzzle:" << endl;
                               solver.show();

                              if(solver.solve()) {
                              cout << "\nSolution Found:" << endl;
                              solver.show();
                              } else {
                              cout << "\nNo solution exists!" << endl;
                              }

                             return 0;
                              }


OUTPUT
=
                              Starting Puzzle:

                              -------------------------
                              | 5 3 0 | 0 7 0 | 0 0 0 |
                              | 6 0 0 | 1 9 5 | 0 0 0 |
                              | 0 9 8 | 0 0 0 | 0 6 0 |
                              -------------------------
                              | 8 0 0 | 0 6 0 | 0 0 3 |
                              | 4 0 0 | 8 0 3 | 0 0 1 |
                              | 7 0 0 | 0 2 0 | 0 0 6 |
                              -------------------------
                              | 0 6 0 | 0 0 0 | 2 8 0 |
                              | 0 0 0 | 4 1 9 | 0 0 5 |
                              | 0 0 0 | 0 8 0 | 0 7 9 |
                              -------------------------

                              Solution Found:

                              -------------------------
                              | 5 3 4 | 6 7 8 | 9 1 2 |
                              | 6 7 2 | 1 9 5 | 3 4 8 |
                              | 1 9 8 | 3 4 2 | 5 6 7 |
                              -------------------------
                              | 8 5 9 | 7 6 1 | 4 2 3 |
                              | 4 2 6 | 8 5 3 | 7 9 1 |
                              | 7 1 3 | 9 2 4 | 8 5 6 |
                              -------------------------
                              | 9 6 1 | 5 3 7 | 2 8 4 |
                              | 2 8 7 | 4 1 9 | 6 3 5 |
                              | 3 4 5 | 2 8 6 | 1 7 9 |
                              -------------------------
