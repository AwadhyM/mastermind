#include "../include/codePeg.h"
#include <algorithm>
#include <stdexcept>

const std::string pegToString(CodePeg peg) {
  switch (peg) {
  case CodePeg::Blue:
    return "Blue";
  case CodePeg::Orange:
    return "Orange";
  case CodePeg::Purple:
    return "Purple";
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
  default:
    return " ";
  }
}

CodePeg stringToPeg(const std::string &str) {
  std::string input = str;

  // Make input case-insensitive
  std::transform(input.begin(), input.end(), input.begin(), ::tolower);

  if (input == "blue")
    return CodePeg::Blue;
  if (input == "orange")
    return CodePeg::Orange;
  if (input == "purple")
    return CodePeg::Purple;

  throw std::invalid_argument("Invalid color peg string: " + str);
}
