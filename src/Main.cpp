#include "Game.hpp"

int main(){
  Game game;
  if (game.init()) game.run();
  else return 1;
  return 0;
}
