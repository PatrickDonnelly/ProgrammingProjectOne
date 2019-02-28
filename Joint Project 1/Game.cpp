// Name: Patrick Donnelly
// Login: C00236160
// Date: 25th February 2019
// Approximate time taken: 80 hours
//---------------------------------------------------------------------------
// Project description: A single player action shooter where the player is tasked
//						with burning palm tree plantations that have been destroying the
//						rainforest. The player must destroy the trees and machinary to earn points.
//						If the player plants natural trees they will gain even more points.
//						The goal is to get the highest score possible
// ---------------------------------------------------------------------------
// Known Bugs: No known bugs

//////////////////////////////////////////////////////////// 
// include correct library file for release and debug versions
//////////////////////////////////////////////////////////// 

#ifdef _DEBUG 
#pragma comment(lib,"sfml-graphics-d.lib") 
#pragma comment(lib,"sfml-audio-d.lib") 
#pragma comment(lib,"sfml-system-d.lib") 
#pragma comment(lib,"sfml-window-d.lib") 
#pragma comment(lib,"sfml-network-d.lib") 
#else 
#pragma comment(lib,"sfml-graphics.lib") 
#pragma comment(lib,"sfml-audio.lib") 
#pragma comment(lib,"sfml-system.lib") 
#pragma comment(lib,"sfml-window.lib") 
#pragma comment(lib,"sfml-network.lib") 
#endif 
#pragma comment(lib,"opengl32.lib") 
#pragma comment(lib,"glu32.lib") 



#include "Game.h"   // include Game header file


int main()
{
	Game aGame;  // Object of type game
	aGame.loadContent();  // Calls this function from the game class
	aGame.setUpGame();  // Calls this function from the game class
	aGame.run();  // Calls this function from the game class
	return 0;
}

Game::Game() : window(sf::VideoMode(static_cast<int>(SCREEN_WIDTH), static_cast<int>(SCREEN_HEIGHT)), "Project Game", sf::Style::Default)
// Default constructor
{
}

void Game::setUpGame()
{

	if (!buffer.loadFromFile("nature.wav")) // Loads a sound buffer
	{
		std::cout << "cannot load file";
	}
	
	sound.setBuffer(buffer);  // sets buffer
	sound.play();  // plays sound
	sound.setLoop(true);  // loops track when finished
	sound.setPitch(1.0f);  // sets pitch top standard
	

	if (!backGroundTexture.loadFromFile("farm2.png"))  // loads an image for a texture
	{
		std::cout << "cannot load image";
	}
	backGround.setTexture(backGroundTexture);
	backGround.setPosition(0, 0);

	if (!menuStartTexture.loadFromFile("menuStart.png"))  // loads an image for a texture
	{
		std::cout << "cannot load image";
	}
	if (!menuExitTexture.loadFromFile("menuExit.png"))  // loads an image for a texture
	{
		std::cout << "cannot load image";
	}
	if (!menuHelpTexture.loadFromFile("menuHelp.png"))  // loads an image for a texture
	{
		std::cout << "cannot load image";
	}

	menu.setTexture(menuStartTexture);
	menu.setPosition(0, 0);
	player.setUpPlayerSprite();
	for (int i = 0; i < MAX_TRUCKS; i++)
	{
		enemyOne[i].setUpEnemy();
	}
	palmTreeOne.setUpTree(); // sets up object of type tree
	palmTreeTwo.setUpTree();  // sets up object of type tree
	palmTreeThree.setUpTree();  // sets up object of type tree
	palmTreeFour.setUpTree();  // sets up object of type tree

	treeOne.setUpTree();  // sets up object of type tree
	treeTwo.setUpTree();  // sets up object of type tree
	treeThree.setUpTree();  // sets up object of type tree
	treeFour.setUpTree();  // sets up object of type tree

	moundOne.setUpTree();  // sets up object of type tree
	moundTwo.setUpTree();  // sets up object of type tree
	moundThree.setUpTree();  // sets up object of type tree
	moundFour.setUpTree();  // sets up object of type tree

	saplingOne.setUpTree();  // sets up object of type tree
	saplingTwo.setUpTree();  // sets up object of type tree
	saplingThree.setUpTree();  // sets up object of type tree
	saplingFour.setUpTree();  // sets up object of type tree

	palmTreeOne.palmTree.setPosition(200, 100);  // sets position of this palm tree
	palmTreeTwo.palmTree.setPosition(200, 400);  // sets position of this palm tree
	palmTreeThree.palmTree.setPosition(500, 100);  // sets position of this palm tree
	palmTreeFour.palmTree.setPosition(500, 400);  // sets position of this palm tree

	moundOne.mound.setPosition(180, 160);  // sets position of this mound
	moundTwo.mound.setPosition(180, 460);  // sets position of this mound
	moundThree.mound.setPosition(480, 160);  // sets position of this mound
	moundFour.mound.setPosition(480, 460);  // sets position of this mound

	enemyFollow.setUpEnemy(); // sets up an enemy that will follow the player
	enemyFollowTwo.setUpEnemy();  // sets up an enemy that will follow the player
	southGuard.setUpEnemy();  // sets up an enemy that will shot at the player
	eastGuard.setUpEnemy();  // sets up an enemy that will shot at the player

	for (int i = 0; i < FIREBALL_ARRAY_SIZE; i++)
	{
		fireballArray[i].setUpShapes();  // sets up the players projectile
		fireballArray[i].velocity.x = 0; // sets initial velocity of the projectile on thex axis
		fireballArray[i].velocity.y = 0;  // sets initial velocity of the projectile on thex axis
	}
	for (int i = 0; i < FIREBALL_ARRAY_SIZE; i++)
	{
		southGuardFireArray[i].setUpShapes();  // Sets up south guards bullet
	}
	for (int i = 0; i < FIREBALL_ARRAY_SIZE; i++)
	{
		eastGuardFireArray[i].setUpShapes();  // sets up east guards bullet
	}
}

