//Player.h
//AUTHOR: Alexander Thompson
//Version: 7/1/2017

#ifndef PLAYER_H
#define PLAYER_H
#include "Map.h"

class Player{
	private:
	int x,y;
	char standingOn;
	
	public:
	Player(Map, int, int);
	
	void move(Map,int,int);
};


#endif
