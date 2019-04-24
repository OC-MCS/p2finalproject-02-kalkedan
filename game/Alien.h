#pragma once
#include<iostream>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;

class Alien
{
private:
	Sprite alien;
	//Texture alienTexture;
	//Vector2f position;
public:
	Alien()
	{

	}
	Alien(Texture &tex, Vector2f pos)
	{
		alien.setPosition(pos);
		alien.setTexture(tex);

	}
	
	
	void draw(RenderWindow& window)
	{
		
		window.draw(alien);
	}
	
	void moveAlien(int speed)
	{
		if(alien.getPosition().y<1600)
		alien.move(0, speed);
	}
	Sprite getAliensSprite()
	{
		return alien;
	}
	
};
