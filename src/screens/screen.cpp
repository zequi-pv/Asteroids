#include "screen.h"

#include <iostream>

using namespace std;

void drawMenu(	RectangleButton& rectanglePlay,
				RectangleButton& rectangleRules,
				RectangleButton& rectangleCredits,
				RectangleButton& rectangleExit,
				Vector2& mouse,
				Texture2D menuBackground,
				Texture2D playButton,
				Texture2D playButtonC, 
				Texture2D rulesButton, 
				Texture2D rulesButtonC,
				Texture2D creditsButton, 
				Texture2D creditsButtonC,
				Texture2D exitButton, 
				Texture2D exitButtonC)
{

	DrawTexturePro(	menuBackground, 
					{ 0.0f, 0.0f, 1024.0f, 768.0f }, 
					{ 0.0f, 0.0f, 1024.0f, 768.0f },
					{ 0.0f, 0.0f },
					0.0f,
					RAYWHITE);
	/*DrawTexturePro(ship.texShip,
	{ 0.0f, 0.0f,static_cast<float>(ship.texShip.width), static_cast<float>(ship.texShip.height) }, 
	{ static_cast<float>(ship.pos.x),static_cast<float>(ship.pos.y), static_cast<float>(ship.size.x), static_cast<float>(ship.size.y) }, 
	{ static_cast<float>(ship.size.x / 2), static_cast<float>(ship.size.y / 2) }, 
	ship.rotation, RAYWHITE);*/
	rectanglePlay.rectangleY = 270;
	//DrawRectangle(rectanglePlay.rectangleX, rectanglePlay.rectangleY = 270, rectanglePlay.rectangleWidth, rectanglePlay.rectangleHeight, GRAY);
	DrawTexturePro(playButton,
		{ 0.0f, 0.0f, static_cast<float>(playButton.width), static_cast<float>(playButton.height) },
		{ static_cast<float>(rectanglePlay.rectangleX) , static_cast<float>(rectanglePlay.rectangleY), static_cast<float>(rectanglePlay.rectangleWidth), static_cast<float>(rectanglePlay.rectangleHeight) },
		{ static_cast<float>(30 / 2), static_cast<float>(10 / 2) },
		0.0f,
		RAYWHITE);
	//DrawText("Play", 400, 270, 40, BLACK);
	rectangleRules.rectangleY = 340;
	//DrawRectangle(rectangleRules.rectangleX , rectangleRules.rectangleY = 340, rectangleRules.rectangleWidth, rectangleRules.rectangleHeight, GRAY);
	DrawTexturePro(rulesButton,
		{ 0.0f, 0.0f, static_cast<float>(rulesButton.width), static_cast<float>(rulesButton.height) },
		{ static_cast<float>(rectangleRules.rectangleX) , static_cast<float>(rectangleRules.rectangleY), static_cast<float>(rectangleRules.rectangleWidth), static_cast<float>(rectangleRules.rectangleHeight) },
		{ static_cast<float>(30 / 2), static_cast<float>(15 / 2) },
		0.0f,
		RAYWHITE);
	//DrawText("Rules", 400, 340, 40, BLACK);
	rectangleCredits.rectangleY = 410;
	//DrawRectangle(rectangleCredits.rectangleX, rectangleCredits.rectangleY = 410, rectangleCredits.rectangleWidth, rectangleCredits.rectangleHeight, GRAY);
	DrawTexturePro(creditsButton,
		{ 0.0f, 0.0f, static_cast<float>(creditsButton.width), static_cast<float>(creditsButton.height) },
		{ static_cast<float>(rectangleCredits.rectangleX) , static_cast<float>(rectangleCredits.rectangleY), static_cast<float>(rectangleCredits.rectangleWidth), static_cast<float>(rectangleCredits.rectangleHeight) },
		{ static_cast<float>(30 / 2), static_cast<float>(20 / 2) },
		0.0f,
		RAYWHITE);
	//DrawText("Credits", 400, 410, 40, BLACK);
	rectangleExit.rectangleY = 480;
	//DrawRectangle(rectangleExit.rectangleX, rectangleExit.rectangleY = 480, rectangleExit.rectangleWidth, rectangleExit.rectangleHeight, GRAY);
	DrawTexturePro(exitButton,
		{ 0.0f, 0.0f, static_cast<float>(exitButton.width), static_cast<float>(exitButton.height) },
		{ static_cast<float>(rectangleExit.rectangleX) , static_cast<float>(rectangleExit.rectangleY), static_cast<float>(rectangleExit.rectangleWidth), static_cast<float>(rectangleExit.rectangleHeight) },
		{ static_cast<float>(30 / 2), static_cast<float>(20 / 2) },
		0.0f,
		RAYWHITE);
	//DrawText("Exit", 400, 480, 40, BLACK);

	if (optionsCollision(mouse, rectanglePlay) )
	{
		rectanglePlay.isSelected = true;
		DrawTexturePro(playButtonC,
			{ 0.0f, 0.0f, static_cast<float>(playButtonC.width), static_cast<float>(playButtonC.height) },
			{ static_cast<float>(rectanglePlay.rectangleX) , static_cast<float>(rectanglePlay.rectangleY), static_cast<float>(rectanglePlay.rectangleWidth), static_cast<float>(rectanglePlay.rectangleHeight) },
			{ static_cast<float>(30 / 2), static_cast<float>(10 / 2) },
			0.0f,
			RAYWHITE);
		//DrawText("Play", 400, 270, 40, RED);
	}
	else if (!optionsCollision(mouse, rectanglePlay))
	{
		rectanglePlay.isSelected = false;
	}

	if (optionsCollision(mouse, rectangleRules))
	{
		rectangleRules.isSelected = true;
		DrawTexturePro(rulesButtonC,
			{ 0.0f, 0.0f, static_cast<float>(rulesButtonC.width), static_cast<float>(rulesButtonC.height) },
			{ static_cast<float>(rectangleRules.rectangleX) , static_cast<float>(rectangleRules.rectangleY), static_cast<float>(rectangleRules.rectangleWidth), static_cast<float>(rectangleRules.rectangleHeight) },
			{ static_cast<float>(30 / 2), static_cast<float>(15 / 2) },
			0.0f,
			RAYWHITE);
		//DrawText("Rules", 400, 340, 40, RED);
	}
	else if (!optionsCollision(mouse, rectangleRules))
	{
		rectangleRules.isSelected = false;
	}

	if (optionsCollision(mouse, rectangleCredits))
	{
		rectangleCredits.isSelected = true;
		DrawTexturePro(creditsButtonC,
			{ 0.0f, 0.0f, static_cast<float>(creditsButtonC.width), static_cast<float>(creditsButtonC.height) },
			{ static_cast<float>(rectangleCredits.rectangleX) , static_cast<float>(rectangleCredits.rectangleY), static_cast<float>(rectangleCredits.rectangleWidth), static_cast<float>(rectangleCredits.rectangleHeight) },
			{ static_cast<float>(30 / 2), static_cast<float>(20 / 2) },
			0.0f,
			RAYWHITE);
		//DrawText("Credits", 400, 410, 40, RED);
	}
	else if (!optionsCollision(mouse, rectangleCredits))
	{
		rectangleCredits.isSelected = false;
	}

	if (optionsCollision(mouse, rectangleExit))
	{
		rectangleExit.isSelected = true;
		DrawTexturePro(exitButtonC,
			{ 0.0f, 0.0f, static_cast<float>(exitButtonC.width), static_cast<float>(exitButtonC.height) },
			{ static_cast<float>(rectangleExit.rectangleX) , static_cast<float>(rectangleExit.rectangleY), static_cast<float>(rectangleExit.rectangleWidth), static_cast<float>(rectangleExit.rectangleHeight) },
			{ static_cast<float>(30 / 2), static_cast<float>(20 / 2) },
			0.0f,
			RAYWHITE);
		//DrawText("Exit", 400, 480, 40, RED);
	}
	else if (!optionsCollision(mouse, rectangleExit))
	{
		rectangleExit.isSelected = false;
	}
}

