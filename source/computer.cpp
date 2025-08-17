#include "../include/computer.h"

#include <array>
#include <iostream>
#include <random>

Computer::Computer() {};

std::array<CodePeg, 4> Computer::generateCode() const {
  std::array<CodePeg, 4> generatedCode{};
  for (auto &slot : generatedCode) {
    slot = Computer::gen();
  }
  return generatedCode;
}

CodePeg Computer::gen() {
  std::random_device rd;
  std::uniform_int_distribution<> uid(0, 3);
  CodePeg val = static_cast<CodePeg>(uid(rd));
  return val;
}

std::array<CodePeg, 4> Computer::makeGuess() const {
  // TODO - Implement proper code breaking functionality.
  return generateCode();
}
