//Map.cpp
//AUTHOR: ALEXANDER THOMPSON
//VERSION: 31/12/2016

#include <iostream>
#include <fstream>
#include "Map.h"
#include <SFML/Graphics.hpp>

using namespace std;

//constructor for Map
//sets width to a, height to b,
//loads layout from fileName	
Map::Map(int a,int b,string mapFile, string wallFile, string groundFile,
													string playerFile){
	width  = a;
	height = b;
	
	if (!wall.loadFromFile(wallFile)){
		cout << "Error loading wall texture!";
	}
	if (!ground.loadFromFile(groundFile)){
		cout << "Error loading ground texture!";
	}
	if (!player.loadFromFile(playerFile)){
		cout << "Error loading player texture!";
	}
	
	layout = new char*[height];
	for (int i=0; i < height; i++){
		layout[i] = new char[width];
	}

	ifstream file(mapFile);
	char c;
	if (file.is_open()){
		for (int i=0; i<height; i++){
			for (int j=0; j<width; j++){
				file.get(c);
				if (c != '\n'){
					layout [i][j] = c;
				}
			}
		}
	}
	file.close();
		
}
//constructs map with width and height as default values
//loads layout from fileName
Map::Map(string mapFile, string wallFile, string groundFile,string playerFile) :
	Map::Map(32, 18, mapFile, wallFile, groundFile, playerFile){}

//get methods
char** Map::getLayout(){return layout;}
sf::Texture Map::getWall(){return wall;}
sf::Texture Map::getGround(){return ground;}
sf::Texture Map::getPlayer(){return player;}
int Map::getWidth(){return width;}
int Map::getHeight(){return height;}

//prints map layout (test method)
void Map::printLayout(){
	for (int i=0; i<height; i++){
		cout << "\n";
		for (int j=0; j<width; j++){
			cout << layout[i][j];
		}
	}
}

void Map::drawMap(sf::RenderWindow &window){
	
	sf::Sprite** spriteLayout;
	
	spriteLayout = new sf::Sprite* [height];
	for (int i=0; i<height; i++){
		spriteLayout[i] = new sf::Sprite [width];
	}
	
	for (int i=0; i<height; i++){
		for (int j=0; j<width; j++){
			
			switch (layout[i][j]){
				
				case '#':
					spriteLayout[i][j].setTexture(wall);
					break;
					
				case '_':
					spriteLayout[i][j].setTexture(ground);
					break;
					
				case 'P':
					spriteLayout[i][j].setTexture(player);
					break;
					
				default:
					spriteLayout[i][j].setTexture(player);
					break;
				}
			spriteLayout[i][j].setPosition(sf::Vector2f(j*60, i*60));
			window.draw(spriteLayout[i][j]);
		}
	}
}
	
	
	
	
	

