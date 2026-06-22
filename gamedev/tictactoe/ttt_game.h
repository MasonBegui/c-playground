#ifndef TTT_GAME_H
#define TTT_GAME_H

#define BOARD_SIZE 3

#define SYM_X 'X'
#define SYM_O 'O'


typedef struct {
    char sym;
    int score;
}Player;

typedef struct {
    Player p1;
    Player p2;
    char board [BOARD_SIZE][BOARD_SIZE];

}GameState;

int init(GameState *);
void print_board (char board[BOARD_SIZE][BOARD_SIZE]);


#endif