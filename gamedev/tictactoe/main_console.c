#include <stdio.h>
#include <stdlib.h>

#include "ttt_game.h"

int get_yes_no(void) {
  int answer;
  int scanfRtn;
  do {
    printf("Do you want to play again? (1 = yes, 0 = no): ");
    scanfRtn = scanf("%d", &answer);
    while (getchar() != '\n')
      ; // clears the input buffer
  } while (scanfRtn != 1 || (answer != 0 && answer != 1));
  return answer;
}

int get_player_input(Player *currentPlayer) {
  int choice;
  int choiceCond;
  do {
    printf("Hello player %d, it's your turn\nPlease pick an avaible slot: ",
           currentPlayer->id);
    int scanfRtn = scanf("%d", &choice);
    while (getchar() != '\n')
      ; // clears the input buffer
    choiceCond = choice < 1 || choice > 9 || scanfRtn == 0;
    if (choiceCond) {
      printf("This is not a valid slot. Please try again.\n");
    }
  } while (choiceCond);

  return choice;
}

int main() {

  GameState game;
  init_game(&game);

  int playing = 1;
  while (playing) {
    print_game(game.board);

    Player *currentPlayer = NULL;
    if (game.currentPlayer == 1) {
      currentPlayer = &game.p1;
    } else {
      currentPlayer = &game.p2;
    }

    int choiceIndex;
    do {
      choiceIndex = get_player_input(currentPlayer);
      if (!is_valid_move(&game, choiceIndex)) {
        printf("This is not a valid option\n");
        print_game(game.board);
      }
    } while (!is_valid_move(&game, choiceIndex));

    int result = make_move(&game, choiceIndex);
    if (result == MOVE_WIN) {
      printf("Player %d is the winner\n", currentPlayer->id);
      playing = get_yes_no();
      if (!playing) {
        break;
      }
      reset_board(&game);
    } else if (result == MOVE_DRAW) {
      printf("It's a draw!\n");
      playing = get_yes_no();
      if (!playing) {
        break;
      }
      reset_board(&game);
    }
  }

  printf("\nGame stats:\n");
  printf("Player 1 (X): %d win(s)\n", game.p1.wins);
  printf("Player 2 (O): %d win(s)\n", game.p2.wins);

  return EXIT_SUCCESS;
}