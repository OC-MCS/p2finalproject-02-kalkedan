#pragma once
#include <iostream>
using namespace std;
#include"ship.h";
#include"Alien.h"
#include <SFML/Graphics.hpp>
using namespace sf;

class Missile
{
private:  
	int ID;
	Sprite missile;
	Texture missleTeXture;
	Vector2f position;

public:

	Missile(Texture &tex, Vector2f pos, int  id)
	{
		missile.setTexture(tex);
		missile.setPosition(pos);
		ID = id;
	}
	
	

	// This function draw the missile
	void draw(RenderWindow& window)
	{

		window.draw(missile);
	}
	
	//This function move the missile
	void moveMissile()
	{
		if (missile.getPosition().y > 0)
		{
			missile.move(0, -20);
		}
	
	}
	// This function set the current position of the missile
	void updateMissile(Vector2f pos)
	{
		missile.setPosition(pos);

	}
//This function get the Id of the missile to update the missile's position

	int getId()
	{
		return ID;
	}
	// This is a getter function that return the sprite
	Sprite getMissileSprite()
	{
		return missile;
	}
	//This function detect if there is any hit between the missile
	//parameter: accept a single alien to check the hit
	//return bool
	bool isgetHit(Alien alien)
	{
		FloatRect missileBounds = missile.getGlobalBounds();
		FloatRect alienBounds = alien.getAliensSprite().getGlobalBounds();

		bool status = false;
		if (alienBounds.intersects(missileBounds))
		{
			status = true;
			
		}
		return status;
	}
};