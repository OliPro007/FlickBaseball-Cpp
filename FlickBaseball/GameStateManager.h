#pragma once
#include <vector>
#include <stack>
#include <iostream>
#include "MenuState.h"
#include "Button.h"

namespace fbb {

class GameStateManager {
public:
	GameStateManager();
	~GameStateManager();

	std::vector<fbb::Button>* getButtons() { return gameStates.at(currentState)->getButtons(); }
	void setState(int state);

	static const int MENU_STATE = 0;

private:
	std::vector<fbb::IGameState*> gameStates;
	std::stack<fbb::IGameState*> previousStates;
	int currentState;
};

} //End namespace