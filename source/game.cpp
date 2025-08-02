#include "game.h"

#include <algorithm>
#include <iostream>

#include "board.h"
#include "feedbackPeg.h"

Game::Game() : numberOfRounds(12) { welcomeMessage(); };

void Game::welcomeMessage() const {
  std::cout << "=====================================\n";
  std::cout << "     Welcome to Mastermind!\n";
  std::cout << "=====================================\n";
  std::cout << "Guess the secret code of colors.\n";
  std::cout << "You’ll receive feedback after each guess:\n";
  std::cout << " - A green peg: correct color and position\n";
  std::cout << " - A white peg: correct color, wrong position\n";
  std::cout << " - A red peg: color is not part of code\n";
  std::cout << "Can you crack the code?\n\n";
  std::cout << "Good luck!\n\n";
}

Game::GameResult Game::play() {
  board.emplace();
  opponent.emplace();
  notifyUserThatCodeHasBeenGenerated();
#ifdef DEBUG_BUILD
  printCode(opponent->getCode());
#endif

  for (int i = 0; i <= numberOfRounds; i++) {
    const auto guess = user.makeGuess();
    const auto feedback = opponent->generateFeedback(
        guess); // Not sure how right this is. Either get the guess from above.
                // Or add the guess to the board, and then get it
    board->addRound(guess, feedback);
    board->render();

    if (hasPlayerWon())
      return GameResult::PLAYER_WON;
  }

  return GameResult::PLAYER_LOSS;
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
#ifdef DEBUG_BUILD
  std::cout << "Computer opponent has generated a secret code:";
#else
  std::cout << "Computer opponent has generated a secret code.\n\n";
#endif
}

void Game::printCode(std::array<CodePeg, 4> code) const {
  for (int i = 0; i < code.size(); i++) {
    if (i == code.size() - 1) {
      std::cout << pegToString(code[i]) << std::endl;
    } else {
      std::cout << pegToString(code[i]) << ",";
    }
  }
    std::cout << "\n\n";
}

void Game::printFeedback(std::array<FeedbackPeg, 4> code) const {
  for (int i = 0; i < code.size(); i++) {
    if (i == code.size() - 1) {
      std::cout << feedbackPegToString(code[i]) << std::endl;
    } else {
      std::cout << feedbackPegToString(code[i]) << ",";
    }
  }
}

bool Game::hasPlayerWon() const {
  const auto feedbackCurrentRound = board->getBoard().back().feedback;
  return std::all_of(feedbackCurrentRound.begin(), feedbackCurrentRound.end(),
                     [](FeedbackPeg f) { return f == FeedbackPeg::Green; });
}
