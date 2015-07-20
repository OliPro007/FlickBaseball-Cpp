#pragma once
#include <vector>
#include <queue>
#include <iostream>
#include "Main.h"
#include "Button.h"
#include "Event.h"

namespace fbb {

class IGameState {
public:
	virtual ~IGameState() {}
	virtual void init() = 0;
	virtual void draw(sf::RenderTarget& window) = 0;
	virtual void update() = 0;
	std::vector<fbb::Button>* getButtons() { return &buttonList; };
	bool pollEvent(fbb::Event& event) { 
		if(eventQueue.size() > 0) {
			event = eventQueue.front();
			eventQueue.pop();
			return true;
		} else {
			return false;
		}
	}
	void pushEvent(fbb::Event& event) { eventQueue.push(event); }

protected:
	sf::Font font;
	std::vector<fbb::Button> buttonList;
	std::queue<fbb::Event> eventQueue;

	static const BYTE MENU_STATE = 0;
	static const BYTE NORMALMODE_STATE = 1;
	static const BYTE FREEMODE_STATE = 2;
	static const BYTE OPTIONS_STATE = 3;
	static const BYTE HELP_STATE = 4;

};

} //End namespace