void Game::loadContent()
// load the font file & setup the message
{
	if (!m_font.loadFromFile("ASSETS/FONTS/BebasNeue.otf"))  // loads font type
	{
		std::cout << "error with font file file";
	}
	m_message.setFont(m_font);  // set the font for the text
	m_message.setCharacterSize(24); // set the text size
	m_message.setFillColor(sf::Color::White); // set the text colour
	m_message.setPosition(10, 10);  // its position on the screen
}


void Game::run()
// This function contains the main game loop which controls the game. 
{
	srand(time(nullptr)); // set the seed once
	sf::Time timePerFrame = sf::seconds(1.0f / 60.0f);
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	// the clock object keeps the time.
	sf::Clock clock;
	clock.restart();

	while (window.isOpen())
	{
		// check if the close window button is clicked on
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		//get the time since last update and restart the clock
		timeSinceLastUpdate += clock.restart();

		//update every 60th of a second
		//only when the time since last update is greater than 1/60 update the world.
		if (timeSinceLastUpdate > timePerFrame)
		{
			update();
			draw();
			collisionDetection();
			
			// reset the timeSinceLastUpdate to 0 
			timeSinceLastUpdate = sf::Time::Zero;
		}
	}  // end while loop

}

void Game::update()
// This function takes the keyboard input and updates the game world
{
	
	if (gameOver == true)  // if the game ends
	{
		sound.setPitch(0.5f);  // slows the song down
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))  // if the one key is pressed
		{
			setUpGame();  // sets up all the objects in the game so the player canh play and returns to main menu
			gameOver = false;  // sets game over to false
			gameStarted = false; // sets game started to false
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))  // if the two key is pressed
		{
			window.close();  // closes the window
		}
	}
	if (gameStarted == false && gameOver == false)  // if the game hasn't started and it is not game over
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))  // if the one key is pressed
		{
			menu.setTexture(menuStartTexture);  // changes to the start game option
			start = true;
			help = false;
			exit = false;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))  // if the two key is pressed
		{
			menu.setTexture(menuHelpTexture);  // changes to the help option
			start = false;
			help = true;
			exit = false;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))  // if the three key is pressed
		{
			menu.setTexture(menuExitTexture);  // changes to the exit option
			start = false;
			help = false;
			exit = true;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && start == true)  // if the enter key is pressed and start bool is true
		{
			gameStarted = true;  // starts the game
			gameOver = false;
			start = false;
			help = false;
			exit = false;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && help == true)  // if the enter key is pressed and help bool is true
		{
			gameHelp = true;  // enters the help menu
			gameOver = false;
			start = false;
			help = false;
			exit = false;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && exit == true)  // if the enter key is pressed and exit bool is true
		{
			window.close();  // closes the window
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1) && gameHelp == true)  // if the one key is pressed and gamehelp bool is true
		{
			gameHelp = false;  // exits the help menu
		}
		
	}
	if (gameOver == false && gameStarted == true)  // if it is not game over and the game has started
	{
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))  // move the plajyer left
		{
			player.playerMoveLeft();
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))  // moive the player right
		{
			player.playerMoveRigth();
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))  // move the p[layer up
		{
			player.playerMoveUp();
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))  // move the player down
		{
			player.playerMoveDown();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))  // button used for planting
		{
			if (vectorLength(player.playerBody.getPosition() - moundOne.mound.getPosition()) < 60 && palmTreeOne.treeAlive == false)
			{
				moundOne.planted = true;  // a sapling has been planted in the first mound when its empty and the player is close enough

			}
			if (vectorLength(player.playerBody.getPosition() - moundTwo.mound.getPosition()) < 60 && palmTreeTwo.treeAlive == false)
			{
				moundTwo.planted = true;  // a sapling has been planted in the second mound when its empty and the player is close enough

			}
			if (vectorLength(player.playerBody.getPosition() - moundThree.mound.getPosition()) < 60 && palmTreeThree.treeAlive == false)
			{
				moundThree.planted = true;  // a sapling has been planted in the third mound when its empty and the player is close enough


			}
			if (vectorLength(player.playerBody.getPosition() - moundFour.mound.getPosition()) < 60 && palmTreeFour.treeAlive == false)
			{
				moundFour.planted = true;  // a sapling has been planted in the first mound when its empty and the player is close enough

			}
		}
		for (int i = 0; i < MAX_TRUCKS; i++)
		{
			enemyOne[i].move();  // moves the enemies in this array
		}

		if (player.waitToFireCounter > 0)
		{
			player.waitToFireCounter--;  // counts down the time between players shots

		}

		if (moundOne.growing == 1199)  // when the sapling has grown for 20 seconds
		{
			player.score += 100;  // the player gets 100 points

			treeOne.grown = true;  // the tree is now grown
		}
		if (moundTwo.growing == 1199)  // when the sapling has grown for 20 seconds
		{
			player.score += 100;  // the player gets 100 points
			treeTwo.grown = true;  // the tree is now grown
		}
		if (moundThree.growing == 1199)  // when the sapling has grown for 20 seconds
		{
			player.score += 100;  // the player gets 100 points
			treeThree.grown = true;  // the tree is now grown
		}
		if (moundFour.growing == 1199)  // when the sapling has grown for 20 seconds
		{
			player.score += 100;  // the player gets 100 points
			treeFour.grown = true;  // the tree is now grown
		}
		if (player.score > 200)  // when the player scores more than 200 difficulty will increase
		{
			sound.setPitch(1.05f);  // the pace of the music increases
			enemyFollowTwo.speed = 1; // this enemies speed increases
			enemyOne[0].speedLeft = 2; // this enemies speed increases
			enemyOne[0].speedRight = -2; // this enemies speed increases
		}
		if (player.score > 500)  // when the player scores more than 500 difficulty will increase
		{
			sound.setPitch(1.1f);  // the pace of the music increases
			enemyFollowTwo.speed = 2; // this enemies speed increases
			enemyOne[0].speedLeft = 3; // this enemies speed increases
			enemyOne[0].speedRight = -3; // this enemies speed increases
			enemyOne[1].speedLeft = 1; // this enemies speed increases
			enemyOne[1].speedRight = -1; // this enemies speed increases
		}
		if (player.score > 800)  // when the player scores more than 800 difficulty will increase
		{
			sound.setPitch(1.2f);  // the pace of the music increases
			enemyFollowTwo.speed = 3; // this enemies speed increases
			enemyOne[0].speedLeft = 4; // this enemies speed increases
			enemyOne[0].speedRight = -4; // this enemies speed increases
			enemyOne[1].speedLeft = 2; // this enemies speed increases
			enemyOne[1].speedRight = -2; // this enemies speed increases
		}
		if (player.score > 1000)  // when the player scores more than 1000 difficulty will increase
		{
			sound.setPitch(1.3f);  // the pace of the music increases
			enemyOne[0].speedLeft = 5; // this enemies speed increases
			enemyOne[0].speedRight = -5; // this enemies speed increases
			enemyOne[1].speedLeft = 3; // this enemies speed increases
			enemyOne[1].speedRight = -3; // this enemies speed increases
		}
		if (player.score > 1200)  // when the player scores more than 1200 difficulty will increase
		{
			sound.setPitch(1.4f);  // the pace of the music increases
			enemyOne[0].speedLeft = 6; // this enemies speed increases
			enemyOne[0].speedRight = -6; // this enemies speed increases
			enemyOne[1].speedLeft = 4; // this enemies speed increases
			enemyOne[1].speedRight = -4; // this enemies speed increases
		}
		if (player.score > 1500)  // when the player scores more than 1500 difficulty will increase
		{
			sound.setPitch(1.5f);  // the pace of the music increases
			enemyOne[1].speedLeft = 5; // this enemies speed increases
			enemyOne[1].speedRight = -5; // this enemies speed increases
		}
		if (player.score > 2000)  // when the player scores more than 2000 difficulty will increase
		{
			sound.setPitch(1.6f);  // the pace of the music increases
			enemyOne[1].speedLeft = 6; // this enemies speed increases
			enemyOne[1].speedRight = -6; // this enemies speed increases
		}
		moundOne.treePlanted();  // calls the treePlanted function for this object
		moundTwo.treePlanted();  // calls the treePlanted function for this object
		moundThree.treePlanted();  // calls the treePlanted function for this object
		moundFour.treePlanted();  // calls the treePlanted function for this object

		treeOne.treeGrown();  // calls the treeGrown function for this object
		treeTwo.treeGrown();  // calls the treeGrown function for this object
		treeThree.treeGrown();  // calls the treeGrown function for this object
		treeFour.treeGrown();  // calls the treeGrown function for this object

		enemyFollow.move(player.playerBody.getPosition()); // calls the move function for this object and passes the players position
		enemyFollowTwo.moveTwo(player.playerBody.getPosition()); // calls the move function for this object and passes the players position
		southGuard.moveSouthGuard(treeOne.grown, treeTwo.grown, treeThree.grown, treeFour.grown, player.playerBody.getPosition()); // calls the move function for this object and passes the position of grown trees
		eastGuard.moveEastGuard(treeOne.grown, treeTwo.grown, treeThree.grown, treeFour.grown, player.playerBody.getPosition()); // calls the move function for this object and passes the position of grown trees

		if (player.health <= 0)  // if the players health is less than or equal to zero the game is over
		{
			gameOver = true;
		}
	}
}


