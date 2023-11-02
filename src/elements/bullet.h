#pragma once
#include "raylib.h"

struct Bullet
{
	Vector2 pos;
	Vector2 size;
	float speed;
	Vector2 direction;
	Vector2 velocity;
	float radius;
	float rotation;
	int lifeSpawn;
	bool isActive;
};

void initBullet(Bullet& bullet);
bool bulletOutofBounds(Bullet bullet);