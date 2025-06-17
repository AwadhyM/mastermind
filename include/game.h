#pragma once
#include "computer.h"

class Game {
public:
  int codeLength;
  Computer opponent; // TODO/NOTE - This is an example of tight coupling. Future
                     // improvement could be to use depdency injection
  Game(int codeLength);
  void promptUserToStartGame();
  const std::string getPromptToStartGame();
  void play();
  void welcomeMessage();

private:
  void notifyUserThatCodeHasBeenGenerated();
};
