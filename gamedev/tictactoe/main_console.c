#include <stdio.h>
#include <stdlib.h>

#include "ttt_game.h"

int main() {
  printf("I am the console\n");

  GameState game;
  init_game(&game);

  while(is_running_game(&game)) {
    print_game(game.board);

    




  }



  return EXIT_SUCCESS;
}