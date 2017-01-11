//Player.h
//AUTHOR: Alexander Thompson
//Version: 7/1/2017

#ifndef PLAYER_H
#define PLAYER_H
#include "Map.h"

class Player{
	private:
	Map map;
	int x,y;
	char standingOn;
	char layoutTile;
	
	public:
	Player(Map&,char, int, int);
	
	//get methods
	int getX();
	int getY();
	
	void move(int,int);
	
	void target(int,int);
	void target(Player);
};


#endif
