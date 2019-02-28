#pragma once
#include "SFML/Graphics.hpp" 
class Guard
{
public:
	Guard();
	~Guard();

	void loadImages();
	sf::Texture textureGuardNorth; // the texture for enemy facing north
	sf::Texture textureGuardSouth; // the texture for enemy facing south
	sf::Texture textureGuardEast; // the texture for enemy facing east
	sf::Texture textureWest; // the texture for enemy facing west
	sf::Texture textureGuardWest;
	// Note instead of using the 4 texture images above you might choose to use one image and rotate it.

	sf::Sprite guard; // sprite used to represent enemy
	
	//sf::Sprite platformOne;
	//sf::Sprite platformTwo;
	//sf::Sprite platformThree;
	//sf::Sprite platformFour;
	int speed;  // the speed of the enemy
	int direction; // the direction the enemy is facing
	bool isAlive;  //To see if the enemy is still alive 
	bool moveLeft = false;
	bool moveRight = false;
	bool moveDown = false;
	bool moveUp = true;
	// Function members :
	//EnemyLeftAndRight(); //constructor
	sf::Sprite draw(); //used to draw the enemy
	void update(); //updates every 60 frames
	void hit(); // enemy is hit by a fireball
	void dies(); // enemy dies
	void reSpawn(); // the enemy respawns to a fixed position on the screen
	void moveEastGuard(bool t_treeOne, bool t_treeTwo, bool t_treeThree, bool t_treeFour, sf::Vector2f t_PlayerPosition);// the enemy moves left to right on the screen but stay within the boundary of the screen.
	void moveSouthGuard(bool t_treeOne, bool t_treeTwo, bool t_treeThree, bool t_treeFour, sf::Vector2f t_PlayerPosition);
	void setUpEnemy();
	bool fire = false;

	void Guard::southGuardFire();


};

