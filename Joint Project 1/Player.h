// Player class declaration
#pragma once

#include "SFML/Graphics.hpp" 
// define stuff for player here
class Player
{
	// private data members


public:

	sf::Texture textureNorth; // the texture for player facing north
	sf::Texture textureSouth; // the texture for player facing south
	sf::Texture textureEast; // the texture for player facing east
	sf::Texture textureWest; // the texture for player facing west
	// Note instead of using the 4 texture images above you might choose to use one image and rotate it.

	sf::Sprite body; // sprite used to represent player

	int health;  // the health of the player
	int speed;  // the speed of the player
	int score;   // the player score
	int direction; // the direction the player is facing
	bool isAlive;  //To see if the player is still alive 
	int row;
	int column = 1;
	int frameCount = 1;

	
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


	void setUpPlayerSprite();
	void playerMoveLeft();
	void playerMoveRigth();
	void playerMoveUp();
	void playerMoveDown();
	sf::Sprite getBody();
	sf::Vector2f getSpritePosition();
	sf::Vector2f currentPosition{450,450};

	//void move2();
	sf::Sprite body2;
	sf::Texture textureNorth2; // the texture for player facing north
	sf::Texture textureSouth2; // the texture for player facing south
	sf::Texture textureEast2; // the texture for player facing east
	sf::Texture textureWest2;
	void setUpEnemy2();
	void move2();
	sf::Sprite draw2();
};