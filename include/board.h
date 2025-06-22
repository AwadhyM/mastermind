#include "../include/codePeg.h"
#include "../include/feedbackPeg.h"
#include <array>

class Board {
public:
  void setGuess(std::array<CodePeg, 4> playerGuess);

private:
  std::array<CodePeg, 4> guess{};
};
