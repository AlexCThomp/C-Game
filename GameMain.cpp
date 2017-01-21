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
	Player player(map,'P',0.1f,30,16,
	"forwardPlayer.png","rightPlayer.png","backwardPlayer.png","leftPlayer.png");
	Player enemy(map, 'E',0.25f,1,1,
	"test-enemy.png","test-enemy.png","test-enemy.png","test-enemy.png");
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
				
				default:
					break;
				
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){player.move(Player::up);}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){player.move(Player::right);}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){player.move(Player::down);}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){player.move(Player::left);}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){player.attack();}

		if (enemy.getStatus() == Player::alive){enemy.target(player);}
		if (enemy.getTime() > 10.f){enemy.setStatus(Player::alive);}
		map.drawMap(window);
		window.display();

	}	
	return 0;
}

