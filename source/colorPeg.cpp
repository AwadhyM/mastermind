#include "../include/colorPeg.h"
#include <algorithm>
#include <stdexcept>

const std::string pegToString(ColorPeg peg) {
  switch (peg) {
  case ColorPeg::Blue:
    return "Blue";
  case ColorPeg::Orange:
    return "Orange";
  case ColorPeg::Green:
    return "Green";
  case ColorPeg::Purple:
    return "Purple";
  case ColorPeg::White:
    return "White";
  case ColorPeg::Red:
    return "Red";
  default:
    return "Unknown";
  }
}

const std::string toAnsi(ColorPeg peg) {
  switch (peg) {
  case ColorPeg::Blue:
    return "\033[34m●\033[0m";
  case ColorPeg::Green:
    return "\033[32m●\033[0m";
  case ColorPeg::Orange:
    return "\033[38;2;255;165;0m●\033[0m";
  case ColorPeg::Purple:
    return "\033[35m●\033[0m";
  case ColorPeg::White:
    return "\033[97m●\033[0m";
  case ColorPeg::Red:
    return "\033[31m●\033[0m";
  default:
    return " ";
  }
}

ColorPeg stringToPeg(const std::string &str) {
  std::string input = str;

  // Make input case-insensitive
  std::transform(input.begin(), input.end(), input.begin(), ::tolower);

  if (input == "blue")
    return ColorPeg::Blue;
  if (input == "orange")
    return ColorPeg::Orange;
  if (input == "green")
    return ColorPeg::Green;
  if (input == "purple")
    return ColorPeg::Purple;
  if (input == "white")
    return ColorPeg::White;
  if (input == "red")
    return ColorPeg::Red;

  throw std::invalid_argument("Invalid color peg string: " + str);
}
