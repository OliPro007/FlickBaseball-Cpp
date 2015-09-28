#include "Button.h"

namespace fbb {

Button::Button(const fbb::RoundRectangle& shape, const sf::Text& text) {
	this->shape = shape;
	this->text = text;
}

Button::Button(const Button& other) {
	this->shape = other.shape;
	this->text = other.text;
	this->action = other.action;
}

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	states.transform *= getTransform();
	target.draw(shape, states);
	target.draw(text, states);
}

void Button::onClick() const {
	this->action();
}

void Button::setClicked() {
	this->shape.setFillColor(sf::Color(0, 132, 129, 255));
	this->clicked = true;
	this->selected = false;
}

void Button::setSelected() {
	this->shape.setFillColor(sf::Color(150, 80, 0, 255));
	this->selected = true;
	this->clicked = false;
}

void Button::setUnselected() {
	this->shape.setFillColor(sf::Color(182, 59, 0, 255));
	this->selected = false;
	this->clicked = false;
}

} //End namespace