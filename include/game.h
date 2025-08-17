#pragma once
#include <memory>
#include <optional>

#include "board.h"
#include "playerBase.h"

class Game {

public:
  enum class GameResult { CODEBREAKER_WIN, CODEBREAKER_LOSS };
  static void codeEntryMessage(int codePart);

  Game();
  void promptUserToStartGame() const;
  const std::string getPromptToStartGame() const;
  GameResult play();
  void printCode(std::array<CodePeg, 4> code) const;
  void printFeedback(std::array<FeedbackPeg, 4> code) const;

private:
  struct participants {
    std::unique_ptr<PlayerBase> codebreaker;
    std::unique_ptr<PlayerBase> codemaker;
  };

  participants setUpParticipants();

  std::optional<Board> board;
  void welcomeMessage() const;
  void notifyUserThatCodeHasBeenGenerated() const;
  bool hasPlayerWon() const;
  int numberOfRounds;
};
