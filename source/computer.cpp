#include "../include/computer.h"
#include <iostream>
#include <random>

Computer::Computer(int codeLength) : codeLength(codeLength) {
  code = generateCode();
}

std::vector<CodePeg> Computer::generateCode() {
  std::vector<CodePeg> generatedCode(codeLength);
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

void Computer::printCode() const {
  for (int i = 0; i < code.size(); i++) {
    if (i == code.size() - 1) {
      std::cout << pegToString(code[i]) << std::endl;
    } else {
      std::cout << pegToString(code[i]) << ",";
    }
  }
}
