#include "user.h"

#include <iostream>

void User::guessEntryMessage(int codePart) const {
  const std::array<std::string, 4> positions{"first", "second", "third",
                                             "fourth"};
  std::cout << "Enter your guess for the " << positions[codePart]
            << " part of the of the code:";
}

std::array<CodePeg, 4> User::makeGuess() const {
  std::array<CodePeg, 4> code{};

  int codePart{0};
  while (codePart < 4) {
    guessEntryMessage(codePart);
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