void drawRules(RectangleButton& rectangleReturn,
				Vector2& mouse,
				Texture2D rulesBackground,
				Texture2D returnButton,
				Texture2D returnButtonC)
{
	rectangleReturn.rectangleX = 50;
	rectangleReturn.rectangleY = 700;
	
	DrawTexturePro(	rulesBackground,
					{ 0.0f, 0.0f, 1024.0f, 768.0f },
					{ 0.0f, 0.0f, 1024.0f, 768.0f },
					{ 0.0f, 0.0f },
					0.0f,
					RAYWHITE);
	DrawTexturePro(returnButton,
		{ 0.0f, 0.0f, static_cast<float>(returnButton.width), static_cast<float>(returnButton.height) },
		{ static_cast<float>(rectangleReturn.rectangleX) , static_cast<float>(rectangleReturn.rectangleY), static_cast<float>(rectangleReturn.rectangleWidth), static_cast<float>(rectangleReturn.rectangleHeight) },
		{ static_cast<float>(50 / 2), static_cast<float>(10 / 2)},
		0.0f,
		RAYWHITE);
	if (optionsCollision(mouse, rectangleReturn))
	{
		rectangleReturn.isSelected = true;
		DrawTexturePro(returnButtonC,
			{ 0.0f, 0.0f, static_cast<float>(returnButton.width), static_cast<float>(returnButton.height) },
			{ static_cast<float>(rectangleReturn.rectangleX) , static_cast<float>(rectangleReturn.rectangleY), static_cast<float>(rectangleReturn.rectangleWidth), static_cast<float>(rectangleReturn.rectangleHeight) },
			{ static_cast<float>(50 / 2), static_cast<float>(10 / 2) },
			0.0f,
			RAYWHITE);
	}
	else if (!optionsCollision(mouse, rectangleReturn))
	{
		rectangleReturn.isSelected = false;
	}
}

