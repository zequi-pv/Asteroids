#include "game.h"

#include <iostream>

#include "raylib.h"
#include "raymath.h"

#include "screens/screen.h"
#include "elements/spaceship.h"
#include "elements/asteroid.h"
#include "elements/bullet.h"

using namespace std;

static void update(Vector2 mouse,
    SpaceShip& ship,
    Asteroid& asteroid,
    Asteroid asteroids[],
    Bullet& bullet,
    Bullet bullets[],
    bool gameOver,
    bool& pause,
    int maxAsteroids,
    int maxBullets,
    RectangleButton& rectangleReturn,
    RectangleButton& rectangleContinue,
    GameScreen& currentScreen,
    Texture2D Ship);
static void drawGame(SpaceShip ship, Asteroid asteroids[], Bullet bullets[], bool pause, int maxAsteroids, Texture2D backGround, Texture2D texAsteroid, int maxBullets, Texture2D livesTex, Texture2D scoreTex, Texture2D paused, RectangleButton& rectangleReturn, RectangleButton& rectangleContinue, Texture2D returnButton, Texture2D returnButtonC, Texture2D continueButton, Texture2D continueButtonC, Vector2& mouse);
static void screenCollision(SpaceShip& ship, Asteroid asteroids[], int maxAsteroids);
static bool gameCollision(SpaceShip& ship, Asteroid asteroids[], int maxAsteroids);
static void shoot(Bullet bullets[], SpaceShip ship, int maxBullets);
static void bulletCollision(Bullet bullets[], Asteroid asteroids[], int maxAsteroids, int maxBullets, SpaceShip& ship);
static void initAll(SpaceShip& ship,
    Texture2D Ship,
    Asteroid& asteroid,
    Asteroid asteroids[],
    int maxAsteroids,
    int maxBullets,
    Bullet& bullet,
    Bullet bullets[]);
static void returnToMenu(GameScreen& currentScreen,
    SpaceShip& ship,
    Texture2D Ship,
    Asteroid& asteroid,
    Asteroid asteroids[],
    int maxAsteroids,
    int maxBullets,
    Bullet& bullet,
    Bullet bullets[],
    bool& pause,
    bool& gameOver);
static void resetGame(SpaceShip& ship,
    Texture2D Ship,
    Asteroid& asteroid,
    Asteroid asteroids[],
    int maxAsteroids,
    int maxBullets,
    Bullet& bullet,
    Bullet bullets[],
    bool& pause,
    bool& gameOver);
static void initMatch(SpaceShip& ship,
    Asteroid& asteroid,
    Asteroid asteroids[],
    int maxAsteroids,
    int maxBullets,
    Bullet& bullet,
    Bullet bullets[]);

