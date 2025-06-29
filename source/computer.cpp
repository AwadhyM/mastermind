#include "../include/computer.h"
#include "../include/feedbackPeg.h"
#include <algorithm>
#include <random>

std::array<CodePeg, 4> Computer::getCode() const { return code; }

Computer::Computer() { generateCode(); }

void Computer::generateCode() {
  std::array<CodePeg, 4> generatedCode{};
  for (auto &slot : generatedCode) {
    slot = Computer::gen();
  }
  code = generatedCode;
}

CodePeg Computer::gen() {
  std::random_device rd;
  std::uniform_int_distribution<> uid(0, 3);
  CodePeg val = static_cast<CodePeg>(uid(rd));
  return val;
}

std::array<FeedbackPeg, 4>
Computer::generateFeedback(const std::array<CodePeg, 4> &guess) const {
  // Iterate through each array of guess
  std::array<FeedbackPeg, 4> feedback{};
  for (int i = 0; i < 4; i++) {
    if (guess[i] == code[i]) {
      // Correct color in the correct position
      feedback[i] = FeedbackPeg::Green;
    } else if (std::find(code.begin(), code.end(), guess[i]) != code.end()) {
      // Correct color but incorrect positon
      feedback[i] = FeedbackPeg::White;
    } else {
      // Color is no where to be seen in the code
      feedback[i] = FeedbackPeg::Red;
    }
  }
  return feedback;
}
