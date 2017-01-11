//Player.cpp
//Author: Alexander Thompson
//Version: 7/1/2017

#include "Player.h"
#include "Map.h"

//constructor sets player position on map
Player:: Player(Map &newMap, char tile, int x, int y)
	:map(newMap)
{
	
	this->x = x;
	this->y = y;
	layoutTile = tile;
	standingOn = map.getTile(x,y);
	map.setTile(x,y,layoutTile);
}

//get Methods
int Player::getX(){return x;}
int Player::getY(){return y;}

//makes a move towards the inputted coordinates
void Player:: target(int tX, int tY){
	
	int xMov=0, yMov=0;
	int xDist = x - tX;
	int yDist = y - tY;
	
	if ((abs(xDist) < 6) && (abs(yDist) < 6)){ 	
		if (abs(xDist) >= abs(yDist)){
		
			xMov = ((xDist > 0) ? -1:1);
		
		}else{ 
			yMov = ((yDist > 0) ? -1:1);
		}
	}
	move(xMov, yMov);
}

//makes move towards inputted target
void Player:: target(Player myTarget){
	this->target(myTarget.x, myTarget.y);
}
//moves player X tiles horizontally and Y tiles vertically
void Player:: move(int x, int y){
	
	if (map.getTile(this->x + x, this->y + y) != '#'){
		map.setTile(this->x, this->y, standingOn);
		this->x += x;
		this->y += y;
		standingOn = map.getTile(this->x, this->y);
		map.setTile(this->x,this->y,layoutTile);
	}
}
