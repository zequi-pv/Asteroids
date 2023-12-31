#pragma once
#include "raylib.h"

struct SpaceShip
{
	Vector2 pos;
	Vector2 size;
	Vector2 origin;
	float radius;
	float rotation;
	Vector2 ShipAcceleration;
	Texture2D texShip;
	int lives;
	int score;
	int destroyedAsteroids;
};

void initShip(SpaceShip& ship, Texture2D texShip);
Vector2 getPosition(SpaceShip ship);