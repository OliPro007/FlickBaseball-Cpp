#pragma once
#include <vector>
#include <stack>
#include <map>
#include <iostream>
#include <functional>
#include "MenuState.h"
#include "NormalModeState.h"
#include "Button.h"

namespace fbb {

class GameStateManager {
public:
	GameStateManager(fbb::Config config);
	~GameStateManager();

	void registerGameState(byte id, std::function<IGameState*(void)> constructor);

	void draw(sf::RenderTarget& window);
	void update();

	void mouseMoved(const sf::Event::MouseMoveEvent& e) { gameState->mouseMoved(e); }
	void mousePressed(const sf::Event::MouseButtonEvent& e) { gameState->mousePressed(e); }
	void mouseReleased(const sf::Event::MouseButtonEvent& e) { gameState->mouseReleased(e); }

	void setState(byte state);
	void setPreviousState(byte state);
	byte getPreviousState();
	bool pollEvent(fbb::Event& event) { return gameState->pollEvent(event); }

private:
	IGameState* gameState;
	std::map<byte, std::function<IGameState*(void)>> registry;
	std::stack<byte> previousStates;
	byte currentState;
	fbb::Config config;
};

} //End namespace