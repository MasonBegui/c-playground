#include "ttt_game.h"
#include <stdio.h>

void print_game(char board[BOARD_SIZE][BOARD_SIZE]) {
  printf("\n");
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      printf(" %c ", board[i][j]);
      if (j < BOARD_SIZE - 1)
        printf("|");
    }
    printf("\n");
    if (i < BOARD_SIZE - 1)
      printf("---|---|---\n");
  }
}
int is_running_game(GameState *mygamestate) {
  return mygamestate->running == 1;
}
int init_game(GameState *mygamestate) {
  printf("Init Game\n");

  mygamestate->running = 1;

  // set the players info
  mygamestate->p1.id = 1;
  mygamestate->p1.sym = SYM_X;
  mygamestate->p1.wins = 0;

  mygamestate->p2.id = 2;
  mygamestate->p2.sym = SYM_O;
  mygamestate->p2.wins = 0;

  // in the first game, we always let player one go first
  mygamestate->currentPlayer = mygamestate->p1.id;

  int count = 0;
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      mygamestate->board[i][j] = '0' + (++count);
    }
  }

  return 0;
}

int to_coordinates(int index, int *rowindex, int *colindex) {
  if (index < 1 || index > 9) {
    return -1;
  }
  int baseindex = index - 1;
  *rowindex = baseindex / BOARD_SIZE;
  *colindex = baseindex % BOARD_SIZE;
  return 0;
}

int check_win(char board[BOARD_SIZE][BOARD_SIZE], char symbol) {
  for (int i = 0; i < BOARD_SIZE; i++) {
    const int ra = board[i][0];
    const int rb = board[i][1];
    const int rc = board[i][2];
    const int ca = board[0][i];
    const int cb = board[1][i];
    const int cc = board[2][i];

    if (ca == symbol && cb == symbol && cc == symbol) {
      return 2;
    }
    if (ra == symbol && rb == symbol && rc == symbol) {
      return 1;
    }
  }

  if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
    return 3;
  }
  if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
    return 4;
  }

  return 0;
}