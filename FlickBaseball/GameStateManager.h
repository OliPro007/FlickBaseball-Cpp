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

	std::vector<fbb::Button>* getButtons() { return gameStates.at(currentState)->getButtons(); }
	void setState(const unsigned int state);
	void setPreviousState(const unsigned int state);
	int getPreviousState();
	bool pollEvent(fbb::Event& event) { return gameStates.at(currentState)->pollEvent(event); }

private:
	std::vector<fbb::IGameState*> gameStates;
	std::stack<unsigned int> previousStates;
	int currentState;
};

} //End namespace