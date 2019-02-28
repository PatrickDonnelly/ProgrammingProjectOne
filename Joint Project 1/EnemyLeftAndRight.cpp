#include "EnemyLeftAndRight.h"



EnemyLeftAndRight::EnemyLeftAndRight()
{
	loadImages();
	srand(time(nullptr));
}


EnemyLeftAndRight::~EnemyLeftAndRight()
{
}

void EnemyLeftAndRight::loadImages()
{
	if (!textureEast.loadFromFile("digger.png"))  // loads texture
	{
		//error
	}

	if (!textureWest.loadFromFile("diggerWest.png"))  // loads texture
	{
		//error
	}
}

void EnemyLeftAndRight::setUpEnemy()
{
	int ran = rand() % 450 + 50;  // random number generator
	int ran2 = rand() % 200 + 200;  // random number generator
	body.setPosition(ran, ran2);  // sets enemy to the random number co ordinates
	health = 50;  // sets health
	body.setOrigin(40, 29);  // sets sprite origin
	body.setTexture(textureEast);  // sets texture of enemy sprite
}

void EnemyLeftAndRight::move()
{
	if (body.getPosition().x <= 50)  // switch direction
	{
		moveLeft = true;  // enemy moves left is true
	}
	if(moveLeft == true)
	{
		body.move(speedLeft, 0);  // enemy moves left at this speed
		body.setTexture(textureWest); // switch texture
	}
	if (body.getPosition().x >= 700) // switch direction
	{
		moveLeft = false;  // enemy moves right is true
	}
	if(moveLeft == false)
	{
		body.move(speedRight, 0);  // enemy moves right at this speed
		body.setTexture(textureEast); // switch texture
	}
}
