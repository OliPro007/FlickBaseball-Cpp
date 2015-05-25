#include "SFML\Graphics.hpp"
#include "Game.h"
#include <iostream>

int main() {
	sf::Clock* clock = new sf::Clock();
	sf::Time beginTime = clock->getElapsedTime();

	std::cout << "Creating game instance..." << std::endl;
	fbb::Game game;
	std::cout << "Game instance created successfully! Time: " << (clock->getElapsedTime() - beginTime).asMilliseconds() << " milliseconds" << std::endl;

	delete clock;
	clock = NULL;
	game.gameLoop();

	return 0;
}