// Game class declaration
#pragma once

#include "Player.h"   // include Player header file
#include "EnemyFollow.h"
#include "EnemyLeftAndRight.h"
#include "Fireball.h"

#include "SFML/Graphics.hpp" 
#include <iostream>
#include <cstdlib>  // include support for randomizing
#include <ctime>   // supports ctime function

#include "Globals.h"   // include Global header file

class Game
{
	// private data members

	// put your game objects here eg player object and 
	// array of enemy objects etc.

	sf::RenderWindow window;

public:
	sf::Font m_font;  // font for writing text
	sf::Text m_message;  // text to write on the screen

public:	  // declaration of member functions	
	Game(); // default constructor
	
	void setUpGame(); //sets up player and enemies etc for a new game
	void loadContent();
	void run();
	void update();
	void draw();
	void collisionDetection(); // checks for collisions between the player and enemies 
	void fireballCollisionDetection();  // checks for collisions between the fireball and enemies 
	void isGameOver(); // checks if the game is over
	void displayGameStats(); //display player health and score to the screen

	Player player;
	EnemyFollow enemyFollowArray[MAX_ENEMIES];  // an array of enemies of type follow
	EnemyFollow enemyFollow;
	EnemyLeftAndRight enemyOne;  // 3 enemies of type leftRight
	EnemyLeftAndRight enemyTwo;
	EnemyLeftAndRight enemyThree;
	Fireball playerFireball;  // the player’s fireball in the game
	
	const int MAX_ENEMIES = 10;  // the max number of EnemyFollow objects allowed in game
	int noEnemies;  // the number of active EnemyFollow objects in the game
	bool gameOver; // true if the game is over

	sf::Sprite backGround;
	sf::Texture backGroundTexture;

};
