#pragma once
#include "raylib.h"

struct RectangleButton
{
    int rectangleX = 390;
    int rectangleY = 0;
    int rectangleWidth = 230;
    int rectangleHeight = 50;
    bool isSelected = false;
};

enum class GameScreen
{
    MENU,
    GAMEPLAY,
    RULES,
    CREDITS,
    GAMEOVER,
    GAMEWIN,
    EXIT
};

void drawMenu(RectangleButton& rectanglePlay,
    RectangleButton& rectangleRules,
    RectangleButton& rectangleCredits,
    RectangleButton& rectangleExit,
    Vector2& mouse,
    Texture2D menuBackground,
    Texture2D playButton,
    Texture2D playButtonC,
    Texture2D rulesButton,
    Texture2D rulesButtonC,
    Texture2D creditsButton,
    Texture2D creditsButtonC,
    Texture2D exitButton,
    Texture2D exitButtonC);
void drawRules(RectangleButton& rectangleReturn,
    Vector2& mouse,
    Texture2D rulesBackground,
    Texture2D returnButton,
    Texture2D returnButtonC);
void drawCredits(RectangleButton& rectangleReturn,
    Vector2& mouse,
    Texture2D creditsBackground,
    Texture2D returnButton,
    Texture2D returnButtonC,
    Texture2D githubB,
    Texture2D githubBC,
    Texture2D instaB,
    Texture2D instaBC,
    Texture2D itchB,
    Texture2D itchBC,
    RectangleButton& itchOne,
    RectangleButton& itchTwo,
    RectangleButton& insta,
    RectangleButton& github);
void drawGameOver(RectangleButton& rectangleReturn, RectangleButton& rectangleContinue,
    Texture2D returnButton,
    Texture2D returnButtonC,
    Texture2D continueButton,
    Texture2D continueButtonC,
    Vector2& mouse,
    Texture2D gameOverScreen);
void drawGameWin(RectangleButton& rectangleReturn, RectangleButton& rectangleContinue,
    Texture2D returnButton,
    Texture2D returnButtonC,
    Texture2D continueButton,
    Texture2D continueButtonC,
    Vector2& mouse,
    Texture2D gameWinScreen);
bool optionsCollision(Vector2 mouse, RectangleButton rectangle);