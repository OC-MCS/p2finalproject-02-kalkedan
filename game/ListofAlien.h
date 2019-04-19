#pragma once
#include<iostream>
#include<list>
#include"Alien.h"
#include<random>
#include<ctime>
#include"ListofMissile.h"
#include"Missile.h"
#include"Player.h"
#include <SFML/Graphics.hpp>
using namespace sf;

using namespace std;
class ListofAliens
{
private:
	list<Alien>  aliens;
	Texture aleinsTexture;

public:
	ListofAliens()
	{
		if (!aleinsTexture.loadFromFile("brain_alien.png"))
		{
			cout << "Unable to load ship texture!" << endl;
			exit(EXIT_FAILURE);
		}
		Vector2f pos;
		pos.x = 20;
		pos.y = 20;
		for (int i = 0; i <= 9; i++)
		{
			Alien temp(aleinsTexture, pos);
			aliens.push_back(temp);
			pos.x = pos.x + 80;
		}
	}
	//This function draw the list of aliens
	//return none

	void drawList(RenderWindow& win)
	{

		list<Alien>::iterator iter;

		for (iter = aliens.begin(); iter != aliens.end(); iter++)
		{
			(*iter).draw(win);

		}


	}
	// This function move the list of alien 
	void move()
	{

		list<Alien>::iterator iter;

		for (iter = aliens.begin(); iter != aliens.end(); iter++)
		{
			(*iter).moveAlien();

		}
	}
	//This function generate a random number
	int getRandom()
	{

		return (rand() % 10) - 1;

	}

	// This function ramdomize the bomb launching from the lists of alien 
	//return a signle alien

	Alien getRandomAlien()
	{
		int index = getRandom();
		index = index - 1;

		if (index >= 0 && index < aliens.size())
		{
			list<Alien>::iterator it;
			if (aliens.begin() != aliens.end())
			{
				it = aliens.begin();
				advance(it, index);
				return *it;
			}

		}
		else
		{
			list<Alien>::iterator it;
			it = aliens.begin();
			//advance(it, 1);
			return *it;

		}
	}
	bool isNullaliens()
	{
		if (aliens.size() == 0)
			return true;
		else
			return false;
	}
	// This function delete the alien that got hit by the missile
	//paramter: list of missile to go through the list of missiles toe which missile hits the alien;
	//return none
	void removeAliens(ListofMissile missiles)
	{

		list<Alien>::iterator alienIter;
		list<Missile>::iterator missileIter;
		Player play;
		
			if ((*missiles.getListOfMissile()).size() != 0)
				for (alienIter = aliens.begin(); alienIter != aliens.end(); /* note no ++ here*/)
				{
					
						for (missileIter = (*missiles.getListOfMissile()).begin(); missileIter != (*missiles.getListOfMissile()).end(); missileIter++)
						{

							if ((*missileIter).isgetHit(*alienIter))
							{
								alienIter = aliens.erase(alienIter);
								//missileIter = (*missiles.getListOfMissile()).erase(missileIter);
								
								play.Scoreincreament();

							}

						}
						if (alienIter != aliens.end())
							alienIter++;
					
				}
		
	}
	
	Alien getAlien()
	{
		list<Alien>::iterator iter;
		if (aliens.begin() != aliens.end())
			iter = aliens.begin();

			return *iter;
	}


};
