#include "EnemyFollow.h"



EnemyFollow::EnemyFollow()
{
}


EnemyFollow::~EnemyFollow()
{
}

void EnemyFollow::setUpEnemy()
{
	if (!textureWest.loadFromFile("enemy2_right.png"))
	{
		//error
	}
	body.setTexture(textureWest);
	body.setPosition(100, 100);
}

void EnemyFollow::move()
{
	//player.body.getPosition().x;
	player.getSpritePosition();
	if (body.getPosition().x < player.getSpritePosition().x)
	{
		body.move(2, 0);

		if (!textureWest.loadFromFile("enemy2_right.png"))
		{
			//error
		}
		body.setTexture(textureWest);
	}
	if (body.getPosition().x > player.getSpritePosition().x)
	{
		body.move(-2, 0);

		if (!textureEast.loadFromFile("enemy2_left.png"))
		{
			//error
		}
		body.setTexture(textureEast);
	}
	if (body.getPosition().y > player.currentPosition.y)
	{
		body.move(0, -2);

		if (!textureWest.loadFromFile("enemy2_right.png"))
		{
			//error
		}
		body.setTexture(textureWest);
	}
	if (body.getPosition().y < player.currentPosition.y)
	{
		body.move(0, 2);

		if (!textureEast.loadFromFile("enemy2_left.png"))
		{
			//error
		}
		body.setTexture(textureEast);
	}

}

sf::Sprite EnemyFollow::draw()
{
	//body.getPosition();
	return body;
}
