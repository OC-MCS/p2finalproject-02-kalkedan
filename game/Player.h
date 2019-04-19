#pragma once
#include<iostream>
using namespace std;
class Player
{
private:
	int score = 0;
	int lifeLost = 3;
public:
	void Scoreincreament()
	{
		score = score + 1;
	}
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
};