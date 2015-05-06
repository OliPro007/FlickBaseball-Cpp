#pragma once
#include <vector>
#include <map>
#include "SFML\Graphics.hpp"
#include "Button.h"

namespace fbb {

class Game {
public:
	Game();
	~Game();
	void gameLoop();

	sf::Font getFont() const { return this->font; }
	//TODO: Create gamestate manager and integrate buttons to the states

private:
	const float WIDTH = 1280.0f;
	const float HEIGHT = 720.0f;
	const sf::String TITLE = "Flick Baseball";

	sf::RenderWindow window;
	sf::View camera;
	sf::Font font;
	std::map<std::string, std::vector<sf::Drawable*>> resources;
	std::vector<fbb::Button> mainMenuButtons;
	std::vector<fbb::Button>* currentButtonSet;
};

} //End namespace


