#include "Headers/Game.hpp"

int main()
{
  kdr::Game game;

  game.initialize();
  game.run();
  game.terminate();

  return 0;
}
