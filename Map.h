//Map.h
//AUTHOR: Alexander Thompson
//VERSION: 31/12/2016
#ifndef MAP_H
#define MAP_H
#include <string>
#include <SFML/Graphics.hpp>


using namespace std;

class Map{
	private:
	int height, width, enemyCount;
	sf::Texture wall,ground,player,enemy,corpse;
	char** layout;
	
	public:
	//constructor for Map
	//sets width and height respectively to paraneter values
	//loads layout from fileName
	Map(int,int,string,string,string,string,string);
	
	//constructs map with width and height as default values
	//loads layout from fileName
	Map(string,string,string,string,string);
	
	//Get methods
	char** getLayout();
	char getTile(int,int);
	sf::Texture getWall();
	sf::Texture getGround();
	sf::Texture getPlayer();
	int getWidth();
	int getHeight();
	int getEnemyCount();
	
	//Set methods
	void setTile(int,int,char);
	void setLayout(string);
	
	//set player texture
	void setPlayer(string);

	//set selected texture
	void setTexture(char,sf::Texture);
	
	//prints layout to terminal (test method)
	void printLayout();
	
	//renders map in current stat into the input render window (passed by reference)
	void drawMap(sf::RenderWindow&);
};
	
#endif
