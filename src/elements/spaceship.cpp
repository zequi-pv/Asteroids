#include "spaceship.h"

void initShip(SpaceShip& ship/*, Texture2D texShip*/)
{
	ship.pos = {static_cast<float>(GetScreenWidth() / 2) , static_cast<float>(GetScreenHeight() / 2)};
	ship.size = { 20.0f, 100.0f };
	ship.origin = { ship.size.x / 2, ship.size.y / 2 };
	ship.radius = 16.0f;
	//ship.texShip = texShip;
}

Vector2 getPosition(SpaceShip ship)
{
	return ship.pos;
}