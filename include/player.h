#include "../include/colorPeg.h"
#include <array>

// TODO - For future work - Have this be a virtual class. Create a User and Opponent class

class Player {
public:
	Player() {};
	std::array<ColorPeg, 4> makeGuess();
	ColorPeg guessColorPeg();
	void guessEntryMessage(int codePart);
private:
};
