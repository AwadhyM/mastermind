#include <iostream>
#include "include/game.h"

int main() {
  Game game;

  std::string userChoice = game.getPromptToStartGame();

  if (userChoice != "Y") {
    std::cout << "\nProgramme terminated." << std::endl;
    return 0;
  }

  Game::GameResult res = game.play();

  if (res == Game::GameResult::PLAYER_WON) {
    std::cout << "Congratulations! You guessed the code correctly." << std::endl;
  } else {
    std::cout << "You failed to guess the code. Better luck next time..." << std::endl;
  }

  return 0;
}
