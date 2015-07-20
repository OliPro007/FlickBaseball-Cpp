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

	std::vector<fbb::Button>* getButtons() { return gameStates.at(currentState)->getButtons(); }
	void setState(const BYTE state);
	void setPreviousState(const BYTE state);
	int getPreviousState();
	bool pollEvent(fbb::Event& event) { return gameStates.at(currentState)->pollEvent(event); }

private:
	std::vector<fbb::IGameState*> gameStates;
	std::stack<BYTE> previousStates;
	int currentState;
};

} //End namespace