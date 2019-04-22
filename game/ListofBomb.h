#pragma once
#include<iostream>
using namespace std;
#include"Bomb.h"
#include<list>
#include"Alien.h"
#include <SFML/Graphics.hpp>
#include"Bomb.h"
using namespace sf;
class ListofBomb  
{
private:
	list<Bomb> bombs;
	Texture bombTexture;
public:
	ListofBomb()
	{
		if (!bombTexture.loadFromFile("fire.png"))
		{
			cout << "Unable to load ship texture!" << endl;
			exit(EXIT_FAILURE);
		}

	}

	void drawList(RenderWindow& win)
	{

		list<Bomb>::iterator iter;
		(*iter).draw(win);
	}
	void addtoBombList( Bomb bomb)
	{	
		
		bombs.push_back(bomb);

	}
	




	void move(int speed)
	{
		//const float DISTANCE = 5.0;
		list<Bomb>::iterator iter;

		for (iter = bombs.begin(); iter != bombs.end(); iter++)
		{
			(*iter).moveBomb(speed);

		}
	}

};