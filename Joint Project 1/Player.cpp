

#include "Player.h"   // include Player header file
#include "Globals.h"
#include <iostream>
// Player function definitions here

Player::Player()
{
	loadImages(); // calls load images
}
Player::~Player()
{
}

void Player::loadImages()
{
	if (!textureWest.loadFromFile("player_left.png"))  // loads image for texture
	{
		std::cout << "cannot load image";
	}

	if (!textureSouth.loadFromFile("player_down.png"))  // loads image for texture
	{
		std::cout << "cannot load image";
	}

	if (!textureNorth.loadFromFile("player_up.png"))  // loads image for texture
	{
		std::cout << "cannot load image";
	}

	if (!textureEast.loadFromFile("player_right.png"))  // loads image for texture
	{
		std::cout << "cannot load image";
	}
	
}

// code for functions
void Player::setUpPlayerSprite()
{
	playerBody.setTexture(textureSouth);
	playerBody.setPosition(30, 30); // sets players starting position
	playerBody.setOrigin(32,32);  // sets players origin to the centyre of the sprite
	health = 100; // sets players health to 100
	score = 0;  // sets player's score to zero
}

void Player::playerMoveLeft()
{
	sf::Vector2f velocity = { 0,0 }; // players starting velocity
	if (playerBody.getPosition().x > 0)
	{
		velocity.x = -4; // sets players velocity
	}
	if (velocity.x != 0 || velocity.y != 0)
	{
		lookDirection = velocity; // changes direction player is looking to match velocity to fire the fireball correctly
	}

	playerBody.setTexture(textureWest);  // sets player texture to west
	playerBody.move(velocity); // moves player left
}

void Player::playerMoveRigth()
{
	sf::Vector2f velocity = { 0,0 }; // players starting velocity
	if (playerBody.getPosition().x < SCREEN_WIDTH - 125)
	{
		velocity.x = 4; // sets players velocity
	}
	if (velocity.x != 0 || velocity.y != 0)
	{
		lookDirection = velocity; // changes direction player is looking to match velocity to fire the fireball correctly
	}
	playerBody.setTexture(textureEast);  // sets player texture to east
	playerBody.move(velocity); // moves player right
}

void Player::playerMoveUp()
{
	sf::Vector2f velocity = { 0,0 }; // players starting velocity

	if (playerBody.getPosition().y > 0)
	{
		velocity.y = -4; // sets players velocity
	}
	if (velocity.x != 0 || velocity.y != 0)
	{
		lookDirection = velocity; // changes direction player is looking to match velocity to fire the fireball correctly
	}
	playerBody.setTexture(textureNorth);  // sets player texture to north
	playerBody.move(velocity); // moves player up
}

void Player::playerMoveDown()
{
	sf::Vector2f velocity = { 0,0 }; // players starting velocity
	if (playerBody.getPosition().y < SCREEN_HEIGHT - 140)
	{
		velocity.y = 4; // sets players velocity
	}
	if (velocity.x != 0 || velocity.y != 0)
	{
		lookDirection = velocity; // changes direction player is looking to match velocity to fire the fireball correctly
	}
	playerBody.setTexture(textureSouth);  // sets player texture to south
	playerBody.move(velocity); // moves player down
}