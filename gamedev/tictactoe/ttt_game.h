#ifndef TTT_GAME_H
#define TTT_GAME_H

#define BOARD_SIZE 3

#define SYM_X 'X'
#define SYM_O 'O'


typedef struct {
    int id;
    char sym;
    int wins;
}Player;


typedef struct {
    int row;
    int col;
} Point;

typedef struct {
    Player p1;
    Player p2;
    int currentPlayer; // this value has to be 1 or 2
    int running;
    char board [BOARD_SIZE][BOARD_SIZE];

}GameState;

int init_game(GameState *);
int is_running_game(GameState *);
void print_game (char board[BOARD_SIZE][BOARD_SIZE]);

Point get_board_point(int index);
// void get_board_point(int index, int *row, int *col);


#endif