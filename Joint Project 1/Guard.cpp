#include "Guard.h"



Guard::Guard()
{
	loadImages(); // calls function to load images
}


Guard::~Guard()
{
}

void Guard::loadImages()
{
	if (!textureGuardWest.loadFromFile("player_left.png")) // loads image for texture
	{
		//error
	}
	if (!textureGuardEast.loadFromFile("player_right.png")) // loads image for texture
	{
		//error
	}
	if (!textureGuardNorth.loadFromFile("player_up.png")) // loads image for texture
	{
		//error
	}
	if (!textureGuardSouth.loadFromFile("player_down.png")) // loads image for texture
	{
		//error
	}
}

void Guard::setUpEnemy()
{
	guard.setPosition(730,530); // sets position of guard
	guard.setTexture(textureGuardEast); // sets texture of guard
	
}

/// <summary>
/// Guards will move to the players position and fire at them as long as no player
/// trees are present. Otherwise the guards will move to the players trees and fire at them until they are destroyed.
/// </summary>
/// <param name="t_treeOne"></param>
/// <param name="t_treeTwo"></param>
/// <param name="t_treeThree"></param>
/// <param name="t_treeFour"></param>
/// <param name="t_PlayerPosition"></param>
void Guard::moveSouthGuard(bool t_treeOne, bool t_treeTwo, bool t_treeThree, bool t_treeFour, sf::Vector2f t_PlayerPosition)
{
	if (t_treeOne == true || t_treeTwo == true || t_treeThree == true || t_treeFour == true)
	{
		if (t_treeOne == true || t_treeTwo == true)
		{
			if (guard.getPosition().x > 180)
			{
				moveLeft = true;
				moveRight = false;
				fire = false;
				
			}
			else if (guard.getPosition().x < 180)
			{
				moveRight = true;
				moveLeft = false;
				fire = false;
			}
			else if (guard.getPosition().x == 180)
			{
				guard.setTexture(textureGuardNorth); // sets texture of guard
				moveRight = false;
				moveLeft = false;
				fire = true;
			}
		}
		else if (t_treeThree == true || t_treeFour == true)
		{
			if (guard.getPosition().x > 480)
			{
				moveLeft = true;
				moveRight = false;
				fire = false;

			}
			else if (guard.getPosition().x < 480)
			{
				moveRight = true;
				moveLeft = false;
				fire = false;
			}
			else if (guard.getPosition().x == 480)
			{
				guard.setTexture(textureGuardNorth); // sets texture of guard
				moveRight = false;
				moveLeft = false;
				fire = true;
			}
		}
	}
	else if (guard.getPosition().x - t_PlayerPosition.x <= 5 && guard.getPosition().x - t_PlayerPosition.x >= -5)
	{
		moveLeft = false;
		moveRight = false; 
		guard.setTexture(textureGuardNorth); // sets texture of guard
		fire = true;
	}
	else if (guard.getPosition().x - t_PlayerPosition.x < -5 && guard.getPosition().x <= 400 && moveLeft == false && moveRight == false)
	{
		moveLeft = false;
		moveRight = true;
		fire = false;

	}
	else if (guard.getPosition().x - t_PlayerPosition.x > 5  && moveLeft == false && moveRight == false)
	{
		moveLeft = true;
		moveRight = false;
	}

	if (guard.getPosition().x < -10)
	{
		guard.setPosition(820,guard.getPosition().y);
	}
	if (guard.getPosition().x > 820)
	{
		guard.setPosition(-10, guard.getPosition().y);
	}
	if (moveLeft == true)
	{
		guard.move(-2, 0); // moves left
		guard.setTexture(textureGuardWest); // sets texture of guard
	}
	
	if (moveRight == true)
	{
		guard.move(2, 0); //moves right

		guard.setTexture(textureGuardEast); // sets texture of guard
	}
}

void Guard::moveEastGuard(bool t_treeOne, bool t_treeTwo, bool t_treeThree, bool t_treeFour, sf::Vector2f t_PlayerPosition)
{
	if (t_treeOne == true || t_treeTwo == true || t_treeThree == true || t_treeFour == true)
	{
		if (t_treeOne == true || t_treeTwo == true)
		{
			if (guard.getPosition().y > 140)
			{
				moveUp = true;
				moveDown = false;
				fire = false;
			}
			else if (guard.getPosition().y < 140)
			{
				moveDown = true;
				moveUp = false;
				fire = false;
			}
			else if (guard.getPosition().y == 140)
			{
				guard.setTexture(textureGuardNorth); // sets texture of guard
				moveDown = false;
				moveUp = false;
				fire = true;
			}
		}
		else if (t_treeThree == true || t_treeFour == true)
		{
			if (guard.getPosition().y > 440)
			{
				moveDown = false;
				moveUp = true;
				fire = false;

			}
			else if (guard.getPosition().y < 440)
			{
				moveDown = true;
				moveUp = false;
				fire = false;
			}
			else if (guard.getPosition().y == 440)
			{
				guard.setTexture(textureGuardWest); // sets texture of guard
				moveDown = false;
				moveUp = false;
				fire = true;
			}
		}
	}
	else if (guard.getPosition().y - t_PlayerPosition.y <= 5 && guard.getPosition().y - t_PlayerPosition.y >= -5)
	{
		moveDown = false;
		moveUp = false;
		guard.setTexture(textureGuardWest); // sets texture of guard
		fire = true;
	}
	else if (guard.getPosition().y - t_PlayerPosition.y < -5 && guard.getPosition().y <= 400 && moveDown == false && moveUp == false)
	{
		moveDown = true;
		moveUp = false;
		fire = false;
	}
	else if (guard.getPosition().y - t_PlayerPosition.y > 5 && moveDown == false && moveUp == false)
	{
		moveDown = false;
		moveUp = true;
	}

	if (guard.getPosition().y < -10)
	{
		guard.setPosition(guard.getPosition().x, 630);
	}
	if (guard.getPosition().y > 820)
	{
		guard.setPosition(guard.getPosition().x, - 30);
	}

	if (moveDown == true)
	{
		guard.move(0, 2); // moves down
		guard.setTexture(textureGuardSouth); // sets texture of guard
	}

	if (moveUp == true)
	{
		guard.move(0,-2); // moves up
		guard.setTexture(textureGuardNorth); // sets texture of guard
	}
}

