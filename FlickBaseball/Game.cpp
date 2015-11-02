#include "Game.h"

namespace fbb {

Game::Game(fbb::Config config) :
gsm(config),
window(sf::VideoMode((int)fbb::WIDTH, (int)fbb::HEIGHT, sf::VideoMode::getDesktopMode().bitsPerPixel), TITLE) {
	std::cout << "*** OpenGL Context Settings" << std::endl;
	std::cout << "*** OpenGL version: " << window.getSettings().majorVersion << "." << window.getSettings().minorVersion << std::endl;
	std::cout << "*** Depth bits: " << window.getSettings().depthBits << std::endl;
	std::cout << "*** Stencil bits: " << window.getSettings().stencilBits << std::endl;
	std::cout << "*** Antialiasing level: " << window.getSettings().antialiasingLevel << std::endl;
	std::cout << "*** Attribute flags: " << window.getSettings().attributeFlags << std::endl;
	window.setFramerateLimit(60);
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
					break;
				case sf::Event::MouseMoved:
					gsm.mouseMoved(e1.mouseMove);
					break;
				case sf::Event::MouseButtonPressed:
					gsm.mousePressed(e1.mouseButton);
					break;
				case sf::Event::MouseButtonReleased:
					gsm.mouseReleased(e1.mouseButton);
					break;
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
					gsm.setPreviousState(e2.changeState.thisState);
					gsm.setState(e2.changeState.nextState);
					break;
				case fbb::Event::Return:
					texture.loadFromFile("loading.png");
					sprite.setTexture(texture);
					window.clear();
					window.draw(sprite);
					window.display();
					gsm.setState(gsm.getPreviousState());
					break;
			} //End switch
		} //End game event poll

		gsm.update();

		window.clear(sf::Color::White);
		gsm.draw(window);
		window.display();
	} //End game loop
}

} //End namespace

