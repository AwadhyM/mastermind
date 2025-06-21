#pragma once
#include "computer.h"
#include "player.h"
#include <optional>

class Game {
public:
  Game(int codeLength);
  void promptUserToStartGame() const;
  const std::string getPromptToStartGame() const;
  void play();
  void printCode(std::array<CodePeg, 4> code) const;

  const Player &getUser() const { return user; }

private:
  int codeLength;
  std::optional<Computer> opponent; // TODO/NOTE - This is an example of tight
  Player user;
  void welcomeMessage() const;
  void notifyUserThatCodeHasBeenGenerated() const;
};