namespace game
{
    extern void runGame()
    {
        srand(static_cast<unsigned>(time(NULL)));
        const int screenWidth = 1024;
        const int screenHeight = 768;
        const int maxBullets = 400;
        bool isGameRunning = true;
        
        const int maxAsteroids = 70;
        bool pause = false;
        bool gameOver = false;

        InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

        Texture2D Ship = LoadTexture("res/MainShip.png");
        Texture2D menuBackground = LoadTexture("res/menuBackGround.png");
        Texture2D backGround = LoadTexture("res/backGround.png");
        Texture2D texAsteroid = LoadTexture("res/Asteroid.png");
        Texture2D rulesBackground = LoadTexture("res/rules.png");
        Texture2D creditsBackground = LoadTexture("res/creditsBack.png");
        Texture2D playButton = LoadTexture("res/Buttons/PLAY.png");
        Texture2D rulesButton = LoadTexture("res/Buttons/rulesB.png");
        Texture2D creditsButton = LoadTexture("res/Buttons/CREDITS.png");
        Texture2D exitButton = LoadTexture("res/Buttons/EXIT.png");
        Texture2D returnButton = LoadTexture("res/Buttons/RETURN.png");
        Texture2D continueButton = LoadTexture("res/Buttons/CONTINUE.png");
        Texture2D playButtonC = LoadTexture("res/Buttons/Clicked/plays.png");
        Texture2D rulesButtonC = LoadTexture("res/Buttons/Clicked/rulesBS.png");
        Texture2D creditsButtonC = LoadTexture("res/Buttons/Clicked/creditss.png");
        Texture2D exitButtonC = LoadTexture("res/Buttons/Clicked/exits.png");
        Texture2D returnButtonC = LoadTexture("res/Buttons/Clicked/returns.png");
        Texture2D continueButtonC = LoadTexture("res/Buttons/Clicked/continues.png");
        Texture2D livesTex = LoadTexture("res/Lives.png");
        Texture2D scoreTex = LoadTexture("res/Score_.png");
        Texture2D paused = LoadTexture("res/paused.png");
        Texture2D gameOverScreen = LoadTexture("res/gameover.png");
        Texture2D gameWinScreen = LoadTexture("res/you_won.png");
        Texture2D githubB = LoadTexture("res/github.png");
        Texture2D githubBC = LoadTexture("res/github_gris.png");
        Texture2D instaB = LoadTexture("res/Instagram.png");
        Texture2D instaBC = LoadTexture("res/instagram_gris.png");
        Texture2D itchB = LoadTexture("res/itch.png");
        Texture2D itchBC = LoadTexture("res/itch_gris.png");

        GameScreen currentScreen = GameScreen::MENU;

        RectangleButton rectanglePlay;
        RectangleButton rectangleRules;
        RectangleButton rectangleCredits;
        RectangleButton rectangleExit;
        RectangleButton rectangleReturn;
        RectangleButton rectangleContinue;
        RectangleButton itchOne;
        RectangleButton itchTwo;
        RectangleButton insta;
        RectangleButton github;

        SpaceShip ship = {};
        Bullet bullet = {};
        Bullet bullets[maxBullets] = {};
        Asteroid asteroid = {};
        Asteroid asteroids[maxAsteroids] = {};
        Vector2 vectorDirectionAsteroid = {};
       
        initAll(ship, Ship, asteroid, asteroids, maxAsteroids, maxBullets, bullet, bullets);

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
                update(mouse, ship, asteroid, asteroids, bullet, bullets, gameOver, pause, maxAsteroids, maxBullets, rectangleReturn, rectangleContinue, currentScreen, Ship);
                break;
            case GameScreen::RULES:
                if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && rectangleReturn.isSelected == true)
                {
                    currentScreen = GameScreen::MENU;
                }
                break;
            case GameScreen::CREDITS:
                if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && rectangleReturn.isSelected == true)
                {
                    currentScreen = GameScreen::MENU;
                }
                if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && itchOne.isSelected == true)
                {
                    OpenURL("https://rayder01.itch.io");
                }
                if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && itchTwo.isSelected == true)
                {
                    OpenURL("https://fiorellagaston.itch.io");
                }
                if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && insta.isSelected == true)
                {
                    OpenURL("https://www.instagram.com/fio.gn_/");
                }
                if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && github.isSelected == true)
                {
                    OpenURL("https://github.com/zequi-pv/Asteroids");
                }
                break;
            case GameScreen::GAMEOVER:
                if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && rectangleReturn.isSelected == true)
                {
                    returnToMenu(currentScreen, ship, Ship, asteroid, asteroids, maxAsteroids, maxBullets, bullet, bullets, pause, gameOver);
                    currentScreen = GameScreen::MENU;

                }
                if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && rectangleContinue.isSelected == true)
                {
                    currentScreen = GameScreen::GAMEPLAY;
                    resetGame(ship, Ship, asteroid, asteroids, maxAsteroids, maxBullets, bullet, bullets, pause, gameOver);
                }
                break;
            case GameScreen::GAMEWIN:
                if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && rectangleReturn.isSelected == true)
                {
                    returnToMenu(currentScreen, ship, Ship, asteroid, asteroids, maxAsteroids, maxBullets, bullet, bullets, pause, gameOver);
                    currentScreen = GameScreen::MENU;

                }
                if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && rectangleContinue.isSelected == true)
                {
                    currentScreen = GameScreen::GAMEPLAY;
                    resetGame(ship, Ship, asteroid, asteroids, maxAsteroids, maxBullets, bullet, bullets, pause, gameOver);
                }
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
                drawMenu(rectanglePlay, rectangleRules, rectangleCredits, rectangleExit, mouse, menuBackground, playButton, playButtonC, rulesButton, rulesButtonC, creditsButton, creditsButtonC, exitButton, exitButtonC);
                break;
            case GameScreen::GAMEPLAY:
                drawGame(ship, asteroids, bullets, pause, maxAsteroids, backGround, texAsteroid, maxBullets, livesTex, scoreTex, paused, rectangleReturn, rectangleContinue, returnButton,returnButtonC, continueButton, continueButtonC, mouse);
                break;
            case GameScreen::RULES:
                drawRules(rectangleReturn, mouse, rulesBackground, returnButton, returnButtonC);
                break;
            case GameScreen::CREDITS:
                drawCredits(rectangleReturn, mouse, creditsBackground, returnButton, returnButtonC, githubB, githubBC, instaB, instaBC, itchB, itchBC, itchOne, itchTwo, insta, github);
                break;
            case GameScreen::GAMEOVER:
                drawGameOver(rectangleReturn, rectangleContinue, returnButton, returnButtonC, continueButton, continueButtonC, mouse, gameOverScreen);
                break;
            case GameScreen::GAMEWIN:
                drawGameWin(rectangleReturn, rectangleContinue, returnButton, returnButtonC, continueButton, continueButtonC, mouse, gameWinScreen);
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
}



