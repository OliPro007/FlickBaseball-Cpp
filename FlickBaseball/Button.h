#pragma once
#include "SFML\Graphics.hpp"
#include <iostream>

namespace fbb {

class Button : public sf::Drawable, public sf::Transformable {
public:
	Button(const Button& other);
	Button(sf::VertexArray vertices, sf::Texture unselected, sf::Texture selected, sf::Texture clicked);
	Button(sf::Text text, sf::VertexArray vertices, sf::Texture unselected, sf::Texture selected, sf::Texture clicked);
	~Button();

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	void setText(sf::Text text) { this->text = text; }
	void setClicked() { this->currentImg = &clickedImg; this->clicked = true; this->selected = false; }
	void setSelected() { this->currentImg = &selectedImg; this->selected = true; this->clicked = false; }
	void setUnselected() { this->currentImg = &unselectedImg; this->selected = false; this->clicked = false; }

	sf::Text getText() const { return this->text; }
	sf::FloatRect getBounds() const { return vertices.getBounds(); }
	bool isSelected() const { return this->selected; }
	bool isClicked() const { return this->clicked; }

private:
	sf::Text text;
	sf::VertexArray vertices;
	sf::Texture unselectedImg;
	sf::Texture selectedImg;
	sf::Texture clickedImg;
	sf::Texture* currentImg;
	bool selected = false;
	bool clicked = false;
};

} //End namespace