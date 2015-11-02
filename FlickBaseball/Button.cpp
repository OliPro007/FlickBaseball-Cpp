#include "Button.h"

namespace fbb {

// Constructor
	Button::Button(std::shared_ptr<sf::Shape> shape, const sf::Text& text) {
	this->shape = shape;
	this->text = text;

	this->shape->setOutlineThickness(5.0f);
	this->shape->setOutlineColor(sf::Color(228, 134, 0, 255));
}

// Copy constructor
Button::Button(const Button& other) {
	this->shape = other.shape;
	this->text = other.text;
	this->action = other.action;
}

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	states.transform *= getTransform();
	target.draw(*shape, states);
	target.draw(text, states);
}

void Button::onClick() const {
	this->action();
}

void Button::setClicked() {
	this->shape->setFillColor(sf::Color(0, 132, 129, 255));
	this->clicked = true;
	this->selected = false;
}

void Button::setSelected() {
	this->shape->setFillColor(sf::Color(150, 80, 0, 255));
	this->selected = true;
	this->clicked = false;
}

void Button::setUnselected() {
	this->shape->setFillColor(sf::Color(182, 59, 0, 255));
	this->selected = false;
	this->clicked = false;
}

} //End namespace