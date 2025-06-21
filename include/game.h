#pragma once
#include "computer.h"
#include "player.h"
#include <iostream>
#include <optional>

class Game {
public:
  int codeLength;
  std::optional<Computer>
      opponent; // TODO/NOTE - This is an example of tight coupling. Future
  Player user;

  Game(int codeLength);
  void promptUserToStartGame();
  const std::string getPromptToStartGame();
  void play();
  void welcomeMessage();
  void printCode(std::array<CodePeg, 4> code);

private:
  void notifyUserThatCodeHasBeenGenerated();
};
