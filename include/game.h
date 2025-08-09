#pragma once
#include <optional>

#include "board.h"
#include "computer.h"
#include "user.h"

class Game {

public:
  enum class GameResult { PLAYER_WON, PLAYER_LOSS };
  static void guessEntryMessage(int codePart);
  static void codeGenMessage(int codePart);

  Game();
  void promptUserToStartGame() const;
  const std::string getPromptToStartGame() const;
  GameResult play();
  void printCode(std::array<CodePeg, 4> code) const;
  void printFeedback(std::array<FeedbackPeg, 4> code) const;

  const User &getUser() const { return user; }

private:
  std::optional<Computer> opponent; // TODO/NOTE - This is an example of tight
  std::optional<Board> board;
  User user;
  void welcomeMessage() const;
  void notifyUserThatCodeHasBeenGenerated() const;
  bool hasPlayerWon() const;
  int numberOfRounds;
};
