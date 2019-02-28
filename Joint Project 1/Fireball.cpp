#include "Fireball.h"

Fireball::Fireball()
{
	loadImages();  // loads images
}

Fireball::~Fireball()
{
}

void Fireball::loadImages()
{
	if (!textureFireball.loadFromFile("fireball_up.png"))  // loads texture
	{
		//error
	}
}
void Fireball::setUpShapes()
{
	
	fireball.setTexture(textureFireball);  // sets texture of players fireball
	fireball.setPosition(1000, 1000); // sets position off screen
	fireball.setOrigin(32,32); // sets oruigin to centre

	fireballTwo.setTexture(textureFireball);  // sets texture of the enemies fireball
	fireballTwo.setPosition(1000, 1000);  // sets position off screen
}


// the clock object keeps the time.
void Fireball::move()
{
	fireball.move(velocity);  // movbes the players fireball
}

void Fireball::southGuardFire()
{
	fireballTwo.move(0, -4);  // moves south guards fireball
}

void Fireball::eastGuardFire()
{
	fireballTwo.move(-4, 0);  // moves east guards fireball
}