void drawCredits(RectangleButton& rectangleReturn,
	Vector2& mouse,
	Texture2D creditsBackground,
	Texture2D returnButton,
	Texture2D returnButtonC,
	Texture2D githubB,
	Texture2D githubBC,
	Texture2D instaB,
	Texture2D instaBC,
	Texture2D itchB,
	Texture2D itchBC,
	RectangleButton& itchOne,
	RectangleButton& itchTwo,
	RectangleButton& insta,
	RectangleButton& github)

{

	DrawTexturePro(creditsBackground,
		{ 0.0f, 0.0f, 1024.0f, 768.0f },
		{ 0.0f, 0.0f, 1024.0f, 768.0f },
		{ 0.0f, 0.0f },
		0.0f,
		RAYWHITE);

	itchOne.rectangleX = 360;
	itchOne.rectangleY = 300;
	itchOne.rectangleWidth = 70;
	itchOne.rectangleHeight = 65;

	itchTwo.rectangleX = 360;
	itchTwo.rectangleY = 500;
	itchTwo.rectangleWidth = 70;
	itchTwo.rectangleHeight = 65;

	insta.rectangleX = 440;
	insta.rectangleY = 500;
	insta.rectangleWidth = 70;
	insta.rectangleHeight = 65;

	github.rectangleX = 440;
	github.rectangleY = 300;
	github.rectangleWidth = 70;
	github.rectangleHeight = 65;
	
	//Boton 1

	DrawTexturePro(itchB,
		{ 0.0f, 0.0f, static_cast<float>(itchB.width), static_cast<float>(itchB.height) },
		{ static_cast<float>(itchOne.rectangleX) , static_cast<float>(itchOne.rectangleY), static_cast<float>(itchOne.rectangleWidth), static_cast<float>(itchOne.rectangleHeight) },
		{ static_cast<float>(-5 / 2), static_cast<float>(5 / 2) },
		0.0f,
		RAYWHITE);

	if (optionsCollision(mouse, itchOne))
	{
		itchOne.isSelected = true;
		DrawTexturePro(itchBC,
			{ 0.0f, 0.0f, static_cast<float>(itchBC.width), static_cast<float>(itchBC.height) },
			{ static_cast<float>(itchOne.rectangleX) , static_cast<float>(itchOne.rectangleY), static_cast<float>(itchOne.rectangleWidth), static_cast<float>(itchOne.rectangleHeight) },
			{ static_cast<float>(-5 / 2), static_cast<float>(5 / 2) },
			0.0f,
			RAYWHITE);
	}
	else if (!optionsCollision(mouse, itchOne))
	{
		itchOne.isSelected = false;
	}
	//Boton 2

	DrawTexturePro(itchB,
		{ 0.0f, 0.0f, static_cast<float>(itchB.width), static_cast<float>(itchB.height) },
		{ static_cast<float>(itchTwo.rectangleX) , static_cast<float>(itchTwo.rectangleY), static_cast<float>(itchTwo.rectangleWidth), static_cast<float>(itchTwo.rectangleHeight) },
		{ static_cast<float>(-5 / 2), static_cast<float>(5 / 2) },
		0.0f,
		RAYWHITE);

	if (optionsCollision(mouse, itchTwo))
	{
		itchOne.isSelected = true;
		DrawTexturePro(itchBC,
			{ 0.0f, 0.0f, static_cast<float>(itchBC.width), static_cast<float>(itchBC.height) },
			{ static_cast<float>(itchTwo.rectangleX) , static_cast<float>(itchTwo.rectangleY), static_cast<float>(itchTwo.rectangleWidth), static_cast<float>(itchTwo.rectangleHeight) },
			{ static_cast<float>(-5 / 2), static_cast<float>(5 / 2) },
			0.0f,
			RAYWHITE);
	}
	else if (!optionsCollision(mouse, itchTwo))
	{
		itchTwo.isSelected = false;
	}
	//Boton 3
	

	DrawTexturePro(instaB,
		{ 0.0f, 0.0f, static_cast<float>(instaB.width), static_cast<float>(instaB.height) },
		{ static_cast<float>(insta.rectangleX) , static_cast<float>(insta.rectangleY), static_cast<float>(insta.rectangleWidth), static_cast<float>(insta.rectangleHeight) },
		{ static_cast<float>(-5 / 2), static_cast<float>(5 / 2) },
		0.0f,
		RAYWHITE);

	if (optionsCollision(mouse, insta))
	{
		itchOne.isSelected = true;
		DrawTexturePro(instaBC,
			{ 0.0f, 0.0f, static_cast<float>(instaBC.width), static_cast<float>(instaBC.height) },
			{ static_cast<float>(insta.rectangleX) , static_cast<float>(insta.rectangleY), static_cast<float>(insta.rectangleWidth), static_cast<float>(insta.rectangleHeight) },
			{ static_cast<float>(-5 / 2), static_cast<float>(5 / 2) },
			0.0f,
			RAYWHITE);
	}
	else if (!optionsCollision(mouse, insta))
	{
		insta.isSelected = false;
	}
	//Boton 4
	

	DrawTexturePro(githubB,
		{ 0.0f, 0.0f, static_cast<float>(githubB.width), static_cast<float>(githubB.height) },
		{ static_cast<float>(github.rectangleX) , static_cast<float>(github.rectangleY), static_cast<float>(github.rectangleWidth), static_cast<float>(github.rectangleHeight) },
		{ static_cast<float>(-5 / 2), static_cast<float>(5 / 2) },
		0.0f,
		RAYWHITE);

	if (optionsCollision(mouse, github))
	{
		itchOne.isSelected = true;
		DrawTexturePro(githubBC,
			{ 0.0f, 0.0f, static_cast<float>(githubBC.width), static_cast<float>(githubBC.height) },
			{ static_cast<float>(github.rectangleX) , static_cast<float>(github.rectangleY), static_cast<float>(github.rectangleWidth), static_cast<float>(github.rectangleHeight) },
			{ static_cast<float>(-5 / 2), static_cast<float>(5 / 2) },
			0.0f,
			RAYWHITE);
	}
	else if (!optionsCollision(mouse, github))
	{
		github.isSelected = false;
	}

	rectangleReturn.rectangleX = 50;
	rectangleReturn.rectangleY = 700;

	
	DrawTexturePro(returnButton,
		{ 0.0f, 0.0f, static_cast<float>(returnButton.width), static_cast<float>(returnButton.height) },
		{ static_cast<float>(rectangleReturn.rectangleX) , static_cast<float>(rectangleReturn.rectangleY), static_cast<float>(rectangleReturn.rectangleWidth), static_cast<float>(rectangleReturn.rectangleHeight) },
		{ static_cast<float>(50 / 2), static_cast<float>(10 / 2) },
		0.0f,
		RAYWHITE);
	if (optionsCollision(mouse, rectangleReturn))
	{
		rectangleReturn.isSelected = true;
		DrawTexturePro(returnButtonC,
			{ 0.0f, 0.0f, static_cast<float>(returnButton.width), static_cast<float>(returnButton.height) },
			{ static_cast<float>(rectangleReturn.rectangleX) , static_cast<float>(rectangleReturn.rectangleY), static_cast<float>(rectangleReturn.rectangleWidth), static_cast<float>(rectangleReturn.rectangleHeight) },
			{ static_cast<float>(50 / 2), static_cast<float>(10 / 2) },
			0.0f,
			RAYWHITE);
	}
	else if (!optionsCollision(mouse, rectangleReturn))
	{
		rectangleReturn.isSelected = false;
	}
}

