#include "Game.h"

namespace fbb {

Game::Game() : window(sf::VideoMode((int)WIDTH, (int)HEIGHT, sf::VideoMode::getDesktopMode().bitsPerPixel), TITLE), 
				camera(sf::FloatRect(0.0f, 0.0f, WIDTH, HEIGHT)), background(sf::Quads, 4), gsm() {
	std::cout << "Initializing window..." << std::endl;
	window.setFramerateLimit(60);
	window.setView(camera);

	background[0].position = sf::Vector2f(0.0f, 0.0f);
	background[1].position = sf::Vector2f(WIDTH, 0.0f);
	background[2].position = sf::Vector2f(WIDTH, HEIGHT);
	background[3].position = sf::Vector2f(0.0f, HEIGHT);
	background[0].color = sf::Color::White;
	background[1].color = sf::Color::White;
	background[2].color = sf::Color::White;
	background[3].color = sf::Color::White;
	std::cout << "Done initializing window!" << std::endl;

	currentButtonSet = gsm.getButtons();
}

Game::~Game() {}

void Game::gameLoop() {
	while(window.isOpen()) {
		window.clear();		
		window.draw(background, sf::RenderStates::Default);
		for(fbb::Button& button : *currentButtonSet) {
			window.draw(button);
		}		
		window.display();

		sf::Event event;
		while(window.pollEvent(event)) {
			if(event.type == sf::Event::Closed) {
				window.close();
			}
			if(event.type == sf::Event::MouseMoved) {
				for(fbb::Button& button : *currentButtonSet) {
					if(button.isClicked())
						break;

					if(button.getBounds().contains(sf::Vector2f((float)event.mouseMove.x, (float)event.mouseMove.y))) {
						button.setSelected();
					} else {
						button.setUnselected();
					}
				}
			}
			if(event.type == sf::Event::MouseButtonPressed) {
				for(fbb::Button& button : *currentButtonSet) {
					if(button.getBounds().contains(sf::Vector2f((float)event.mouseButton.x, (float)event.mouseButton.y))) {
						button.setClicked();
						break;
					}
				}
			}
			if(event.type == sf::Event::MouseButtonReleased) {
				for(fbb::Button& button : *currentButtonSet) {
					if(button.getBounds().contains(sf::Vector2f((float)event.mouseButton.x, (float)event.mouseButton.y))) {
						button.setSelected();
					} else {
						button.setUnselected();
					}
				}
			}
		}
	}
}

} //End namespace

