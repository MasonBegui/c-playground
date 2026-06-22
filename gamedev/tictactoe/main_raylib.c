#include <stdlib.h>
#include <stdio.h>
#include "raylib.h"

int main(int argc, const char *argv[]){
    printf("I am the raylib\n");
    const int screenWidth = 800;
    const int screenHeight = 600;
    const char *windowtitle = "Tic-Tac-Toe";

        // 1. Initialize the window
    InitWindow(screenWidth, screenHeight, windowtitle);

    // Limit the game to 60 frames per second
    SetTargetFPS(60);

    // 2. Main game loop
    while (!WindowShouldClose()) {
        // 3. Drawing
        BeginDrawing();

        ClearBackground(RAYWHITE);
        DrawText("Hello, Raylib 6!", 190, 200, 40, LIGHTGRAY);
        EndDrawing();
    }

    // 4. De-initialize and clean up
    CloseWindow();


    return EXIT_SUCCESS;
}