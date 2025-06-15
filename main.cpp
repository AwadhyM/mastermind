#include "include/game.h"
#include <iostream>

<<<<<<< Updated upstream int main() { Game game = Game(4); }
=======
int main() {
  Game game = Game(4);
  game.welcomeMessage();

  std::string userChoice = game.getPromptToStartGame();

  if (userChoice == "Y") {
    game.play();
  } else {
    std::cout << "\nProgramme terminated." << std::endl;
  }
}
>>>>>>> Stashed changes
