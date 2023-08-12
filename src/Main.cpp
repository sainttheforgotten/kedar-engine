#include "Headers/Game.hpp"
#include "Utils/Core.hpp"

int main()
{
  kdr::Game game;
  kdr::core::printEngineInfo();

  game.initialize();
  game.run();
  game.terminate();

  return 0;
}
