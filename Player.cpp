//Player.cpp
//Author: Alexander Thompson
//Version: 7/1/2017

#include "Player.h"
#include "Map.h"

//constructor sets player position on map
Player:: Player(Map map, int x, int y){
	
	this->x = x;
	this->y = y;
	standingOn = map.getTile(x,y);
	map.setTile(x,y,'P');
}

//moves player X tiles horizontally and Y tiles vertically
void Player:: move(Map map, int x, int y){
	
	if (map.getTile(this->x + x, this->y + y) != '#'){
		map.setTile(this->x, this->y, standingOn);
		this->x += x;
		this->y += y;
		standingOn = map.getTile(this->x, this->y);
		map.setTile(this->x,this->y,'P');
	}
}
