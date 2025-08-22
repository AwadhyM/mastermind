#include "playerBase.h"

#include <vector>

std::array<FeedbackPeg, 4>
PlayerBase::generateFeedback(const std::array<CodePeg, 4> &code,
                             const std::array<CodePeg, 4> &guess) const {
  std::vector<FeedbackPeg> feedback;
  feedback.reserve(4);

  std::array<int, 4> code_count{};  // count of each color in the code
  std::array<int, 4> guess_count{}; // count of each color in the guess

  int green_count = 0;

  // First pass: count exact matches (green) and build frequency for others
  for (int i = 0; i < 4; ++i) {
    if (guess[i] == code[i]) {
      green_count++;
    } else {
      code_count[static_cast<int>(code[i])]++;
      guess_count[static_cast<int>(guess[i])]++;
    }
  }

  // Second pass: count color-only matches (white)
  int white_count = 0;
  for (int color = 0; color < 4; ++color) {
    white_count += std::min(code_count[color], guess_count[color]);
  }

  feedback.insert(feedback.end(), green_count, FeedbackPeg::Green);
  feedback.insert(feedback.end(), white_count, FeedbackPeg::White);
  feedback.insert(feedback.end(), 4 - green_count - white_count,
                  FeedbackPeg::Red);

  std::array<FeedbackPeg, 4> feedback_array{};
  std::copy(feedback.begin(), feedback.end(), feedback_array.begin());

  return feedback_array;
}
