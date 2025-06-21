#pragma once
#include "computer.h"
#include "player.h"
#include <iostream>
#include <optional>

class Game {
public:
  Game(int codeLength);
  void promptUserToStartGame();
  const std::string getPromptToStartGame();
  void play();
  void welcomeMessage();
  void printCode(std::array<CodePeg, 4> code);

  const Player &getUser() const { return user; }

private:
  void notifyUserThatCodeHasBeenGenerated();
  int codeLength;
  std::optional<Computer> opponent; // TODO/NOTE - This is an example of tight
                                    // coupling. Future work needed
  Player user;
};
