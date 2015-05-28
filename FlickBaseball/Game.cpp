#include "Game.h"

namespace fbb {

Game::Game() : window(sf::VideoMode((int)fbb::WIDTH, (int)fbb::HEIGHT, sf::VideoMode::getDesktopMode().bitsPerPixel), TITLE), 
			   camera(sf::FloatRect(0.0f, 0.0f, WIDTH, HEIGHT)) {
	window.setFramerateLimit(60);
	window.setView(camera);

	currentButtonSet = gsm.getButtons();
}

Game::~Game() {}

void Game::gameLoop() {
	sf::Event e1;
	fbb::Event e2;

	while(window.isOpen()) {
		while(window.pollEvent(e1)) {
			switch(e1.type) {
				case sf::Event::Closed:
					window.close();
					break; //Close
				case sf::Event::MouseMoved:
					for(fbb::Button& button : *currentButtonSet) {
						if(button.isClicked())
							break;

						if(button.getBounds().contains(sf::Vector2f((float)e1.mouseMove.x, (float)e1.mouseMove.y))) {
							button.setSelected();
						} else {
							button.setUnselected();
						}
					}
					break; //MouseMoved
				case sf::Event::MouseButtonPressed:
					for(fbb::Button& button : *currentButtonSet) {
						if(button.getBounds().contains(sf::Vector2f((float)e1.mouseButton.x, (float)e1.mouseButton.y))) {
							button.setClicked();
							break;
						}
					}
					break; //MousesPressed
				case sf::Event::MouseButtonReleased:
					for(fbb::Button& button : *currentButtonSet) {
						if(button.isClicked()) {
							button.onClick();
						}
						if(button.getBounds().contains(sf::Vector2f((float)e1.mouseButton.x, (float)e1.mouseButton.y))) {
							button.setSelected();
						} else {
							button.setUnselected();
						}
					}
					break; //MouseReleased
			} //End switch
		} //End system event poll

		while(gsm.pollEvent(e2)) {
			sf::Texture texture;
			sf::Sprite sprite;
			switch(e2.type) {
				case fbb::Event::Close:
					window.close();
					break;
				case fbb::Event::ChangeState:
					texture.loadFromFile("loading.png");
					sprite.setTexture(texture);
					window.clear();
					window.draw(sprite);
					window.display();
					currentButtonSet->clear();
					gsm.setPreviousState(e2.changeState.thisState);
					gsm.setState(e2.changeState.nextState);
					currentButtonSet = gsm.getButtons();
					break;
				case fbb::Event::Return:
					texture.loadFromFile("loading.png");
					sprite.setTexture(texture);
					window.clear();
					window.draw(sprite);
					window.display();
					currentButtonSet->clear();
					gsm.setState(gsm.getPreviousState());
					currentButtonSet = gsm.getButtons();
					break;
			} //End switch
		} //End game event poll

		gsm.update();

		window.clear(sf::Color::White);
		gsm.draw(window);
		for(fbb::Button& button : *currentButtonSet) {
			window.draw(button);
		}
		window.display();
	} //End game loop
}

} //End namespace

