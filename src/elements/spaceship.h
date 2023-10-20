#pragma once
#include "raylib.h"

struct SpaceShip
{
	Vector2 pos;
	Vector2 origin;
	float radius;
	float rotation;
};

void initShip(SpaceShip& ship);
Vector2 getPosition(SpaceShip ship);