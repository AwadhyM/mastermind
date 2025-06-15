#include "../include/game.h"
#include <iostream>

Game::Game(int codeLength) : codeLength(codeLength) { welcomeMessage(); };

void Game::welcomeMessage() {
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
