#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "raylib.h"

#include "ttt_game.h"

#define LOGICAL_WIDTH 640
#define LOGICAL_HEIGHT 480

#define TOP_BAND 60
#define BOTTOM_BAND 60
#define PAD 20

#define BTN_SIZE 26
#define BTN_MARGIN 6
#define BTN_TOP 6

enum WindowAction { NONE, ACTION_MINIMIZE, ACTION_MAXIMIZE, ACTION_CLOSE };

static float cellSize;
static float gridX;
static float gridY;
static float gridSize;

static int get_cell_index(float mouseX, float mouseY) {
  if (mouseX < gridX || mouseX > gridX + gridSize) {
    return 0;
  }
  if (mouseY < gridY || mouseY > gridY + gridSize) {
    return 0;
  }
  int row = (int)((mouseY - gridY) / cellSize);
  int col = (int)((mouseX - gridX) / cellSize);
  return row * BOARD_SIZE + col + 1;
}

static void draw_centered_text(const char *text, float y, int fontSize,
                               Color color) {
  int textWidth = MeasureText(text, fontSize);
  DrawText(text, (GetScreenWidth() - textWidth) / 2, (int)y, fontSize, color);
}

static void draw_symbol(float cx, float cy, char sym, float half) {
  float thickness = fmaxf(4.0f, cellSize * 0.06f);
  if (sym == SYM_X) {
    DrawLineEx((Vector2){cx - half, cy - half},
               (Vector2){cx + half, cy + half}, thickness, RED);
    DrawLineEx((Vector2){cx - half, cy + half},
               (Vector2){cx + half, cy - half}, thickness, RED);
  } else if (sym == SYM_O) {
    DrawCircleLines((int)cx, (int)cy, half, BLUE);
    DrawCircleLines((int)cx, (int)cy, half - cellSize * 0.03f, BLUE);
  }
}

static void draw_win_line(char board[BOARD_SIZE][BOARD_SIZE], char sym) {
  float half = cellSize / 2.0f;
  float inset = cellSize * 0.17f;
  float thickness = fmaxf(4.0f, cellSize * 0.06f);

  for (int i = 0; i < BOARD_SIZE; i++) {
    if (board[i][0] == sym && board[i][1] == sym && board[i][2] == sym) {
      float cy = gridY + cellSize * i + half;
      DrawLineEx((Vector2){gridX + inset, cy},
                 (Vector2){gridX + gridSize - inset, cy}, thickness, GREEN);
      return;
    }
    if (board[0][i] == sym && board[1][i] == sym && board[2][i] == sym) {
      float cx = gridX + cellSize * i + half;
      DrawLineEx((Vector2){cx, gridY + inset},
                 (Vector2){cx, gridY + gridSize - inset}, thickness, GREEN);
      return;
    }
  }

  if (board[0][0] == sym && board[1][1] == sym && board[2][2] == sym) {
    DrawLineEx((Vector2){gridX + inset, gridY + inset},
               (Vector2){gridX + gridSize - inset, gridY + gridSize - inset},
               thickness, GREEN);
  } else if (board[0][2] == sym && board[1][1] == sym && board[2][0] == sym) {
    DrawLineEx((Vector2){gridX + gridSize - inset, gridY + inset},
               (Vector2){gridX + inset, gridY + gridSize - inset}, thickness,
               GREEN);
  }
}

