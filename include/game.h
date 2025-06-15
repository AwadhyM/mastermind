#pragma once
#include "computer.h"

class Game {
public:
  int codeLength;
  Computer opponent;
  Game(int codeLength);
  void promptUserToStartGame();
  const std::string getPromptToStartGame();
  void play();
  void welcomeMessage();

private:
  void notifyUserThatCodeHasBeenGenerated();
};
