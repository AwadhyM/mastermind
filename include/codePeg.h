#pragma once
#include <array>
#include <string>

enum class CodePeg { Blue, Orange, Yellow, Purple };

constexpr std::array<CodePeg, 4> allCodePegs = {
    CodePeg::Blue, CodePeg::Yellow, CodePeg::Orange, CodePeg::Purple};

const std::string pegToString(CodePeg peg);

const std::string toAnsi(CodePeg peg);

CodePeg stringToPeg(const std::string &str);

void printInputOptions();
