#pragma once
#include<iostream>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;
class startButtun
{
private:
	Sprite button;
	Texture buttonTexture;
	Vector2f position;
	bool isClicked;
public:
	
	void readfile()
	{
		if (!buttonTexture.loadFromFile("player_play.png"))
		{
			cout << "Unable to load ship texture!" << endl;
			exit(EXIT_FAILURE);
		}
		button.setTexture(buttonTexture);
	}

	void setPos(Vector2f pos)
	{
		position = pos;
		button.setPosition(position.x, position.y);
	}

	void draw(RenderWindow& window)
	{
		window.draw(button);
	}
	bool getIsClicked()
	{
		return isClicked;
	}
	void setIsClicked(bool stat)
	{
		isClicked = stat;
	}
	void clear(RenderWindow& window)
	{
		window.clear();
	}
	bool IsStartClicked(Vector2f mouse)
	{
		if (button.getGlobalBounds().contains(mouse))
		{
			setIsClicked(true);
			return true;
		}
		else
		{
			setIsClicked(false);
			return false;
		}

	}
	Sprite getStartSprite()
	{
		return button;
	}
};