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
    int running;
    char board [BOARD_SIZE][BOARD_SIZE];

}GameState;

int init_game(GameState *);
int is_running_game(GameState *);
void print_game (char board[BOARD_SIZE][BOARD_SIZE]);


#endif