void update(Vector2 mouse, 
    SpaceShip& ship,
    Asteroid& asteroid,
    Asteroid asteroids[], 
    Bullet& bullet,
    Bullet bullets[], 
    bool gameOver, 
    bool& pause, 
    int maxAsteroids, 
    int maxBullets, 
    RectangleButton& rectangleReturn, 
    RectangleButton& rectangleContinue, 
    GameScreen& currentScreen,
    Texture2D Ship)
{
    if (IsKeyPressed(KEY_ESCAPE))
    {
        pause = true;
        
    }
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && rectangleReturn.isSelected == true && pause)
    {
        returnToMenu(currentScreen, ship, Ship, asteroid, asteroids, maxAsteroids, maxBullets, bullet, bullets, pause, gameOver);
        currentScreen = GameScreen::MENU;

    }
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && rectangleContinue.isSelected == true && pause)
    {
        cout << "Juego" << endl;
        pause = false;
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
        
        for (int i = 0; i < maxAsteroids; i++)
        {
            if (!asteroids[i].isActive && !asteroids[i].isDead && asteroids[i].isBig)
            {
                asteroids[i].isActive = true;
                angleAsteroid = atan2(static_cast<double>(asteroids[i].direction.x), static_cast<double>(asteroids[i].direction.y)) * RAD2DEG;
                asteroids[i].rotation = static_cast<float>(angleAsteroid);
            }           
        }

        for (int i = 0; i < maxAsteroids; i++)
        {
            normalizedDirectionAsteroid = static_cast<float>(sqrt(pow(asteroids[i].direction.x, 2) + pow(asteroids[i].direction.y, 2)));
            asteroids[i].pos.x += (asteroids[i].direction.x / normalizedDirectionAsteroid) * GetFrameTime() * 50;
            asteroids[i].pos.y += (asteroids[i].direction.y / normalizedDirectionAsteroid) * GetFrameTime() * 50;
        }

        if (vectorDirectionShip.x != 0 || vectorDirectionShip.y != 0)
        {
            angleShip = atan2(static_cast<double>(vectorDirectionShip.y), static_cast<double>(vectorDirectionShip.x)) * RAD2DEG + 90;
        }

        ship.rotation = static_cast<float>(angleShip);

        normalizedDirectionShip = static_cast<float>(sqrt(pow(vectorDirectionShip.x, 2) + pow(vectorDirectionShip.y, 2)));

        if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT))
        {
            ship.ShipAcceleration.x += (vectorDirectionShip.x / normalizedDirectionShip) * GetFrameTime();
            ship.ShipAcceleration.y += (vectorDirectionShip.y / normalizedDirectionShip) * GetFrameTime();
        }

        ship.pos.x += ship.ShipAcceleration.x * GetFrameTime() * 100;
        ship.pos.y += ship.ShipAcceleration.y * GetFrameTime() * 100;

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            shoot(bullets, ship, maxBullets);
        }


        for (int i = 0; i < maxBullets; i++)
        {
            if (bullets[i].isActive)
            {
                bullets[i].velocity = Vector2Scale(bullets[i].direction, bullets[i].speed * GetFrameTime());
                bullets[i].pos = Vector2Add(bullets[i].pos, bullets[i].velocity);

                if (bulletOutofBounds(bullets[i]))
                {
                    bullets[i].isActive = false;
                }
                
            }
        }

        screenCollision(ship, asteroids, maxAsteroids);
        bulletCollision(bullets, asteroids, maxAsteroids, maxBullets, ship);
       
        if (gameCollision(ship, asteroids, maxAsteroids))
        {
            ship.lives--;
            initMatch(ship, asteroid, asteroids, maxAsteroids, maxBullets, bullet, bullets);
        }

        if (ship.lives <= 0)
        {
            gameOver = true;
            currentScreen = GameScreen::GAMEOVER;
        }
        
       
            if (ship.destroyedAsteroids == 70) 
            {
                gameOver = true;
                currentScreen = GameScreen::GAMEWIN;
            }
        
    }
    
}

