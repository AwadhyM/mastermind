#include "include/board.h"
#include "include/game.h"
#include <iostream>

int main() {
  Game game = Game();

  std::string userChoice = game.getPromptToStartGame();

  if (userChoice == "Y") {
    auto res = game.play();
  } else {
    std::cout << "\nProgramme terminated." << std::endl;
  }

  if (res == Game::GameResult::PLAYER_WON) {
    std::cout << "Congratulation you guessed the code correctly" << std::endl;
  } else {
    std::cout << "You failed to guess the code better luck next time.."
              << std::endl;
  }
}
