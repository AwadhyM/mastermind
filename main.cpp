#include "include/computer.h"
#include "include/game.h"
#include <iostream>

int main() {
  Game game = Game(4);
  Computer comp = Computer(game.codeLength);
}
