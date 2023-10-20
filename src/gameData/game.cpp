#include "game.h"
#include "screens/screen.h"
#include "elements/spaceship.h"
#include "raymath.h"
#include <iostream>

using namespace std;

//static void update(Vector2 mouse, SpaceShip ship);
static void drawGame(Vector2 mouse, SpaceShip ship);

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

    SpaceShip ship = {};

    initShip(ship);


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
            //update(mouse, ship);
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
            //DrawText("GAMEPLAY", GetScreenWidth() / 2, GetScreenHeight() / 2, 30, RAYWHITE);
            drawGame(mouse, ship);
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
//
//void update(Vector2 mouse, SpaceShip ship)
//{
//  /*  Vector2 posMouse = mouse;
//    Vector2 posShip = getPosition(ship);
//
//    Vector2 vectorDirection = Vector2Subtract(posMouse, posShip);
//
//    double angle = atan2 (vectorDirection.y , vectorDirection.x);*/
//}

void drawGame(Vector2 mouse, SpaceShip ship)
{
    Rectangle rec = { static_cast<float>(GetScreenWidth() / 2), static_cast<float>(GetScreenHeight() / 2), 20.0f, 100.0f };
    Vector2 origin = { rec.width / 2, rec.height / 2 };

    Vector2 posMouse = mouse;
    Vector2 posShip = getPosition(ship);
    cout << posShip.x << " " << posShip.y << endl;

    Vector2 vectorDirection = Vector2Subtract(posMouse, posShip);

    double angle = atan2(static_cast<double>(vectorDirection.y), static_cast<double>(vectorDirection.x) ) * RAD2DEG + 90;

    cout << ship.pos.x << " " << ship.pos.y << endl;
    DrawRectanglePro(rec, origin, static_cast<float>(angle), WHITE);
}