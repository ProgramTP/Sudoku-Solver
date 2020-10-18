

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int checker = 0;

void print_sudoku(int sudoku[9][9])
{
  printf("The Sudoku contains:\n");
  for (int j=0; j<9; j++)
  {
    for (int i=0; i<9;i++)
    {
      printf("%d  ",sudoku[j][i]);
    }
    printf("\n");
  }
}

int check_sudoku(int sudoku[9][9])
{
  /*
   *  This function checks whether a Sudoku is properly
   * solved. That means that each row, column, and
   * 3x3 subgrid uses each digit only once.
   * 
   *  If *ignores* zeros, so you can use it to check
   * that a partial solution is valid
   */
  
  /*****
   * TO DO:
   * Complete this function
   *   -- BUT ONLY IF YOU WANT TO!
   * Our testing script only checks your Sudoku
   * solution, if you want to solve it without
   * using this function, or if you want to write
   * your own helper functions, that's ok!
   * *****/
   return 0;  
}

int solved(int sudoku[9][9])
{
  /*
   * This function checks whether a given Sudoku is
   * completely solved (it has no zeros, all digits
   * are used once per row, column, and sub-grid.
   * It returns 1 if the Sudoku is solved, zero
   * otherwise
   */
  
  /*****
   * TO DO
   * Complete this function
   * BUT ONLY IF YOU WANT TO!
   *   You can solve the Sudoku without using this function,
   * or you can write a different helper function, whatever
   * makes more sense to yoU! our checker won't look at this
   * function, 
   * ****/
   return 0;  
}

int row_check(int sudoku[9][9], int row_index, int value){
  for (int i = 0; i < 9; i++){
    if (sudoku[row_index][i] == value){
      return 0;
    }
  }
  return 1;
}

int col_check(int sudoku[9][9], int col_index, int value){
  for (int i = 0; i < 9; i++){
    if (sudoku[i][col_index] == value){
      return 0;
    }
  }
  return 1;
}

int box_check(int sudoku[9][9], int col_start, int row_start, int value){
  for (int i = 0; i < 3; i++){
    for (int j = 0; j < 3; j++){
      if (sudoku[row_start+i][col_start+j] == value){
        return 0;
      }
    }
  }
  return 1;
}

int check(int sudoku[9][9], int col_index, int row_index, int value){
  int a,b,c;
  a = row_check(sudoku, row_index, value);
  b = col_check(sudoku, col_index, value);
  c = box_check(sudoku, (col_index - col_index%3), (row_index - row_index%3), value);
  if (a == 1 && b == 1 && c == 1){
    return 1;
  }
  return 0;
}

int completed(int sudoku[9][9]){
  for (int i = 0; i < 9; i++){
    for (int j = 0; j < 9; j++){
      if (sudoku[i][j] == 0){
        return 0;
      }
    }
  }
  return 1;
}

void solve_sudoku(int sudoku[9][9], int depth)
{
  /*
   * This function solves an input Sudoku, the
   * input has a value of 0 for any entries that
   * are not yet decided. If no solution exists
   * the function returns the input array *exactly
   * as it was* when the function was called.
   * 
   * The 'depth' parameter is provided in case you
   * want to use it to help debug and trace your
   * code. You do not need to use it if you don't
   * want to, and the problem can be solved without
   * using the depth value at all. 
   * 
   * The automated checker won't look at the depth
   * either.
   */
  
  /*****
   * TO DO:
   * Complete this function
   *****/

  for (int i = 0; i < 9; i++){
    for (int j = 0; j < 9; j++){
      if (sudoku[i][j] == 0){
        for (int k = 9; k > 0; k--){
          if (check(sudoku, j, i, k) == 1){
            sudoku[i][j] = k;
            solve_sudoku(sudoku, depth+1);
            if (completed(sudoku) != 1){
              sudoku[i][j] = 0;  
            }
          }
        }
        return;
       }
     }
   }
}

#ifndef __testing

int main()
{
   // We'll provide you with the same test case
   // from the Wiki, so you can check your output.
   // But as always, be aware we will test your
   // solution on different Sudoku puzzles.
  
   int Sudoku[9][9]={{5, 3, 0, 0, 7, 0, 0, 0, 0},
		     {6, 0, 0, 1, 9, 5, 0, 0, 0},
		     {0, 9, 8, 0, 0, 0, 0, 6, 0},
		     {8, 0, 0, 0, 6, 0, 0, 0, 3},
		     {4, 0, 0, 8, 0, 3, 0, 0, 1},
		     {7, 0, 0, 0, 2, 0, 0, 0, 6},
		     {0, 6, 0, 0, 0, 0, 2, 8, 0},
		     {0, 0, 0, 4, 1, 9, 0, 0, 5},
		     {0, 0, 0, 0, 8, 0, 0, 7, 9}};

  printf("Input puzzle is:\n");
  print_sudoku(Sudoku);
  
  solve_sudoku(Sudoku,0);
  
  printf("Solution is:\n");
  print_sudoku(Sudoku);
  
}

#endif
