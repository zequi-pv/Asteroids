#pragma once
#include "raylib.h"

struct Asteroid
{
	Vector2 pos;
	Vector2 size;
	float radius;
	float rotation;
};

void initAsteroid(Asteroid& asteroid);
void initMedAsteroid(Asteroid& asteroid);
void initSmallAsteroid(Asteroid& asteroid);