void drawGameOver(RectangleButton& rectangleReturn, RectangleButton& rectangleContinue, 
	Texture2D returnButton,
	Texture2D returnButtonC, 
	Texture2D continueButton, 
	Texture2D continueButtonC, 
	Vector2& mouse,
	Texture2D gameOverScreen)
{
	DrawTexturePro(gameOverScreen,
		{ 0.0f, 0.0f, 1024.0f, 768.0f },
		{ 0.0f, 0.0f, 1024.0f, 768.0f },
		{ 0.0f, 0.0f },
		0.0f,
		RAYWHITE);
	rectangleReturn.rectangleX = 320;
	rectangleReturn.rectangleY = 530;
	rectangleReturn.rectangleWidth = 190;
	rectangleReturn.rectangleHeight = 50;
	rectangleContinue.rectangleX = 540;
	rectangleContinue.rectangleY = 530;
	rectangleContinue.rectangleWidth = 190;
	rectangleContinue.rectangleHeight = 50;
	//DrawRectangle(rectangleReturn.rectangleX, rectangleReturn.rectangleY, rectangleReturn.rectangleWidth, rectangleReturn.rectangleHeight, RAYWHITE);
	//DrawRectangle(rectangleContinue.rectangleX, rectangleContinue.rectangleY, rectangleContinue.rectangleWidth, rectangleContinue.rectangleHeight, RAYWHITE);
	DrawTexturePro(returnButton,
		{ 0.0f, 0.0f, static_cast<float>(returnButton.width), static_cast<float>(returnButton.height) },
		{ static_cast<float>(rectangleReturn.rectangleX) , static_cast<float>(rectangleReturn.rectangleY), static_cast<float>(rectangleReturn.rectangleWidth), static_cast<float>(rectangleReturn.rectangleHeight) },
		{ static_cast<float>(20 / 2), static_cast<float>(10 / 2) },
		0.0f,
		RAYWHITE);
	DrawTexturePro(continueButton,
		{ 0.0f, 0.0f, static_cast<float>(continueButton.width), static_cast<float>(continueButton.height) },
		{ static_cast<float>(rectangleContinue.rectangleX) , static_cast<float>(rectangleContinue.rectangleY), static_cast<float>(rectangleContinue.rectangleWidth), static_cast<float>(rectangleContinue.rectangleHeight) },
		{ static_cast<float>(50 / 2), static_cast<float>(10 / 2) },
		0.0f,
		RAYWHITE);

	if (optionsCollision(mouse, rectangleReturn))
	{
		rectangleReturn.isSelected = true;
		DrawTexturePro(returnButtonC,
			{ 0.0f, 0.0f, static_cast<float>(returnButtonC.width), static_cast<float>(returnButtonC.height) },
			{ static_cast<float>(rectangleReturn.rectangleX) , static_cast<float>(rectangleReturn.rectangleY), static_cast<float>(rectangleReturn.rectangleWidth), static_cast<float>(rectangleReturn.rectangleHeight) },
			{ static_cast<float>(20 / 2), static_cast<float>(10 / 2) },
			0.0f,
			RAYWHITE);

	}
	else if (!optionsCollision(mouse, rectangleReturn))
	{
		rectangleReturn.isSelected = false;
	}

	if (optionsCollision(mouse, rectangleContinue))
	{
		rectangleContinue.isSelected = true;
		DrawTexturePro(continueButtonC,
			{ 0.0f, 0.0f, static_cast<float>(continueButtonC.width), static_cast<float>(continueButtonC.height) },
			{ static_cast<float>(rectangleContinue.rectangleX) , static_cast<float>(rectangleContinue.rectangleY), static_cast<float>(rectangleContinue.rectangleWidth), static_cast<float>(rectangleContinue.rectangleHeight) },
			{ static_cast<float>(50 / 2), static_cast<float>(10 / 2) },
			0.0f,
			RAYWHITE);

	}
	else if (!optionsCollision(mouse, rectangleContinue))
	{
		rectangleContinue.isSelected = false;
	}
}

