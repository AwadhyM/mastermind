#include "include/board.h"
#include "include/colorPeg.h"
#include "include/game.h"
#include <iostream>

int main() {
  Game game = Game(4);
  game.welcomeMessage();

  std::string userChoice = game.getPromptToStartGame();

  if (userChoice == "Y") {
    game.play();
  } else {
    std::cout << "\nProgramme terminated." << std::endl;
  }

  Board board = Board();
  game.printCode(game.user.makeGuess());
}
