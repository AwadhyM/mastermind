#include "../include/computer.h"
#include <iostream>
#include <random>

std::array<CodePeg, 4> Computer::getCode() const { return code; }

Computer::Computer(int codeLength) : codeLength(codeLength) {
  code = generateCode();
}

std::array<CodePeg, 4> Computer::generateCode() {
  std::array<CodePeg, 4> generatedCode{};
  for (auto &slot : generatedCode) {
    slot = Computer::gen();
  }
  return generatedCode;
}

CodePeg Computer::gen() {
  std::random_device rd("default");
  std::uniform_int_distribution<> uid(0, 3);
  CodePeg val = static_cast<CodePeg>(uid(rd));
  return val;
}
