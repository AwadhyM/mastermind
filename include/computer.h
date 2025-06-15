#pragma once
#include "colorPeg.h"
#include <array>

constexpr int codeLength = 4; // TODO move to game class?

/**
 * @class Computer
 * @brief Represents a computer player that generates a random code of color pegs.
 */
class Computer {
public:
  /**
   * @brief Constructs a Computer object and generates a random code.
   */
  Computer();

  /**
   * @brief Generates a single random ColorPeg.
   * @return A randomly generated ColorPeg.
   */
  static ColorPeg gen();

  /**
   * @brief The generated code consisting of a fixed-length array of ColorPegs.
   */
  std::array<ColorPeg, codeLength> code;

private:
  /**
   * @brief Generates a random code of ColorPegs.
   * @return An array of ColorPegs representing the code.
   */
  std::array<ColorPeg, codeLength> generateCode();

  /**
   * @brief Prints the current code to the standard output.
   */
  void printCode() const;
};
