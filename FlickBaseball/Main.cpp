#include "SFML\Graphics.hpp"

#define WIDTH 1280.0f
#define HEIGHT 720.0f
#define TITLE "Flick Baseball"

int main() {
	sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode((int)WIDTH, (int)HEIGHT), TITLE);
	window->setFramerateLimit(60);
	sf::View* camera = new sf::View(sf::FloatRect(0.0f, 0.0f, WIDTH, HEIGHT));
	window->setView(*camera);
	
	while(window->isOpen()) {		
		sf::Event event;
		while(window->pollEvent(event)) {
			if(event.type == sf::Event::Closed) {
				window->close();
			}
		}
	}

	return 0;
}