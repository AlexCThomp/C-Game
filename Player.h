//Player.h
//AUTHOR: Alexander Thompson
//Version: 7/1/2017

#ifndef PLAYER_H
#define PLAYER_H
#include "Map.h"
#include <SFML/Graphics.hpp>

class Player{
	public:
	enum Direction{up,right,down,left,none};
	
	private:
	Map &map;
	Direction direction;
	sf::Clock clock;
	sf::Texture upT,rightT,downT,leftT;
	float speed;
	int x,y;
	char standingOn;
	char layoutTile;
	
	public:
	Player(Map&,char,float,int,int,string,string,string,string);
	
	//get methods
	int getX();
	int getY();
	Direction getDirection();
	sf::Texture getUpTexture();
	sf::Texture getRightTexture();
	sf::Texture getDownTexture();
	sf::Texture getLeftTexture();
	
	
	//set methods
	void setDirection(Direction);
	
	void move(int,int);
	void move();
	
	void target(int,int);
	void target(Player);
};


#endif
