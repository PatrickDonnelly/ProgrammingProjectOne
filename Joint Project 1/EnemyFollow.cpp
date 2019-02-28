#include "EnemyFollow.h"



EnemyFollow::EnemyFollow()
{
	loadImages();  // calls function to load images
	srand(time(nullptr));  // used for generating ranfom numbers
}

EnemyFollow::~EnemyFollow()
{
}

void EnemyFollow::loadImages()
{
	if (!textureWest.loadFromFile("enemy2_right.png"))  // loads an image for a texture
	{
		//error
	}
	if (!textureEast.loadFromFile("enemy2_left.png"))  // loads an image for a texture
	{
		//error
	}
	if (!textureNorth.loadFromFile("enemy2_up.png"))  // loads an image for a texture
	{
		//error
	}
	if (!textureSouth.loadFromFile("enemy2_down.png"))  // loads an image for a texture
	{
		//error
	}
	body.setTexture(textureEast);  // sets texture of the enemy follower
}

void EnemyFollow::setUpEnemy()
{
	int ran2 = rand() % 450 + 50;
	int ran = rand() % 300 + 200;
	health = 30;  // sets the enemy health to 30
	body.setTexture(textureWest);  // sets enemy texture to face west
	body.setPosition(ran, ran2); // sets to random position
	body.setOrigin(32,32); // sets origin to the centre of the sprite
}

void EnemyFollow::move(sf::Vector2f t_PlayerPosition)
{
	
	if (body.getPosition().x < t_PlayerPosition.x)
	{//moves right
		body.move(speed, 0);
		body.setTexture(textureWest);
	}
	else if (body.getPosition().x > t_PlayerPosition.x)
	{//moves left
		body.move(-speed, 0);
		body.setTexture(textureEast);
	}
	else if (body.getPosition().y > t_PlayerPosition.y)
	{//moves up
		body.move(0, -speed);
		body.setTexture(textureNorth);
	}
	else if (body.getPosition().y < t_PlayerPosition.y)
	{//moves down
		body.move(0,speed);
		body.setTexture(textureSouth);
	}
}

void EnemyFollow::moveTwo(sf::Vector2f t_PlayerPosition)
{

	if (body.getPosition().x < t_PlayerPosition.x)
	{//moves right
		body.move(speedTwo, 0);
		body.setTexture(textureWest);
	}
	if (body.getPosition().x > t_PlayerPosition.x)
	{//moves left
		body.move(-speedTwo, 0);
		body.setTexture(textureEast);
	}
	if (body.getPosition().y > t_PlayerPosition.y)
	{//moves up
		body.move(0, -speedTwo);
		body.setTexture(textureNorth);
	}
	if (body.getPosition().y < t_PlayerPosition.y)
	{//moves down
		body.move(0, speedTwo);
		body.setTexture(textureSouth);
	}
}

