#include <iostream>

#include "game.h"

std::array<CodePeg, 4> User::makeGuess() const {
  std::array<CodePeg, 4> code{};
  printInputOptions();
  int codePart{0};
  while (codePart < 4) {
    Game::guessEntryMessage(codePart);
    code[codePart] = guessCodePeg();
    codePart++;
  }
  return code;
}

CodePeg User::guessCodePeg() const {
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


std::array<CodePeg, 4> User::generateCode() const {
	// TODO - Implement code generation functionality
    return {};
}
