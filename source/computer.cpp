#include "../include/computer.h"
#include <iostream>
#include <random>

Computer::Computer() { code = generateCode(); }

std::array<ColorPeg, codeLength> Computer::generateCode() {
  std::array<ColorPeg, codeLength> code{};

  // Populate array with randomly generated values
  for (auto &slot : code) {
    slot = Computer::gen();
  }

  return code;
};

ColorPeg Computer::gen() {
  std::random_device rd("default");
  std::uniform_int_distribution<> uid(0, 3);
  ColorPeg val = static_cast<ColorPeg>(uid(rd));
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
