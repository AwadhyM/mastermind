#include "../include/codePeg.h"
#include "../include/feedbackPeg.h"
#include <array>

class Board {
public:
  void setGuess(std::array<CodePeg, 4> playerGuess);
  std::array<CodePeg, 4> getGuess() const;

private:
  std::array<CodePeg, 4> guess{};
  std::array<FeedbackPeg, 4> feedback{};
};
