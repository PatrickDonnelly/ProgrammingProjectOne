// Game class declaration
#pragma once

#include "Player.h"   // include Player header file
#include "EnemyFollow.h"   // include EnemyFollow header file
#include "EnemyLeftAndRight.h"   // include EnemyLeftAndRight header file
#include "Fireball.h"   // include Fireball header file
#include "Tree.h"   // include Tree header file
#include "Guard.h"   // include Guard header file
#include "MyVector2.h"   // include MyVector2 header file

#include "SFML/Graphics.hpp" // include sfml graphics
#include <iostream>  // include iostream
#include <cstdlib>  // include support for randomizing
#include <ctime>   // supports ctime function
#include <SFML/Audio.hpp>  // include audio for sfml
#include "Globals.h"   // include Global header file

class Game
{
	// private data members

	// put your game objects here eg player object and 
	// array of enemy objects etc.

	sf::RenderWindow window;  // window that displays the game
	sf::Font m_font;  // font for writing text
	sf::Text m_message;  // text to write on the screen

public:	  // declaration of member functions	
	Game(); // default constructor
	const static int MAX_TRUCKS = 2;  // max amount of truck enemies stored in an array
	const static int FIREBALL_ARRAY_SIZE = 2; // max size of the players bullet array
	const int MAX_ENEMIES = 10;  // the max number of EnemyFollow objects allowed in game
	int noEnemies;  // the number of active EnemyFollow objects in the game
	bool gameOver = false; // true if the game is over
	bool gameStarted = false; // bool for whether the game has started or not
	bool gameHelp = false;  // for the help menu to open or not
	bool gameExit = false;  // for the exit option to be used or not
	bool start = true;  // start option is used or not
	bool help = false;  // help bool
	bool exit = false; // exit bool

	Player player; // creates an object of type player
	EnemyFollow enemyFollow; // creates an object of type EnemyFollow
	EnemyFollow enemyFollowTwo; // creates an object of type EnemyFollow
	EnemyLeftAndRight enemyOne[MAX_TRUCKS];  // 3 enemies of type EnemyLeftAndRight
	Tree palmTreeOne; // creates an object of type Tree
	Tree palmTreeTwo; // creates an object of type Tree
	Tree palmTreeThree; // creates an object of type Tree
	Tree palmTreeFour; // creates an object of type Tree
	Tree moundOne; // creates an object of type Tree
	Tree moundTwo; // creates an object of type Tree
	Tree moundThree; // creates an object of type Tree
	Tree moundFour; // creates an object of type Tree
	Tree saplingOne; // creates an object of type Tree
	Tree saplingTwo; // creates an object of type Tree
	Tree saplingThree; // creates an object of type Tree
	Tree saplingFour; // creates an object of type Tree
	Tree treeOne; // creates an object of type Tree
	Tree treeTwo; // creates an object of type Tree
	Tree treeThree; // creates an object of type Tree
	Tree treeFour; // creates an object of type Tree
	Guard southGuard; // creates an object of type Guard
	Guard eastGuard; // creates an object of type Guard
	Fireball fireballArray[FIREBALL_ARRAY_SIZE]; // creates an object of type Fireball
	Fireball southGuardFireArray[FIREBALL_ARRAY_SIZE]; // creates an object of type Fireball
	Fireball eastGuardFireArray[FIREBALL_ARRAY_SIZE]; // creates an object of type Fireball
	
	sf::SoundBuffer buffer;  // loads sound buffer
	sf::Sound sound; // plays a sound
	sf::Sprite backGround;  // background sprite
	sf::Sprite menu; // sprite for the menu screen
	sf::Texture backGroundTexture;  // texture for background
	sf::Texture menuStartTexture;  // texture for start menu
	sf::Texture menuExitTexture;  // texture for exit menu
	sf::Texture menuHelpTexture;  // texture for exit menu
	
	void setUpGame(); //sets up player and enemies etc for a new game
	void loadContent();  // loads font
	void run();  // runs the game method
	void update();  // updates the game
	void draw();  // draws the objects
	void collisionDetection(); // checks for collisions between the player and enemies 
	void fireballCollisionDetection();  // checks for collisions between the fireball and enemies - not used
};
