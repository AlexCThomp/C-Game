//GameMain.cpp
//AUTHOR: ALEXANDER THOMPSON
//VERSION: 6/1/2017
#include <SFML/Graphics.hpp>
#include "Map.h"

int main()
{	
	
	sf::RenderWindow window(sf::VideoMode(1920,1080), "test");
	Map map("testMap.txt", "test-wall.png", "test-ground.png", "test-bro.png");
	map.drawMap(window);
	map.printLayout();
	
	window.display(); //display the initial state
			
	
	while(window.isOpen()){
		
		sf::Event event;
		while (window.pollEvent(event)){
			
			switch (event.type){
				
				case sf::Event::Closed: //user closed window
					window.close();
					break;
					
				case sf::Event::KeyPressed: //user pressed a key
					switch (event.key.code){
						case sf::Keyboard::Left: //left arrow
							break;
							
						case sf::Keyboard::Up: //up arrow
							break;
							
						case sf::Keyboard::Right: //right arrow
							break;
							
						case sf::Keyboard::Down: //down arrow
							break;
					}
					break;
					
				default:
					break;
				
			}
			
		}

		window.display();

	}	
	return 0;
}

