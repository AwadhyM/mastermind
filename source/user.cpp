#include <iostream>

#include "game.h"

std::array<CodePeg, 4> User::makeGuess() const {
  std::array<CodePeg, 4> code{};
  std::cout << "Enter your guess using these color codes:\n";
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
  std::array<CodePeg, 4> code{};
  std::cout << "Generate code using these color codes:\n";
  printInputOptions();
  int codePart{0};
  while (codePart < 4) {
    Game::codeGenMessage(codePart);
    code[codePart] =
        guessCodePeg(); // TODO - rewrite this to be validate code peg
    codePart++;
  }
  return code;
}
