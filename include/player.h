#include "../include/codePeg.h"
#include <array>

// TODO - For future work - Have this be a virtual class. Create a User and
// Opponent class

class Player {
public:
  Player() {};
  std::array<CodePeg, 4> makeGuess();
  CodePeg guessCodePeg();
  void guessEntryMessage(int codePart);

private:
};
