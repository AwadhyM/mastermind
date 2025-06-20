#include "../include/player.h"
#include <iostream>

void Player::guessEntryMessage(int codePart) {
  const std::array<std::string, 4> positions{"first", "second", "third",
                                             "fourth"};
  std::cout << "Enter your guess for the part of the of the code:";
}

std::array<CodePeg, 4> Player::makeGuess() {
  std::array<CodePeg, 4> code{};

  int codePart{0};
  while (codePart < 4) {
    guessEntryMessage(codePart);
    code[codePart] = guessCodePeg();
    codePart++;
  }
  return code;
}

CodePeg Player::guessCodePeg() {
  while (true) {
    std::string userInput;
    std::getline(std::cin, userInput);
    try {
      CodePeg peg = stringToPeg(userInput);

      return peg;
    } catch (const std::invalid_argument &e) {
      std::cout << "Invalid color. Please try again.\n";
    }
  }
}
