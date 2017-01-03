//Map.cpp
//AUTHOR: ALEXANDER THOMPSON
//VERSION: 31/12/2016

#include <iostream>
#include <fstream>
#include "Map.h"
using namespace std;

//constructor for Map
//sets width to a, height to b,
//loads layout from fileName	
Map::Map(int a,int b,string fileName){
	width  = a;
	height = b;
	layout = new char*[height];
	for (int i=0; i < height; i++){
		layout[i] = new char[width];
	}

	ifstream file(fileName);
	char c;
	if (file.is_open()){
		for (int i=0; i<height; i++){
			for (int j=0; j<width; j++){
				file.get(c);
				if (c != '\r'){
					layout [i][j] = c;
				}
			}
		}
	}
	file.close();
		
}
//constructs map with width and height as default values
//loads layout from fileName
Map::Map(string fileName) : Map::Map(32, 18, fileName){}

//returns the map layout
char** Map::getLayout(){return layout;}

//prints map layout (test method)
void Map::printLayout(){
	for (int i=0; i<height; i++){
		for (int j=0; j<width; j++){
			cout << layout[i][j];
		}
	}
}

