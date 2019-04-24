//=========================================================
// This is just the starting point for your final project.
// You are expected to modify and add classes/files as needed.
// The code below is the original code for our first graphics
// project (moving the little green ship). 
//========================================================
#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
#include"Missile.h"
#include"ListofAlien.h"
#include"ListofMissile.h"
#include "bomb.h"
#include "ListofBomb.h"
#include"startButton.h"
#include"Player.h"
#include<ctime>
#include<conio.h>
using namespace sf; 

//============================================================
// Kalkedan Ararso
//============================================================

// note: a Sprite represents an image on screen. A sprite knows and remembers its own position
// ship.move(offsetX, offsetY) adds offsetX, offsetY to 
// the current position of the ship. 
// x is horizontal, y is vertical. 
// 0,0 is in the UPPER LEFT of the screen, y increases DOWN the screen
void moveShip(Sprite& ship)
{
	const float DISTANCE = 5.0;

	if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		// left arrow is pressed: move our ship left 5 pixels
		// 2nd parm is y direction. We don't want to move up/down, so it's zero.
		ship.move(-DISTANCE, 0);
	}
	else if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		// right arrow is pressed: move our ship right 5 pixels
		ship.move(DISTANCE, 0);
		
	} 
	
}
void restart()
{
	const int WINDOW_WIDTH = 850;
	const int WINDOW_HEIGHT = 1600;
	srand(0);
	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "aliens!");
	// Limit the framerate to 60 frames per second
	window.setFramerateLimit(180);

	// load textures from file into memory. This doesn't display anything yet.
	// Notice we do this *before* going into animation loop.

	Texture starsTexture;
	if (!starsTexture.loadFromFile("stars.jpg"))
	{
		cout << "Unable to load stars texture!" << endl;
		exit(EXIT_FAILURE);
	}
	Texture missileTexture;
	if (!missileTexture.loadFromFile("missile.png"))
	{
		cout << "Unable to load missile texture!" << endl;
		exit(EXIT_FAILURE);
	}

	Texture bombTexture;
	if (!bombTexture.loadFromFile("fire.png"))
	{
		cout << "Unable to load missile texture!" << endl;
		exit(EXIT_FAILURE);
	}



	// A sprite is a thing we can draw and manipulate on the screen.
	// We have to give it a "texture" to specify what it looks like

	Sprite background;
	background.setTexture(starsTexture);
	// The texture file is 640x480, so scale it up a little to cover 800x600 window
	background.setScale(5, 5);


	// create sprite and texture it
	ListofAliens anAliens;
	ListofMissile aMissiles;
	Alien alien;
	startButtun start;
	Player player;
	Ship ship;
	ship.readfile();

	alien = anAliens.getRandomAlien();
	if (!missileTexture.loadFromFile("missile.png"))
	{
		cout << "Unable to load missile texture!" << endl;
		exit(EXIT_FAILURE);
	}
	Bomb bomb(bombTexture, alien.getAliensSprite().getPosition());
	ListofBomb listBomb;
	start.readfile();
	// initial position of the ship will be approx middle of screen

	ship.setPos(window.getSize().x / 2.0f, window.getSize().y*(8 / 9.0f));
	Missile missile(missileTexture, ship.getShipsSprite().getPosition(), 0);
	start.setPos(ship.getShipsSprite().getPosition());

	int id = 0;
	int count = 0;
	int speedofAlien, speedofBomb;
	bool isPlaying = true;
	int life = 3;
	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		// For now, we just need this so we can click on the window and close it
		Event event;


		while (window.pollEvent(event))
		{

			// "close requested" event: we close the window
			if (event.type == Event::Closed)
				window.close();
			else if (event.type == Event::KeyPressed)
			{
				if (event.key.code == Keyboard::Space)
				{
					Missile temp(missileTexture, ship.getShipsSprite().getPosition(), id);
					missile = temp;
					aMissiles.addtoMissuleList(missile);
					id++;
				}

			}
			else if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				if (start.getIsClicked() == true);
				{
					start.clear(window);
				}
				start.setIsClicked(false);

			}

		}

		//===========================================================
		// Everything from here to the end of the loop is where you put your
		// code to produce ONE frame of the animation. The next iteration of the loop will
		// render the next frame, and so on. All this happens ~ 60 times/second.
		//===========================================================

		// draw background first, so everything that's drawn later 
		// will appear on top of background
		start.draw(window);



		if (start.getIsClicked() == false)
		{

			window.draw(background);


			if (count % 180 == 0 && anAliens.isNullaliens()==false)
			{
				alien = anAliens.getRandomAlien();
				Bomb temp(bombTexture, alien.getAliensSprite().getPosition());
				bomb = temp;
				listBomb.addtoBombList(bomb);
				

			}
			speedofBomb = 10;

			bomb.moveBomb(speedofBomb);

			ship.moveShip();
			anAliens.move();
			missile.moveMissile();
			aMissiles.updateMissuleList(missile);
			anAliens.removeAliens(aMissiles);
			

			if (anAliens.isNullaliens() == true)
			{
				player.setLevel(2);
				speedofAlien = 1;
				speedofBomb = 20;
				restart();

			}
			if (missile.isgetHit(alien) == true)
			{
				player.Scoreincreament();
				window.close();
				restart();
			}

			if (anAliens.getAlien().getAliensSprite().getPosition().y == 1300)
			{
				window.close();
				restart();


			}
			if (bomb.isgetHit(ship) == true)
			{
				life--;
				player.setLisfe(life);

			}
			if (player.getLIfe() == 0)
			{
				
				window.close();
				restart();
			}


			ship.draw(window);
			missile.draw(window);
			player.Textdraw(window);
			anAliens.drawList(window);
			bomb.draw(window);


			// end the current frame; this makes everything that we have 
			// already "drawn" actually show up on the screen
			count++;
		}
		window.display();

		// At this point the frame we have built is now visible on screen.
		// Now control will go back to the top of the animation loop
		// to build the next frame. Since we begin by drawing the
		// background, each frame is rebuilt from scratch.

	} // end body of animation loop



}
int main()
{
	const int WINDOW_WIDTH = 850;
	const int WINDOW_HEIGHT = 1600;
	srand(0);
	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "aliens!");
	// Limit the framerate to 60 frames per second
	window.setFramerateLimit(180);

	// load textures from file into memory. This doesn't display anything yet.
	// Notice we do this *before* going into animation loop.
	
	Texture starsTexture;
	if (!starsTexture.loadFromFile("stars.jpg"))
	{
		cout << "Unable to load stars texture!" << endl;
		exit(EXIT_FAILURE);
	}
	Texture missileTexture;
	if (!missileTexture.loadFromFile("missile.png"))
	{
		cout << "Unable to load missile texture!" << endl;
		exit(EXIT_FAILURE);
	}

	Texture bombTexture;
	if (!bombTexture.loadFromFile("fire.png"))
	{
		cout << "Unable to load missile texture!" << endl;
		exit(EXIT_FAILURE);
	}



	// A sprite is a thing we can draw and manipulate on the screen.
	// We have to give it a "texture" to specify what it looks like

	Sprite background;
	background.setTexture(starsTexture);
	// The texture file is 640x480, so scale it up a little to cover 800x600 window
	background.setScale(5, 5);


	// create sprite and texture it
	ListofAliens anAliens;
	ListofMissile aMissiles;
	Alien alien;
	startButtun start;
	Player player;
	Ship ship;
	ship.readfile();
	
	alien = anAliens.getRandomAlien();
	if (!missileTexture.loadFromFile("missile.png"))
	{
		cout << "Unable to load missile texture!" << endl;
		exit(EXIT_FAILURE);
	}
	Bomb bomb(bombTexture,alien.getAliensSprite().getPosition());
	ListofBomb listBomb;
	start.readfile();
