#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "ttt_game.h"

int get_player_input(Player *currentPlayer) {
  int choice;
  int choiceCond;
  do {
    printf("Hello player %d, it's your turn\nPlease pick an avaible slot: ",
           currentPlayer->id);

    char cchoice; // character choice
    scanf("%c", &cchoice);
    choice = cchoice - '0';

    choiceCond = choice < 1 || choice > 9;
    if (choiceCond) {
      printf("This is not a valid slot. Please try again.\n");
    }
  } while (choiceCond);

  return choice;
}

int main() {

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

    // this captures user input on where they want to place their symbol

  get_valid_coord: {
    const int choiceIndex = get_player_input(currentPlayer);
    int row;
    int col;
    to_coordinates(choiceIndex, &row, &col);
    if (game.board[row][col] != SYM_O && game.board[row][col] != SYM_X) {
      game.board[row][col] = currentPlayer->sym;
    } else {
      // we need the user to select a correct choiceIndex
      // gotos are kinda bad but this works
      printf("This is not a valid option\n");
      print_game(game.board);
      goto get_valid_coord;
    }
  }
    // TODO: we need to now check if there is three in a row. We only need to
    // check the currrent player symbol.

    // row case
    for (int row = 0; row < BOARD_SIZE; row++) {
      const int a = game.board[row][0];
      const int b = game.board[row][1];
      const int c = game.board[row][2];

      if (a == b && b == c) {
        printf("Player %d is the winner\n", currentPlayer->id);
        currentPlayer->wins++;
        assert(0);
      }
    } // end of row case

    // TODO: col case
    for (int col = 0; col < BOARD_SIZE; col++) {
      //   printf("(%d,%d)= %c\n", 0 , col ,game.board[0][col]);
    } // end of col case

    // TODO: diag. case

    //TODO: is draw?


    // lets swtich players
    if (game.currentPlayer == 1) {
      game.currentPlayer = 2;
    } else {
      game.currentPlayer = 1;
    }
  }

  return EXIT_SUCCESS;
}