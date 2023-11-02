#pragma once
#include "raylib.h"

struct Asteroid
{
	Vector2 pos;
	Vector2 size;
	float radius;
	float rotation;
	bool isActive;
	bool isDead;
	bool isBig;
	bool isMedium;
	bool isSmall;
	Vector2 direction;
};

void initAsteroid(Asteroid& asteroid);