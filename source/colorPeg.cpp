#include "../include/colorPeg.h"

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
  case ColorPeg::Black:
    return "Black";
  default:
    return "Unknown";
  }
}