static void draw_board(GameState *game, int gameOver, char previewSym) {
  Vector2 mouse = GetMousePosition();
  int hoverIndex = get_cell_index(mouse.x, mouse.y);

  for (int row = 0; row < BOARD_SIZE; row++) {
    for (int col = 0; col < BOARD_SIZE; col++) {
      float x = gridX + cellSize * col;
      float y = gridY + cellSize * row;
      float cx = x + cellSize / 2.0f;
      float cy = y + cellSize / 2.0f;

      if (!gameOver && mouse.x >= x && mouse.x <= x + cellSize &&
          mouse.y >= y && mouse.y <= y + cellSize &&
          is_valid_move(game, row * BOARD_SIZE + col + 1)) {
        DrawRectangle((int)x, (int)y, (int)(cellSize + 0.5f),
                      (int)(cellSize + 0.5f), LIGHTGRAY);
      }

      draw_symbol(cx, cy, game->board[row][col], cellSize * 0.35f);
    }
  }

  for (int i = 1; i < BOARD_SIZE; i++) {
    DrawLine((int)(gridX + cellSize * i), (int)gridY,
             (int)(gridX + cellSize * i), (int)(gridY + gridSize), DARKGRAY);
    DrawLine((int)gridX, (int)(gridY + cellSize * i),
             (int)(gridX + gridSize), (int)(gridY + cellSize * i), DARKGRAY);
  }

  DrawRectangleLines((int)gridX, (int)gridY, (int)(gridSize + 0.5f),
                     (int)(gridSize + 0.5f), DARKGRAY);

  if (hoverIndex > 0) {
    int row, col;
    to_coordinates(hoverIndex, &row, &col);
    char symbol = game->board[row][col];
    if (symbol >= '1' && symbol <= '9') {
      draw_symbol(gridX + cellSize * col + cellSize / 2.0f,
                  gridY + cellSize * row + cellSize / 2.0f, previewSym,
                  cellSize * 0.35f);
    }
  }
}

static void make_button_rect(int i, Rectangle *btn) {
  btn->x = GetScreenWidth() - BTN_MARGIN - BTN_SIZE * (3 - i);
  btn->y = BTN_TOP;
  btn->width = BTN_SIZE;
  btn->height = BTN_SIZE;
}

static enum WindowAction get_window_action(void) {
  Vector2 mouse = GetMousePosition();
  if (!IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
    return NONE;
  }

  enum WindowAction actions[3] = {ACTION_MINIMIZE, ACTION_MAXIMIZE,
                                  ACTION_CLOSE};
  for (int i = 0; i < 3; i++) {
    Rectangle btn;
    make_button_rect(i, &btn);
    if (CheckCollisionPointRec(mouse, btn)) {
      return actions[i];
    }
  }
  return NONE;
}

static void draw_window_buttons(void) {
  Vector2 mouse = GetMousePosition();

  for (int i = 0; i < 3; i++) {
    Rectangle btn;
    make_button_rect(i, &btn);

    bool hovered = CheckCollisionPointRec(mouse, btn);
    bool maximized = i == 1 && IsWindowMaximized();

    if (hovered) {
      DrawRectangle((int)btn.x, (int)btn.y, BTN_SIZE, BTN_SIZE, LIGHTGRAY);
    }
    DrawRectangleLines((int)btn.x, (int)btn.y, BTN_SIZE, BTN_SIZE, DARKGRAY);

    float cx = btn.x + BTN_SIZE / 2.0f;
    float cy = btn.y + BTN_SIZE / 2.0f;
    if (i == 0) {
      DrawLine((int)(btn.x + 6), (int)(btn.y + BTN_SIZE - 7),
               (int)(btn.x + BTN_SIZE - 6), (int)(btn.y + BTN_SIZE - 7),
               DARKGRAY);
    } else if (i == 1) {
      DrawRectangleLines((int)(cx - 7), (int)(cy - 6), 14, 12, DARKGRAY);
      if (maximized) {
        DrawRectangleLines((int)(cx - 3), (int)(cy - 8), 14, 12, DARKGRAY);
      }
    } else {
      DrawLine((int)(btn.x + 6), (int)(btn.y + 6), (int)(btn.x + BTN_SIZE - 6),
               (int)(btn.y + BTN_SIZE - 6), DARKGRAY);
      DrawLine((int)(btn.x + BTN_SIZE - 6), (int)(btn.y + 6), (int)(btn.x + 6),
               (int)(btn.y + BTN_SIZE - 6), DARKGRAY);
    }
  }
}

