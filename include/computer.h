#pragma once
#include "colorPeg.h"
#include <array>

constexpr int codeLength = 4;

class Computer {
public:
  Computer();
  static ColorPeg gen();
  std::array<ColorPeg, codeLength> code;

private:
  std::array<ColorPeg, codeLength> generateCode();
  void printCode() const;
};
