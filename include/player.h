#include "../include/codePeg.h"
#include <array>

// TODO - For future work - Have this be a virtual class. Create a User and
// Opponent class

class Player {
public:
  Player() {};
  std::array<CodePeg, 4> makeGuess() const;
  CodePeg guessCodePeg() const;
  void guessEntryMessage(int codePart) const;

private:
};
