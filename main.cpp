#include <iostream>

#include "game.h"

int main() {
  Game game;

  std::string userChoice = game.getPromptToStartGame();

  if (userChoice != "Y") {
    std::cout << "\nProgramme terminated." << std::endl;
    return 0;
  }

  Game::GameResult res = game.play();

  if (res == Game::GameResult::CODEBREAKER_WIN) {
    std::cout << "Congratulations! Codebreaker guessed the code correctly."
              << std::endl;
  } else {
    std::cout << "Codebreaker failed to guess the code. Better luck next time..."
              << std::endl;
  }

  return 0;
}
