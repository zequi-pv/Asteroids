#include <iostream>
#include "raylib.h"
#include "raymath.h"
#include "game.h"
#include "screens/screen.h"
#include "elements/spaceship.h"
#include "elements/asteroid.h"
#include "elements/bullet.h"

#define screenWidth 1024
#define screenHeight 768
#define maxBullets 400


using namespace std;

static void update(Vector2 mouse, SpaceShip& ship, Asteroid bigAsteroids[], Vector2 vectorDirectionAsteroid, Bullet bullets[], bool gameOver, bool pause, int maxBigAsteroids/*, int maxMediumAsteroids, int maxSmallAsteroids*/);
static void drawGame(SpaceShip ship, Asteroid bigAsteroids[], Bullet bullets[], bool pause, int maxBigAsteroids, int maxMediumAsteroids, int maxSmallAsteroids);
static void screenCollision(SpaceShip& ship, Asteroid asteroids[], int maxAsteroids);
static bool gameCollision(SpaceShip& ship, Asteroid asteroids[], int maxAsteroids);

void runGame()
{
    srand((unsigned int)time(NULL));
    bool isGameRunning = true;
    int randEndX = GetRandomValue(1, 1024);
    int randEndY = GetRandomValue(1, 768);
    const int maxBigAsteroids = 10;
    const int maxMediumAsteroids = 20;
    const int maxSmallAsteroids = 40;
    bool pause = false;
    bool gameOver = false; 

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    Texture2D texTest = LoadTexture("assets/MainShip.png");

    GameScreen currentScreen = GameScreen::MENU;

    RectangleButton rectangleTitle;
    RectangleButton rectanglePlay;
    RectangleButton rectangleRules;
    RectangleButton rectangleCredits;
    RectangleButton rectangleExit;
    RectangleButton rectangleReturn;
    RectangleButton rectangleContinue;

    SpaceShip ship = {};
    Bullet bullet = {};
    Bullet bullets[maxBullets] = {};
    Asteroid bigAsteroid = {};
    Asteroid mediumAsteroid = {};
    Asteroid smallAsteroid = {};
    Asteroid bigAsteroids[maxBigAsteroids] = {};
    Asteroid mediumAsteroids[maxMediumAsteroids] = {};
    Asteroid smallAsteroids[maxSmallAsteroids] = {};
    Vector2 vectorDirectionAsteroid = {};
    Vector2 posEnd = { static_cast<float>(randEndX), static_cast<float>(randEndY) };

    initShip(ship, texTest);

    for (int i = 0; i < maxBigAsteroids; i++)
    {
        initAsteroid(bigAsteroid);
        bigAsteroids[i] = bigAsteroid;
    }

    for (int i = 0; i < maxMediumAsteroids; i++)
    {
        initMedAsteroid(mediumAsteroid);
        mediumAsteroids[i] = mediumAsteroid;
    }

    for (int i = 0; i < maxMediumAsteroids; i++)
    {
        initMedAsteroid(mediumAsteroid);
        mediumAsteroids[i] = mediumAsteroid;
    }

    for (int i = 0; i < maxBigAsteroids; i++)
    {
        vectorDirectionAsteroid = Vector2Subtract(bigAsteroids[i].pos, posEnd);
    }

    for (int i = 0; i < maxBullets; i++)
    {
        initBullet(bullet);
        bullet.pos = { ship.pos.x, ship.pos.y };
        bullets[i] = bullet;
    }
    

    while (!WindowShouldClose() && isGameRunning)
    {
        SetExitKey(NULL);

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
            update(mouse, ship, bigAsteroids, vectorDirectionAsteroid, bullets, gameOver, pause, maxBigAsteroids/*, maxMediumAsteroids, maxSmallAsteroids*/);
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
            drawGame(ship, bigAsteroids, bullets, pause, maxBigAsteroids, maxMediumAsteroids, maxSmallAsteroids);
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

void update(Vector2 mouse, SpaceShip& ship, Asteroid bigAsteroids[], Vector2 vectorDirectionAsteroid, Bullet bullets[], bool gameOver, bool pause, int maxBigAsteroids/*, int maxMediumAsteroids, int maxSmallAsteroids*/)
{
    if (IsKeyPressed(KEY_ESCAPE))
    {
        pause = !pause;
    }

    if (!gameOver && !pause)
    {
        float normalizedDirectionAsteroid = 0;
        double angleAsteroid = 0;
        float normalizedDirectionShip = 0;
        double angleShip = 0;
        Vector2 posMouse = mouse;
        Vector2 posShip = getPosition(ship);
        Vector2 vectorDirectionShip = Vector2Subtract(posMouse, posShip);

        for (int i = 0; i < maxBigAsteroids; i++)
        {
            angleAsteroid = atan2(static_cast<double>(vectorDirectionAsteroid.x), static_cast<double>(vectorDirectionAsteroid.y)) * RAD2DEG;
            bigAsteroids[i].rotation = static_cast<float>(angleAsteroid);
            normalizedDirectionAsteroid = static_cast<float>(sqrt(pow(vectorDirectionAsteroid.x, 2) + pow(vectorDirectionAsteroid.y, 2)));
            bigAsteroids[i].pos.x += (vectorDirectionAsteroid.x / normalizedDirectionAsteroid) * GetFrameTime() * 50;
            bigAsteroids[i].pos.y += (vectorDirectionAsteroid.y / normalizedDirectionAsteroid) * GetFrameTime() * 50;
        }

        
        
        

        if (vectorDirectionShip.x != 0 || vectorDirectionShip.y != 0)
        {
            angleShip = atan2(static_cast<double>(vectorDirectionShip.y), static_cast<double>(vectorDirectionShip.x)) * RAD2DEG + 90;
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

        if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT))
        {
            for (int i = 0; i < maxBullets; i++)
            {
                if (bullets[i].isActive)
                {
                    bullets[i].pos.x += GetFrameTime() * 100;
                    bullets[i].pos.y += GetFrameTime() * 100;

                    if (bulletOutofBounds(bullets[i]))
                    {
                        bullets[i].isActive = false;
                    }
                }
                if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT))
                {
                    bullets[i].isActive = true;
                    bullets[i].pos = { ship.pos.x, ship.pos.y };
                }
            }
        }

        screenCollision(ship, bigAsteroids, maxBigAsteroids);

        if (gameCollision(ship, bigAsteroids, maxBigAsteroids))
        {
            ship.lives--;
        }
        /*if (gameCollision(ship, bigAsteroids, maxMediumAsteroids))
        {
            ship.lives--;
        }
        if (gameCollision(ship, bigAsteroids, maxSmallAsteroids))
        {
            ship.lives--;
        }*/
        cout << ship.lives << endl;
        if (ship.lives <= 0)
        {
            gameOver = true;
            DrawText("GAME OVER", GetScreenWidth() / 2, GetScreenHeight() / 2, 40, RAYWHITE);
        }
        
    }
    
}

