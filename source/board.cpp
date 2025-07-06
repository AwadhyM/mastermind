#include <iostream>
#include "../include/board.h"

void Board::addRound(const std::array<CodePeg, 4> &roundGuess,
                     const std::array<FeedbackPeg, 4> &roundFeedback) {
  rounds.push_back(Round{roundGuess, roundFeedback});
}

void Board::render() {
  std::cout << "| Code       | Feedback\n|";
  std::cout << "--------------------------\n";
  for (const auto &round : rounds) {
    std::cout << "| ";
    for (const auto &code : round.guess) {
      std::cout << toAnsi(code) << " ";
    }

    std::cout << "   | ";
    for (const auto &fb : round.feedback) {
      std::cout << toAnsi(fb) << " ";
    }

    std::cout << " |\n";
  }
  std::cout << "\n";
}

const std::vector<Round> Board::getBoard() const { return rounds; }
