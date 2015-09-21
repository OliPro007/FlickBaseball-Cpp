#include "GameStateManager.h"

namespace fbb {

GameStateManager::GameStateManager() {
	std::cout << "Initializing game state manager..." << std::endl;
	gameStates.push_back(new MenuState());
	gameStates.push_back(new NormalModeState);
	gameStates.shrink_to_fit();

	setState(0);
	std::cout << "Done initializing game state manager!" << std::endl;
}

GameStateManager::~GameStateManager() {}

void GameStateManager::draw(sf::RenderTarget& window) {
	gameStates.at(currentState)->draw(window);
}

void GameStateManager::update() {
	gameStates.at(currentState)->update();
}

void GameStateManager::setState(const byte state) {
	currentState = state;
	gameStates.at(currentState)->init();
}

int GameStateManager::getPreviousState() {
	int i = previousStates.top();
	previousStates.pop();
	return i;
}

void GameStateManager::setPreviousState(const byte state) {
	previousStates.push(state);
}

} //End namespace

