#include "../include/feedbackPeg.h"

const std::string pegToString(feedbackPeg peg) {
  switch (peg) {
  case feedbackPeg::White:
    return "White";
  case feedbackPeg::Red:
    return "Red";
  default:
    return "Unknown";
  }
}

const std::string toAnsi(feedbackPeg peg) {
  switch (peg) {
  case feedbackPeg::White:
    return "\033[97m●\033[0m";
  case feedbackPeg::Red:
    return "\033[31m●\033[0m";
  default:
    return " ";
  }
}
