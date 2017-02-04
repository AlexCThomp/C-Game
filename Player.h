//Player.h
//AUTHOR: Alexander Thompson
//Version: 7/1/2017

#ifndef PLAYER_H
#define PLAYER_H
#include "Map.h"
#include "Tile.h"
#include <SFML/Graphics.hpp>

class Player : public Tile{
	public:
	enum Direction{up=1,right,down,left,none};
	enum Status{alive,dead};
	
	private:
	Map &map;
	Direction direction;
	Status status;
	sf::Clock clock;
	sf::Texture upT,rightT,downT,leftT;
	float speed, attackSpeed;
	char standingOn;
	char layoutTile;
	
	public:
	Player(Map&,char,float,int,int,string,string,string,string);
	Player(Map&,char,float,string,string,string,string);
	
	//get methods
	int getX();
	int getY();
	char inFront();
	char look(Direction);
	char getLayoutTile();
	Direction getDirection();
	Status getStatus();
	sf::Texture getUpTexture();
	sf::Texture getRightTexture();
	sf::Texture getDownTexture();
	sf::Texture getLeftTexture();
	float getTime();
	Direction adjacentPath(Direction**,int,int);
	
	
	//set methods
	void setDirection(Direction);
	void setStatus(Status);

	//other methods
	void move(int,int);
	void move(Direction);
	
	void target(int,int);
	void target(Player);

	void attack();
};


#endif
