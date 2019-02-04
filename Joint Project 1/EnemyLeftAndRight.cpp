#include "EnemyLeftAndRight.h"



EnemyLeftAndRight::EnemyLeftAndRight()
{
}


EnemyLeftAndRight::~EnemyLeftAndRight()
{
}

void EnemyLeftAndRight::setUpEnemy()
{
	body.setPosition(200, 200);
}

void EnemyLeftAndRight::move()
{
	if (body.getPosition().x == 200)
	{
		moveLeft = true;
	}
	if(moveLeft == true)
	{
		body.move(3, 0);

		if (!textureWest.loadFromFile("enemy1_right.png"))
		{
			//error
		}
		body.setTexture(textureWest);
	}
	if (body.getPosition().x == 380)
	{
		moveLeft = false;
	}
	if(moveLeft == false)
	{
		body.move(-3, 0);

		if (!textureEast.loadFromFile("enemy1_left.png"))
		{
			//error
		}
		body.setTexture(textureEast);
	}
}

sf::Sprite EnemyLeftAndRight::draw()
{
	body.getPosition();
	return body;
}
