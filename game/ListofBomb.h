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
	
	//This function adds the bombs to the list
	void addtoBombList( Bomb bomb)
	{	
		
		bombs.push_back(bomb);

	}
	

};