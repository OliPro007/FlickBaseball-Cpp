#pragma once
#include <iostream>
#include <functional>
#include <memory>
#include "SFML/Graphics.hpp"
#include "RoundRectangle.h"

namespace fbb {

class Button : public sf::Drawable, public sf::Transformable {
public:
	typedef std::function<void()> Action;

	Button(std::shared_ptr<sf::Shape> shape = std::make_shared<sf::RectangleShape>(), const sf::Text& text = sf::Text());
	Button(const Button& other);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void setAction(Action&& action) { this->action = std::move(action); }
	void onClick() const;

	void setText(const sf::Text& text) { this->text = text; }
	void setClicked();
	void setSelected();
	void setUnselected();

	const sf::Text getText() const { return this->text; }
	const sf::FloatRect getBounds() const { return shape->getGlobalBounds(); }
	const bool isSelected() const { return this->selected; }
	const bool isClicked() const { return this->clicked; }

private:
	std::shared_ptr<sf::Shape> shape;
	sf::Text text;
	Action action;
	bool selected = false;
	bool clicked = false;
};

} //End namespace
