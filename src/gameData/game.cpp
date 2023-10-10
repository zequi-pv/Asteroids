#include "game.h"
#include "screens/screen.h"

void runGame()
{
    const int screenWidth = 1024;
    const int screenHeight = 768;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    GameScreen currentScreen = GameScreen::MENU;

    RectangleButton rectangleTitle;
    RectangleButton rectanglePlay;
    RectangleButton rectangleRules;
    RectangleButton rectangleCredits;
    RectangleButton rectangleExit;

    Vector2 mouse = { static_cast<float>(GetMouseX()), static_cast<float>(GetMouseY()) };

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(BLACK);

        //DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

        switch (currentScreen)
        {
        case GameScreen::MENU:
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && optionsCollision(mouse, rectanglePlay))
            {
                currentScreen = GameScreen::GAMEPLAY;
            }
            break;
        case GameScreen::GAMEPLAY:
            break;
        case GameScreen::RULES:
            break;
        case GameScreen::CREDITS:
            break;
        case GameScreen::EXIT:
            break;
        default:
            break;
        }

        switch (currentScreen)
        {
        case GameScreen::MENU:
            drawMenu(rectangleTitle, rectanglePlay, rectangleRules, rectangleCredits, rectangleExit, mouse);
            break;
        case GameScreen::GAMEPLAY:
            break;
        case GameScreen::RULES:
            break;
        case GameScreen::CREDITS:
            break;
        case GameScreen::EXIT:
            break;
        default:
            break;
        }

        EndDrawing();
    }

    CloseWindow();
}