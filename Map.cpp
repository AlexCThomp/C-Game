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
													string playerFile, string enemyFile){
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
	if (!enemy.loadFromFile(enemyFile)){
		cout << "Error loading enemyFile";
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
Map::Map(string mapFile, string wallFile, string groundFile,string playerFile, string enemyFile) :
	Map::Map(32, 18, mapFile, wallFile, groundFile, playerFile, enemyFile){}

//get methods
char** Map::getLayout(){return layout;}
char Map::getTile(int x, int y){return layout[y][x];}
sf::Texture Map::getWall(){return wall;}
sf::Texture Map::getGround(){return ground;}
sf::Texture Map::getPlayer(){return player;}
int Map::getWidth(){return width;}
int Map::getHeight(){return height;}

//set Methods

//Sets a tile to input character(maybe we need a custom datat type for tiles?)
void Map:: setTile(int x, int y, char c){
	layout[y][x] = c;
}

//sets player texture
void Map:: setPlayer(string newTexture){
	
	if (!player.loadFromFile(newTexture)){
		cout << "Error loading player texture!";
	}
}

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
	int screenWidth = window.getSize().x;
	int screenHeight = window.getSize().y;
	float resScaleY = (float) screenHeight / 1080.f; 
	float resScaleX = (float) screenWidth / 1920.f;
	
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
					
				case 'E':
					spriteLayout[i][j].setTexture(enemy);
					break;
					
				default:
					spriteLayout[i][j].setTexture(ground);
					break;
				}
			
			spriteLayout[i][j].setScale(resScaleX, resScaleY);
			spriteLayout[i][j].setPosition(sf::Vector2f(j*(screenWidth/width), i*(screenHeight/height)));
			window.draw(spriteLayout[i][j]);
		}
	}
}
	
	
	
	
	

