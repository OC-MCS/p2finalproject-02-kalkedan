#pragma once
#include<iostream>
#include"Missile.h"
#include<list>
#include"ship.h"
using namespace std;
class ListofMissile
{
private:
	list <Missile> missiles;
	Texture missileTexure;
public:
	ListofMissile()
	{
		if (!missileTexure.loadFromFile("missile.png"))
		{
			cout << "Unable to load ship texture!" << endl;
			exit(EXIT_FAILURE);
		}
		
	}


	void drawList( RenderWindow& win)
	{
		if (!missileTexure.loadFromFile("missile.png"))
		{
			cout << "Unable to load ship texture!" << endl;
			exit(EXIT_FAILURE);
		}
		list<Missile>::iterator iter;
		for(iter=missiles.begin();iter!=missiles.end();)
		(*iter).draw(win);
	}
	void addtoMissuleList(Missile missile)
	{
		list<Missile>::iterator iter;

		
		missiles.push_back(missile);
	}
	void updateMissuleList(Missile missile)
	{
		Vector2f orginalPos = missile.getMissileSprite().getPosition();
		list<Missile>::iterator iter;
		for (iter = missiles.begin(); iter != missiles.end(); iter++)
		{
			if (missile.getId() == (*iter).getId())
			{
				(*iter).updateMissile(orginalPos);
			}
			
		}
	
	}
	
	void move()
	{
		
		list<Missile>::iterator iter;

		for (iter = missiles.begin(); iter != missiles.end(); iter++)
		{
			(*iter).moveMissile();

		}
	}
	list<Missile> *getListOfMissile()
	{
		list<Missile> *list=&missiles;
			return list;
	}
	void Missileerase()
	{
		list<Missile> temp;		
		missiles = temp;	
	}
	
		

};

