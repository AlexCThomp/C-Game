//Tile.cpp
//Alexander Thompson
#include <string>
#include "Tile.h"
#include "Map.h"
#include <iostream>

Tile:: Tile(int newX, int newY, string newTexture){
	x = newX;
	y = newY;

	if (!texture.loadFromFile(newTexture)){
		std::cout << "error loading Tile texture";
	}
}
Tile:: Tile(Map &newMap,char tile, string newTexture){

	Map map(newMap);
	int mapWidth = map.getWidth();
	int mapHeight = map.getHeight();
	
	for (int i = 0; i < mapHeight; i++){
		for (int j = 0; j < mapWidth; j++){
			if (map.getLayout()[i][j] == tolower(tile)){
				x = j;
				y = i;
			}
		}
	}

	if (!texture.loadFromFile(newTexture)){
		std::cout << "error loading Tile texture";
	}
}
	

int Tile:: getX(){return x;}
int Tile:: getY(){return y;}
sf::Texture Tile::getTexture(){return texture;}
