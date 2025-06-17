#pragma once
#include <string>

enum class ColorPeg { Blue, Orange, Green, Purple, White, Red };

const std::string pegToString(ColorPeg peg);

const std::string toAnsi(ColorPeg peg);
