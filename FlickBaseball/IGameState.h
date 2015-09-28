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
	virtual void draw(sf::RenderTarget& window) {
		for(fbb::Button& button : buttonList) {
			window.draw(button);
		}
	}
	virtual void update() = 0;

	virtual void mouseMoved(const sf::Event::MouseMoveEvent& e) {
		for(fbb::Button& button : buttonList) {
			if(button.isClicked())
				break;

			if(button.getBounds().contains(sf::Vector2f((float)e.x, (float)e.y))) {
				button.setSelected();
			} else {
				button.setUnselected();
			}
		}
	}
	virtual void mousePressed(const sf::Event::MouseButtonEvent& e) {
		for(fbb::Button& button : buttonList) {
			if(button.getBounds().contains(sf::Vector2f((float)e.x, (float)e.y))) {
				button.setClicked();
				break;
			}
		}
	}
	virtual void mouseReleased(const sf::Event::MouseButtonEvent& e) {
		for(fbb::Button& button : buttonList) {
			if(button.isClicked()) {
				button.onClick();
			}
			if(button.getBounds().contains(sf::Vector2f((float)e.x, (float)e.y))) {
				button.setSelected();
			} else {
				button.setUnselected();
			}
		}
	}

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

	static const byte MENU_STATE = 0;
	static const byte NORMALMODE_STATE = 1;
	static const byte FREEMODE_STATE = 2;
	static const byte OPTIONS_STATE = 3;
	static const byte HELP_STATE = 4;

};

} //End namespace