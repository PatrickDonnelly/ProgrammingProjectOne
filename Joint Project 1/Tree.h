#pragma once

#include "SFML/Graphics.hpp" 

class Tree
{
public:
	Tree();
	~Tree();

	sf::Texture palmTreeTexture; // the texture for enemy facing north
	sf::Texture palmTreeFireLeft; // the texture for enemy facing south
	sf::Texture palmTreeFireRight; // the texture for enemy facing east
	sf::Texture saplingTexture; // the texture for enemy facing west
	sf::Texture matureTreeTexture;
	sf::Texture moundTexture;
	sf::Texture halfTree;
	void loadImages();
	// Note instead of using the 4 texture images above you might choose to use one image and rotate it.

	//sf::Sprite mound; // sprite used to represent enemy
	sf::Sprite palmTree;
	sf::Sprite moundOne;
	sf::Sprite mound;
	sf::Sprite moundTwo;
	sf::Sprite moundThree;
	sf::Sprite moundFour;
	sf::Sprite sapling;
	sf::Sprite matureTree;

	bool grown = false;
	int matureTreeHealth = 100;

	int health = 100;  // the speed of the enemy

	bool treeAlive;  //To see if the enemy is still alive 
	int growing = 0;
	bool planted = false;
	// Function members :
	//EnemyLeftAndRight(); //constructor

	void treeGrown();
	void treePlanted();
	void update(); //updates every 60 frames
	void onFire(); // enemy is hit by a fireball
	//void growing(); // enemy dies
	void reSpawn(); // the enemy respawns to a fixed position on the screen
	sf::Sprite draw();
	void setUpTree();

	
};

