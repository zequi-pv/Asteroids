#include "spaceship.h"

void initShip(SpaceShip& ship)
{
	ship.pos = {static_cast<float>(GetScreenWidth() / 2) , static_cast<float>(GetScreenHeight() / 2)};
	ship.radius = 16.0f;
}

Vector2 getPosition(SpaceShip ship)
{
	return ship.pos;
}