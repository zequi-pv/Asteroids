#include "asteroid.h"
#include "iostream"

void initAsteroid(Asteroid& asteroid)
{
	int randomX = rand() % 1024 + 1;
	int randomY = rand() % 768 + 1;
	asteroid.pos = { static_cast<float>(randomX), static_cast<float>(randomY) };
	asteroid.size = { 70.0f, 70.0f };
	asteroid.radius = 30.0f;
}

void initMedAsteroid(Asteroid& asteroid)
{
	int randomX = rand() % 1024 + 1;
	int randomY = rand() % 768 + 1;
	asteroid.pos = { static_cast<float>(randomX), static_cast<float>(randomY) };
	asteroid.radius = 15.0f;
}

void initSmallAsteroid(Asteroid& asteroid)
{
	int randomX = rand() % 1024 + 1;
	int randomY = rand() % 768 + 1;
	asteroid.pos = { static_cast<float>(randomX), static_cast<float>(randomY) };
	asteroid.radius = 7.5f;
}