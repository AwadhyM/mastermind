#include <array>

#include "codePeg.h"
#include "playerBase.h"

class User : public PlayerBase {
public:
  User() {};
  std::array<CodePeg, 4> makeGuess() const override;
  std::array<CodePeg, 4> generateCode() const override;

private:
  CodePeg guessCodePeg() const;
};

