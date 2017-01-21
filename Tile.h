//Tile.h
//Author: Alexander Thompson

#ifndef TILE_H
#define TILE_H
#include <string>
#include <SFML/Graphics.hpp>

using namespace std;

class Tile{
	protected:
	sf::Texture texture;
	int x,y;

	public:
	Tile(int,int,string);
	//get methods
	int getX();
	int getY();
	sf::Texture getTexture();
};





#endif

