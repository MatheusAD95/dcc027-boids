#include "game.h"
#include <cstdio>
#define GLEW_STATIC 1
int main() {
  Game::getGame().init(800, 600);
  Game::getGame().start();
  return 0;
}