void drawGameWin(RectangleButton& rectangleReturn, RectangleButton& rectangleContinue,
	Texture2D returnButton,
	Texture2D returnButtonC,
	Texture2D continueButton,
	Texture2D continueButtonC,
	Vector2& mouse,
	Texture2D gameWinScreen)
{
	DrawTexturePro(gameWinScreen,
		{ 0.0f, 0.0f, 1024.0f, 768.0f },
		{ 0.0f, 0.0f, 1024.0f, 768.0f },
		{ 0.0f, 0.0f },
		0.0f,
		RAYWHITE);
	rectangleReturn.rectangleX = 320;
	rectangleReturn.rectangleY = 530;
	rectangleReturn.rectangleWidth = 190;
	rectangleReturn.rectangleHeight = 50;
	rectangleContinue.rectangleX = 540;
	rectangleContinue.rectangleY = 530;
	rectangleContinue.rectangleWidth = 190;
	rectangleContinue.rectangleHeight = 50;
	//DrawRectangle(rectangleReturn.rectangleX, rectangleReturn.rectangleY, rectangleReturn.rectangleWidth, rectangleReturn.rectangleHeight, RAYWHITE);
	//DrawRectangle(rectangleContinue.rectangleX, rectangleContinue.rectangleY, rectangleContinue.rectangleWidth, rectangleContinue.rectangleHeight, RAYWHITE);
	DrawTexturePro(returnButton,
		{ 0.0f, 0.0f, static_cast<float>(returnButton.width), static_cast<float>(returnButton.height) },
		{ static_cast<float>(rectangleReturn.rectangleX) , static_cast<float>(rectangleReturn.rectangleY), static_cast<float>(rectangleReturn.rectangleWidth), static_cast<float>(rectangleReturn.rectangleHeight) },
		{ static_cast<float>(20 / 2), static_cast<float>(10 / 2) },
		0.0f,
		RAYWHITE);
	DrawTexturePro(continueButton,
		{ 0.0f, 0.0f, static_cast<float>(continueButton.width), static_cast<float>(continueButton.height) },
		{ static_cast<float>(rectangleContinue.rectangleX) , static_cast<float>(rectangleContinue.rectangleY), static_cast<float>(rectangleContinue.rectangleWidth), static_cast<float>(rectangleContinue.rectangleHeight) },
		{ static_cast<float>(50 / 2), static_cast<float>(10 / 2) },
		0.0f,
		RAYWHITE);

	if (optionsCollision(mouse, rectangleReturn))
	{
		rectangleReturn.isSelected = true;
		DrawTexturePro(returnButtonC,
			{ 0.0f, 0.0f, static_cast<float>(returnButtonC.width), static_cast<float>(returnButtonC.height) },
			{ static_cast<float>(rectangleReturn.rectangleX) , static_cast<float>(rectangleReturn.rectangleY), static_cast<float>(rectangleReturn.rectangleWidth), static_cast<float>(rectangleReturn.rectangleHeight) },
			{ static_cast<float>(20 / 2), static_cast<float>(10 / 2) },
			0.0f,
			RAYWHITE);

	}
	else if (!optionsCollision(mouse, rectangleReturn))
	{
		rectangleReturn.isSelected = false;
	}

	if (optionsCollision(mouse, rectangleContinue))
	{
		rectangleContinue.isSelected = true;
		DrawTexturePro(continueButtonC,
			{ 0.0f, 0.0f, static_cast<float>(continueButtonC.width), static_cast<float>(continueButtonC.height) },
			{ static_cast<float>(rectangleContinue.rectangleX) , static_cast<float>(rectangleContinue.rectangleY), static_cast<float>(rectangleContinue.rectangleWidth), static_cast<float>(rectangleContinue.rectangleHeight) },
			{ static_cast<float>(50 / 2), static_cast<float>(10 / 2) },
			0.0f,
			RAYWHITE);

	}
	else if (!optionsCollision(mouse, rectangleContinue))
	{
		rectangleContinue.isSelected = false;
	}
}

bool optionsCollision(Vector2 mouse, RectangleButton rectangle) 
{
	return	mouse.x > rectangle.rectangleX
			&& mouse.x < rectangle.rectangleX + rectangle.rectangleWidth
			&& mouse.y > rectangle.rectangleY
			&& mouse.y < rectangle.rectangleY + rectangle.rectangleHeight;
}