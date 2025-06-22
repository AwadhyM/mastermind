#pragma once
#include <string>

enum class FeedbackPeg { Green, White, Red };

const std::string feedbackPegToString(FeedbackPeg peg);

const std::string toAnsi(FeedbackPeg peg);
