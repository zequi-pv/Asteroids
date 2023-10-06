#include "game.h"
#include "screens/screen.h"

void runGame()
{
    const int screenWidth = 1024;
    const int screenHeight = 768;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

        drawMenu();

        EndDrawing();
    }

    CloseWindow();
}