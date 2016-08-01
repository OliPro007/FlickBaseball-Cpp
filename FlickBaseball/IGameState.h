#pragma once
#include <vector>
#include <queue>
#include <map>
#include <iostream>
#include <fstream>
#include "Main.h"
#include "Button.h"
#include "Event.h"
#include "rapidxml.hpp"

namespace fbb {

class IGameState {
public:
	virtual ~IGameState() { buttonList.clear(); }

	void loadStringtable(std::string locale, char state) {
		using namespace rapidxml;

		std::ifstream file;
		file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
		try {
			file.open(locale + ".xml");
			xml_document<> doc;
			xml_node<>* root;
			std::vector<char> buffer((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
			buffer.push_back('\0');
			doc.parse<0>(&buffer[0]);
			root = doc.first_node("stringtable");

			for(xml_node<>* stateNode = root->first_node("state"); stateNode; stateNode = stateNode->next_sibling()) {
				if(*(stateNode->first_attribute("id")->value()) == state) {
					for(xml_node<>* string = stateNode->first_node("string"); string; string = string->next_sibling()) {
						//Use a map to tie the id with the value;
						std::pair<std::string, std::string> pair(string->first_attribute("id")->value(), string->value());
						stringTable.emplace(pair);
					}
				}
			}
			file.close();
		} catch(std::exception e) {
			std::cerr << e.what() << std::endl;
			throw;
		}
	}

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

	static const byte MENU_STATE			= 0x00;
	static const byte NORMALMODE_STATE		= 0x01;
	static const byte FREEMODE_STATE		= 0x02;
	static const byte OPTIONS_STATE			= 0x03;
	static const byte HELP_STATE			= 0x04;

protected:
	sf::Font font;
	std::vector<fbb::Button> buttonList;
	std::queue<fbb::Event> eventQueue;
	std::map<std::string, sf::String> stringTable;

};

} //End namespace