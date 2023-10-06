#pragma once
#include "raylib.h"

enum class GameScreen
{
    MENU,
    SINGLEPLAYER,
    RULES,
    CREDITS,
    EXIT
};


void drawMenu();
