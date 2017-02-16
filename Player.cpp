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
	type = tile;
	standingOn = map.getTile(x,y);
	map.setTile(x,y,layoutTile);
}

Player:: Player(Map& newMap,char tile,float newSpeed,string newUpT,
				string newRightT, string newDownT, string newLeftT)
	:Tile(newMap,tile,newUpT), map(newMap){

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
	attackSpeed = 0.3f;
	layoutTile = tile;
	type = tile;
	standingOn = '_';
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
char Player::getLayoutTile(){return layoutTile;}

//returns tile in front of player
char Player::inFront(){
	return look(direction);
}

char Player::look(Direction facing){
	switch (facing){
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

//helper method for target(int,int)
//returns direction that is adjacent to input coordinates
//in a pathMap
Player::Direction Player::adjacentPath(Direction** adjMap, int targetX, int targetY){

	Direction above,below,toLeft,toRight;
	//char tileAbove, tileBelow, tileLeft, tileRight;
	
	if (targetX == 0 || targetY == 0 || targetX >= map.getWidth()-1 ||
		targetY >= map.getHeight()-1){return none;}

	/*
	tileAbove = map.getTile(targetX, targetY-1);
	tileRight = map.getTile(targetX+1, targetY);
	tileBelow = map.getTile(targetX, targetY+1);
	tileLeft = map.getTile(targetX-1, targetY);
	*/
	
	above = adjMap[targetY-1][targetX];
	below = adjMap[targetY+1][targetX];
	toLeft = adjMap[targetY][targetX-1];
	toRight = adjMap[targetY][targetX+1];

	
	
	if (toRight !=none){return toRight;}
	else if (toLeft != none){return toLeft;}
	else if (below != none){return below;}
	else if (above != none){return above;}
	else{return none;}
	
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
	else if (status == alive){
		layoutTile = type;
		map.setTile(x,y,type);
	}
	clock.restart();
}

void Player:: reset(){
	int mapWidth = map.getWidth();
	int mapHeight = map.getHeight();
	
	for (int i = 0; i < mapHeight; i++){
		for (int j = 0; j < mapWidth; j++){
			if (map.getLayout()[i][j] == tolower(type)){
				x = j;
				y = i;
				map.setTile(x,y,type);
				j = mapWidth;
				i = mapHeight;
				
			}
		}
	}
	setStatus(alive);
}

//makes a move towards the inputted coordinates
void Player:: target(int tX, int tY){

	int distance = abs(x - tX) + abs(y - tY);
	if (clock.getElapsedTime().asSeconds() > speed){
		if(1 < distance){
			Player::Direction sourceDirection;
			Player::Direction** pathMap;
			
			pathMap = new Direction*[map.getHeight()];
			for (int i=0; i < map.getHeight(); i++){
				pathMap[i] = new Direction[map.getWidth()];
			}
			
			for(int i = 0; i < map.getHeight(); i++){
				for(int j = 0; j < map.getWidth(); j++){
			
					pathMap[i][j] = none;
				}
			}
			if (map.getTile(x,y-1) != '#'){
				pathMap[y-1][x] = up;
			}
			if (map.getTile(x+1,y) != '#'){
				pathMap[y][x+1] = right;
			}
			if (map.getTile(x,y+1) != '#'){
				pathMap[y+1][x] = down;
			}
			if (map.getTile(x-1,y) != '#'){
				pathMap[y][x-1] = left;
			}
	
			//with multiple enemies it gets stuck here (loops infinitely)
			int forceBreak = 0;
			while((sourceDirection = adjacentPath(pathMap,tX,tY)) == none && forceBreak < 500){
				for(int y = 0; y < map.getHeight(); y++){
					for(int x = 0; x < map.getWidth(); x++){
						if (pathMap[y][x] != none){
							
							if(map.getTile(x-1,y) != '#' && pathMap[y][x-1] == none){
								pathMap[y][x-1] = pathMap[y][x];
							}
							if(map.getTile(x+1,y) != '#' && pathMap[y][x+1] == none){
								pathMap[y][x+1] = pathMap[y][x];
								x++;
							}
							if(map.getTile(x,y-1) != '#' && pathMap[y-1][x] == none){
								pathMap[y-1][x] = pathMap[y][x];
							}
							if(map.getTile(x,y+1) != '#' && pathMap[y+1][x] == none){
								pathMap[y+1][x] = pathMap[y][x];
							}
							
							
						}
					}
				}
				forceBreak++;
			}
			
	
			/*
			cout << "\n";
			for(int i = 0; i < map.getHeight(); i++){
				cout << "\n";
				for(int j = 0; j < map.getWidth(); j++){
					printf("%d", pathMap[i][j]);
				}
			}
			*/
			for(int i = 0; i < map.getHeight(); i++){
				delete [] pathMap[i];
			}
			delete [] pathMap;
			pathMap = 0;
			move(sourceDirection);
			
		}else{
			if (x < tX){direction = right;}
			else if (x > tX){direction = left;}
			else if (y < tY){direction = down;}
			else if (y > tY){direction = up;}
		}
			
	}	
}

//makes move towards inputted target
void Player:: target(Player myTarget){
	if (inFront() == myTarget.getLayoutTile()){
		attack();
	}else{target(myTarget.Tile::getX(), myTarget.Tile::getY());}
}
//moves player X tiles horizontally and Y tiles vertically
void Player:: move(int newX, int newY){

	if (clock.getElapsedTime().asSeconds() > speed){
		clock.restart();
		if ((map.getTile(x + newX, y + newY) == '_')){
		
			map.setTile(x, y, standingOn);
			x += newX;
			y += newY;
			standingOn = map.getTile(x, y);
			map.setTile(x,y,layoutTile);
			clock.restart();
		}
	}
}
//checks to see if the player was hit
void Player:: detectHit(){
if(map.getTile(x,y) == '#'){
		setStatus(dead);
		map.setTile(x,y,layoutTile);
	}
}
void Player:: move(Direction newDirection){
	
	if (newDirection == direction || layoutTile != 'P'){
		direction = newDirection;
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
				move(0,0);
				break;
		}
	}else{
		setDirection(newDirection);
		clock.restart();
	}
}

void Player:: attack(){
	
	if (clock.getElapsedTime().asSeconds() > attackSpeed){
		if (inFront() == 'E' || inFront() == 'P'){
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
		clock.restart();
	}
	
	
}
				




					
	
	
	
