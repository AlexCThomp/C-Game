//GameMain.cpp
//AUTHOR: ALEXANDER THOMPSON and maybe Steve?
//VERSION: 6/1/2017
#include <SFML/Graphics.hpp>
#include "Map.h"
#include "Player.h"

int main()
{	
	sf::VideoMode resolution = sf::VideoMode::getDesktopMode();
	sf::RenderWindow window(resolution, "test");
	Map map("testMap.txt", "test-wall.png", "test-ground.png", "test-bro.png");
	Player player(map,30,16);
	window.clear(sf::Color::Black);
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
							player.move(map,-1,0);
							break;
							
						case sf::Keyboard::Up: //up arrow
							player.move(map,0,-1);
							break;
							
						case sf::Keyboard::Right: //right arrow
							player.move(map,1,0);
							break;
							
						case sf::Keyboard::Down: //down arrow
							player.move(map,0,1);
							break;
					}
					break;
					
				default:
					break;
				
			}
			
		}
		map.drawMap(window);
		window.display();

	}	
	return 0;
}

