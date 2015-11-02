#include "GameStateManager.h"

namespace fbb {

GameStateManager::GameStateManager(fbb::Config config) :
config(config) {
	std::cout << "Initializing game state manager..." << std::endl;
	registerGameState(IGameState::MENU_STATE, [this]()->IGameState* { return new MenuState(this->config); });
	registerGameState(IGameState::NORMALMODE_STATE, [this]()->IGameState* { return new NormalModeState(this->config); });
	setState(IGameState::MENU_STATE);
	std::cout << "Done initializing game state manager!" << std::endl;
}

GameStateManager::~GameStateManager() {
	delete gameState;
	gameState = nullptr;
	registry.clear();
}

void GameStateManager::registerGameState(byte id, std::function<IGameState*(void)> constructor) {
	registry[id] = constructor;
}

void GameStateManager::draw(sf::RenderTarget& window) {
	gameState->draw(window);
}

void GameStateManager::update() {
	gameState->update();
}

void GameStateManager::setState(byte state) {
	try {
		currentState = state;
		delete gameState;
		gameState = nullptr;
		gameState = registry[state]();
	} catch(std::exception e) {
		std::cerr << "setState failed (see previous exception). Reloading previous state...";
		setState(getPreviousState());
	}
}

byte GameStateManager::getPreviousState() {
	int i = previousStates.top();
	previousStates.pop();
	return i;
}

void GameStateManager::setPreviousState(byte state) {
	previousStates.push(state);
}

} //End namespace

