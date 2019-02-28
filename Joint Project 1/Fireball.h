#pragma once

#include "SFML/Graphics.hpp" 

class Fireball
{
public:
	Fireball();
	~Fireball();

	sf::Texture textureFireball; // the texture for firebal
	// Note instead of using the 4 texture images above you might choose to use one image and rotate it.

	sf::Sprite fireball; // sprite used to represent fireball
	sf::Sprite fireballTwo;

	int speed;  // the speed of the fireball
	int direction; // the direction of the fireball
	bool isAlive;  //To see if the fireball is still alive 

	//Function members :
	//Fireball(); //constructor
	void draw(); //used to draw the fireball
	void update(); //updates every 60 frames
	void hit(); // the fireball has hit something
	void fired(); // the fireball is fired
	void move(); // the fireball moves 
	void loadImages();
	sf::RectangleShape shape;
	sf::Vector2f velocity;

	void setUpShapes();
	//void move();

	//***********************************
	
	void moveUp();

	void moveDown();

	void moveRight();
	void eastGuardFire();
	void moveLeft();
	void stop();

	void southGuardFire();

	int fireballWait = 0;
	bool readyFire = false;

	void moveGuard();
	
};

