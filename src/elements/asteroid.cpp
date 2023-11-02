#include "asteroid.h"

#include <iostream>

void initAsteroid(Asteroid& asteroid)
{
	int randomX = GetRandomValue(1024, 1030);
	int randomY = GetRandomValue(768, 770);
	asteroid.pos = { static_cast<float>(randomX), static_cast<float>(randomY) };
	asteroid.isActive = false;
	asteroid.isDead = false;
}
