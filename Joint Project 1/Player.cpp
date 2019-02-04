

#include "Player.h"   // include Player header file
#include "Globals.h"
#include <iostream>
// Player function definitions here

Player::Player()
{
	//body.setPosition(body.getPosition().x, body.getPosition().y);
	//body.setPosition(getSpritePosition());
	//currentPosition;
}
Player::~Player()
{
}

// code for functions
void Player::setUpPlayerSprite()
{
	if (!textureSouth.loadFromFile("player_down.png"))
	{
		std::cout << "cannot load image";
	}
	body.setTexture(textureSouth);
	//m_player.setOrigin(20, 20);
	//body.setPosition(300, 300);
	body.setTexture(textureSouth);
	//column = (frameCount % 8);
	//row = frameCount / 8;
	//body.setTextureRect(sf::IntRect(1 * 128, 1 * 94, 128, 94));
}

void Player::playerMoveLeft()
{
	if (body.getPosition().x > 20)
	{
		body.setPosition(body.getPosition().x - 3, body.getPosition().y);
		//body.move(-3, 0);
	}
	else
	{
		body.setPosition(body.getPosition().x + 20, body.getPosition().y);
		currentPosition = body.getPosition();
		//body.move(20, 0);
	}
	if (!textureWest.loadFromFile("player_left.png"))
	{
		std::cout << "cannot load image";
	}
	body.setTexture(textureWest);
}

void Player::playerMoveRigth()
{
	if (body.getPosition().x < SCREEN_WIDTH - 80)
	{
		body.setPosition(body.getPosition().x + 3, body.getPosition().y);
		currentPosition = body.getPosition();
		//body.move(3, 0);
	}
	else
	{
		body.setPosition(body.getPosition().x - 20, body.getPosition().y);
		//body.move(-20, 0);
	}
	
	if (!textureEast.loadFromFile("player_right.png"))
	{
		std::cout << "cannot load image";
	}
	body.setTexture(textureEast);
	
}

void Player::playerMoveUp()
{
	if (body.getPosition().y > 20)
	{
		body.setPosition(body.getPosition().x, body.getPosition().y - 3);
		currentPosition = body.getPosition();
		//body.move(0, -3);
	}
	else
	{
		body.setPosition(body.getPosition().x, body.getPosition().y + 20);
		//body.move(0, 20);
	}
	
	if (!textureNorth.loadFromFile("player_up.png"))
	{
		std::cout << "cannot load image";
	}
	body.setTexture(textureNorth);
}

void Player::playerMoveDown()
{
	if (body.getPosition().y < SCREEN_HEIGHT - 100)
	{
		body.setPosition(body.getPosition().x, body.getPosition().y + 3);
		getSpritePosition();
		//body.move(0, 3);
		currentPosition = body.getPosition();
		//getSpritePosition(currentPosition);
	}
	else
	{
		body.setPosition(body.getPosition().x, body.getPosition().y - 20);
		//body.move(0, -20);
	}

	if (!textureSouth.loadFromFile("player_down.png"))
	{
		std::cout << "cannot load image";
	}
	body.setTexture(textureSouth);
}

sf::Sprite Player::getBody()
{
	//sf::Vector2f pos;
	//pos = body.getPosition();
	return body;
}

sf::Vector2f Player::getSpritePosition()
{
	
	body.setPosition(body.getPosition().x,body.getPosition().y);
	currentPosition = body.getPosition();
	return currentPosition;
}

void Player::setUpEnemy2()
{
	if (!textureWest.loadFromFile("enemy2_right.png"))
	{
		//error
	}
	body2.setTexture(textureWest);
	body2.setPosition(200, 100);
}

void Player::move2()
{
	//player.body.getPosition().x;
	
	if (body2.getPosition().x < body.getPosition().x)
	{
		body2.move(2, 0);

		if (!textureWest2.loadFromFile("enemy2_right.png"))
		{
			//error
		}
		body2.setTexture(textureWest2);
	}
	if (body2.getPosition().x > body.getPosition().x)
	{
		body2.move(-2, 0);

		if (!textureEast2.loadFromFile("enemy2_left.png"))
		{
			//error
		}
		body2.setTexture(textureEast2);
	}
	if (body2.getPosition().y > body.getPosition().y)
	{
		body2.move(0, -2);

		if (!textureWest2.loadFromFile("enemy2_right.png"))
		{
			//error
		}
		body2.setTexture(textureWest2);
	}
	if (body2.getPosition().y < body.getPosition().y)
	{
		body2.move(0, 2);

		if (!textureEast2.loadFromFile("enemy2_left.png"))
		{
			//error
		}
		body2.setTexture(textureEast2);
	}

}

sf::Sprite Player::draw2()
{
	//body.getPosition();
	return body2;
}