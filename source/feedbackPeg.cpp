#include "../include/feedbackPeg.h"

const std::string pegToString(FeedbackPeg peg) {
  switch (peg) {
  case FeedbackPeg::White:
    return "White";
  case FeedbackPeg::Red:
    return "Red";
  case FeedbackPeg::Green:
    return "Green";
  default:
    return "Unknown";
  }
}

const std::string toAnsi(FeedbackPeg peg) {
  switch (peg) {
  case FeedbackPeg::White:
    return "\033[97m●\033[0m";
  case FeedbackPeg::Red:
    return "\033[31m●\033[0m";
  case FeedbackPeg::Green:
    return "\033[32m●\033[0m";
  default:
    return " ";
  }
}
