#pragma once
#include <array>

#include "codePeg.h"
#include "feedbackPeg.h"

/**
 * @class Computer
 * @brief Represents a computer player that generates a random code of color
 * pegs.
 */
class Computer {
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
  void generateCode();

  /**
   * @brief Generates feedback based on other players guess
   * @return An array of FeedbackPegs representing the code.
   */
  std::array<FeedbackPeg, 4>
  generateFeedback(const std::array<CodePeg, 4> &guess) const;

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
