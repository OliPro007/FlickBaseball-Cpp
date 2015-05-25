#pragma once
#include <vector>
#include <queue>
#include <iostream>
#include "Button.h"
#include "Event.h"

namespace fbb {

class IGameState {
public:
	virtual ~IGameState() {}
	virtual void init() = 0;
	virtual void draw() = 0;
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

	static const unsigned int MENU_STATE = 0;
	static const unsigned int NORMALGAME_STATE = 1;

protected:
	sf::Font font;
	std::vector<fbb::Button> buttonList;
	std::queue<fbb::Event> eventQueue;

};

} //End namespace