void bulletCollision(Bullet bullets[], Asteroid asteroids[], int maxAsteroids, int maxBullets, SpaceShip& ship)
{
    for (int i = 0; i < maxBullets; i++)
    {
        for (int j = 0; j < maxAsteroids; j++)
        {
            float distX = bullets[i].pos.x - asteroids[j].pos.x;
            float distY = bullets[i].pos.y - asteroids[j].pos.y;
            float distance = static_cast<float>(sqrt(pow(distX, 2) + pow(distY, 2)));
            if (bullets[i].isActive && asteroids[j].isActive)
            {
                if (distance <= bullets[i].radius + asteroids[j].radius)
                {
                    asteroids[j].isDead = true;
                    asteroids[j].isActive = false;
                    ship.score += 100;
                    ship.destroyedAsteroids++;
                    int counter = 0;

                    if (asteroids[j].isBig)
                    {
                        for (int k = 0; k < maxAsteroids; k++)
                        {
                            if (!asteroids[k].isActive)
                            {
                                asteroids[k].isActive = true;
                                asteroids[k].isDead = false;
                                asteroids[k].pos = asteroids[j].pos;
                                asteroids[k].isBig = false;
                                asteroids[k].isMedium = true;
                                asteroids[k].isSmall = false;

                                counter++;

                                if (counter == 2)
                                {
                                    break;
                                }
                            }
                        }
                    }
                    else if (asteroids[j].isMedium)
                    {
                        for (int k = 0; k < maxAsteroids; k++)
                        {
                            if (!asteroids[k].isActive)
                            {
                                asteroids[k].isActive = true;
                                asteroids[k].isDead = false;
                                asteroids[k].pos = asteroids[j].pos;
                                asteroids[k].isBig = false;
                                asteroids[k].isMedium = false;
                                asteroids[k].isSmall = true;

                                counter++;

                                if (counter == 2)
                                {
                                    break;
                                }
                            }
                        }
                    }


                }
            }


        }
    }
}

void shoot(Bullet bullets[], SpaceShip ship, int maxBullets) 
{
    for (int i = 0; i < maxBullets; i++)
    {
        if (!bullets[i].isActive)
        {
            bullets[i].isActive = true;
            bullets[i].pos = ship.pos;
            bullets[i].rotation = ship.rotation;
            bullets[i].direction = Vector2Subtract(GetMousePosition(), ship.pos);
            float length = Vector2Length(bullets[i].direction);
            bullets[i].direction = Vector2Divide(bullets[i].direction, { length, length });
            break;
        }
    }
}

