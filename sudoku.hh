#pragma once

#include <array>
#include <cstddef>
#include <iostream>
#include <utility>

#define LENGTH 9
#define WIDTH 9

class SudokuTable {

private:

  static std::pair<std::size_t, std::size_t> find_empty_coordinates(std::array<char, LENGTH * WIDTH> &table) {
    for (std::size_t i = 0; i < LENGTH; ++i)
      for (std::size_t j = 0; j < WIDTH; ++j) {
        const auto index = get_one_dimensional_index(i, j);

        if (table[index] == '0')
          return {i, j};
      }

    return { LENGTH, WIDTH };
  }

  static std::size_t get_one_dimensional_index(std::size_t i, std::size_t j) {
    return i * WIDTH + j;
  };

  
  static bool is_valid(const std::array<char, LENGTH*WIDTH> &table, const char value,
                      const std::pair<std::size_t, std::size_t> &coordinates)
  {
    for(std::size_t i = 0; i < LENGTH; ++i) {
      if(table[get_one_dimensional_index(i, coordinates.second)] == value) {
        return false;
      }
    }

    for(std::size_t j = 0; j < WIDTH; ++j) {
      if(table[get_one_dimensional_index(coordinates.first, j)] == value) {
        return false;
      }
    }
  
    std::size_t x =  (coordinates.first / 3) * 3;
    std::size_t y =  (coordinates.second / 3) * 3;

    for(std::size_t i = x; i < x + 3; ++i) {
      for(std::size_t j = y; j < y + 3; ++j) {
        if(table[get_one_dimensional_index(i, j)] == value) {
          return false;
        }
      }
    }
  
    return true;
  }

public:
  /// @brief Gets an sodoku table and solves it.
  /// @param A std::array representing sudoku table
  /// @return A boolean value representing whether table has been solved or not.
  static bool solve(std::array<char, LENGTH * WIDTH> &table) {
    const auto empty_block_coordinates = find_empty_coordinates(table);

    if (empty_block_coordinates.first == LENGTH && empty_block_coordinates.second == WIDTH)
      return true; // There is no more empty block

    for (char value = '1'; value <= '9'; ++value)
      if (is_valid(table, value, empty_block_coordinates)) {
        table[get_one_dimensional_index(empty_block_coordinates.first, empty_block_coordinates.second)] = value;

        if(solve(table))
          return true;

        table[get_one_dimensional_index(empty_block_coordinates.first, empty_block_coordinates.second)] = '0';
      }
    
    return false;
  }

  /// @brief Prints the sudoku table on stdout
  /// @param A std::array representing sudoku table
  static void print(const std::array<char, LENGTH * WIDTH> &table) {
    for (std::size_t i = 0; i < LENGTH; ++i) {
      for (std::size_t j = 0; j < WIDTH; ++j) {
        const auto output = table[i * WIDTH + j] != '0' ? table[i * WIDTH + j] : ' ';
        std::cout << output << " | ";
      }
      std::cout << '\n';
    }
  }
};