#pragma once
#include<iostream>
using namespace std;
class Player
{
private:
	int score = 0;
	int lifeLost = 3;
	Font lifeLostdis;
	Font Scoredis;
	int level = 1;
	
public:
	//This function increament the score;

	void Scoreincreament()
	{
		score = score + 1;
	}
	//This function decrease the number of life
	void lifedecresing()
	{
		if (lifeLost > 0)
			lifeLost= lifeLost-1;
	}
	
	int getLIfe()
	{
		return lifeLost;
	} 
	void setLisfe(int life)
	{
		lifeLost = life;
	}
	int getLevel()
	{
		return level;
	}
	
	void setLevel( int l)
	{
		level=l;
	}
	//This function darws a text
	void Textdraw(RenderWindow &win)
	{
		
		if (!lifeLostdis.loadFromFile("C:\\windows\\Fonts\\arial.ttf"))
		{
			//	die ("couldn't load font");
		}
	
		Text title1("Life Lost", lifeLostdis, 50);
		title1.setPosition(5, 6);

		win.draw(title1);
		if (!Scoredis.loadFromFile("C:\\windows\\Fonts\\arial.ttf"))
		{
			//	die ("couldn't load font");
		}
		
		Text Scoredis("Score",  Scoredis, 50);
		Scoredis.setPosition(300, 6);
		win.draw(Scoredis);

	}

	
};