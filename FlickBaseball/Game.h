#pragma once
#include <vector>
#include <iostream>
#include "SFML\Graphics.hpp"
#include "Button.h"
#include "GameStateManager.h"

namespace fbb {

class Game {
public:
	Game();
	~Game();
	void gameLoop();

private:
	const float WIDTH = 1280.0f;
	const float HEIGHT = 720.0f;
	const sf::String TITLE = "Flick Baseball";

	sf::RenderWindow window;
	sf::View camera;
	sf::VertexArray background;
	fbb::GameStateManager gsm;
	std::vector<fbb::Button>* currentButtonSet;
};

} //End namespace


