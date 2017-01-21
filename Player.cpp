//Player.cpp
//Author: Alexander Thompson
//Version: 7/1/2017
#include <string>
#include "Player.h"
#include "Map.h"
#include <iostream>

//constructor sets player position on map
Player:: Player(Map &newMap, char tile,float newSpeed, int x, int y,
				string newUpT, string newRightT, string newDownT, string newLeftT)
	:Tile(x,y,newUpT),map(newMap){
		
	if (!upT.loadFromFile(newUpT)){
		cout << "Error loading player up texture!";
	}
	if (!rightT.loadFromFile(newRightT)){
		cout << "Error loading player right texture!";
	}
	if (!downT.loadFromFile(newDownT)){
		cout << "Error loading player down texture!";
	}
	if (!leftT.loadFromFile(newLeftT)){
		cout << "Error loading player left texture!";
	}
	direction = none;
	status = alive;
	clock.restart();
	speed = newSpeed;
	attackSpeed = 0.05f;
	layoutTile = tile;
	standingOn = map.getTile(x,y);
	map.setTile(x,y,layoutTile);
}

//get Methods
Player::Direction Player::getDirection(){return direction;}
Player::Status Player::getStatus(){return status;}
sf::Texture Player::getUpTexture(){return upT;}
sf::Texture Player::getRightTexture(){return rightT;}
sf::Texture Player::getDownTexture(){return downT;}
sf::Texture Player::getLeftTexture(){return leftT;}
float Player::getTime(){return clock.getElapsedTime().asSeconds();}

//returns tile in front of player
char Player::inFront(){
	switch (direction){
		case up:
			return map.getTile(x,y-1);
		case right:
			return map.getTile(x+1,y);
		case down:
			return map.getTile(x,y+1);
		case left:
			return map.getTile(x-1,y);
		default:
			return layoutTile;
	}
}
//set Methods
void Player::setDirection(Direction newDirection){
	direction = newDirection;
	switch (direction){
		case up:
			map.setTexture(layoutTile,upT);
			break;
		case right:
			map.setTexture(layoutTile,rightT);
			break;
		case down:
			map.setTexture(layoutTile,downT);
			break;
		case left:
			map.setTexture(layoutTile,leftT);
			break;
		default:
			break;
	}
}

void Player:: setStatus(Status newStatus){
	status = newStatus;
	if (status == dead){layoutTile = 'C';}
	else if (status == alive){layoutTile = 'E';}
	clock.restart();
}
//makes a move towards the inputted coordinates
void Player:: target(int tX, int tY){
	
	int xDist = x - tX;
	int yDist = y - tY;
	
	if (((abs(xDist) < 15) && (abs(yDist) < 15))&&
	(clock.getElapsedTime().asSeconds() > speed)){
		
		if (abs(xDist) >= abs(yDist)){
			direction = ((xDist > 0) ? left:right);
		}else{ 
			direction = ((yDist > 0) ? up:down);
		}		
	}
	move(direction);
}

//makes move towards inputted target
void Player:: target(Player myTarget){
	this->target(myTarget.x, myTarget.y);
}
//moves player X tiles horizontally and Y tiles vertically
void Player:: move(int newX, int newY){
	if(map.getTile(x,y) == '#'){
		setStatus(dead);
		map.setTile(x,y,layoutTile);
	}else if ((map.getTile(x + newX, y + newY) == '_') &&
	clock.getElapsedTime().asSeconds() > speed){
		map.setTile(x, y, standingOn);
		x += newX;
		y += newY;
		standingOn = map.getTile(x, y);
		map.setTile(x,y,layoutTile);
		clock.restart();
	}
}

void Player:: move(Direction newDirection){
	
	if (newDirection == direction){
		switch (newDirection){
			case left:
				move(-1,0);
				break;
			
			case up:
				move(0,-1);
				break;
			
			case right:	
				move(1,0);
				break;
	
			case down:
				move(0,1);
				break;
			
			default:
				break;
		}
	}else{
		setDirection(newDirection);
		clock.restart();
	}
}

void Player:: attack(){
	if (clock.getElapsedTime().asSeconds() > attackSpeed){
		if (inFront() == 'E'){
			switch (direction){
				case up:
					map.setTile(x,y-1,'#');
					break;
				case right:
					map.setTile(x+1,y,'#');
					break;
				case down:
					map.setTile(x,y+1,'#');
					break;
				case left:
					map.setTile(x-1,y,'#');
					break;
				default:
					break;
			}
		}
	}
	clock.restart();
}
				




					
	
	
	
