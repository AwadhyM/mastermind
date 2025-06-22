#pragma once
#include <string>

enum class CodePeg { Blue, Orange, Yellow, Purple };

const std::string pegToString(CodePeg peg);

const std::string toAnsi(CodePeg peg);

CodePeg stringToPeg(const std::string &str);
