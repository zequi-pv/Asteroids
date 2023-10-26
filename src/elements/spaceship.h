#pragma once
#include "raylib.h"

struct SpaceShip
{
	Vector2 pos;
	Vector2 size;
	Vector2 origin;
	float radius;
	float rotation;
	//Texture2D texShip;
};

void initShip(SpaceShip& ship/*, Texture2D texShip*/);
Vector2 getPosition(SpaceShip ship);