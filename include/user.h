#include <array>

#include "codePeg.h"

// TODO - For future work - Have this be a virtual class. Create a User and
// Opponent class

class User {
public:
  User() {};
  std::array<CodePeg, 4> makeGuess() const;
  CodePeg guessCodePeg() const;

private:
};
