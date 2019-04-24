#pragma once
#include<iostream>
#include <SFML/Graphics.hpp>
using namespace sf;

using namespace std;
struct shipPosition
{
	float shipx;
	float shipy;
};


class Ship
{
private:
	Texture shipTexture;
	Sprite ship;
	Vector2f position;

public:
	void readfile()
	{
		if (!shipTexture.loadFromFile("ship.png"))
		{
			cout << "Unable to load ship texture!" << endl;
			exit(EXIT_FAILURE);
		}
		ship.setTexture(shipTexture);

	}
	void setPos(float x, float y)
	{
		
		ship.setPosition(x,y);
	}
	Vector2f getShipPosition()
	{
		return position;
	}
	void draw(RenderWindow& window)
	{

		window.draw(ship);
	}
	void moveShip()
	{
		const float DISTANCE = 5.0;

		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			// left arrow is pressed: move our ship left 5 pixels
			// 2nd parm is y direction. We don't want to move up/down, so it's zero.
			if(ship.getPosition().x>0)
			ship.move(-DISTANCE, 0);
		}
		else if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			if (ship.getPosition().x +130<= 850)
				ship.move(DISTANCE, 0);
		}
	}
	Sprite getShipsSprite()
	{
		return ship;
	}

};