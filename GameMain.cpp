//GameMain.cpp
//AUTHOR: ALEXANDER THOMPSON and maybe Steve?
//VERSION: 6/1/2017
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Map.h"
#include "Player.h"

int main()
{	
	
	
	sf::VideoMode resolution = sf::VideoMode::getDesktopMode();
	sf::RenderWindow window(resolution, "test");
	Map map("testMap.txt", "test-wall.png", "test-ground.png", "forwardPlayer.png", "test-enemy.png");
	Player player(map,'P',0.25f,30,16);
	Player enemy(map, 'E',0.5f,1,1);
	window.clear(sf::Color::Black);
	map.drawMap(window);
	map.printLayout();
	cout << "\n";
	
	window.display(); //display the initial state
	
	
	sf::Clock clock;
	
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
							player.setDirection(Player::left);
							break;
							
						case sf::Keyboard::Up: //up arrow
							player.setDirection(Player::up);
							break;
							
						case sf::Keyboard::Right: //right arrow
							player.setDirection(Player::right);
							break;
							
						case sf::Keyboard::Down: //down arrow
							player.setDirection(Player::down);
							break;
							
						default:
							break;
					}
					break;
				
				case sf::Event::KeyReleased: 
					switch (event.key.code){
						case sf::Keyboard::Left: //left arrow
							player.setDirection(Player::none);
							break;
							
						case sf::Keyboard::Up: //up arrow
							player.setDirection(Player::none);
							break;
							
						case sf::Keyboard::Right: //right arrow
							player.setDirection(Player::none);
							break;
							
						case sf::Keyboard::Down: //down arrow
							player.setDirection(Player::none);
							break;
							
						default:
							break;	
						}
				
				default:
					break;
				
			}
			
		}
		player.move();
		enemy.target(player);
		map.drawMap(window);
		window.display();

	}	
	return 0;
}

