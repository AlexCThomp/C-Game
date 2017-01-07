//grapics testing stuff
#include <SFML/Graphics.hpp>

#include <SFML/Graphics.hpp>

int main()
{
	//direction of travel variables
	
	bool up,down,left,right = false;
	
	
	sf::RenderWindow window(sf::VideoMode(1920,1080), "FUCK");
	//clears window with color (black)
	window.clear(sf::Color::Black);
	//draws circle
	sf::CircleShape circle(50);
	
	circle.setFillColor(sf::Color(250,50,50));
	circle.setOutlineThickness(10);
	circle.setOutlineColor(sf::Color(250,150,100));
	
	window.draw(circle);
	
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
							left = true;
							break;
							
						case sf::Keyboard::Up: //up arrow
							up = true;
							break;
							
						case sf::Keyboard::Right: //right arrow
							right = true;
							break;
							
						case sf::Keyboard::Down: //down arrow
							down = true;
							break;
					}
					break;
				
				case sf::Event::KeyReleased:
					switch (event.key.code){
						
						case sf::Keyboard::Left: //left arrow
							left = false;
							break;
							
						case sf::Keyboard::Up: //up arrow
							up = false;
							break;
							
						case sf::Keyboard::Right: //right arrow
							right = false;
							break;
							
						case sf::Keyboard::Down: //down arrow
							down = false;
							break;
					}
					
				default:
					break;
				
			}
			
		}
		if (left){
			window.clear(sf::Color::Black);
			circle.move(-1,0);
			window.draw(circle);
		}else if (right){
			window.clear(sf::Color::Black);
			circle.move(1,0);
			window.draw(circle);
		}else if (up){
			window.clear(sf::Color::Black);
			circle.move(0,-1);
			window.draw(circle);
		}else if (down){
			window.clear(sf::Color::Black);
			circle.move(0,1);
			window.draw(circle);
		}
		window.display();

	}	
	return 0;
}
