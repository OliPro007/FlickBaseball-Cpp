#pragma once
#include <iostream>
#include <functional>
#include "SFML\Graphics.hpp"
#include "RoundRectangle.h"

namespace fbb {

class Button : public sf::Drawable, public sf::Transformable {
public:
	Button(const fbb::RoundRectangle& shape = fbb::RoundRectangle(sf::Vector2f(10.0f, 10.0f)), const sf::Text& text = sf::Text());
	Button(const Button& other);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void setAction(const std::function<void()>& action) { this->action = action; }
	void onClick() const;

	void setText(const sf::Text& text) { this->text = text; }
	void setClicked();
	void setSelected();
	void setUnselected();

	const sf::Text getText() const { return this->text; }
	const sf::FloatRect getBounds() const { return shape.getGlobalBounds(); }
	const bool isSelected() const { return this->selected; }
	const bool isClicked() const { return this->clicked; }

private:
	fbb::RoundRectangle shape;
	sf::Text text;
	std::function<void()> action;
	bool selected = false;
	bool clicked = false;
};

} //End namespace