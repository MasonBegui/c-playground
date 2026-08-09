#ifndef TTT_GAME_H
#define TTT_GAME_H

#define BOARD_SIZE 3

#define SYM_X 'X'
#define SYM_O 'O'

#define MOVE_INVALID -1
#define MOVE_OK 0
#define MOVE_WIN 1
#define MOVE_DRAW 2


typedef struct {
    int id;
    char sym;
    int wins;
}Player;

typedef struct {
    Player p1;
    Player p2;
    int currentPlayer; // this value has to be 1 or 2
    int running;
    char board [BOARD_SIZE][BOARD_SIZE];

}GameState;

int init_game(GameState *);
int reset_board(GameState *);
int is_running_game(GameState *);
void print_game (char board[BOARD_SIZE][BOARD_SIZE]);

int to_coordinates(int index, int *rowindex, int *colindex);

int check_win(char board[BOARD_SIZE][BOARD_SIZE], char symbol);
int check_draw(char board[BOARD_SIZE][BOARD_SIZE]);
int is_valid_move(GameState *, int index);
int make_move(GameState *, int index);



#endif