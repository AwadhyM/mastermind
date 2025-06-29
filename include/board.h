#pragma once

#include "../include/codePeg.h"
#include "../include/feedbackPeg.h"
#include <array>
#include <vector>

/**
 * @class Board
 * @brief Represents the Mastermind game board.
 *
 * The Board class stores the history of guesses and feedback for each round.
 * It provides functionality to add rounds, render the board, and retrieve
 * specific round data.
 */
class Board {
public:
  /**
   * @brief Adds a new round to the board.
   *
   * @param roundGuess The 4-code guess made by the player.
   * @param roundFeedback The feedback pegs (black/white) for the guess.
   *
   * Stores the guess and feedback internally for rendering and review.
   */
  void addRound(const std::array<CodePeg, 4> &roundGuess,
                const std::array<FeedbackPeg, 4> &roundFeedback);

  /**
   * @brief Renders the entire board to the terminal.
   *
   * Displays all past guesses and their corresponding feedbacks.
   * Typically called after each round.
   */
  void render();

private:
  /**
   * @brief Stores a player's guess.
   *
   * Helper function used internally by addRound.
   * @param roundGuess The guess to store.
   */
  void addGuess(const std::array<CodePeg, 4> &roundGuess);

  /**
   * @brief Stores the feedback for a guess.
   *
   * Helper function used internally by addRound.
   * @param roundFeedback The feedback to store.
   */
  void addFeedback(const std::array<FeedbackPeg, 4> &roundFeedback);

  /**
   * @brief Gets the player's guess for a specific round.
   *
   * @param round The round number (0-based).
   * @return The guess for the specified round.
   *
   * @note Assumes the caller passes a valid round number.
   */
  const std::array<CodePeg, 4> getGuessForRound(int round) const;

  /**
   * @brief Gets the feedback for a specific round.
   *
   * @param round The round number (0-based).
   * @return The feedback for the specified round.
   *
   * @note Assumes the caller passes a valid round number.
   */
  const std::array<FeedbackPeg, 4> getFeedbackForRound(int round) const;

  // Stores all player guesses per round.
  std::vector<std::array<CodePeg, 4>> guess{};

  // Stores all feedbacks per round.
  std::vector<std::array<FeedbackPeg, 4>> feedback{};
};

