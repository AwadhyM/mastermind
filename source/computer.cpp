#include "../include/computer.h"

#include <algorithm>
#include <random>

#include "../include/feedbackPeg.h"

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
  std::array<FeedbackPeg, 4> feedback{};
  std::array<bool, 4> codeUsed{};
  std::array<bool, 4> guessUsed{};

  int blackCount = 0;
  int whiteCount = 0;

  // count black pegs (correct colour and position)
  for (int i = 0; i < 4; ++i) {
    if (guess[i] == code[i]) {
      blackCount++;
      codeUsed[i] = true;
      guessUsed[i] = true;
    }
  }

  // count white pegs (correct colour, wrong position)
  for (int i = 0; i < 4; ++i) {
    if (guessUsed[i])
      continue;
    for (int j = 0; j < 4; ++j) {
      if (!codeUsed[j] && guess[i] == code[j]) {
        whiteCount++;
        codeUsed[j] = true;
        guessUsed[i] = true;
        break;
      }
    }
  }

  // Fill feedback array: Greens first, then Whites, then Reds
  int index = 0;
  for (int i = 0; i < blackCount; ++i)
    feedback[index++] = FeedbackPeg::Green;
  for (int i = 0; i < whiteCount; ++i)
    feedback[index++] = FeedbackPeg::White;

  return feedback;
}
