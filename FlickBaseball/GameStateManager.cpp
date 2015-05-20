#include "GameStateManager.h"

namespace fbb {

GameStateManager::GameStateManager() : gameStates(), previousStates() {
	std::cout << "Initializing game state manager..." << std::endl;
	gameStates.push_back(new MenuState());
	gameStates.shrink_to_fit();

	setState(MENU_STATE);
	std::cout << "Done initializing game state manager!" << std::endl;
}

GameStateManager::~GameStateManager() {}

void GameStateManager::setState(int state) {
	currentState = state;
	gameStates.at(currentState)->init();
}

} //End namespace

