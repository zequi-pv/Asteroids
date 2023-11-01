#pragma once
#include "raylib.h"

struct Bullet
{
	Vector2 pos;
	Vector2 size;
	Vector2 speed;
	float radius;
	float rotation;
	bool isActive;
};

void initBullet(Bullet& bullet);
bool bulletOutofBounds(Bullet bullet);