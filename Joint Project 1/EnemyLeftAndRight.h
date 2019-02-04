#pragma once

#include "SFML/Graphics.hpp" 

class EnemyLeftAndRight
{
public:
	EnemyLeftAndRight();
	~EnemyLeftAndRight();

	sf::Texture textureNorth; // the texture for enemy facing north
	sf::Texture textureSouth; // the texture for enemy facing south
	sf::Texture textureEast; // the texture for enemy facing east
	sf::Texture textureWest; // the texture for enemy facing west
	// Note instead of using the 4 texture images above you might choose to use one image and rotate it.

	sf::Sprite body; // sprite used to represent enemy

	int speed;  // the speed of the enemy
	int direction; // the direction the enemy is facing
	bool isAlive;  //To see if the enemy is still alive 
	bool moveLeft = true;
	// Function members :
	//EnemyLeftAndRight(); //constructor
	sf::Sprite draw(); //used to draw the enemy
	void update(); //updates every 60 frames
	void hit(); // enemy is hit by a fireball
	void dies(); // enemy dies
	void reSpawn(); // the enemy respawns to a fixed position on the screen
	void move(); // the enemy moves left to right on the screen but stay within the boundary of the screen.
	void setUpEnemy();
};

