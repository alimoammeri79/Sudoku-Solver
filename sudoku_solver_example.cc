/**
 * @file sudoku_solver_example.cpp
 * 
 * @brief An example to use SudokuTable class in action.
 */
#include <iostream>
#include "sudoku.hh"

int main() {
  std::array<char, 9*9> table{'0', '9', '1', '0', '6', '0', '7', '0', '0',
                              '0', '0', '0', '0', '8', '2', '0', '3', '9',
                              '5', '0', '3', '0', '0', '0', '2', '0', '0',
                              '0', '0', '0', '9', '1', '3', '0', '6', '2',
                              '0', '0', '2', '4', '0', '6', '8', '0', '0',
                              '1', '4', '0', '8', '2', '5', '0', '0', '0',
                              '0', '0', '9', '0', '0', '0', '5', '0', '7',
                              '6', '7', '0', '1', '5', '0', '0', '0', '0',
                              '0', '0', '5', '0', '4', '0', '6', '9', '0'};

  if(SudokuTable::solve(table))
    SudokuTable::print(table);

  return 0;
}
