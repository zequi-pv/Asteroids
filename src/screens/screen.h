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
    EXIT
};

void drawMenu(  RectangleButton& rectanglePlay,
                RectangleButton& rectangleRules,
                RectangleButton& rectangleCredits,
                RectangleButton& rectangleExit,
                Vector2& mouse,
                Texture2D menuBackground);
bool optionsCollision(Vector2 mouse, RectangleButton rectangle);
