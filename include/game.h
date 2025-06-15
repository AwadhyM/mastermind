#pragma once
#include "computer.h"

class Game {
public:
  int codeLength;
  Computer opponent;
  Game(int codeLength);
  void start();

private:
  void welcomeMessage();
};
