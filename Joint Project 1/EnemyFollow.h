#pragma once

#include "SFML/Graphics.hpp" 



class EnemyFollow
{

public:
	EnemyFollow();
	~EnemyFollow();

	
	sf::Texture textureNorth; // the texture for enemy facing north
	sf::Texture textureSouth; // the texture for enemy facing south
	sf::Texture textureEast; // the texture for enemy facing east
	sf::Texture textureWest; // the texture for enemy facing west
	// Note instead of using the 4 texture images above you might choose to use one image and rotate it.

	sf::Sprite body; // sprite used to represent enemy

	//int speed;  // the speed of the enemy
	int timesHit; // the number of times hit
	int direction; // the direction the enemy is facing
	bool isAlive;  //To see if the enemy is still alive 
	int health = 30;
	// Functions
	//EnemyFollow(); //constructor
	void setUpEnemy();
	sf::Sprite draw(); //used to draw the enemy
	void update(); //updates every 60 frames
	void hit(); // enemy is hit by a fireball
	void dies();// enemy dies
	void reSpawn(); // the enemy respawns somewhere randomly on the screen
	void move(sf::Vector2f t_PlayerPosition); // the enemy follows the player but stay within the boundary of the screen.
	void moveTwo(sf::Vector2f t_PlayerPosition); // the enemy follows the player but stay within the boundary of the screen.
	void loadImages();
	
	int speed = 1;
	int speedTwo = 1;
};

