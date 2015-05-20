#include "Button.h"

namespace fbb {

//////////////////////////////////////
// Copy constructor
//////////////////////////////////////
Button::Button(const Button& other) {
	this->text = other.text;
	this->vertices = other.vertices;
	this->unselectedImg = other.unselectedImg;
	this->selectedImg = other.selectedImg;
	this->clickedImg = other.clickedImg;
	this->currentImg = &unselectedImg;
}

///////////////////////////////////////
// Constructor - textless
///////////////////////////////////////
Button::Button(sf::VertexArray vertices, sf::Texture unselected, sf::Texture selected, sf::Texture clicked) {
	this->vertices = vertices;
	this->unselectedImg = unselected;
	this->selectedImg = selected;
	this->clickedImg = clicked;
	this->currentImg = &unselectedImg;
}

///////////////////////////////////////
// Constructor - full
///////////////////////////////////////
Button::Button(sf::Text text, sf::VertexArray vertices, sf::Texture unselected, sf::Texture selected, sf::Texture clicked) {
	this->text = text;
	this->vertices = vertices;
	this->unselectedImg = unselected;
	this->selectedImg = selected;
	this->clickedImg = clicked;
	this->currentImg = &unselectedImg;
}

//////////////////////////////////////
// Destructor
//////////////////////////////////////
Button::~Button() {}

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	states.transform *= getTransform();
	states.texture = currentImg;
	target.draw(vertices, states);
	target.draw(text, states);
}

} //End namespace