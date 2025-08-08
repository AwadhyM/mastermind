#include "../include/computer.h"

#include <array>
#include <random>

#include "../include/feedbackPeg.h"

Computer::Computer() {};

std::array<CodePeg, 4> Computer::generateCode() const {
  std::array<CodePeg, 4> generatedCode{};
  for (auto &slot : generatedCode) {
    slot = Computer::gen();
  }
  return generatedCode;
}

CodePeg Computer::gen() {
  std::random_device rd;
  std::uniform_int_distribution<> uid(0, 3);
  CodePeg val = static_cast<CodePeg>(uid(rd));
  return val;
}

std::array<FeedbackPeg, 4>
Computer::generateFeedback(const std::array<CodePeg, 4> &code,
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