void drawGame(SpaceShip ship, 
    Asteroid asteroids[],
    Bullet bullets[], 
    bool pause, 
    int maxAsteroids, 
    Texture2D backGround, 
    Texture2D texAsteroid, 
    int maxBullets, 
    Texture2D livesTex, 
    Texture2D scoreTex, 
    Texture2D paused, 
    RectangleButton& rectangleReturn, 
    RectangleButton& rectangleContinue, 
    Texture2D returnButton, 
    Texture2D returnButtonC, 
    Texture2D continueButton, 
    Texture2D continueButtonC, 
    Vector2& mouse)
{
    DrawTexturePro(backGround,
        { 0.0f, 0.0f, 1024.0f, 768.0f },
        { 0.0f, 0.0f, 1024.0f, 768.0f },
        { 0.0f, 0.0f },
        0.0f,
        RAYWHITE);

    if (pause)
    {
        rectangleReturn.rectangleX = 320;
        rectangleReturn.rectangleY = 350;
        rectangleReturn.rectangleWidth = 190;
        rectangleReturn.rectangleHeight = 50;
        rectangleContinue.rectangleX = 540;
        rectangleContinue.rectangleY = 350;
        rectangleContinue.rectangleWidth = 190;
        rectangleContinue.rectangleHeight = 50;
        //DrawRectangle(rectangleReturn.rectangleX, rectangleReturn.rectangleY, rectangleReturn.rectangleWidth, rectangleReturn.rectangleHeight, RAYWHITE);
        //DrawRectangle(rectangleContinue.rectangleX, rectangleContinue.rectangleY, rectangleContinue.rectangleWidth, rectangleContinue.rectangleHeight, RAYWHITE);
        DrawTexturePro(paused,
            { 0.0f, 0.0f, static_cast<float>(paused.width), static_cast<float>(paused.height) },
            { 420.0f, 280.0f, 200.0f , 50.0f },
            { 10.0f , 10.0f },
            0.0f, RAYWHITE);
        DrawTexturePro(returnButton,
            { 0.0f, 0.0f, static_cast<float>(returnButton.width), static_cast<float>(returnButton.height) },
            { static_cast<float>(rectangleReturn.rectangleX) , static_cast<float>(rectangleReturn.rectangleY), static_cast<float>(rectangleReturn.rectangleWidth), static_cast<float>(rectangleReturn.rectangleHeight) },
            { static_cast<float>(20 / 2), static_cast<float>(10 / 2) },
            0.0f,
            RAYWHITE);
        DrawTexturePro(continueButton,
            { 0.0f, 0.0f, static_cast<float>(continueButton.width), static_cast<float>(continueButton.height) },
            { static_cast<float>(rectangleContinue.rectangleX) , static_cast<float>(rectangleContinue.rectangleY), static_cast<float>(rectangleContinue.rectangleWidth), static_cast<float>(rectangleContinue.rectangleHeight) },
            { static_cast<float>(50 / 2), static_cast<float>(10 / 2) },
            0.0f,
            RAYWHITE);

        if (optionsCollision(mouse, rectangleReturn))
        {
            rectangleReturn.isSelected = true;
            DrawTexturePro(returnButtonC,
                { 0.0f, 0.0f, static_cast<float>(returnButtonC.width), static_cast<float>(returnButtonC.height) },
                { static_cast<float>(rectangleReturn.rectangleX) , static_cast<float>(rectangleReturn.rectangleY), static_cast<float>(rectangleReturn.rectangleWidth), static_cast<float>(rectangleReturn.rectangleHeight) },
                { static_cast<float>(20 / 2), static_cast<float>(10 / 2) },
                0.0f,
                RAYWHITE);
            
        }
        else if (!optionsCollision(mouse, rectangleReturn))
        {
            rectangleReturn.isSelected = false;
        }

        if (optionsCollision(mouse, rectangleContinue))
        {
            rectangleContinue.isSelected = true;
            DrawTexturePro(continueButtonC,
                { 0.0f, 0.0f, static_cast<float>(continueButtonC.width), static_cast<float>(continueButtonC.height) },
                { static_cast<float>(rectangleContinue.rectangleX) , static_cast<float>(rectangleContinue.rectangleY), static_cast<float>(rectangleContinue.rectangleWidth), static_cast<float>(rectangleContinue.rectangleHeight) },
                { static_cast<float>(50 / 2), static_cast<float>(10 / 2) },
                0.0f,
                RAYWHITE);

        }
        else if (!optionsCollision(mouse, rectangleContinue))
        {
            rectangleContinue.isSelected = false;
        }
    }

    for (int i = 0; i < maxBullets; i++)
    {
        if (bullets[i].isActive)
        {
            //cout << "Dibuje bala" << endl;
            DrawCircle(static_cast<int>(bullets[i].pos.x), static_cast<int>(bullets[i].pos.y), bullets[i].radius, WHITE);
        }
    }

    for (int i = 0; i < maxAsteroids; i++)
    {
        if (asteroids[i].isActive && asteroids[i].isBig)
        {
            asteroids[i].size.x = static_cast<float>(texAsteroid.width);
            asteroids[i].size.y = static_cast<float>(texAsteroid.width);
            DrawTexturePro(texAsteroid,
                { 0.0f, 0.0f, static_cast<float>(texAsteroid.width), static_cast<float>(texAsteroid.height) },
                { asteroids[i].pos.x, asteroids[i].pos.y, asteroids[i].size.x, asteroids[i].size.y },
                { asteroids[i].size.x / 2, asteroids[i].size.y / 2 },
                asteroids[i].rotation,
                RAYWHITE);
        }

        if (asteroids[i].isActive && asteroids[i].isMedium)
        {
            asteroids[i].size.x = static_cast<float>(texAsteroid.width / 2);
            asteroids[i].size.y = static_cast<float>(texAsteroid.width / 2);
            DrawCircle(static_cast<int>(asteroids[i].pos.x), static_cast<int>(asteroids[i].pos.y), asteroids[i].radius, RED);
            DrawTexturePro(texAsteroid,
                { 0.0f, 0.0f, static_cast<float>(texAsteroid.width), static_cast<float>(texAsteroid.height) },
                { asteroids[i].pos.x, asteroids[i].pos.y, asteroids[i].size.x, asteroids[i].size.y },
                { asteroids[i].size.x / 2, asteroids[i].size.y / 2 },
                asteroids[i].rotation,
                RAYWHITE);
        }
        
        if (asteroids[i].isActive && asteroids[i].isSmall)
        {
            asteroids[i].size.x = static_cast<float>(texAsteroid.width / 4);
            asteroids[i].size.y = static_cast<float>(texAsteroid.width / 4);
            DrawCircle(static_cast<int>(asteroids[i].pos.x), static_cast<int>(asteroids[i].pos.y), asteroids[i].radius, RED);
            DrawTexturePro(texAsteroid,
                { 0.0f, 0.0f, static_cast<float>(texAsteroid.width), static_cast<float>(texAsteroid.height) },
                { asteroids[i].pos.x, asteroids[i].pos.y, asteroids[i].size.x, asteroids[i].size.y },
                { asteroids[i].size.x / 2, asteroids[i].size.y / 2 },
                asteroids[i].rotation,
                RAYWHITE);
        }
    }

    DrawCircle(static_cast<int>(ship.pos.x), static_cast<int>(ship.pos.y), ship.radius, YELLOW);
    DrawTexturePro(ship.texShip, { 0.0f, 0.0f,static_cast<float>(ship.texShip.width), static_cast<float>(ship.texShip.height) }, { static_cast<float>(ship.pos.x),static_cast<float>(ship.pos.y), static_cast<float>(ship.size.x), static_cast<float>(ship.size.y) }, { static_cast<float>(ship.size.x / 2), static_cast<float>(ship.size.y / 2) }, ship.rotation, RAYWHITE);
    
    DrawTexturePro(scoreTex, 
                    { 0.0f, 0.0f, static_cast<float>(scoreTex.width), static_cast<float>(scoreTex.height) },
                    { 650.0f, 50.0f, 200.0f , 50.0f},
                    { 10.0f , 10.0f},
                    0.0f, RAYWHITE);
    DrawText(TextFormat("%i", ship.score), 850, 40, 50, PURPLE);
    DrawTexturePro(livesTex,
        { 0.0f, 0.0f, static_cast<float>(scoreTex.width), static_cast<float>(scoreTex.height) },
        { 650.0f, 100.0f, 200.0f , 50.0f },
        { 10.0f , 10.0f },
        0.0f, RAYWHITE);
    DrawText(TextFormat("%i",ship.lives), 850, 95, 50, PURPLE);
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

void returnToMenu(GameScreen& currentScreen,
    SpaceShip& ship,
    Texture2D Ship,
    Asteroid& asteroid,
    Asteroid asteroids[],
    int maxAsteroids,
    int maxBullets,
    Bullet& bullet,
    Bullet bullets[],
    bool& pause,
    bool& gameOver)
{
    resetGame(ship, Ship, asteroid, asteroids, maxAsteroids, maxBullets, bullet, bullets, pause, gameOver);
    currentScreen = GameScreen::MENU;
}

void initMatch(SpaceShip& ship,
    Asteroid& asteroid,
    Asteroid asteroids[],
    int maxAsteroids,
    int maxBullets,
    Bullet& bullet,
    Bullet bullets[])
{
    ship.pos = { static_cast<float>(GetScreenWidth() / 2) , static_cast<float>(GetScreenHeight() / 2) };
    ship.size = { 48.0f, 48.0f };
    ship.origin = { ship.size.x / 2, ship.size.y / 2 };
    ship.radius = 16.0f;
    

    for (int i = 0; i < 10; i++)
    {
        initAsteroid(asteroid);
        asteroids[i] = asteroid;
        asteroids[i].radius = 30.0f;
        asteroids[i].isBig = true;
    }

    for (int i = 10; i < 30; i++)
    {
        initAsteroid(asteroid);
        asteroids[i].radius = 17.0f;
        asteroids[i] = asteroid;
        asteroids[i].isMedium = true;
    }

    for (int i = 30; i < 70; i++)
    {
        initAsteroid(asteroid);
        asteroid.radius = 7.5f;
        asteroids[i] = asteroid;
        asteroids[i].isSmall = true;
    }

    for (int i = 0; i < maxAsteroids; i++)
    {
        int randEndX = GetRandomValue(1024, 1030);
        int randEndY = GetRandomValue(768, 770);
        Vector2 posEnd = { static_cast<float>(randEndX), static_cast<float>(randEndY) };
        asteroids[i].direction = Vector2Subtract(asteroids[i].pos, posEnd);
    }

    for (int i = 0; i < maxBullets; i++)
    {
        initBullet(bullet);
        bullets[i] = bullet;
    }
}

void initAll(SpaceShip& ship, 
    Texture2D Ship, 
    Asteroid& asteroid,
    Asteroid asteroids[],
    int maxAsteroids, 
    int maxBullets,
    Bullet& bullet,
    Bullet bullets[])
{
    initShip(ship, Ship);

    for (int i = 0; i < 10; i++)
    {
        initAsteroid(asteroid);
        asteroids[i] = asteroid;
        asteroids[i].radius = 30.0f;
        asteroids[i].isBig = true;
    }

    for (int i = 10; i < 30; i++)
    {
        initAsteroid(asteroid);
        asteroids[i].radius = 15.0f;
        asteroids[i] = asteroid;
        asteroids[i].isMedium = true;
    }

    for (int i = 30; i < 70; i++)
    {
        initAsteroid(asteroid);
        asteroid.radius = 7.5f;
        asteroids[i] = asteroid;
        asteroids[i].isSmall = true;
    }

    for (int i = 0; i < maxAsteroids; i++)
    {
        int randEndX = GetRandomValue(1024, 1030);
        int randEndY = GetRandomValue(768, 770);
        Vector2 posEnd = { static_cast<float>(randEndX), static_cast<float>(randEndY) };
        asteroids[i].direction = Vector2Subtract(asteroids[i].pos, posEnd);
    }

    for (int i = 0; i < maxBullets; i++)
    {
        initBullet(bullet);
        bullets[i] = bullet;
    }
}

void resetGame(SpaceShip& ship,
    Texture2D Ship,
    Asteroid& asteroid,
    Asteroid asteroids[],
    int maxAsteroids,
    int maxBullets,
    Bullet& bullet,
    Bullet bullets[], 
    bool& pause,
    bool& gameOver)
{
    pause = false;
    gameOver = false;
    initAll(ship, Ship, asteroid, asteroids, maxAsteroids, maxBullets, bullet, bullets);
}

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