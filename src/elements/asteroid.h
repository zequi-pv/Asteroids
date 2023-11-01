#pragma once
#include "raylib.h"

struct Asteroid
{
	Vector2 pos;
	float radius;
	float rotation;
};

void initAsteroid(Asteroid& asteroid);
void initMedAsteroid(Asteroid& asteroid);
void initSmallAsteroid(Asteroid& asteroid);