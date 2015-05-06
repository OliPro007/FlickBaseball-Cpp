#include "MenuState.h"

namespace fbb {

MenuState::MenuState() {
	buttonList.push_back(fbb::Button(text, sf::Vector2f(100.0f, 100.0f), spriteUnselected, spriteSelected, spriteClicked))
}

MenuState::~MenuState() {
	fbb::IGameState::~IGameState();
}

void MenuState::init() {}

void MenuState::draw() {

}

void MenuState::update() {

}

} //End namespace