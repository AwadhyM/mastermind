#pragma once
#include "codePeg.h"
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
   * @brief Generates a random code of CodePegs.
   * @return An array of CodePegs representing the code.
   */
  std::array<CodePeg, 4> generateCode();

  std::array<CodePeg, 4> getCode() const;

private:
  /**
   * @brief Generates a single random CodePeg.
   * @return A randomly generated CodePeg.
   */
  static CodePeg gen();

  /**
   * @brief The generated code consisting of a fixed-length array of CodePegs.
   */
  std::array<CodePeg, 4> code;
};