void Game::collisionDetection()
{
	if (gameOver == false && gameStarted == true)  // if the game is playing
	{
		for (int i = 0; i < FIREBALL_ARRAY_SIZE; i++)
		{
			if (southGuardFireArray[i].fireballTwo.getPosition().y > -20)
			{
				southGuardFireArray[i].southGuardFire();  // willfire the bullet when it leaves the screen
			}
			else
			{
				southGuardFireArray[i].fireballTwo.setPosition(1000, 1000);  // otherwise position is off screen
			}
		}
		if (southGuard.fire == true)  // south guard can fire when this is true
		{
			for (int i = 0; i < FIREBALL_ARRAY_SIZE; i++)
			{
				if (southGuardFireArray[i].fireballTwo.getPosition().y == 1000)
				{
					southGuardFireArray[i].fireballTwo.setPosition(southGuard.guard.getPosition());  // sets the position to the south guards current position
					break;
				}
			}
		}

		for (int i = 0; i < FIREBALL_ARRAY_SIZE; i++)
		{
			if (eastGuardFireArray[i].fireballTwo.getPosition().x > -20)
			{
				eastGuardFireArray[i].eastGuardFire();  // willfire the bullet when it leaves the screen
			}
			else
			{
				eastGuardFireArray[i].fireballTwo.setPosition(1000, 1000);  // otherwise position is off screen
			}
		}
		if (eastGuard.fire == true)  // east guard can fire when this is true
		{
			for (int i = 0; i < FIREBALL_ARRAY_SIZE; i++)
			{
				if (eastGuardFireArray[i].fireballTwo.getPosition().x == 1000)
				{
					eastGuardFireArray[i].fireballTwo.setPosition(eastGuard.guard.getPosition());  // sets the position to the south guards current position
					break;
				}
			}
		}

		for (int i = 0; i < MAX_TRUCKS; i++)
		{
			if (vectorLength(enemyOne[i].body.getPosition() - player.playerBody.getPosition()) < 50)  // Gets the length between the player and enemy
			{

				if (enemyOne[i].moveLeft == false && enemyOne[i].body.getPosition().x < player.playerBody.getPosition().x)
				{
					enemyOne[i].moveLeft = true;  // switches the enemies movement direction upon collision
					player.playerBody.setPosition(player.playerBody.getPosition().x - 40, player.playerBody.getPosition().y);  // recoil on collision for the player
					enemyOne[i].body.setPosition(enemyOne[i].body.getPosition().x + 40, enemyOne[i].body.getPosition().y);  // recoil for the enemy on collision
					if (player.score < 1000)
					{
						player.health -= 5;  // at the beginning this enemy will deal a small amount of damage
					}
					else
					{
						player.health -= 10;  // after the player scores 1000 points the damage is doubled
					}

				}
				else if (enemyOne[i].moveLeft == true && enemyOne[i].body.getPosition().x > player.playerBody.getPosition().x)
				{
					enemyOne[i].moveLeft = false;  // switches the enemies movement direction upon collision
					player.playerBody.setPosition(player.playerBody.getPosition().x + 40, player.playerBody.getPosition().y);  // recoil for the player on collision
					enemyOne[i].body.setPosition(enemyOne[i].body.getPosition().x - 40, enemyOne[i].body.getPosition().y);  // recoil for the enemy on collision
					if (player.score < 1000)
					{
						player.health -= 5;  // at the beginning this enemy will deal a small amount of damage
					}
					else
					{
						player.health -= 10;  // after the player scores 1000 points the damage is doubled
					}
				}
			}

		}
		if (enemyFollow.body.getGlobalBounds().intersects(player.playerBody.getGlobalBounds()))  // collision between the player and the enemy following
		{
			if (enemyFollow.body.getPosition().x < player.playerBody.getPosition().x)
			{
				enemyFollow.body.setPosition(enemyFollow.body.getPosition().x - 20, enemyFollow.body.getPosition().y);// recoil for the enemy on collision

				if (player.playerBody.getPosition().x <= 539)
				{
					player.playerBody.setPosition(player.playerBody.getPosition().x + 20, player.playerBody.getPosition().y);// recoil for the player on collision
				}

			}
			else if (enemyFollow.body.getPosition().x > player.playerBody.getPosition().x)
			{

				enemyFollow.body.setPosition(enemyFollow.body.getPosition().x + 20, enemyFollow.body.getPosition().y);// recoil for the enemy on collision
				if (player.playerBody.getPosition().x >= 20)
				{
					player.playerBody.setPosition(player.playerBody.getPosition().x - 20, player.playerBody.getPosition().y);// recoil for the player on collision
				}
			}

			if (enemyFollow.body.getPosition().y < player.playerBody.getPosition().y)
			{
				enemyFollow.body.setPosition(enemyFollow.body.getPosition().x,enemyFollow.body.getPosition().y - 20);// recoil for the enemy on collision

				if (player.playerBody.getPosition().y <= 480)
				{
					player.playerBody.setPosition(player.playerBody.getPosition().x, player.playerBody.getPosition().y + 20);// recoil for the player on collision
				}

			}
			else if (enemyFollow.body.getPosition().y > player.playerBody.getPosition().y)
			{

				enemyFollow.body.setPosition(enemyFollow.body.getPosition().x, enemyFollow.body.getPosition().y + 20);// recoil for the enemy on collision
				if (player.playerBody.getPosition().y >= 32)
				{
					player.playerBody.setPosition(player.playerBody.getPosition().x, player.playerBody.getPosition().y - 20);// recoil for the player on collision
				}
			}
		}

		if (enemyFollowTwo.body.getGlobalBounds().intersects(player.playerBody.getGlobalBounds()))  // collision between the player and the enemy following
		{
			if (enemyFollowTwo.body.getPosition().x < player.playerBody.getPosition().x)
			{
				enemyFollowTwo.body.setPosition(enemyFollowTwo.body.getPosition().x - 20, enemyFollowTwo.body.getPosition().y);  // recoil for the enemy on collision

				if (player.playerBody.getPosition().x <= 539)
				{
					player.playerBody.setPosition(player.playerBody.getPosition().x + 20, player.playerBody.getPosition().y);  // recoil for the player on collision
				}
			}
			else if (enemyFollowTwo.body.getPosition().x > player.playerBody.getPosition().x)
			{
				enemyFollowTwo.body.setPosition(enemyFollowTwo.body.getPosition().x + 20, enemyFollowTwo.body.getPosition().y);  // recoil for the enemy on collision

				if (player.playerBody.getPosition().x >= 20)
				{
					player.playerBody.setPosition(player.playerBody.getPosition().x - 20, player.playerBody.getPosition().y);  // recoil for the player on collision
				}
			}
			if (enemyFollowTwo.body.getPosition().y < player.playerBody.getPosition().y)
			{
				enemyFollowTwo.body.setPosition(enemyFollowTwo.body.getPosition().x, enemyFollowTwo.body.getPosition().y - 20);  // recoil for the enemy on collision

				if (player.playerBody.getPosition().y <= 480)
				{
					player.playerBody.setPosition(player.playerBody.getPosition().x, player.playerBody.getPosition().y + 20);  // recoil for the player on collision
				}

			}
			else if (enemyFollowTwo.body.getPosition().y > player.playerBody.getPosition().y)
			{

				enemyFollowTwo.body.setPosition(enemyFollowTwo.body.getPosition().x, enemyFollowTwo.body.getPosition().y + 20);  // recoil for the enemy on collision
				if (player.playerBody.getPosition().y >= 32)
				{
					player.playerBody.setPosition(player.playerBody.getPosition().x, player.playerBody.getPosition().y - 20);  // recoil for the player on collision
				}
			}

		}

		for (int i = 0; i < FIREBALL_ARRAY_SIZE; i++)
		{  // when the bullet is at the player
			if (fireballArray[i].fireball.getPosition().y - player.playerBody.getPosition().y < 80 && fireballArray[i].fireball.getPosition().y - player.playerBody.getPosition().y > -80
				&& fireballArray[i].fireball.getPosition().x - player.playerBody.getPosition().x < 80 && fireballArray[i].fireball.getPosition().x - player.playerBody.getPosition().x > -80)
			{
				fireballArray[i].move();  // moves the players fireball
				if (fireballArray[i].velocity.x == 0 && fireballArray[i].velocity.y == 0)
				{
					fireballArray[i].fireball.setPosition(1000, 1000);  // sets the players bullet off screen when not moving
				}
			}
			else
			{
				fireballArray[i].fireball.setPosition(1000, 1000);  // sets players bullets off screen when not in use
			}
		}

		if (fireballArray[FIREBALL_ARRAY_SIZE].readyFire == true)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))  // fires the players bullet when the space bar is pressed
			{
				for (int i = 0; i < FIREBALL_ARRAY_SIZE; i++)
				{

					if (fireballArray[i].fireball.getPosition().y == 1000)
					{
						fireballArray[i].fireball.setPosition(player.playerBody.getPosition());  // sets the bullet to the players position
						fireballArray[i].velocity = player.lookDirection; // Sets the bullet velocity to the same speed as the player
						fireballArray[i].velocity.x *= 2; // Sets the bullet velocity to twice the speed of the player
						fireballArray[i].velocity.y *= 2; // Sets the bullet velocity to twice the speed of the player

						fireballArray[FIREBALL_ARRAY_SIZE].fireballWait = 10;  // time before bullets can be fired
						fireballArray[FIREBALL_ARRAY_SIZE].readyFire = false; // bullet is not ready to fire
						break;  // breaks 
					}
				}
			}
		}
		else
		{
			fireballArray[FIREBALL_ARRAY_SIZE].fireballWait++; //increments wait time
			if (fireballArray[FIREBALL_ARRAY_SIZE].fireballWait == 20) // when it reaches twenty
			{
				fireballArray[FIREBALL_ARRAY_SIZE].fireballWait = 0;  // resets to zero
				fireballArray[FIREBALL_ARRAY_SIZE].readyFire = true; // player can fire
			}
		}

		for (int i = 0; i < MAX_TRUCKS; i++)
		{
			for (int j = 0; j < FIREBALL_ARRAY_SIZE; j++)
			{
				if (enemyOne[i].body.getGlobalBounds().intersects(fireballArray[j].fireball.getGlobalBounds()))  // if the players bullet collides with the enemy
				{
					int randomNumTwo = rand() % 200 + 200;  // random number between 200 and 399
					fireballArray[j].fireball.setPosition(1000, 1000); // sets position of this fire3ball off screen
					fireballArray[i].velocity.x = 0; // Sets the bullet velocity to twice the speed of the player
					fireballArray[i].velocity.y = 0;
					enemyOne[i].health -= 10;  // enemy loses 10 hity points

					if (enemyOne[i].health == 0)  // if enemy loses all their health
					{
						player.score += 20;  // player gets 20 points
						enemyOne[i].health = 50; // enemy health is reset
						enemyOne[i].body.setPosition(-400, randomNumTwo); // enemy respawns
					}
				}
				if (enemyFollow.body.getGlobalBounds().intersects(fireballArray[j].fireball.getGlobalBounds()))// if the players bullet collides with the enemy
				{
					int randomNum = rand() % 700 + 1;// random number between 1 and 700
					int randomNumtwo = rand() % 500 + 1;// random number between 1 and 500
					int randomNumThree = rand() % 2 + 1;// random number between 1 and 2
					fireballArray[j].fireball.setPosition(1000, 1000); // sets position off screen
					fireballArray[i].velocity.x = 0; // Sets the bullet velocity to twice the speed of the player
					fireballArray[i].velocity.y = 0;
					enemyFollow.health -= 10;  // enemy loses 10 hit points

					if (enemyFollow.health == 0)  // if enemy loses all their health
					{
						player.score += 10;  // player gets 10 points

						if (randomNumThree == 1) // if this random number is 1
						{
							enemyFollow.body.setPosition(randomNum, -75); // respawns to the left of the screen
						}
						else if (randomNumThree == 2) // if this random number is 2
						{
							enemyFollow.body.setPosition(-75, randomNumtwo);  // respawns to the top of the screen
						}
						enemyFollow.health = 30;  // enemy health is reset to 30
					}
				}
				if (enemyFollowTwo.body.getGlobalBounds().intersects(fireballArray[j].fireball.getGlobalBounds()))
				{
					int randomNum = rand() % 700 + 1;// random number between 1 and 700
					int randomNumtwo = rand() % 500 + 1;// random number between 1 and 500
					int randomNumThree = rand() % 2 + 1;// random number between 1 and 2
					fireballArray[j].fireball.setPosition(1000, 1000); // sets position off screen
					fireballArray[i].velocity.x = 0; // Sets the bullet velocity to twice the speed of the player
					fireballArray[i].velocity.y = 0;
					enemyFollowTwo.health -= 10;  // enemy loses 10 hit points

					if (enemyFollowTwo.health == 0)  // if enemy loses all their health
					{
						player.score += 10;  // player gets 10 points

						if (randomNumThree == 1) // if this random number is 1
						{
							enemyFollowTwo.body.setPosition(randomNum, -75); // respawns to the left of the screen
						}
						else if (randomNumThree == 2) // if this random number is 2
						{
							enemyFollowTwo.body.setPosition(-75, randomNumtwo);  // respawns to the top of the screen
						}
						enemyFollowTwo.health = 30;  // enemy health is reset to 30
					}
				}
				if (palmTreeOne.palmTree.getGlobalBounds().intersects(fireballArray[j].fireball.getGlobalBounds())) // when bullet collides with first palm tree
				{
					int randomNum = rand() % 400 + 100; // generates a number between 100 and 499
					fireballArray[j].fireball.setPosition(1000, 1000); // sets position of player bullet off screen
					fireballArray[i].velocity.x = 0; // Sets the bullet velocity to twice the speed of the player
					fireballArray[i].velocity.y = 0;
					palmTreeOne.health -= 10; // palm tree loses 10 hit points
					player.score += 10; // player gains 10 points
					if (palmTreeOne.health == 0)  // if palm tree loses all health
					{
						palmTreeOne.palmTree.setPosition(randomNum, -200);  // palm tree is set off screen
						palmTreeOne.treeAlive = false;  // tree is dead
					}
				}
				if (palmTreeTwo.palmTree.getGlobalBounds().intersects(fireballArray[j].fireball.getGlobalBounds()))
				{
					int randomNum = rand() % 400 + 100; // generates a number between 100 and 499
					fireballArray[j].fireball.setPosition(1000, 1000); // sets position of player bullet off screen
					fireballArray[i].velocity.x = 0; // Sets the bullet velocity to twice the speed of the player
					fireballArray[i].velocity.y = 0;
					palmTreeTwo.health -= 10; // palm tree loses 10 hit points
					player.score += 10; // player gains 10 points
					if (palmTreeTwo.health == 0)  // if palm tree loses all health
					{
						palmTreeTwo.palmTree.setPosition(randomNum, -200);  // palm tree is set off screen
						palmTreeTwo.treeAlive = false;  // tree is dead
					}
				}
				if (palmTreeThree.palmTree.getGlobalBounds().intersects(fireballArray[j].fireball.getGlobalBounds()))
				{
					int randomNum = rand() % 400 + 100; // generates a number between 100 and 499
					fireballArray[j].fireball.setPosition(1000, 1000); // sets position of player bullet off screen
					fireballArray[i].velocity.x = 0; // Sets the bullet velocity to twice the speed of the player
					fireballArray[i].velocity.y = 0;
					palmTreeThree.health -= 10; // palm tree loses 10 hit points
					player.score += 10; // player gains 10 points
					if (palmTreeThree.health == 0)  // if palm tree loses all health
					{
						palmTreeThree.palmTree.setPosition(randomNum, -200);  // palm tree is set off screen
						palmTreeThree.treeAlive = false;  // tree is dead
					}
				}
				if (palmTreeFour.palmTree.getGlobalBounds().intersects(fireballArray[j].fireball.getGlobalBounds()))
				{
					int randomNum = rand() % 400 + 100; // generates a number between 100 and 499
					fireballArray[j].fireball.setPosition(1000, 1000); // sets position of player bullet off screen
					fireballArray[i].velocity.x = 0; // Sets the bullet velocity to twice the speed of the player
					fireballArray[i].velocity.y = 0;
					palmTreeFour.health -= 10; // palm tree loses 10 hit points
					player.score += 10; // player gains 10 points
					if (palmTreeFour.health == 0)  // if palm tree loses all health
					{
						palmTreeFour.palmTree.setPosition(randomNum, -200);  // palm tree is set off screen
						palmTreeFour.treeAlive = false;  // tree is dead
					}
				}
				if (treeOne.matureTree.getGlobalBounds().intersects(southGuardFireArray[j].fireballTwo.getGlobalBounds()) && treeOne.grown == true)
				{  // if southguard hits this tree grown by player
					southGuardFireArray[j].fireballTwo.setPosition(1000, 1000);  // enemy bullet is set off screen
					treeOne.matureTreeHealth -= 20; // tree loses health
				}
				if (treeTwo.matureTree.getGlobalBounds().intersects(southGuardFireArray[j].fireballTwo.getGlobalBounds()) && treeTwo.grown == true)
				{  // if southguard hits this tree grown by player
					southGuardFireArray[j].fireballTwo.setPosition(1000, 1000);  // enemy bullet is set off screen
					treeTwo.matureTreeHealth -= 20; // tree loses health
				}
				if (treeThree.matureTree.getGlobalBounds().intersects(southGuardFireArray[j].fireballTwo.getGlobalBounds()) && treeThree.grown == true)
				{  // if southguard hits this tree grown by player
					southGuardFireArray[j].fireballTwo.setPosition(1000, 1000);  // enemy bullet is set off screen
					treeThree.matureTreeHealth -= 20; // tree loses health
				}
				if (treeFour.matureTree.getGlobalBounds().intersects(southGuardFireArray[j].fireballTwo.getGlobalBounds()) && treeFour.grown == true)
				{  // if southguard hits this tree grown by player
					southGuardFireArray[j].fireballTwo.setPosition(1000, 1000);  // enemy bullet is set off screen
					treeFour.matureTreeHealth -= 20; // tree loses health
				}
				if (player.playerBody.getGlobalBounds().intersects(southGuardFireArray[j].fireballTwo.getGlobalBounds()))
				{  // if southguard hits player
					southGuardFireArray[j].fireballTwo.setPosition(1000, 1000);  // enemy bullet is set off screen
					player.health -= 4; // player loses health
				}
				if (treeOne.matureTree.getGlobalBounds().intersects(eastGuardFireArray[j].fireballTwo.getGlobalBounds()) && treeOne.grown == true)
				{  // if eastguard hits this tree grown by player
					eastGuardFireArray[j].fireballTwo.setPosition(1000, 1000);   // enemy bullet is set off screen
					treeOne.matureTreeHealth -= 20; // tree loses health
				}
				if (treeTwo.matureTree.getGlobalBounds().intersects(eastGuardFireArray[j].fireballTwo.getGlobalBounds()) && treeTwo.grown == true)
				{  // if eastguard hits this tree grown by player
					eastGuardFireArray[j].fireballTwo.setPosition(1000, 1000);   // enemy bullet is set off screen
					treeTwo.matureTreeHealth -= 20; // tree loses health
				}
				if (treeThree.matureTree.getGlobalBounds().intersects(eastGuardFireArray[j].fireballTwo.getGlobalBounds()) && treeThree.grown == true)
				{  // if eastguard hits this tree grown by player
					eastGuardFireArray[j].fireballTwo.setPosition(1000, 1000);  // enemy bullet is set off screen
					treeThree.matureTreeHealth -= 20; // tree loses health
				}
				if (treeFour.matureTree.getGlobalBounds().intersects(eastGuardFireArray[j].fireballTwo.getGlobalBounds()) && treeFour.grown == true)
				{  // if eastguard hits this tree grown by player
					eastGuardFireArray[j].fireballTwo.setPosition(1000, 1000);  // enemy bullet is set off screen
					treeFour.matureTreeHealth -= 20; // tree loses health
				}
				if (player.playerBody.getGlobalBounds().intersects(eastGuardFireArray[j].fireballTwo.getGlobalBounds()))
				{  // if eastguard hits player
					eastGuardFireArray[j].fireballTwo.setPosition(1000, 1000);  // enemy bullet is set off screen
					player.health -= 4; // player loses health
				}

			}
		}
		if (player.waitToFireCounter > 0)
		{
			player.waitToFireCounter--;  // player wait to fire counter decrements when more than zero
		}
	}
}

