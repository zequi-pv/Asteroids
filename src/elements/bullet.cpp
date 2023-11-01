#include "bullet.h"

void initBullet(Bullet& bullet)
{
	bullet.pos = {};
	bullet.size = { 10.0f, 10.0f };
	bullet.speed = { 100.0f, 100.0f };
	bullet.radius = 2.0f;
	bullet.isActive = false;
}

bool bulletOutofBounds(Bullet bullet)
{
	return bullet.pos.x > 1024 && bullet.pos.x < 0 && bullet.pos.y > 768 && bullet.pos.y < 0;
}