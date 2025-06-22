#include "../include/board.h"
void Board::setGuess(std::array<CodePeg, 4> playerGuess) {
  guess = playerGuess;
};

std::array<CodePeg, 4> Board::getGuess() const { return guess; }
void Board::setfeedback(std::array<FeedbackPeg, 4> val) { feedback = val; };