void drawGame(SpaceShip ship, Asteroid bigAsteroids[],Bullet bullets[], bool pause, int maxBigAsteroids, int maxMediumAsteroids, int maxSmallAsteroids)
{
    maxSmallAsteroids;
    maxMediumAsteroids;
    if (pause)
    {
        DrawText("PAUSED", GetScreenWidth() / 2, GetScreenHeight() / 2, 40, RAYWHITE);
    }

    for (int i = 0; i < maxBullets; i++)
    {
        if (bullets[i].isActive)
        {
            cout << "Dibuja" << endl;
            DrawCircle(static_cast<int>(bullets[i].pos.x), static_cast<int>(bullets[i].pos.y), bullets[i].radius, WHITE);
        }
    }
    

    for (int i = 0; i < maxBigAsteroids; i++)
    {
        DrawCircle(static_cast<int>(bigAsteroids[i].pos.x), static_cast<int>(bigAsteroids[i].pos.y), bigAsteroids[i].radius, RED);

    }
    DrawCircle(static_cast<int>(ship.pos.x), static_cast<int>(ship.pos.y), ship.radius, YELLOW);
    DrawTexturePro(ship.texShip, { 0.0f, 0.0f,static_cast<float>(ship.texShip.width), static_cast<float>(ship.texShip.height) }, { static_cast<float>(ship.pos.x),static_cast<float>(ship.pos.y), static_cast<float>(ship.size.x), static_cast<float>(ship.size.y) }, { static_cast<float>(ship.size.x / 2), static_cast<float>(ship.size.y / 2) }, ship.rotation, RAYWHITE);
}

void PausedGame(bool& pause, RectangleButton rectangleReturn, RectangleButton rectangleContinue)
{
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && rectangleContinue.isSelected)
    {
        pause = false;
    }
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && rectangleReturn.isSelected)
    {

    }
}

void returnToMenu(GameScreen& currentScreen)
{

    currentScreen = GameScreen::MENU;
}

void resetGame() {}

bool gameCollision(SpaceShip& ship, Asteroid asteroids[], int maxAsteroids)
{
    for (int i = 0; i < maxAsteroids; i++)
    {
        float distX = ship.pos.x - asteroids[i].pos.x;
        float distY = ship.pos.y - asteroids[i].pos.y;
        float distance = static_cast<float>(sqrt(pow(distX, 2) + pow(distY, 2)));

        if (distance <= ship.radius + asteroids[i].radius)
        {
            return true;
        }
    }
    return false;
}

void screenCollision(SpaceShip& ship, Asteroid asteroids[], int maxAsteroids)
{
    if (ship.pos.x + ship.radius >= GetScreenWidth())
    {
        ship.pos.x = 0 + ship.radius;
    }
    else if (ship.pos.x - ship.radius <= 0) 
    {
        ship.pos.x = GetScreenWidth() - ship.radius;
    }

    if (ship.pos.y + ship.radius >= GetScreenHeight())
    {
        ship.pos.y = 0 + ship.radius;
    }
    else if (ship.pos.y - ship.radius <= 0)
    {
        ship.pos.y = GetScreenHeight() - ship.radius;
    }

    for (int  i = 0; i < maxAsteroids; i++)
    {
        if (asteroids[i].pos.x + asteroids[i].radius > GetScreenWidth())
        {
            asteroids[i].pos.x = 0 + asteroids[i].radius;
        }
        else if (asteroids[i].pos.x - asteroids[i].radius < 0)
        {
            asteroids[i].pos.x = GetScreenWidth() - asteroids[i].radius;
        }

        if (asteroids[i].pos.y + asteroids[i].radius > GetScreenHeight())
        {
            asteroids[i].pos.y = 0 + asteroids[i].radius;
        }
        else if (asteroids[i].pos.y - asteroids[i].radius < 0)
        {
            asteroids[i].pos.y = GetScreenHeight() - asteroids[i].radius;
        }
    }
}