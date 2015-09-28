#pragma once
#include <vector>
#include <stack>
#include <iostream>
#include "MenuState.h"
#include "NormalModeState.h"
#include "Button.h"

namespace fbb {

class GameStateManager {
public:
	GameStateManager();
	~GameStateManager();

	void draw(sf::RenderTarget& window);
	void update();

	void mouseMoved(const sf::Event::MouseMoveEvent& e) { gameStates.at(currentState)->mouseMoved(e); }
	void mousePressed(const sf::Event::MouseButtonEvent& e) { gameStates.at(currentState)->mousePressed(e); }
	void mouseReleased(const sf::Event::MouseButtonEvent& e) { gameStates.at(currentState)->mouseReleased(e); }

	void setState(const byte state);
	void setPreviousState(const byte state);
	int getPreviousState();
	bool pollEvent(fbb::Event& event) { return gameStates.at(currentState)->pollEvent(event); }

private:
	std::vector<fbb::IGameState*> gameStates;
	std::stack<byte> previousStates;
	int currentState;
};

} //End namespace