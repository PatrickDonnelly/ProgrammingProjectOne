#pragma once

#include "SFML/Graphics.hpp" 

class Fireball
{
public:
	Fireball();
	~Fireball();

	sf::Texture textureNorth; // the texture for fireball facing north
	sf::Texture textureSouth; // the texture for fireball facing south
	sf::Texture textureEast; // the texture for fireball facing east
	sf::Texture textureWest; // the texture for fireball facing west
	// Note instead of using the 4 texture images above you might choose to use one image and rotate it.

	sf::Sprite body; // sprite used to represent fireball

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

};

