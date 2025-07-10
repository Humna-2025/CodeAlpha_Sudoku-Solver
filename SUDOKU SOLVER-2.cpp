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
