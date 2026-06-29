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
     mygamestate->p1.sym = SYM_X;
    mygamestate->p1.score = 0;

    mygamestate->p2.sym = SYM_O;
    mygamestate->p2.score = 0;

    int count = 0;
    for(int i = 0 ; i < BOARD_SIZE ; i++){
        for(int j = 0 ; j < BOARD_SIZE ; j++){
            mygamestate->board[i][j] = '0' + (++count);
        }
    }
    
    return 0;
}