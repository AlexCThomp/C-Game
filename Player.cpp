//Player.cpp
//Author: Alexander Thompson
//Version: 7/1/2017
#include <string>
#include "Player.h"
#include "Map.h"
#include <iostream>

//constructor sets player position on map
Player:: Player(Map &newMap, char tile,float newSpeed, int x, int y)
	:map(newMap)
{
	
	this->x = x;
	this->y = y;
	direction = none;
	clock.restart();
	speed = newSpeed;
	layoutTile = tile;
	standingOn = map.getTile(x,y);
	map.setTile(x,y,layoutTile);
}

//get Methods
int Player::getX(){return x;}
int Player::getY(){return y;}
Player::Direction Player::getDirection(){return direction;}

//set Methods
void Player::setDirection(Direction newDirection){
	direction = newDirection;
}

//makes a move towards the inputted coordinates
void Player:: target(int tX, int tY){
	
	int xMov=0, yMov=0;
	int xDist = x - tX;
	int yDist = y - tY;
	
	if ((abs(xDist) < 15) && (abs(yDist) < 15)){ 	
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
	
	if ((map.getTile(this->x + x, this->y + y) == '_') &&
	clock.getElapsedTime().asSeconds() > speed){
		map.setTile(this->x, this->y, standingOn);
		this->x += x;
		this->y += y;
		standingOn = map.getTile(this->x, this->y);
		map.setTile(this->x,this->y,layoutTile);
		clock.restart();
	}
}

void Player:: move(){
	
	switch (direction){
		case left:
			move(-1,0);
			map.setPlayer("leftPlayer.png");
			break;
			
		case up:
			move(0,-1);
			map.setPlayer("forwardPlayer.png");
			break;
			
		case right:	
			move(1,0);
			map.setPlayer("rightPlayer.png");
			break;
	
		case down:
			move(0,1);
			map.setPlayer("backwardPlayer.png");
			break;
			
		default:
			break;
	}
}
	
	
	
