#include "MenuState.h"

namespace fbb {

MenuState::MenuState() : buttonList(){
	std::cout << "Created menu state!" << std::endl;
}

MenuState::~MenuState() {
	fbb::IGameState::~IGameState();
}

void MenuState::init() {
	sf::Texture textureUnselected;
	textureUnselected.loadFromFile("button_unselected.png");

	sf::Texture textureSelected;
	textureSelected.loadFromFile("button_selected.png");

	sf::Texture textureClicked;
	textureClicked.loadFromFile("button_clicked.png");

	float pos = 100.0f;
	float textureX = 0.0f + textureUnselected.getSize().x;
	float textureY = 0.0f + textureUnselected.getSize().y;
	sf::VertexArray quad(sf::Quads, 4);
	quad[0].position = sf::Vector2f(pos, pos);
	quad[1].position = sf::Vector2f(pos + textureX, pos);
	quad[2].position = sf::Vector2f(pos + textureX, pos + textureY);
	quad[3].position = sf::Vector2f(pos, pos + textureY);
	quad[0].texCoords = sf::Vector2f(0.0f, 0.0f);
	quad[1].texCoords = sf::Vector2f(textureX, 0.0f);
	quad[2].texCoords = sf::Vector2f(textureX, textureY);
	quad[3].texCoords = sf::Vector2f(0.0f, textureY);

	font.loadFromFile("opensansc.ttf");
	sf::Text text("Test", font, 30);
	text.setColor(sf::Color::Black);
	sf::FloatRect textRect = text.getLocalBounds();
	text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	text.setPosition(pos + textureX / 2, pos + textureY / 2);

	fbb::Button button(text, quad, textureUnselected, textureSelected, textureClicked);
	buttonList.push_back(button);
}

void MenuState::draw() {

}

void MenuState::update() {

}

} //End namespace