#include "include/board.h"
#include "include/game.h"
#include <iostream>

int main() {
  Game game = Game();

  std::string userChoice = game.getPromptToStartGame();

  if (userChoice == "Y") {
    game.play();
  } else {
    std::cout << "\nProgramme terminated." << std::endl;
  }
  game.printCode(game.getUser().makeGuess());
}
