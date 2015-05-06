#include "Game.h"

namespace fbb {

Game::Game() : window(sf::VideoMode((int)WIDTH, (int)HEIGHT, sf::VideoMode::getDesktopMode().bitsPerPixel), TITLE), 
	camera(sf::FloatRect(0.0f, 0.0f, WIDTH, HEIGHT)) {
	window.setFramerateLimit(60);
	window.setView(camera);

	sf::Texture* textureUnselected = new sf::Texture();
	textureUnselected->loadFromFile("button_unselected.png");
	sf::Sprite* spriteUnselected = new sf::Sprite();
	spriteUnselected->setTexture(*textureUnselected, true);

	sf::Texture* textureSelected = new sf::Texture();
	textureSelected->loadFromFile("button_selected.png");
	sf::Sprite* spriteSelected = new sf::Sprite();
	spriteSelected->setTexture(*textureSelected, true);

	sf::Texture* textureClicked = new sf::Texture();
	textureClicked->loadFromFile("button_clicked.png");
	sf::Sprite* spriteClicked = new sf::Sprite();
	spriteClicked->setTexture(*textureClicked, true);

	font.loadFromFile("opensansc.ttf");
	sf::Text* text = new sf::Text("Test", font, 30);
	text->setColor(sf::Color::Black);
	
	resources.emplace("MainMenuSprites", new std::vector<sf::Drawable*> { spriteUnselected, spriteSelected, spriteClicked });
	resources.emplace("MainMenuTexts", new std::vector<sf::Drawable*> { text });

	currentButtonSet = &mainMenuButtons;
}

Game::~Game() {}

void Game::gameLoop() {
	while(window.isOpen()) {
		window.clear();
		for(fbb::Button& button : *currentButtonSet) {
			button.draw(window, sf::RenderStates::Default);
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

					if(button.getSize().contains(sf::Vector2f((float)event.mouseMove.x, (float)event.mouseMove.y))) {
						button.setSelected();
					} else {
						button.setUnselected();
					}
				}
			}
			if(event.type == sf::Event::MouseButtonPressed) {
				for(fbb::Button& button : *currentButtonSet) {
					if(button.getSize().contains(sf::Vector2f((float)event.mouseButton.x, (float)event.mouseButton.y))) {
						button.setClicked();
						break;
					}
				}
			}
			if(event.type == sf::Event::MouseButtonReleased) {
				for(fbb::Button& button : *currentButtonSet) {
					if(button.getSize().contains(sf::Vector2f((float)event.mouseButton.x, (float)event.mouseButton.y))) {
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

