#include "game.h"
#include "screens/screen.h"

void runGame()
{
    const int screenWidth = 1024;
    const int screenHeight = 768;
    bool isGameRunning = true;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    GameScreen currentScreen = GameScreen::MENU;

    RectangleButton rectangleTitle;
    RectangleButton rectanglePlay;
    RectangleButton rectangleRules;
    RectangleButton rectangleCredits;
    RectangleButton rectangleExit;


    while (!WindowShouldClose() && isGameRunning)
    {
        BeginDrawing();

        ClearBackground(BLACK);

        Vector2 mouse = { static_cast<float>(GetMouseX()), static_cast<float>(GetMouseY()) };

        switch (currentScreen)
        {
        case GameScreen::MENU:
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && rectanglePlay.isSelected == true)
            {
                currentScreen = GameScreen::GAMEPLAY;
            }
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && rectangleRules.isSelected == true)
            {
                currentScreen = GameScreen::RULES;
            }
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && rectangleCredits.isSelected == true)
            {
                currentScreen = GameScreen::CREDITS;
            }
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && rectangleExit.isSelected == true)
            {
                currentScreen = GameScreen::EXIT;
            }
            break;
        case GameScreen::GAMEPLAY:
            break;
        case GameScreen::RULES:       
            break;
        case GameScreen::CREDITS:
            break;
        case GameScreen::EXIT:

            isGameRunning = false;

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
            DrawText("GAMEPLAY", GetScreenWidth() / 2, GetScreenHeight() / 2, 30, RAYWHITE);
            break;
        case GameScreen::RULES:
            DrawText("RULES", GetScreenWidth() / 2, GetScreenHeight() / 2, 30, RAYWHITE);
            break;
        case GameScreen::CREDITS:
            DrawText("CREDITS", GetScreenWidth() / 2, GetScreenHeight() / 2, 30, RAYWHITE);
            break;
        case GameScreen::EXIT:
            DrawText("EXIT", GetScreenWidth() / 2, GetScreenHeight() / 2, 30, RAYWHITE);
            break;
        default:
            break;
        }

        EndDrawing();
    }

    CloseWindow();
}