void Game::draw()
// This function draws the game world
{
	// Clear the screen and draw your game sprites
	window.clear();
	
	if (gameOver == false && gameStarted == true)  // will draw these objects when the game is playing
	{

		window.draw(backGround); // Draws the back ground

		m_message.setString(std::to_string(player.health));
		m_message.setFillColor(sf::Color::White);
		m_message.setPosition(player.playerBody.getPosition().x - 16, player.playerBody.getPosition().y - 64);
		window.draw(m_message);  // write message to the screen

		m_message.setString(std::to_string(palmTreeOne.health));
		m_message.setFillColor(sf::Color::Blue);
		m_message.setPosition(palmTreeOne.palmTree.getPosition().x + 16, palmTreeOne.palmTree.getPosition().y - 32);
		window.draw(m_message);  // draws the health of the first palm tree

		m_message.setString(std::to_string(palmTreeTwo.health));
		m_message.setFillColor(sf::Color::Blue);
		m_message.setPosition(palmTreeTwo.palmTree.getPosition().x + 16, palmTreeTwo.palmTree.getPosition().y - 32);
		window.draw(m_message);  // draws the health of the second palm tree

		m_message.setString(std::to_string(palmTreeThree.health));
		m_message.setFillColor(sf::Color::Blue);
		m_message.setPosition(palmTreeThree.palmTree.getPosition().x + 16, palmTreeThree.palmTree.getPosition().y - 32);
		window.draw(m_message);  // draws the health of the third palm tree

		m_message.setString(std::to_string(palmTreeFour.health));
		m_message.setFillColor(sf::Color::Blue);
		m_message.setPosition(palmTreeFour.palmTree.getPosition().x + 16, palmTreeFour.palmTree.getPosition().y - 32);
		window.draw(m_message);  // draws the health of the fourth palm tree

		m_message.setString(std::to_string(enemyFollow.health));
		m_message.setFillColor(sf::Color::Red);
		m_message.setPosition(enemyFollow.body.getPosition().x + 16, enemyFollow.body.getPosition().y - 32);
		window.draw(m_message);  // draws the first following enemies health

		m_message.setString(std::to_string(enemyFollowTwo.health));
		m_message.setFillColor(sf::Color::Red);
		m_message.setPosition(enemyFollowTwo.body.getPosition().x + 16, enemyFollowTwo.body.getPosition().y - 32);
		window.draw(m_message);  // draws the second following enemies health

		if (moundOne.planted == true)
		{  // Draws the first sapling and its growing progressn from 0 to 100
			m_message.setString(std::to_string(moundOne.growing / 12));
			m_message.setFillColor(sf::Color::Blue);
			m_message.setPosition(saplingOne.sapling.getPosition().x + 16, saplingOne.sapling.getPosition().y - 32);
			window.draw(m_message);
			saplingOne.sapling.setPosition(moundOne.mound.getPosition().x + 20, moundOne.mound.getPosition().y - 18);
			window.draw(saplingOne.sapling);
		}
		if (moundTwo.planted == true)
		{  // Draws the second sapling and its growing progressn from 0 to 100
			m_message.setString(std::to_string(moundTwo.growing / 12));
			m_message.setFillColor(sf::Color::Blue);
			m_message.setPosition(saplingTwo.sapling.getPosition().x + 16, saplingTwo.sapling.getPosition().y - 32);
			window.draw(m_message);
			saplingTwo.sapling.setPosition(moundTwo.mound.getPosition().x + 20, moundTwo.mound.getPosition().y - 18);
			window.draw(saplingTwo.sapling);
		}
		if (moundThree.planted == true)
		{  // Draws the third sapling and its growing progressn from 0 to 100
			m_message.setString(std::to_string(moundThree.growing / 12));
			m_message.setFillColor(sf::Color::Blue);
			m_message.setPosition(saplingThree.sapling.getPosition().x + 16, saplingThree.sapling.getPosition().y - 32);
			window.draw(m_message);
			saplingThree.sapling.setPosition(moundThree.mound.getPosition().x + 20, moundThree.mound.getPosition().y - 18);
			window.draw(saplingThree.sapling);
		}
		if (moundFour.planted == true)
		{  // Draws the fourth sapling and its growing progressn from 0 to 100
			m_message.setString(std::to_string(moundFour.growing / 12));
			m_message.setFillColor(sf::Color::Blue);
			m_message.setPosition(saplingFour.sapling.getPosition().x + 16, saplingFour.sapling.getPosition().y - 32);
			window.draw(m_message);
			saplingFour.sapling.setPosition(moundFour.mound.getPosition().x + 20, moundFour.mound.getPosition().y - 18);
			window.draw(saplingFour.sapling);
		}

		window.draw(enemyFollow.body);  // draws the first enemy that will follow the player
		window.draw(enemyFollowTwo.body);  // draws the second enemy that will follow the player

		for (int i = 0; i < MAX_TRUCKS; i++)
		{  // draws health for enemies that move left to right
			m_message.setString(std::to_string(enemyOne[i].health));
			m_message.setFillColor(sf::Color::Red);
			m_message.setPosition(enemyOne[i].body.getPosition().x, enemyOne[i].body.getPosition().y - 60);
			window.draw(m_message);
		}

		if (treeOne.grown == true)
		{  // draws the first mature tree and its health when grown
			m_message.setString(std::to_string(treeOne.matureTreeHealth));
			m_message.setFillColor(sf::Color::White);
			treeOne.matureTree.setPosition(moundOne.mound.getPosition().x + 45, moundOne.mound.getPosition().y - 25);
			m_message.setPosition(treeOne.matureTree.getPosition().x - 20, treeOne.matureTree.getPosition().y - 80);
			window.draw(m_message);
			window.draw(treeOne.matureTree);
		}
		if (treeThree.grown == true)
		{  // draws the third mature tree and its health when grown
			m_message.setString(std::to_string(treeThree.matureTreeHealth));
			m_message.setFillColor(sf::Color::White);
			treeThree.matureTree.setPosition(moundThree.mound.getPosition().x + 45, moundThree.mound.getPosition().y - 25);
			m_message.setPosition(treeThree.matureTree.getPosition().x - 20, treeThree.matureTree.getPosition().y - 80);
			window.draw(m_message);
			window.draw(treeThree.matureTree);
		}
		window.draw(palmTreeOne.palmTree);  // draws the first palm tree
		window.draw(palmTreeThree.palmTree);  // draws the third palm tree
		window.draw(moundOne.mound);  // draws the first mound
		window.draw(moundThree.mound);  // draws the third mound

		for (int i = 0; i < MAX_TRUCKS; i++)
		{
			window.draw(enemyOne[i].body);  // draws the enemy array of enemies moving left to right
		}
		if (treeTwo.grown == true)
		{  // draws the second mature tree and its health when grown
			m_message.setString(std::to_string(treeTwo.matureTreeHealth));
			m_message.setFillColor(sf::Color::White);
			treeTwo.matureTree.setPosition(moundTwo.mound.getPosition().x + 45, moundTwo.mound.getPosition().y - 25);
			m_message.setPosition(treeTwo.matureTree.getPosition().x - 20, treeTwo.matureTree.getPosition().y - 80);
			window.draw(m_message);
			window.draw(treeTwo.matureTree);
		}
		if (treeFour.grown == true)
		{  // draws the fourth mature tree and its health when grown
			m_message.setString(std::to_string(treeFour.matureTreeHealth));
			m_message.setFillColor(sf::Color::White);
			treeFour.matureTree.setPosition(moundFour.mound.getPosition().x + 45, moundFour.mound.getPosition().y - 25);
			m_message.setPosition(treeFour.matureTree.getPosition().x - 20, treeFour.matureTree.getPosition().y - 80);
			window.draw(m_message);
			window.draw(treeFour.matureTree);
		}

		window.draw(palmTreeTwo.palmTree);  // draws the second palm tree
		window.draw(palmTreeFour.palmTree);  // draws the fourth palm tree
		window.draw(moundTwo.mound);  // draws the second mound
		window.draw(moundFour.mound);  // draws the fourth mound
		window.draw(player.playerBody);  // draws player

		for (int i = 0; i < FIREBALL_ARRAY_SIZE; i++)
		{
			window.draw(fireballArray[i].fireball);  // draws players bullet
		}

		for (int i = 0; i < FIREBALL_ARRAY_SIZE; i++)
		{
			window.draw(southGuardFireArray[i].fireballTwo);  // draws soputh guards bullet
		}
		for (int i = 0; i < FIREBALL_ARRAY_SIZE; i++)
		{
			window.draw(eastGuardFireArray[i].fireballTwo);  // draws east guards bullet
		}

		window.draw(southGuard.guard);  // draws south guard
		window.draw(eastGuard.guard);  // draws east guard

		m_message.setString("Score : " + std::to_string(player.score));  // displays score
		m_message.setFillColor(sf::Color::White);
		m_message.setPosition(10, 560);
		window.draw(m_message);  // write message to the screen
	}
	if (gameStarted == false && gameOver == false)
	{//Displays main menu
		window.draw(menu);
		m_message.setString("Press 1 and enter to start \n\n\n\n Press 2 and enter for help \n\n\n\n Press 3 and enter to exit");
		m_message.setFillColor(sf::Color::White);
		m_message.setOutlineColor(sf::Color::Black);
		m_message.setOutlineThickness(4);
		m_message.setPosition(30, 150);
		window.draw(m_message);
	}
	if (gameHelp == true && gameOver == false)
	{//displays information on the help page
		window.clear(sf::Color::Green);
		m_message.setString(" You must destroy the palm trees using \nyour lighter by pressing the 'space' key.\n\n Once the palm tree has disappeared \nyou can plant a new tree in the mound by pressing the 'E' key.\n\n You can also set enemies on fire \nwith your lighter using the 'space' key.\n\n Use the 'arrow' keys to move 'up', 'down', \n'left' and 'right' in order to avoid enemies and navigate the map.\n\n The goal of the game is to earn a high score \n by burning palm trees and machinary and planting new trees \nwhile avoiding enemy fire and the enemies pursuing you\n\n The more points you earn the quicker the enemies will move so be careful.\n\n Press '1' to exit to menu");
		m_message.setFillColor(sf::Color::White);
		m_message.setOutlineColor(sf::Color::Black);
		m_message.setOutlineThickness(3);
		m_message.setPosition(30, 30);
		window.draw(m_message);
	}
	if (gameOver == true)
	{// displays score when game ends
		window.clear(sf::Color::Red);
		m_message.setString("Game Over \n\n Score : " + std::to_string(player.score) + "\n\n Press 1 to restart" + "\n\n Press 2 to exit game");
		m_message.setFillColor(sf::Color::White);
		m_message.setOutlineColor(sf::Color::Black);
		m_message.setOutlineThickness(4);
		m_message.setPosition(300, 200);
		window.draw(m_message);
	}
	window.display();
}

