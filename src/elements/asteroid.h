#pragma once
#include "raylib.h"

struct Asteroid
{
	Vector2 pos;
	Vector2 size;
	float radius;
};

void initAsteroid(Asteroid& asteroid);