#include "game.h"
#include "screens/screen.h"
#include "elements/spaceship.h"
#include "elements/asteroid.h"
#include "raymath.h"
#include <iostream>

using namespace std;

static void update(Vector2 mouse, SpaceShip& ship, Asteroid asteroids[]);
static void drawGame(SpaceShip ship, Asteroid asteroid);

void runGame()
{
    srand(time(NULL));
    const int screenWidth = 1024;
    const int screenHeight = 768;
    const int maxAsteroids = 10;
    bool isGameRunning = true;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    Texture2D texTest = LoadTexture("assets/TestShip.png");

    GameScreen currentScreen = GameScreen::MENU;

    RectangleButton rectangleTitle;
    RectangleButton rectanglePlay;
    RectangleButton rectangleRules;
    RectangleButton rectangleCredits;
    RectangleButton rectangleExit;

    SpaceShip ship = {};
    Asteroid asteroid = {};
    Asteroid asteroids[maxAsteroids];

    initShip(ship);

    for (int i = 0; i < maxAsteroids; i++)
    {
        initAsteroid(asteroid);
        asteroids[i] = asteroid;
    }


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
            update(mouse, ship, asteroids);
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
            drawGame(ship, asteroid);
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

void update(Vector2 mouse, SpaceShip& ship, Asteroid asteroids[])
{
    float ShipAcceleration = 0;
    float normalizedDirection = 0;
    Vector2 posMouse = mouse;
    Vector2 posShip = getPosition(ship);

    Vector2 vectorDirection = Vector2Subtract(posMouse, posShip);

    double angle = atan2(static_cast<double>(vectorDirection.y) , static_cast<double>(vectorDirection.x)) * RAD2DEG + 90;
   
    ship.rotation = static_cast<float>(angle);

    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
    {
        normalizedDirection = static_cast<float>(sqrt(pow(vectorDirection.x, 2) + pow(vectorDirection.y, 2)));

        ShipAcceleration += normalizedDirection;
    }

    ship.pos.x = posShip.x + ShipAcceleration * GetFrameTime();
    ship.pos.y = posShip.y + ShipAcceleration * GetFrameTime();
}

void drawGame(SpaceShip ship, Asteroid asteroid)
{
    Rectangle rec = { ship.pos.x, ship.pos.y, ship.size.x, ship.size.y };
    
    DrawCircle(asteroid.pos.x, asteroid.pos.y, asteroid.radius, RED);
    DrawRectanglePro(rec, ship.origin, ship.rotation, WHITE);
    //DrawTexturePro(ship.texShip, { 0.0f, 0.0f, static_cast<float>(ship.size.y), static_cast<float>(ship.size.y) }, { static_cast<float>(GetScreenWidth() / 2), static_cast<float>(GetScreenHeight() / 2) }, ship.origin, ship.rotation, RAYWHITE);
}