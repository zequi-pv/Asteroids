#include "spaceship.h"

void initShip(SpaceShip& ship, Texture2D texShip)
{
	ship.pos = {static_cast<float>(GetScreenWidth() / 2) , static_cast<float>(GetScreenHeight() / 2)};
	ship.size = { 48.0f, 48.0f };
	ship.origin = { ship.size.x / 2, ship.size.y / 2 };
	ship.radius = 16.0f;
	ship.texShip = texShip;
	ship.lives = 3;
	ship.score = 0;
}

Vector2 getPosition(SpaceShip ship)
{
	return ship.pos;
}