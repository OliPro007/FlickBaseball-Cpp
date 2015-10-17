#include "GameStateManager.h"

namespace fbb {

GameStateManager::GameStateManager() {
	std::cout << "Initializing game state manager..." << std::endl;
	registerGameState(IGameState::MENU_STATE, []()->IGameState* { return new MenuState(); });
	registerGameState(IGameState::NORMALMODE_STATE, []()->IGameState* { return new NormalModeState; });
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
	currentState = state;
	delete gameState;
	gameState = nullptr;
	gameState = registry[state]();
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

