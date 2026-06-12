#include <stdio.h>
#include <stdlib.h>

#include "ttt_game.h"

int main() {
  printf("I am the console\n");
  printf("___|___|___\n");
  printf("___|___|___\n");
  printf("   |   |   \n");

  GameState game;
  init(game);
  return EXIT_SUCCESS;
}