#include "game.h"
#include "screens/screen.h"
#include "elements/spaceship.h"
#include "elements/asteroid.h"
#include "raymath.h"
#include <iostream>

using namespace std;

static void update(Vector2 mouse, SpaceShip& ship, Asteroid asteroids[]);
static void drawGame(SpaceShip ship, Asteroid asteroids[], int maxAsteroids);

void runGame()
{
    srand((unsigned int)time(NULL));
    const int screenWidth = 1024;
    const int screenHeight = 768;
    const int maxAsteroids = 10;
    bool isGameRunning = true;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    Texture2D texTest = LoadTexture("assets/MainShip.png");

    GameScreen currentScreen = GameScreen::MENU;

    RectangleButton rectangleTitle;
    RectangleButton rectanglePlay;
    RectangleButton rectangleRules;
    RectangleButton rectangleCredits;
    RectangleButton rectangleExit;

    SpaceShip ship = {};
    Asteroid asteroid = {};
    Asteroid asteroids[maxAsteroids];

    initShip(ship, texTest);

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
            else if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && rectangleRules.isSelected == true)
            {
                currentScreen = GameScreen::RULES;
            }
            else if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && rectangleCredits.isSelected == true)
            {
                currentScreen = GameScreen::CREDITS;
            }
            else if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && rectangleExit.isSelected == true)
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
            drawGame(ship, asteroids, maxAsteroids);
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
    float normalizedDirectionAsteroid = 0;
    float normalizedDirectionShip = 0;
    double angleShip = 0;
    double angleAsteroid = 0;
    Vector2 posMouse = mouse;
    Vector2 posShip = getPosition(ship);
    asteroids;
    Vector2 vectorDirectionShip = Vector2Subtract(posMouse, posShip);
    if (vectorDirectionShip.x != 0 || vectorDirectionShip.y != 0)
    {
        angleShip = atan2(static_cast<double>(vectorDirectionShip.y) , static_cast<double>(vectorDirectionShip.x)) * RAD2DEG + 90;
    }
   
    ship.rotation = static_cast<float>(angleShip);

    normalizedDirectionShip = static_cast<float>(sqrt(pow(vectorDirectionShip.x, 2) + pow(vectorDirectionShip.y, 2)));
       
    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
    {
        ship.ShipAcceleration.x += (vectorDirectionShip.x / normalizedDirectionShip) * GetFrameTime();
        ship.ShipAcceleration.y += (vectorDirectionShip.y / normalizedDirectionShip) * GetFrameTime();
    }

    ship.pos.x += ship.ShipAcceleration.x * GetFrameTime() * 100;
    ship.pos.y += ship.ShipAcceleration.y * GetFrameTime() * 100;
}

void drawGame(SpaceShip ship, Asteroid asteroids[], int maxAsteroids)
{
    Rectangle rec = { ship.pos.x, ship.pos.y, ship.size.x, ship.size.y };
    
    for (int i = 0; i < maxAsteroids; i++)
    {
        DrawCircle(static_cast<int>(asteroids[i].pos.x), static_cast<int>(asteroids[i].pos.y), asteroids[i].radius, RED);

    }
    DrawCircle(static_cast<int>(ship.pos.x), static_cast<int>(ship.pos.y), ship.radius, YELLOW);
    DrawTexturePro(ship.texShip, { 0.0f, 0.0f,static_cast<float>(ship.texShip.width), static_cast<float>(ship.texShip.height) }, { static_cast<float>(ship.pos.x),static_cast<float>(ship.pos.y), static_cast<float>(ship.size.x), static_cast<float>(ship.size.y) }, { static_cast<float>(ship.size.x / 2), static_cast<float>(ship.size.y / 2) }, ship.rotation, RAYWHITE);
}