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
	

	//bombPosition pos=alien1.getposition();
public:
	Bomb()
	{

	}

	
	Bomb(Texture &tex, Vector2f pos)

	{
		bomb.setTexture(tex);		
		bomb.setPosition(pos);

	}
	
	void draw(RenderWindow& window)
	{

		window.draw(bomb);
	}
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