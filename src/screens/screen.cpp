#include "screen.h"
#include <iostream>

using namespace std;

void drawMenu(	RectangleButton rectangleTitle,
				RectangleButton rectanglePlay,
				RectangleButton rectangleRules,
				RectangleButton rectangleCredits,
				RectangleButton rectangleExit, 
				Vector2 mouse)
{

	DrawRectangle(rectangleTitle.rectangleX, rectangleTitle.rectangleY = 200, rectangleTitle.rectangleWidth, rectangleTitle.rectangleHeight, GRAY);
	DrawText("Asteroids", 400, 200, 40, BLACK);

	DrawRectangle(rectanglePlay.rectangleX, rectanglePlay.rectangleY = 270, rectanglePlay.rectangleWidth, rectanglePlay.rectangleHeight, GRAY);
	DrawText("Play", 400, 270, 40, BLACK);

	DrawRectangle(rectangleRules.rectangleX , rectangleRules.rectangleY = 340, rectangleRules.rectangleWidth, rectangleRules.rectangleHeight, GRAY);
	DrawText("Rules", 400, 340, 40, BLACK);

	DrawRectangle(rectangleCredits.rectangleX, rectangleCredits.rectangleY = 410, rectangleCredits.rectangleWidth, rectangleCredits.rectangleHeight, GRAY);
	DrawText("Credits", 400, 410, 40, BLACK);

	DrawRectangle(rectangleExit.rectangleX, rectangleExit.rectangleY = 480, rectangleExit.rectangleWidth, rectangleExit.rectangleHeight, GRAY);
	DrawText("Exit", 400, 480, 40, BLACK);
	cout << "Menu" << endl;
	if (optionsCollision(mouse, rectanglePlay) )
	{
		cout << "Colisiono" << endl;
		DrawText("Play", 400, 270, 40, RED);
	}
	if (optionsCollision(mouse, rectangleRules))
	{
		DrawText("Rules", 400, 340, 40, RED);
	}
	if (optionsCollision(mouse, rectangleCredits))
	{
		DrawText("Credits", 400, 410, 40, RED);
	}
	if (optionsCollision(mouse, rectangleExit))
	{
		DrawText("Exit", 400, 480, 40, RED);
	}
}

bool optionsCollision(Vector2 mouse, RectangleButton rectangle) 
{
	return	mouse.x > rectangle.rectangleX
			&& mouse.x < rectangle.rectangleX + rectangle.rectangleWidth
			&& mouse.y > rectangle.rectangleY
			&& mouse.y < rectangle.rectangleY + rectangle.rectangleHeight;
}