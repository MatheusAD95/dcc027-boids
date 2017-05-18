#include "game.h"
#include <cstdio>
#define GLEW_STATIC 1
int main() {
  Game g = Game::getGame();
  g.init(800, 600);
  g.start();
  return 0;
}
