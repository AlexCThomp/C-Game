//Map.h
//AUTHOR: Alexander Thompson
//VERSION: 31/12/2016
#ifndef MAP_H
#define MAP_H
#include <string>

using namespace std;

class Map{
	private:
	int height, width;
	char** layout;
	
	public:
	//constructor for Map
	//sets width and height respectively to paraneter values
	//loads layout from fileName
	Map(int,int,string);
	
	//constructs map with width and height as default values
	//loads layout from fileName
	Map(string);
	
	char** getLayout();
	//prints layout to terminal (test method)
	void printLayout();
};
	
#endif
