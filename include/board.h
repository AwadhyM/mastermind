#pragma once

#include <array>
#include <vector>

#include "codePeg.h"
#include "feedbackPeg.h"

/**
 * @class Board
 * @brief Represents the Mastermind game board.
 *
 * The Board class stores the history of guesses and feedback for each round.
 * It provides functionality to add rounds, render the board, and retrieve
 * specific round data.
 */

struct Round {
  std::array<CodePeg, 4> guess;
  std::array<FeedbackPeg, 4> feedback;
};

class Board {
public:
  /**
   * @brief Adds a new round to the board.
   *
   * @param roundGuess The 4-code guess made by the player.
   * @param roundFeedback The feedback pegs (black/white) for the guess.
   */
  void addRound(const std::array<CodePeg, 4> &roundGuess,
                const std::array<FeedbackPeg, 4> &roundFeedback);

  /**
   * @brief Renders the entire board to the terminal.
   */
  void render();

  /**
   * @brief Returns copy of board
   */
  const std::vector<Round> getBoard() const;

private:
  std::vector<Round> rounds;
};
