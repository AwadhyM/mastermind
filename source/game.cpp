#include "../include/game.h"
#include <iostream>

Game::Game(int codeLength) : codeLength(codeLength), opponent(codeLength) {
  welcomeMessage();
};

void Game::welcomeMessage() const {
  std::cout << "=====================================\n";
  std::cout << "     Welcome to Mastermind!\n";
  std::cout << "=====================================\n";
  std::cout << "Guess the secret code of colors.\n";
  std::cout << "You’ll receive feedback after each guess:\n";
  std::cout << " - A black peg: correct color and position\n";
  std::cout << " - A white peg: correct color, wrong position\n";
  std::cout << "Can you crack the code?\n\n";
  std::cout << "Good luck!\n\n";
}

void Game::play() {
  opponent.emplace(codeLength);
  notifyUserThatCodeHasBeenGenerated();
}

void Game::promptUserToStartGame() const {
  std::string userInput = getPromptToStartGame();
}

const std::string Game::getPromptToStartGame() const {
  std::string userInput;
  while (true) {
    std::cout << "Would you like to start the game? Press Y/N: ";
    std::getline(std::cin, userInput);

    if (userInput == "Y" || userInput == "N") {
      break;
    }
    std::cout << "Invalid input. Please enter 'Y' or 'N'.\n";
  }
  return userInput;
}

void Game::notifyUserThatCodeHasBeenGenerated() const {
  std::cout << "Computer opponent has generated a secret code\n";
}

void Game::printCode(std::array<CodePeg, 4> code) const {
  for (int i = 0; i < code.size(); i++) {
    if (i == code.size() - 1) {
      std::cout << pegToString(code[i]) << std::endl;
    } else {
      std::cout << pegToString(code[i]) << ",";
    }
  }
}
