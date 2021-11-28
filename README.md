# Sudoku_backtracking
Sudoku game by backtracking algorithm by c++ language
Given a partially filled 9×9 2D array ‘grid[9][9]’, 
the goal is to assign digits (from 1 to 9) to the empty cells so that every row, column, and subgrid of size 3×3 contains exactly one instance of the digits from 1 to 9.

1)Create a function that checks if the given matrix is valid sudoku or not. Keep Hashmap for the row, column and boxes. 
If any number has a frequency greater than 1 in the hashMap return false else return true;

2)Create a recursive function that takes a grid and the current row and column index.

3)Check some base cases. If the index is at the end of the matrix, i.e. i=N-1 and j=N then check if the grid is safe or not, if safe print the grid and return true else return false. 
The other base case is when the value of column is N, i.e j = N, then move to next row, i.e. i++ and j = 0.

4)if the current index is not assigned then fill the element from 1 to 9 and recur for all 9 cases with the index of next element, i.e. i, j+1. if the recursive call returns true then break the loop and return true.

5)if the current index is assigned then call the recursive function with index of next element, i.e. i, j+1
