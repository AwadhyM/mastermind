#include "../include/codePeg.h"

#include <algorithm>
#include <iostream>
#include <stdexcept>

const std::string pegToString(CodePeg peg) {
  switch (peg) {
  case CodePeg::Blue:
    return "Blue";
  case CodePeg::Orange:
    return "Orange";
  case CodePeg::Purple:
    return "Purple";
  case CodePeg::Yellow:
    return "Yellow";
  default:
    return "Unknown";
  }
}

const std::string pegToChar(CodePeg peg) {
  switch (peg) {
  case CodePeg::Blue:
    return "B";
  case CodePeg::Orange:
    return "O";
  case CodePeg::Purple:
    return "P";
  case CodePeg::Yellow:
    return "Y";
  default:
    return "Unknown";
  }
}

const std::string toAnsi(CodePeg peg) {
  switch (peg) {
  case CodePeg::Blue:
    return "\033[34m●\033[0m";
  case CodePeg::Orange:
    return "\033[38;2;255;165;0m●\033[0m";
  case CodePeg::Purple:
    return "\033[35m●\033[0m";
  case CodePeg::Yellow:
    return "\033[33m●\033[0m";
  default:
    return " ";
  }
}

CodePeg stringToPeg(const std::string &str) {
  std::string input = str;

  // Make input case-insensitive
  std::transform(input.begin(), input.end(), input.begin(), ::toupper);

  if (input == "B")
    return CodePeg::Blue;
  if (input == "O")
    return CodePeg::Orange;
  if (input == "Y")
    return CodePeg::Yellow;
  if (input == "P")
    return CodePeg::Purple;

  throw std::invalid_argument("Invalid color peg string: " + str);
}

void printInputOptions() {
  std::cout << "Enter your guess using these color codes:\n";

  for (CodePeg peg : allCodePegs) {
    std::cout << pegToChar(peg) << " = " << pegToString(peg);
    if (peg != allCodePegs.back())
      std::cout << ", ";
  }
  std::cout << '\n';
}
