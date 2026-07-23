#include "ttt_game.h"
#include <stdio.h>

void print_game (char board[BOARD_SIZE][BOARD_SIZE]) {
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf(" %c ", board[i][j]);
            if (j < BOARD_SIZE - 1) printf("|");
        }
        printf("\n");
        if (i < BOARD_SIZE - 1) printf("---|---|---\n");
    }
}
int is_running_game(GameState *mygamestate) {
    return mygamestate->running == 1;
}
int init_game(GameState * mygamestate) {
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
    for(int i = 0 ; i < BOARD_SIZE ; i++){
        for(int j = 0 ; j < BOARD_SIZE ; j++){
            mygamestate->board[i][j] = '0' + (++count);
        }
    }
    
    return 0;
}

int to_coordinates(int index, int *rowindex, int *colindex){
  if (index < 1 || index > 9){
    return -1;
  }
  int baseindex = index - 1;
  *rowindex = baseindex / BOARD_SIZE;
  *colindex = baseindex % BOARD_SIZE;
  return 0;
}