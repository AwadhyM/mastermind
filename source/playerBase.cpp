#include "playerBase.h"

std::array<FeedbackPeg, 4>
PlayerBase::generateFeedback(const std::array<CodePeg, 4> &code,
                           const std::array<CodePeg, 4> &guess) const {
  std::array<FeedbackPeg, 4> feedback{};
  std::array<bool, 4> code_used{};
  std::array<bool, 4> guess_used{};

  for (int i = 0; i < feedback.size(); ++i) {
    if (guess[i] == code[i]) {
      feedback[i] = FeedbackPeg::Green;
      code_used[i] = true;
      guess_used[i] = true;
    } else {
      feedback[i] = FeedbackPeg::Red;
    }
  }

  for (int i = 0; i < feedback.size(); ++i) {
    if (guess_used[i])
      continue;

    for (int j = 0; j < guess.size(); ++j) {
      if (!code_used[j] && guess[i] == code[j]) {
        feedback[i] = FeedbackPeg::White;
        code_used[j] = true;
        guess_used[i] = true;
        break;
      }
    }
  }

  return feedback;
}
