#pragma once
#include "colorPeg.h"
#include <vector>

/**
 * @class Computer
 * @brief Represents a computer player that generates a random code of color
 * pegs.
 */
class Computer {
public:
  int codeLength;
  /**
   * @brief Constructs a Computer object and generates a random code.
   */
  Computer(int codeLength);

  /**
   * @brief Generates a random code of ColorPegs.
   * @return An array of ColorPegs representing the code.
   */
  std::vector<ColorPeg> generateCode();

  /**
   * @brief Generates a single random ColorPeg.
   * @return A randomly generated ColorPeg.
   */
  static ColorPeg gen();

  /**
   * @brief The generated code consisting of a fixed-length array of ColorPegs.
   */
  std::vector<ColorPeg> code;

private:
  /**
   * @brief Prints the current code to the standard output.
   */
  void printCode() const;
};
