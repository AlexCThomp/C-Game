//GameMain.cpp
//AUTHOR: ALEXANDER THOMPSON
//VERSION: 6/1/2017
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "Map.h"
#include "Player.h"
#include <vector>

int main()
{	
	
	int enemyCount;
	std::vector<Player> enemy;
	
	sf::VideoMode resolution = sf::VideoMode::getDesktopMode();
	sf::RenderWindow window(resolution, "test");
	Map map("testMap.txt", "test-wall.png", "test-ground.png", "forwardPlayer.png", "test-enemy.png");
	Player player(map,'P',0.1f,"forwardPlayer.png","rightPlayer.png",
				 "backwardPlayer.png","leftPlayer.png");
	enemyCount = map.getEnemyCount();
	
	for (int i = 0; i < enemyCount; i++){
		
		enemy.emplace_back(map, 'E',0.25f,"test-enemy.png","test-enemy.png",
						"test-enemy.png","test-enemy.png");
	}
	
	window.clear(sf::Color::Black);
	map.drawMap(window);
	map.printLayout();
	cout << "\n";
	
	window.display(); //display the initial state
	
	
	sf::Clock clock;
	/*sf::Music music;
	
	if (!music.openFromFile("warofgods.ogg")){
		cout << "music error";
		return -1;
	}
	music.setLoop(true);
	music.play();*/
	while(window.isOpen()){
	
		
		sf::Event event;
		while (window.pollEvent(event)){
			
			switch (event.type){
				
				case sf::Event::Closed: //user closed window
					//music.stop();
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

		for (int i = 0; i < enemyCount; i++){
			if (enemy[i].getStatus() == Player::alive){enemy[i].target(player);}
			if (enemy[i].getTime() > 10.f){enemy[i].setStatus(Player::alive);}
		}
		map.drawMap(window);
		window.display();

	}	
	return 0;
}