// initial position of the ship will be approx middle of screen
	
	ship.setPos(window.getSize().x / 2.0f, window.getSize().y*(8 / 9.0f));
	Missile missile(missileTexture, ship.getShipsSprite().getPosition(),0);
	start.setPos(ship.getShipsSprite().getPosition());

	int id = 0;
	int count = 0;
	int speedofAlien, speedofBomb;
	bool isPlaying = true;
	int life = 3;
	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		// For now, we just need this so we can click on the window and close it
		Event event;
		

		while (window.pollEvent(event))
		{
			
			// "close requested" event: we close the window
			if (event.type == Event::Closed)
				window.close();
			else if (event.type == Event::KeyPressed)
			{
				if (event.key.code == Keyboard::Space)
				{
					Missile temp(missileTexture, ship.getShipsSprite().getPosition(),id);
						missile = temp;
					aMissiles.addtoMissuleList(missile);
					id++;
				}
				
			}
			else if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				if(start.getIsClicked()==true);
				{
					start.clear(window);
				}
				start.setIsClicked(false);
				
			}
			
		}

		//===========================================================
		// Everything from here to the end of the loop is where you put your
		// code to produce ONE frame of the animation. The next iteration of the loop will
		// render the next frame, and so on. All this happens ~ 60 times/second.
		//===========================================================

		// draw background first, so everything that's drawn later 
		// will appear on top of background
		start.draw(window);
		

		
		if (start.getIsClicked() == false)
		{

			window.draw(background);
			
			
			if (count % 180 == 0)
			{
				if(anAliens.isNullaliens()==false)
				alien = anAliens.getRandomAlien();
				Bomb temp(bombTexture, alien.getAliensSprite().getPosition());
				bomb = temp;
				listBomb.addtoBombList(temp);
				
			}
			ship.moveShip();
			anAliens.move();
			missile.moveMissile();
			aMissiles.updateMissuleList(missile);
			anAliens.removeAliens(aMissiles);
			speedofBomb = 10;
			bomb.moveBomb(speedofBomb);
			if (bomb.isgetHit(ship) == true)
			{
				life--;
				player.setLisfe(life);

			}
			
			if (anAliens.isNullaliens() == true)
			{
				player.setLevel(2);
				speedofAlien = 1;
				speedofBomb = 20;
				window.close();
				restart();

			}
			
			if ( anAliens.getAlien().getAliensSprite().getPosition().y ==1300)
			{
				window.close();
				restart();
			}
			
			if (player.getLIfe() == 0)
			{
				Font game;
				if (!game.loadFromFile("C:\\windows\\Fonts\\arial.ttf"))
				{
					//	die ("couldn't load font");
				}

				sf::Text gameover;
				gameover.setFont(game);
				gameover.setString("Gameover");
				gameover.setOutlineThickness(4);
				gameover.setCharacterSize(250);
				window.draw(gameover);

				window.close();
				restart();
			}
			
			
			
				ship.draw(window);
				missile.draw(window);
				player.Textdraw(window);
				anAliens.drawList(window);
				bomb.draw(window);
			
			
			// end the current frame; this makes everything that we have 
			// already "drawn" actually show up on the screen
			count++;
		}
		window.display();

		// At this point the frame we have built is now visible on screen.
		// Now control will go back to the top of the animation loop
		// to build the next frame. Since we begin by drawing the
		// background, each frame is rebuilt from scratch.

	} // end body of animation loop

	return 0;
}

