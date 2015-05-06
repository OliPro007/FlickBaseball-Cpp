#pragma once
#include "SFML\Graphics.hpp"

namespace fbb {

class Button : public sf::Drawable {
public:
	Button(const Button& other);
	Button(sf::Vector2f location, sf::Sprite* unclicked, sf::Sprite* clicked, sf::Sprite* selected);
	Button(sf::Text text, sf::Vector2f location, sf::Sprite* unclicked, sf::Sprite* clicked, sf::Sprite* selected);
	~Button();

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	void setText(sf::Text text) { this->text = text; }
	void setLocation(sf::Vector2f location) { this->location = location; }
	void setClicked() { this->currentImg = &clickedImg; this->clicked = true; this->selected = false; }
	void setSelected() { this->currentImg = &selectedImg; this->selected = true; this->clicked = false; }
	void setUnselected() { this->currentImg = &unselectedImg; this->selected = false; this->clicked = false; }

	sf::Text getText() const { return this->text; }
	sf::Vector2f getLocation() const { return this->location; }
	sf::FloatRect getSize() const { return currentImg->getGlobalBounds(); }
	bool isSelected() const { return this->selected; }
	bool isClicked() const { return this->clicked; }

private:
	sf::Text text;
	sf::Vector2f location;
	sf::Sprite unselectedImg;
	sf::Sprite selectedImg;
	sf::Sprite clickedImg;
	sf::Sprite* currentImg;
	bool selected = false;
	bool clicked = false;
};

} //End namespace