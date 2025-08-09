#pragma once
#include <array>

#include "codePeg.h"
#include "playerBase.h"

/**
 * @class Computer
 * @brief Represents a computer player that generates a random code of color
 * pegs.
 */
class Computer : public PlayerBase {
public:
  /**
   * @brief Constructs a Computer object and generates a random code.
   */
  Computer();

  /**
   * @brief Generates a random code of CodePegs that the other player is
   * required to guess.
   * @return An array of CodePegs representing the code.
   */
  std::array<CodePeg, 4> generateCode() const override;

  std::array<CodePeg, 4> makeGuess() const override;

private:
  /**
   * @brief Generates a single random CodePeg.
   * @return A randomly generated CodePeg.
   */
  static CodePeg gen();
};
