#pragma once
#include<iostream>
#include"Alien.h"
using namespace std;

#include <SFML/Graphics.hpp>
using namespace sf;

class Bomb
{
private:
	Sprite bomb;
	


public:
	

Bomb(Texture &tex, Vector2f pos)

	{
		bomb.setTexture(tex);		
		bomb.setPosition(pos);

	}
	// This function draw the bomb
	void draw(RenderWindow& window)
	{

		window.draw(bomb);
	}
	// This function moves the bomb
	void moveBomb(int speed)
	{
		if (bomb.getPosition().y < 1600)
		{
			bomb.move(0, speed);
		}
	}
	Sprite getBombSprite()
	{
		return bomb;
	}
	// This function checks if the bomb hits the missile;
	//paramter: ship we pass the ship as paramter to check the global bound
	//return bool
	bool isgetHit(Ship ship)
	{
		FloatRect shipBounds = ship.getShipsSprite().getGlobalBounds();
		FloatRect bombBounds = bomb.getGlobalBounds();

		bool status = false;
		if (shipBounds.intersects(bombBounds))
		{
			status = true;
			
		}
		return status;
	}

};