#pragma once
#include <vector>
#include <iostream>
#include <functional>
#include "SFML/Graphics.hpp"
#include "Main.h"
#include "Button.h"
#include "GameStateManager.h"
#include "Event.h"

namespace fbb {

class Game {
public:
	Game(fbb::Config config);
	~Game();
	void gameLoop();

private:	
	const sf::String TITLE = "Flick Baseball";

	sf::RenderWindow window;
	fbb::GameStateManager gsm;
};

} //End namespace


