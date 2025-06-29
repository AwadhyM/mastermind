#include "../include/board.h"
#include <iostream>

void Board::addGuess(const std::array<CodePeg, 4> &roundGuess) {
  guess.push_back(roundGuess);
}

void Board::addFeedback(const std::array<FeedbackPeg, 4> &roundFeedback) {
  feedback.push_back(roundFeedback);
}

void Board::addRound(const std::array<CodePeg, 4> &roundGuess,
                     const std::array<FeedbackPeg, 4> &roundFeedback) {
  addGuess(roundGuess);
  addFeedback(roundFeedback);
}

const std::array<CodePeg, 4> Board::getGuessForRound(int round) const {
  return guess[round];
}

const std::array<FeedbackPeg, 4> Board::getFeedbackForRound(int round) const {
  return feedback[round];
}

void Board::render() {
  std::cout << "| Code       | Feedback\n";
  std::cout << "--------------------------\n";
  // We want to iterate the details of each round
  std::cout << "| ";
  for (int i = 0; i < guess.size(); i++) {
    // Print Each entered code
    for (const auto &code : guess[i]) {
      std::cout << toAnsi(code) << " ";
    }

    // Print each feedback peg
    std::cout << "   | ";
    for (const auto &fb : feedback[i]) {
      std::cout << toAnsi(fb) << " ";
    }
  }
  std::cout << "\n";
}
