#include <stdio.h>
#include <stdlib.h>

#include "ttt_game.h"

int get_player_input(Player *currentPlayer) {
  int choice;
  int choiceCond;
  do {
    printf("Hello player %d, it's your turn\nPlease pick an avaible slot: ",
           currentPlayer->id);
    scanf("%d", &choice);

    choiceCond = choice < 1 || choice > 9;
    if (choiceCond) {
      printf("This is not a valid slot. Please try again.\n");
    }
  } while (choiceCond);

  return choice;
}

int main() {
  printf("I am the console\n");

  GameState game;
  init_game(&game);

  while (is_running_game(&game)) {
    print_game(game.board);

    Player *currentPlayer = NULL;
    if (game.currentPlayer == 1) {
      currentPlayer = &game.p1;
    } else {
      currentPlayer = &game.p2;
    }

    int choiceIndex = get_player_input(currentPlayer);

    get_board_point(choiceIndex);

    // TODO: given the choiceIndex, how do we map it to our 2d board array
    // TODO: we need to determine if the slot is taken

    // lets swtich players
    if (game.currentPlayer == 1) {
      game.currentPlayer = 2;
    } else {
      game.currentPlayer = 1;
    }
  }

  return EXIT_SUCCESS;
}