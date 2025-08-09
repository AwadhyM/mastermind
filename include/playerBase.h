#pragma once
#include "codePeg.h"
#include "feedbackPeg.h"
class PlayerBase {
public:
  virtual std::array<CodePeg, 4> makeGuess() const = 0;
  virtual std::array<CodePeg, 4> generateCode() const = 0;

  /**
   * @brief Generates feedback based on other players guess
   * @return An array of FeedbackPegs representing the code.
   */
  std::array<FeedbackPeg, 4>
  generateFeedback(const std::array<CodePeg, 4> &code,
                   const std::array<CodePeg, 4> &guess) const;
};
