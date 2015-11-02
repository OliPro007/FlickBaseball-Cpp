#include "SFML\Graphics.hpp"
#include "Game.h"
#include <iostream>
#include <fstream>

void loadLocale(fbb::Config& config);
void loadConfig(fbb::Config& config);

int main() {
	setlocale(LC_ALL, "");
	sf::Clock* clock = new sf::Clock();
	sf::Time beginTime = clock->getElapsedTime();

	std::cout << "Creating game instance..." << std::endl;
	fbb::Config config = {};
	loadConfig(config);
	fbb::Game game(config);
	std::cout << "Game instance created successfully! Time: " << (clock->getElapsedTime() - beginTime).asMilliseconds() << " milliseconds" << std::endl;

	delete clock;
	clock = nullptr;
	game.gameLoop();

	return 0;
}

void loadConfig(fbb::Config& config) {
	std::ifstream cfg("cfg.xml");
	if(cfg) {
		//read xml
	} else {
		//write xml and load default values from default struct values
		if(config.locale == "en") //will be empty string for system default
			loadLocale(config);
	}
}

void loadLocale(fbb::Config& config) {
	std::string locale = setlocale(LC_ALL, NULL); //Get locale string

	if(locale == "C")
		locale = "en";

	config.locale = locale.substr(0, 2); //Get the language identifier only
	for(size_t i = 0; i < config.locale.length(); i++) //Put to lowercase because Windows seems to like the long <language>_<region>.<code> format
		config.locale[i] = tolower(config.locale[i]);
}