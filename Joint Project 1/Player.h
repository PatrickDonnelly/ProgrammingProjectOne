// Player class declaration
#pragma once

#include "SFML/Graphics.hpp" 



// define stuff for player here
class Player
{
	// private data members


public:
	int waitToFireCounter;
	sf::Texture textureNorth; // the texture for player facing north
	sf::Texture textureSouth; // the texture for player facing south
	sf::Texture textureEast; // the texture for player facing east
	sf::Texture textureWest; // the texture for player facing west
	// Note instead of using the 4 texture images above you might choose to use one image and rotate it.

	sf::Sprite playerBody; // sprite used to represent player

	int health = 100;  // the health of the player
	int speed;  // the speed of the player
	int score = 0;;   // the player score
	int direction; // the direction the player is facing
	bool isAlive;  //To see if the player is still alive 
	int row;
	int column = 1;
	int frameCount = 1;
	sf::Vector2f velocity = { 0,0 };
	sf::Vector2f lookDirection = { 0,0 };
	
	Player(); //constructor
	~Player();
	void draw(); //used to draw the player
	void update(); //updates every 60 frames
	void shoot(); //function to cause fireball to shoot
	void dies(); // the player dies
	void decreaseHealth(); // reduce player health
	void displayPlayerStats(); // display the player health & score on the screen
	void increaseScore();  // the player’s score increases
	void decreaseScore(); // the player’s score decreases

	void loadImages();
	void setUpPlayerSprite();
	void playerMoveLeft();
	void playerMoveRigth();
	void playerMoveUp();
	void playerMoveDown();
	sf::Sprite getBody();
	sf::Vector2f currentPosition{450,450};


};