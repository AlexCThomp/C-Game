//Tile.cpp
//Alexander Thompson
#include <string>
#include "Tile.h"
#include <iostream>

Tile:: Tile(int newX, int newY, string newTexture){
	x = newX;
	y = newY;

	if (!texture.loadFromFile(newTexture)){
		std::cout << "error loading Tile texture";
	}
}

int Tile:: getX(){return x;}
int Tile:: getY(){return y;}
sf::Texture Tile::getTexture(){return texture;}