int main() {
  GameState game;
  init_game(&game);

  int gameOver = 0;
  char resultMessage[64] = "";
  char winSymbol = 0;
  bool quit = false;

SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_WINDOW_HIGHDPI);
  InitWindow(LOGICAL_WIDTH, LOGICAL_HEIGHT, "Tic-Tac-Toe");
  SetTargetFPS(60);

  while (!WindowShouldClose() && !quit) {
    enum WindowAction action = get_window_action();
    if (action == ACTION_MINIMIZE) {
      MinimizeWindow();
    } else if (action == ACTION_MAXIMIZE) {
      if (IsWindowMaximized()) {
        RestoreWindow();
      } else {
        MaximizeWindow();
      }
    } else if (action == ACTION_CLOSE) {
      quit = true;
    }

    cellSize =
        fminf((GetScreenWidth() - 2 * PAD) / BOARD_SIZE,
              (GetScreenHeight() - TOP_BAND - BOTTOM_BAND) / BOARD_SIZE);
    if (cellSize < 40.0f) {
      cellSize = 40.0f;
    }
    gridSize = cellSize * BOARD_SIZE;
    gridX = (GetScreenWidth() - gridSize) * 0.5f;
    gridY =
        TOP_BAND + (GetScreenHeight() - TOP_BAND - BOTTOM_BAND - gridSize) * 0.5f;

    if (!gameOver) {
      int choiceIndex = 0;

      if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        choiceIndex = get_cell_index(GetMouseX(), GetMouseY());
      } else {
        for (int key = KEY_ONE; key <= KEY_NINE; key++) {
          if (IsKeyPressed(key)) {
            choiceIndex = key - KEY_ONE + 1;
            break;
          }
        }
      }

      Player *currentPlayer =
          game.currentPlayer == 1 ? &game.p1 : &game.p2;

      if (choiceIndex > 0 && is_valid_move(&game, choiceIndex)) {
        int result = make_move(&game, choiceIndex);
        if (result == MOVE_WIN) {
          snprintf(resultMessage, sizeof(resultMessage),
                   "Player %d is the winner!", currentPlayer->id);
          winSymbol = currentPlayer->sym;
          gameOver = 1;
        } else if (result == MOVE_DRAW) {
          snprintf(resultMessage, sizeof(resultMessage), "It's a draw!");
          gameOver = 1;
        }
      }
    } else if (IsKeyPressed(KEY_R) || IsKeyPressed(KEY_ENTER)) {
      reset_board(&game);
      gameOver = 0;
      winSymbol = 0;
    }

    Player *currentPlayer = game.currentPlayer == 1 ? &game.p1 : &game.p2;

    BeginDrawing();

    ClearBackground(RAYWHITE);

    draw_centered_text("Tic-Tac-Toe", 8, 20, DARKGRAY);

    const char *score = TextFormat("Player %d (%c): %d win(s)   vs   "
                                   "Player %d (%c): %d win(s)",
                                   game.p1.id, game.p1.sym, game.p1.wins,
                                   game.p2.id, game.p2.sym, game.p2.wins);
    draw_centered_text(score, 34, 15, DARKGRAY);

    draw_window_buttons();

    draw_board(&game, gameOver, currentPlayer->sym);

    if (gameOver) {
      if (winSymbol != 0) {
        draw_win_line(game.board, winSymbol);
      }
      draw_centered_text(resultMessage, gridY + gridSize + 14, 22,
                         winSymbol == SYM_X   ? RED
                         : winSymbol == SYM_O ? BLUE
                                              : DARKGRAY);
      draw_centered_text("Press R or ENTER to play again",
                         gridY + gridSize + 40, 16, DARKGRAY);
    } else {
      char hint[80];
      snprintf(hint, sizeof(hint),
               "Player %d's turn - click a cell or press keys 1-9",
               currentPlayer->id);
      draw_centered_text(hint, gridY + gridSize + 22, 16, DARKGRAY);
    }

    EndDrawing();
  }

  CloseWindow();

  return EXIT_SUCCESS;
}