#include "../include/board.h"
void Board::setGuess(std::array<CodePeg, 4> playerGuess) {
  guess = playerGuess;
};

std::array<CodePeg, 4> Board::getGuess() const { return guess; }
