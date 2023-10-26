#include "asteroid.h"
#include "iostream"

void initAsteroid(Asteroid& asteroid)
{
	int randomX = rand() % 1024 + 1;
	int randomY = rand() % 768 + 1;
	asteroid.pos = { static_cast<float>(randomX), static_cast<float>(randomY) };
	asteroid.size = { 35.0f, 30.0f };
	asteroid.radius = 30.0f;
}