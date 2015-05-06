#include "Button.h"

namespace fbb {

//////////////////////////////////////
// Copy constructor
//////////////////////////////////////
Button::Button(const Button& other) {
	this->text = other.text;
	this->location = other.location;
	this->unselectedImg = other.unselectedImg;
	this->selectedImg = other.selectedImg;
	this->clickedImg = other.clickedImg;
	this->currentImg = &unselectedImg;

	this->unselectedImg.setPosition(location);
	this->selectedImg.setPosition(location);
	this->clickedImg.setPosition(location);
}

///////////////////////////////////////
// Constructor - textless
///////////////////////////////////////
Button::Button(sf::Vector2f location, sf::Sprite* unselected, sf::Sprite* selected, sf::Sprite* clicked) {
	this->location = location;
	this->unselectedImg = *unselected;
	this->selectedImg = *selected;
	this->clickedImg = *clicked;
	this->currentImg = &unselectedImg;

	this->unselectedImg.setPosition(location);
	this->selectedImg.setPosition(location);
	this->clickedImg.setPosition(location);
}

///////////////////////////////////////
// Constructor - full
///////////////////////////////////////
Button::Button(sf::Text text, sf::Vector2f location, sf::Sprite* unselected, sf::Sprite* selected, sf::Sprite* clicked) {
	this->text = text;
	this->location = location;
	this->unselectedImg = *unselected;
	this->selectedImg = *selected;
	this->clickedImg = *clicked;
	this->currentImg = &unselectedImg;

	sf::Vector2f textLocation(location.x + (currentImg->getGlobalBounds().width- text.getGlobalBounds().width) / 2, location.y + text.getGlobalBounds().height / 2);
	this->text.setPosition(textLocation);
	this->unselectedImg.setPosition(location);
	this->selectedImg.setPosition(location);
	this->clickedImg.setPosition(location);
}

//////////////////////////////////////
// Destructor
//////////////////////////////////////
Button::~Button() {}

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(*currentImg);
	target.draw(text);
}

} //End namespace